#include <stdlib.h>
#include <string.h>

char*** result;
int returnSize;
int* returnColumnSizes;

void backtrack(int row, int n, char** board,
               int* cols, int* diag1, int* diag2) {

    if (row == n) {
        result[returnSize] = (char**)malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            result[returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
            strcpy(result[returnSize][i], board[i]);
        }

        returnColumnSizes[returnSize] = n;
        returnSize++;
        return;
    }

    for (int col = 0; col < n; col++) {
        int d1 = row - col + n - 1;
        int d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2])
            continue;

        board[row][col] = 'Q';
        cols[col] = diag1[d1] = diag2[d2] = 1;

        backtrack(row + 1, n, board, cols, diag1, diag2);

        board[row][col] = '.';
        cols[col] = diag1[d1] = diag2[d2] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize_, int** returnColumnSizes_) {
    result = (char***)malloc(400 * sizeof(char**));
    returnColumnSizes = (int*)malloc(400 * sizeof(int));
    returnSize = 0;

    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
        board[i][n] = '\0';
    }

    int* cols = (int*)calloc(n, sizeof(int));
    int* diag1 = (int*)calloc(2 * n - 1, sizeof(int));
    int* diag2 = (int*)calloc(2 * n - 1, sizeof(int));

    backtrack(0, n, board, cols, diag1, diag2);

    *returnSize_ = returnSize;
    *returnColumnSizes_ = returnColumnSizes;

    return result;
}