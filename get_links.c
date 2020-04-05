#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define A_HREF 9
#define MAX_URLS 100
#define MAX_LENGTH 1000

char **get_links(char *response) {
    int i=0, j=0, k=0;
    char *tag = NULL;
    char *link = NULL;

    char **link_array = malloc(sizeof *link_array * MAX_URLS);
    assert(link_array);

    if (link_array) {
        for (i = 0; i < MAX_URLS; i++) {
            link_array[i] = malloc(sizeof *link_array[i] * MAX_LENGTH);
        }
    }
    
    printf("\n..................... TESTING GET_LINKS .......................\n");
    tag = strstr(response, "<a href=");
    j=0;
    while (strstr(tag, "<a href=")) {
        printf("\n..................... START OF WHILE(TAG) .......................\n");
        

    
        //printf("link[0] : %c \n" ,tag[0]);
        printf("tag = %s\n\n\n\n",tag);
        tag = tag + A_HREF;

        link = (char *)malloc(sizeof(char) * 256);
        assert(link);

        //parse html tag until you get to the end of the link, adding it to link array
        k=0; 
        while (tag[k] != '"') {
            link[k] = tag[k];
            k++;
        }
        // add null byte to array to make string
        link[k] = '\0';
        printf("link= %s\n\n\n\n",link);

        strcpy(link_array[j], link);
        j++;
        printf("value for i is : %d", j);
        tag = tag +A_HREF;
        tag = strstr(tag, "<a href=");
        if (tag == NULL) {
            break;
        }
        
    
    
    } 
    printf("\n..................... END OF GET_LINKS .......................\n");
    return link_array; 

}


