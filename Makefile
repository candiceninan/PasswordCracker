passwd: passwd.c
	mpicc -g -Wall passwd.c -o passwd

clean:
	rm -f passwd
