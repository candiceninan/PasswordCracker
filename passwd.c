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
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Provides SHA-1 functions: */
#include "sha1.c"

/* Defines the alphanumeric character set: */
char *alpha_num = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

/* Pointer to the current valid character set */
char *valid_chars;

/* When the password is found, we'll store it here: */
char found_pw[128] = { 0 };

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
            /* TODO: This prints way too often... */
            printf("%s -> %s\n", strcp, hash);
            if (strcmp(hash, target) == 0) {
                /* We found a match! */
                strcpy(found_pw, strcp);
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

    /* TODO: We need some sanity checking here... */
    int length = atoi(argv[1]);
    char *target = argv[2];
    valid_chars = alpha_num;

    /* TODO: Print out job information here (valid characters, number of
     * processes, etc). */

    crack(target, "", length);

    /* TODO: the 'crack' call above starts with a blank string, and then
     * proceeds to add characters one by one, in order. To parallelize this, we
     * need to make each process start with a specific character. Kind of like
     * the following:
    int i;
    for (i = 0; i < strlen(valid_chars); ++i) {
        char start_str[2] = { valid_chars[i], '\0' };
        bool found = crack(target, start_str, length);
    }
    */

    if (strlen(found_pw) > 0) {
        printf("Recovered password: %s\n", found_pw);
    }

    return 0;
}
