main: main.o ordenar.o
	gcc main.o ordenar.o -o main -g -Wall

main.o: main.c
	gcc main.c -c -g -Wall

ordenar.o: ordenar.c
	gcc ordenar.c -c -g -Wall

clean:
	rm main.o ordenar.o main -f
