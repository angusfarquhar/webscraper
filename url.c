#include <string.h>
#include "url.h"

Url make_url(char *address) {
    int i = 0;
    char tmp[1000];
    char c;
    Url url;
    printf("START OF MAKE URL\n\n");
    printf("address is : %s\n\n", address);

    if (!strstr(address, "/")) {
        strcpy(url.host, address);
        printf("after strcpy url.host : %s\n\n", url.host);
        return url;
    } else {
        while (address[i] != '/') {
        printf("address[i] : %c\n", address[i]);
        c = address[i];
        tmp[i] = c;
        printf("host : %c\n", tmp[i]);
        i++;
     }
     printf ("\n\nout of if statement\n\n");

     // add null byte to array to make string
     tmp[i] = '\0';

     strcpy(url.host, tmp);
     printf("tmp = %s\n\naddress+i+1 = %s", tmp, address+i+1);
     strcpy(url.path, address+i+1);
     printf("\nurl.host : %s \n\n", url.host);
     printf("\nurl.path : %s \n\n", url.path);

     return url;
    }
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