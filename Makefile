all: search.o directory.o application.o
	gcc -g -std=c99 $^ -o application
application.o : application.c application.h
	gcc -c -Wall -g  application.h application.c -std=c99
search.o : search.c search.h
	gcc -c -Wall -g  search.h search.c -std=c99
directory.o: directory.c directory.h
	gcc -c -Wall -g  directory.h directory.c -std=c99
