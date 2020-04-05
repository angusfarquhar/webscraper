#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"

int status(char *header) {
    
    if (strstr(header, "HTTP/1.1 200 OK")) {

        printf("\nheader is 200 OK\n");

        return 1;

    } else {
        printf("\nheader is NOT 200 OK\n");    
    }


    return 0;

}