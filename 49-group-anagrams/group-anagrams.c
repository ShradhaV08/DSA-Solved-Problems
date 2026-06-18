#include <stdlib.h>
#include <string.h>

int compareChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char* sortString(char *s) {
    int len = strlen(s);
    char *copy = (char *)malloc((len + 1) * sizeof(char));

    strcpy(copy, s);
    qsort(copy, len, sizeof(char), compareChar);

    return copy;
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));

    char **keys = (char **)malloc(strsSize * sizeof(char *));
    int *groupSize = (int *)calloc(strsSize, sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < strsSize; i++) {

        char *key = sortString(strs[i]);

        int group = -1;

        for (int j = 0; j < *returnSize; j++) {
            if (strcmp(keys[j], key) == 0) {
                group = j;
                break;
            }
        }

        if (group == -1) {
            group = *returnSize;
            keys[group] = key;

            result[group] = (char **)malloc(strsSize * sizeof(char *));
            groupSize[group] = 0;

            (*returnSize)++;
        } else {
            free(key);
        }

        result[group][groupSize[group]++] = strs[i];
    }

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = groupSize[i];

    free(keys);
    free(groupSize);

    return result;
}