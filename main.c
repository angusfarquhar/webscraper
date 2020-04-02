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

int main(int argc, char ** argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 2)
    {
        fprintf(stderr, "error: no url entered!\n");
        exit(0);
    }

    portno = atoi("80");


    /* Translate host name into peer's IP address ;
     * This is name translation service by the operating system
     */
    server = gethostbyname(argv[1]);
    printf("argv: %s\nserver: %s\n", argv[1], server->h_addr_list[0]);

    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    /* Building data structures for socket */

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy(server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    /* Create TCP socket -- active open
    * Preliminary steps: Setup: creation of active open socket
    */

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
    
    sprintf(buffer, "GET / HTTP/1.1\nHost: %s:%d\nAccept: */*\nAccept-Encoding: gzip\nProxy-Connection: Keep-Alive\nUser-Agent: joeb\r\n\r\n", argv[1], portno);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(0);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(0);
    }

    printf("%s\n", buffer);

    return 0;
}
