#gcc -o main main.c person.c ../list.c -Wall

all: main.o person.o list.o
	gcc -o main main.o person.o list.o -Wall

main.o: main.c
	gcc -c main.c -Wall

person.o: person.c person.h
	gcc -c person.c -Wall

list.o: ../list.c ../list.h
	gcc -c ../list.c -Wall