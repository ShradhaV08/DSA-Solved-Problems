/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 */

void dfs(int* candidates, int candidatesSize, int index, int target,
         int* path, int pathSize,
         int*** ans, int* returnSize, int** returnColumnSizes) {

    if (target == 0) {
        (*ans)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
        memcpy((*ans)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    if (index == candidatesSize || target < 0)
        return;

    // Take current candidate
    path[pathSize] = candidates[index];
    dfs(candidates, candidatesSize, index,
        target - candidates[index],
        path, pathSize + 1,
        ans, returnSize, returnColumnSizes);

    // Skip current candidate
    dfs(candidates, candidatesSize, index + 1,
        target,
        path, pathSize,
        ans, returnSize, returnColumnSizes);
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    int **ans = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));

    int path[40];

    dfs(candidates, candidatesSize, 0, target,
        path, 0,
        &ans, returnSize, returnColumnSizes);

    return ans;
}