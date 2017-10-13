main: main.o next.o
	gcc main.o next.o -o main -Wall -g


main.o: main.c
	gcc main.c -c -g -Wall

next.o: next.c
	gcc next.c -c -g -Wall

clean:
	rm main.o next.o -f
