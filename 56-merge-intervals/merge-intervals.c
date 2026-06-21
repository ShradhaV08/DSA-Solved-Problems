#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
             int* returnSize, int** returnColumnSizes) {

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    result[0] = (int *)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {

        if (intervals[i][0] <= result[idx][1]) {

            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        }
        else {
            idx++;

            result[idx] = (int *)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;

    return result;
}