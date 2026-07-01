/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **ans;
int ansSize;

void dfs(char *s, int idx, int lrem, int rrem, int open,
         char *path, int len) {

    if (s[idx] == '\0') {
        if (lrem == 0 && rrem == 0 && open == 0) {
            path[len] = '\0';

            for (int i = 0; i < ansSize; i++)
                if (strcmp(ans[i], path) == 0)
                    return;

            ans[ansSize++] = strdup(path);
        }
        return;
    }

    char c = s[idx];

    if (c == '(') {
        if (lrem > 0)
            dfs(s, idx + 1, lrem - 1, rrem, open, path, len);

        path[len] = c;
        dfs(s, idx + 1, lrem, rrem, open + 1, path, len + 1);
    }
    else if (c == ')') {
        if (rrem > 0)
            dfs(s, idx + 1, lrem, rrem - 1, open, path, len);

        if (open > 0) {
            path[len] = c;
            dfs(s, idx + 1, lrem, rrem, open - 1, path, len + 1);
        }
    }
    else {
        path[len] = c;
        dfs(s, idx + 1, lrem, rrem, open, path, len + 1);
    }
}

char** removeInvalidParentheses(char* s, int* returnSize) {

    int lrem = 0, rrem = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(')
            lrem++;
        else if (s[i] == ')') {
            if (lrem > 0)
                lrem--;
            else
                rrem++;
        }
    }

    ans = (char **)malloc(10000 * sizeof(char *));
    ansSize = 0;

    char path[30];   // max length = 25

    dfs(s, 0, lrem, rrem, 0, path, 0);

    *returnSize = ansSize;
    return ans;
}