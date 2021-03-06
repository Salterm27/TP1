#T.P. 1 - Programacion C++

#Universidad de Buenos Aires
#Facultad de Ingenieria
#Algoritmos y Programacion II - 95.12
#Catedra: Calvo

#Autores: Alterman S., Fullone J., Scheinkerman L.


CC = g++ -Wall -Wextra -g


all: TP1 clean


TP1: main.o Cmdline.o Complex.o Fourier.o Array.h
	$(CC) -o TP1 main.o Complex.o Fourier.o Cmdline.o

main.o: main.cpp Complex.h Array.h Fourier.h Cmdline.h
	$(CC) -o main.o -c main.cpp

Complex.o: Complex.cpp Complex.h 
	$(CC) -o Complex.o -c Complex.cpp

Fourier.o: Fourier.cpp Fourier.h Array.h Complex.h
	$(CC) -o Fourier.o -c Fourier.cpp

Cmdline.o: Cmdline.cpp Cmdline.h
	$(CC) -o Cmdline.o -c Cmdline.cpp


clean:
	rm *.o
