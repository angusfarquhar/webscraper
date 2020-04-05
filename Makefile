OBJ = main.o get_request.o status.o get_links.o url.o
EXE = main

##Create .o files from .c files. Searches for .c files with same .o names given in OBJ
build:
	gcc -g -Wall *.c -o main

##Performs clean (i.e. delete object files) and deletes executable
clean:
	rm *.o
	rm main
