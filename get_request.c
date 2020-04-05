/* A simple client program for server.c

   To compile: gcc client.c -o client

   To run: start the server, then the client */


   // TO DO: - parse the address, sort out buffer, 
            

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <assert.h>
#include "url.h"

#define PORTNO 80
#define MAXBYTES 100000
#define BUFFER 256

char *get_request(char *address)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER];
    char *response;

    /* Translate host name into peer's IP address ;
     * This is name translation service by the operating system
     */
    printf("HERE yeah\n\n");
    Url url = make_url(address);
    printf("make_url done : url.host = %s\n\n", url.host);
    server = gethostbyname(url.host);
    printf("\n\nserver: %s\n\n", url.host);
    printf("HERE 2\n\n");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    /* Building data structures for socket */

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy(server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(PORTNO);

    /* Create TCP socket -- active open
    * Preliminary steps: Setup: creation of active open socket
    */
   printf("HERE 3\n\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(0);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(0);
    }

    /* Do processing
    */
    
    sprintf(buffer, "GET /%s HTTP/1.1\nHost: %s:%d\nUser-Agent: afarquhar\nConnection: close\r\n\r\n", url.path, url.host, PORTNO);
    printf("MAKING GET REQUEST... [GET /%s HTTP/1.1\nHost: %s:%d\nUser-Agent: afarquhar\nConnection: close]", url.path, url.host, PORTNO);
    n = write(sockfd, buffer, strlen(buffer));

    response = (char *)malloc(sizeof(char) * MAXBYTES);
    assert(response);

    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(0);
    }

    do 
    {
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(0);
    } else 
        {   
            printf("............. BUFFER .............\n\n%s\n\n", buffer);
            strcat(response, buffer);

        }
    } while (n > 0);
    
    
    printf("............. RESPONSE .............\n\n%s\n\n", response);

    //if (status(response) == 1) {
    //    printf("SUCCESS!!\n");
    //}

    return response;
}


