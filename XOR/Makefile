main: main.o func.o
	gcc -g -o main main.o func.o

main.o: main.c func.h
	gcc -g -c main.c

func.o: func.o func.h
	gcc -g -c func.c
