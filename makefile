all: main.o list.o library.o
	gcc -o main main.o list.o library.o

main.o: main.c list.h library.h
	gcc -c main.c

library.o: library.c library.h list.h
	gcc -c library.c

list.o: list.c list.h
	gcc -c list.c

run:
	./main

clean:
	rm -rf *.o
