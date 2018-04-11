# Project 2: Distributed Password Cracker

See Project Spec here: https://www.cs.usfca.edu/~mmalensek/cs220/assignments/project-2.html

## Performance Evaluation

Edit this README.md file to answer the following questions:

### Password Recovery (1 pts)

Choose five entries from the password database and recover the passwords. List the username + password combinations here, along with the run time of your program and the number of hashes computed per second.

Aditya
Target hash: F7FF9E8B7BB2E09B70935A5D785E0CC5D9D0ABF0
Time elapsed: 68.72s
Total passwords hashed: 187637830 (2730528.81/s)
Recovered password: Hello

Liu
Target hash: A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD
Time elapsed: 0.15s
Total passwords hashed: 298535 (2052308.98/s)
Recovered password: Meow

Niha
Target hash: F4169F30903C1FCA747CDCD7C2D0081A79E23514
Time elapsed: 111.76s
Total passwords hashed: 306075215 (2738656.24/s)
Recovered password: M0kaY

Carmen
Target hash: 64369A22CBC5686E2CCF609AAE16FE42FA1178B4
Time elapsed: 4016.43s
Total passwords hashed: 1668652398 (415456.73/s)
Recovered password: Bloink

Erika
Target hash: 250E77F12A5AB6972A0895D290C4792F0A326EA8
Time elapsed: 3067.58s
Total passwords hashed: 2352625377 (237373.57/s)
Recovered password: banana



### Performance Benchmarking (1 pts)

Choose one of the password hashes from the database (preferably one that runs for a while). Compare the run time with 4, 16, 32, and 64 processes. You'll need to run on the jet machines to do this. List the speedup and parallel efficiency for each.

Aditya

4 - 
Time elapsed: 450.05s
Total passwords hashed: 159438483 (354268.60/s)

16 - 
Time elapsed: 5.45s
Total passwords hashed: 8652248 (1587712.97/s)


32 - 
Time elapsed: 136.41s
Total passwords hashed: 228337181 (1673856.93/s)

64 - 
Time elapsed: more than 2 hours
Total passwords hashed: > 100000000 

16 seemed to be the most efficient, while 64 took the longest. 4 was too little and 32 was an effective time compared to 4 and 64. We see the lower numbers taking some time and as you increase the number of processes above the number you have (24 in the case of jets) it will slow down. 

### Algorithmic Trade-offs (1pts)

Brute-forcing passwords can take some time. What might be a better approach?  On the other hand, what is one guarantee our algorithm can provide that others may not be able to?

A better approach might be to use a database with a dictionary of words that we can utilize to compare passwords in order to speed up the process instead of starting from the bottom. We guarantee that all the possible combinations will be checked and will definitely find the password. 
