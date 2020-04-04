##Adapted from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=gcc
CFLAGS=-Wall -Wextra -std=gnu99 -I. 
DEPS = get_request.h status.h
OBJ = main.o get_request.o status.o get_links.o
EXE = main

##Create .o files from .c files. Searches for .c files with same .o names given in OBJ
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

##Create executable linked file from object files. 
$(EXE): $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

##Delete object files
clean:
	/bin/rm $(OBJ)

##Performs clean (i.e. delete object files) and deletes executable
clobber: clean
	/bin/rm $(EXE) 

docker:
	docker build -t joshcarp/alpine-smarter:1.0 .
	docker run --rm -ti joshcarp/alpine-smarter:1.0
	docker rm joshcarp/alpine-smarter:1.0

PROJECTNAME=a1
PRIVATEKEY=afarquhar_key
uni:
	scp -i ../$(PRIVATEKEY) -r ../$(PROJECTNAME) afarquhar@172.26.128.157:../$(PROJECTNAME)
	ssh -i $(PRIVATEKEY) afarquhar@172.26.128.157
