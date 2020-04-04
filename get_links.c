#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_links(char *response) {
    char *link;
    link = strstr(response, "<a href=");
    
    if (link) {

        printf("\nfound a link!\n");
        printf("\nLINK : %s\n", link);

        return 1;

    } else {
        printf("\nno link found :(\n");    
    }


    return 0;

}