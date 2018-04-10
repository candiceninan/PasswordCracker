# Project 2: Distributed Password Cracker

See Project Spec here: https://www.cs.usfca.edu/~mmalensek/cs220/assignments/project-2.html

## Performance Evaluation

Edit this README.md file to answer the following questions:

### Password Recovery (1 pts)

Choose five entries from the password database and recover the passwords. List the username + password combinations here, along with the run time of your program and the number of hashes computed per second.

LIU
Starting parallel password cracker.
Number of processes: 24
Coordinator node: jet01
Valid characters: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ (52)
Target password length: 4
Target hash: A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD
Operation complete.
Time elapsed: 0.1787030697
Total passwords hashed: 325646
Recovered password: Meow


### Performance Benchmarking (1 pts)

Choose one of the password hashes from the database (preferably one that runs for a while). Compare the run time with 4, 16, 32, and 64 processes. You'll need to run on the jet machines to do this. List the speedup and parallel efficiency for each.

(your answer)

### Algorithmic Trade-offs (1pts)

Brute-forcing passwords can take some time. What might be a better approach?  On the other hand, what is one guarantee our algorithm can provide that others may not be able to?

(your answer)
