#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *urls[100000];
int count = 0;

// Encodes a URL to a shortened URL.
char* encode(char* longUrl) {
    urls[count] = (char*)malloc(strlen(longUrl) + 1);
    strcpy(urls[count], longUrl);

    char *shortUrl = (char*)malloc(50);
    sprintf(shortUrl, "http://tinyurl.com/%d", count);

    count++;
    return shortUrl;
}

// Decodes a shortened URL to its original URL.
char* decode(char* shortUrl) {
    int id;

    sscanf(shortUrl, "http://tinyurl.com/%d", &id);

    return urls[id];
}