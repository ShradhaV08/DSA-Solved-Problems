#include <stdlib.h>
#include <string.h>

char* shortestPalindrome(char* s) {
    int n = strlen(s);

    if (n <= 1)
        return s;

    // Reverse s
    char *rev = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++)
        rev[i] = s[n - 1 - i];
    rev[n] = '\0';

    // Build temp = s + "#" + rev
    int len = 2 * n + 1;
    char *temp = (char*)malloc((len + 1) * sizeof(char));

    strcpy(temp, s);
    temp[n] = '#';
    strcpy(temp + n + 1, rev);

    // KMP LPS array
    int *lps = (int*)calloc(len, sizeof(int));

    for (int i = 1; i < len; i++) {
        int j = lps[i - 1];

        while (j > 0 && temp[i] != temp[j])
            j = lps[j - 1];

        if (temp[i] == temp[j])
            j++;

        lps[i] = j;
    }

    int palLen = lps[len - 1];

    // Build answer
    char *result = (char*)malloc((2 * n - palLen + 1) * sizeof(char));

    int idx = 0;

    for (int i = n - 1; i >= palLen; i--)
        result[idx++] = s[i];

    strcpy(result + idx, s);

    free(rev);
    free(temp);
    free(lps);

    return result;
}