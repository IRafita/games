main: main.o concret.o
	gcc main.o concret.o -o main -Wall -g

main.o: main.c
	gcc main.c -c -g -Wall

concret.o: concret.c
	gcc concret.c -c -g -Wall

clean:
	rm main.o concret.o main -f
