all: main.o sieve.o
	gcc main.o sieve.o -lm

main.o: main.c sieve.h
	gcc -c main.c sieve.h

sieve.o: sieve.c sieve.h
	gcc -c sieve.c sieve.h

run: 
	./a.out