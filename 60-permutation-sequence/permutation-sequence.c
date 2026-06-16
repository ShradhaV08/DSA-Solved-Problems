#include <stdlib.h>
#include <stdio.h>

char* getPermutation(int n, int k) {
    int factorial[10];
    factorial[0] = 1;

    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i;

    int used[10] = {0};
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';

    k--;  // convert to 0-based index

    for (int pos = 0; pos < n; pos++) {
        int blockSize = factorial[n - pos - 1];
        int index = k / blockSize;
        k %= blockSize;

        int count = 0;

        for (int num = 1; num <= n; num++) {
            if (!used[num]) {
                if (count == index) {
                    result[pos] = num + '0';
                    used[num] = 1;
                    break;
                }
                count++;
            }
        }
    }

    return result;
}