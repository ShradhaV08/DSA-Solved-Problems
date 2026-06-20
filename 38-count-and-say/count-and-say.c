#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* countAndSay(int n) {
    char *curr = (char*)malloc(5000);
    strcpy(curr, "1");

    for (int i = 2; i <= n; i++) {

        char *next = (char*)malloc(5000);
        int pos = 0;

        int len = strlen(curr);

        for (int j = 0; j < len; ) {

            char ch = curr[j];
            int count = 0;

            while (j < len && curr[j] == ch) {
                count++;
                j++;
            }

            pos += sprintf(next + pos, "%d%c", count, ch);
        }

        free(curr);
        curr = next;
    }

    return curr;
}