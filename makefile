processWAV: Main.o Functions.o
	gcc -o processWAV Main.o Functions.o

Main.o: Header.h Main.c
	gcc -c Main.c

Functions.o: Functions.c
	gcc -c Functions.c