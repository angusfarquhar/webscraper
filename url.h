#include <stdio.h>
#include <stdlib.h>

typedef struct Url {
   char host[256];
   char path[256];
} Url;

char *parse_url(char *url);
Url make_url(char *address);

