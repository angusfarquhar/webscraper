#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define A_HREF 9

int get_links(char *response) {
    char *tag = NULL;
    char* link;
    

    tag = strstr(response, "<a href=");
    printf("\n..................... TESTING LINKS .......................\n");
    printf("link[0] : %c \n" ,tag[0]);
    
    tag = tag + A_HREF;

    link = (char *)malloc(sizeof(char) * 256);
    assert(link);

    //parse html tag until you get to the end of the link, adding it to link array
    int i = 0;
    while (tag[i] != '"') {
         link[i] = tag[i];
         printf("link : %c\n", link[i]);
         i++;
     }

     // add null byte to array to make string
     link[i] = '\0';

     printf("complete link!! : %s", link);
     printf("strlen(tag) : %lu\n\nstrlen(link) : %lu", strlen(tag), strlen(link));

    if (strlen(tag) > strlen(link) ) {
        
        printf("\n..................... NEW TAG .......................\n");
        //move tag forward by length of string
        printf("\n%s\n", tag + strlen(link));
        printf("\n..................... END OF NEW TAG .......................\n");
        return get_links(tag);

    } else {
        printf("\n NO LINK FOUND :( \n");    
    }

    printf("\n..................... END OF LINKS .......................\n");
    return 0;

}


