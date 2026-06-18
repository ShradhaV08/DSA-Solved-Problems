#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* nums, int numsSize, int* used, int* curr, int depth,
               int*** result, int* returnSize) {

    if (depth == numsSize) {
        (*result)[*returnSize] = (int*)malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++)
            (*result)[*returnSize][i] = curr[i];

        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {

        if (used[i])
            continue;

        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        curr[depth] = nums[i];

        backtrack(nums, numsSize, used, curr, depth + 1,
                  result, returnSize);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 50000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    int* used = (int*)calloc(numsSize, sizeof(int));
    int* curr = (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    backtrack(nums, numsSize, used, curr, 0,
              &result, returnSize);

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(used);
    free(curr);

    return result;
}