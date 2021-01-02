issort.o: question1.c question1.h
	gcc -Wall -g -c question1.c -o issort.o

libissort.a: issort.o
	ar -rcs libissort.a issort.o

isort: issort.o libissort.a
	gcc -Wall -g -o isort issort.o libissort.a

txtfind.o: question2.c question2.h
	gcc -Wall -g -c question2.c -o txtfind.o

libtxtfind.a: txtfind.o
	ar -rcs libtxtfind.a txtfind.o

txtfind: txtfind.o libtxtfind.a
	gcc -Wall -g -o txtfind txtfind.o libtxtfind.a

.PHONY: clean all isort myissort txtfind mytxtfind

myissort: libissort.a

mytxtfind: libtxtfind.a

all: libissort.a issort issort.o libtxtfind.a txtfind txtfind.o

clean:
	rm -f *.o *.a *.so issort