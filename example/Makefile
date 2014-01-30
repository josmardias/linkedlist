CC	=	gcc
#CC	=	clang

all: main.o person.o list.o
	$(CC) -o main main.o person.o list.o -Wall

main.o: main.c
	$(CC) -c main.c -Wall

person.o: person.c person.h
	$(CC) -c person.c -Wall

list.o: ../list.c ../list.h
	$(CC) -c ../list.c -Wall