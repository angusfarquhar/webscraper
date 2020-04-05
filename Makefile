##Adapted from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -I. -g
DEPS = get_request.h status.h
OBJ = main.o get_request.o status.o get_links.o
EXE = main

##Create .o files from .c files. Searches for .c files with same .o names given in OBJ
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

##Create executable linked file from object files. 
$(EXE): $(OBJ)
	gcc $(CFLAGS) -o $@ $^ 

##Delete object files
clean:
	/bin/rm $(OBJ)

##Performs clean (i.e. delete object files) and deletes executable
clobber: clean
	/bin/rm $(EXE)
