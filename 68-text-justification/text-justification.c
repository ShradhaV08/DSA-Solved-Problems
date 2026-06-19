#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;

    int i = 0;

    while (i < wordsSize) {
        int start = i;
        int len = 0;

        while (i < wordsSize &&
               len + strlen(words[i]) + (i - start) <= maxWidth) {
            len += strlen(words[i]);
            i++;
        }

        int end = i - 1;
        int numWords = end - start + 1;

        char* line = (char*)malloc(maxWidth + 1);
        int pos = 0;

        // Last line or single word -> left justify
        if (i == wordsSize || numWords == 1) {

            for (int j = start; j <= end; j++) {
                int wlen = strlen(words[j]);
                memcpy(line + pos, words[j], wlen);
                pos += wlen;

                if (j != end)
                    line[pos++] = ' ';
            }

            while (pos < maxWidth)
                line[pos++] = ' ';
        }
        else {
            int spaces = maxWidth - len;
            int gaps = numWords - 1;

            int even = spaces / gaps;
            int extra = spaces % gaps;

            for (int j = start; j <= end; j++) {

                int wlen = strlen(words[j]);
                memcpy(line + pos, words[j], wlen);
                pos += wlen;

                if (j != end) {
                    int cnt = even + (extra > 0 ? 1 : 0);
                    if (extra > 0)
                        extra--;

                    while (cnt--)
                        line[pos++] = ' ';
                }
            }
        }

        line[pos] = '\0';
        result[*returnSize] = line;
        (*returnSize)++;
    }

    return result;
}