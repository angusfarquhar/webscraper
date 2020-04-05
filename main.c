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
#include "get_request.h"
#include "get_links.h"
#include "url.h"

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

    char **link_array = get_links(response);

    for (int i = 0; i <100; i++) {
        printf("--> this is the link in link array[%d] : %s\n\n",i, link_array[i]);
    }
    

    printf("\n\n................. END PROGRAM .........................\n\n");
    return 0;
}


