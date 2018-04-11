/**
 * passwd.c
 *
 * Given a length and SHA-1 password hash, this program will use a brute-force
 * algorithm to recover the password using hash inversions.
 *
 * Compile: mpicc -g -Wall passwd.c -o passwd
 * Run: mpirun --oversubscribe -n 4 ./passwd num-chars hash [valid-chars]
 *
 * Where:
 *   - num-chars is the number of characters in the password
 *   - hash is the SHA-1 password hash (may not be in uppercase...)
 *   - valid-chars tells the program what character set to use (numeric, alpha,
 *     alphanumeric)
 */

#include <ctype.h>
#include <mpi.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Provides SHA-1 functions: */
#include "sha1.c"

/* Defines the alphanumeric character set: */
char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *numeric = "0123456789";
char *alpha_num = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int hashes = 0, pw_found = 0, rank;
/* Pointer to the current valid character set */
char *valid_chars;

/* When the password is found, we'll store it here: */
char found_pw[128] = {0};
MPI_Request sendRequest, recRequest;
int comm_sz;
/**
 * Generates passwords in order (brute-force) and checks them against a
 * specified target hash.
 * Inputs:
 *  - target - target hash to compare against
 *  - str - initial string. For the first function call, this can be "".
 *  - max_length - maximum length of the password string to generate
 */
bool crack(char *target, char *str, int max_length) {
  int curr_len = strlen(str);
  char *strcp = calloc(max_length + 1, sizeof(char));
  strcpy(strcp, str);

  /* We'll copy the current string and then add the next character to it. So
   * if we start with 'a', then we'll append 'aa', and so on. */
  int i;
  for (i = 0; i < strlen(valid_chars); ++i) {
    MPI_Iprobe(MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &pw_found, MPI_STATUS_IGNORE);
    if (pw_found) {
      MPI_Recv(found_pw, 100, MPI_CHAR, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      return true;
    }
    strcp[curr_len] = valid_chars[i];
    if (curr_len + 1 < max_length) {
      bool found = crack(target, strcp, max_length);
      if (found == true) {
        return true;
      }
    } else {
      /* Only check the hash if our string is long enough */
      char hash[41];
      sha1sum(hash, strcp);
      // for every million
      if (hashes % 1000000 == 0) {
        printf("[%d|%d] %s -> %s\n", rank, hashes, strcp, hash);
      }
      hashes++;
      if (strcmp(hash, target) == 0) {
        /* We found a match! */
        strcpy(found_pw, strcp);
        int i;
        for (i = 0; i < comm_sz; i++) {
          MPI_Isend(found_pw, max_length, MPI_CHAR, i, 0, MPI_COMM_WORLD, &sendRequest);
        }
        return true;
      }
    }
  }

  free(strcp);
  return false;
}

/**
 * Modifies a string to only contain uppercase characters.
 */
void uppercase(char *string) {
  int i;
  for (i = 0; string[i] != '\0'; i++) {
    string[i] = toupper(string[i]);
  }
}

int main(int argc, char *argv[]) {

  if (argc < 3 || argc > 4) {
    printf("Usage: mpirun %s num-chars hash [valid-chars]\n", argv[0]);
    printf("  Options for valid-chars: numeric, alpha, alphanum\n");
    printf("  (defaults to 'alphanum')\n");
    return 0;
  }

  MPI_Init(&argc, &argv);

  int comm_sz;
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  char hostname[MPI_MAX_PROCESSOR_NAME];
  int name_sz;
  MPI_Get_processor_name(hostname, &name_sz);

  /* We need some sanity checking here... */
  int length = atoi(argv[1]);
  char *target = argv[2];
  char *type = argv[3];

  uppercase(target);
  if (strcmp(type, "alpha") == 0) {
    valid_chars = alpha;
  } else if (strcmp(type, "numeric") == 0) {
    valid_chars = numeric;
  } else {
    //set alphanum as default
    valid_chars = alpha_num;
  }
  //check hash length
  if (strlen(argv[2]) != 40) {
    if (rank == 0) {
      printf("Hash length is NOT valid. \n");
    }
    return 1;
  }
  //check password length
  if (atoi(argv[1]) <= 0) {
    if (rank == 0) {
      printf("Password must be AT LEAST one character! \n");
    }
    return 1;
}


  double time = MPI_Wtime();
  if (rank == 0) {
  /* Print out job information here (valid characters, number of
     * processes, etc). */
    printf("Starting parallel password cracker.\n");
    printf("Number of processes: %d\n", comm_sz);
    printf("Coordinator node: %s\n", hostname);
    printf("Valid characters: %s (%lu)\n", valid_chars, strlen(valid_chars));
    printf("Target password length: %d\n", length);
    printf("Target hash: %s\n", target);
  }
  int count = strlen(valid_chars) / comm_sz;
  int end;
  int start = rank*count;
  
  
  if (rank == comm_sz-1) {
    end = strlen(valid_chars);
  } else {
    end = (rank*count)+count;
  }

  bool found = false;
  int i;
  for (i = start; i < end && !found; i++) {
    char str_start[2] = {valid_chars[i], 0};
    found = crack(target, str_start, length);
  }

  if (!pw_found && found ) {
    for (i = 0; i < comm_sz; i++)
      if (i != rank)
        MPI_Send(found_pw, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD);
  }

  long int hash_total = 0;
  MPI_Reduce(&hashes, &hash_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  /* Password check to finalize if found*/
  MPI_Iprobe(MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &pw_found, MPI_STATUS_IGNORE);

  if (pw_found)
    MPI_Recv(found_pw, 100, MPI_CHAR, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

  /* Print time/process stats when complete */
  if (rank == 0) {
    printf("Operation complete.\n");
    printf("Time elapsed: %.2fs\n", MPI_Wtime()-time);
    printf("Total passwords hashed: %ld (%.2f/s)\n", hash_total, hash_total/(MPI_Wtime()-time));

    if (strlen(found_pw) > 0)
      printf("Recovered password: %s\n", found_pw);
    else
      printf("FAILED to recover password!\n");
  }

  MPI_Finalize();

  return 0;
}
