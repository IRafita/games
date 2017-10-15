main: main.o ../concret/concret.o
	gcc main.o ../concret/concret.o -o main -Wall -g

main.o: main.c
	gcc main.c -c -g -Wall

../concret/concret.o: ../concret/concret.c
	cd ../concret; make concret.o

clean:
	cd ../concret; make clean
	rm main.o main -f
