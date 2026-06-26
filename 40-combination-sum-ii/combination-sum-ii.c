/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 */

#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void dfs(int *candidates, int candidatesSize, int start, int target,
         int *path, int pathSize,
         int ***ans, int *returnSize, int **returnColumnSizes) {

    if (target == 0) {
        (*ans)[*returnSize] = (int *)malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++)
            (*ans)[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];

        dfs(candidates, candidatesSize, i + 1,
            target - candidates[i],
            path, pathSize + 1,
            ans, returnSize, returnColumnSizes);
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), cmp);

    *returnSize = 0;

    int **ans = (int **)malloc(200 * sizeof(int *));
    *returnColumnSizes = (int *)malloc(200 * sizeof(int));

    int path[100];

    dfs(candidates, candidatesSize, 0, target,
        path, 0,
        &ans, returnSize, returnColumnSizes);

    return ans;
}