/* A simple client program for server.c

   To compile: gcc client.c -o client

   To run: start the server, then the client */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

char *get_request(char *url);
char *parse_url(char *url);
char *get_links(char *response);

int main(int argc, char ** argv)
{
    printf("\n\n................. START PROGRAM .........................\n\n");
    if (argc < 2)
    {
        fprintf(stderr, "error: no url entered!\n");
        exit(0);
    }
    char *url = argv[1];
    printf("\nurl put into the CLI : %s\n", url);
    url = parse_url(url);
    printf("\nurl after parsing : %s\n", url);

    char *response = get_request(url);

    printf("............. END RESPONSE .............\n\n%s\n\n", response);

    printf("............. START PARSING LINKS .............\n\n%s\n\n", response);

    get_links(response);
    

    printf("\n\n................. END PROGRAM .........................\n\n");
    return 0;
}

char *parse_url(char *url) 
{
    if (strstr(url, "http://")) {
        url = url+ 7;
        printf("\nPARSED url in function: %s\n", url);
    }
    if (strstr(url, "https://")) {
        url = url+ 8;
        printf("\nPARSED url in function: %s\n", url);
    }

    printf("\nURL IS FINE!!\n");
    return url;
    
}
