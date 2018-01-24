all:	liberry

liberry:	liberry.o
	gcc -o liberry main.o 

liberry.o:	main.c
	gcc -c main.c

clean:
	rm main.o liberry

build:
	gcc main.c -o liberry
