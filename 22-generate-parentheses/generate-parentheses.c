#include <stdlib.h>
#include <string.h>

char **result;
int count;

void backtrack(char *current, int pos, int open, int close, int n) {
    if (pos == 2 * n) {
        result[count] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[count], current);
        count++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(current, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(current, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    result = (char **)malloc(15000 * sizeof(char *));
    count = 0;

    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    backtrack(current, 0, 0, 0, n);

    *returnSize = count;
    return result;
}