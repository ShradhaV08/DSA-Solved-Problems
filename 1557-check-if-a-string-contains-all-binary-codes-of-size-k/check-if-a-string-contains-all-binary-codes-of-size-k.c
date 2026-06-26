#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool hasAllCodes(char* s, int k) {
    int n = strlen(s);

    if (n < k)
        return false;

    int total = 1 << k;
    bool *seen = (bool *)calloc(total, sizeof(bool));

    int mask = total - 1;
    int hash = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        hash = ((hash << 1) & mask) | (s[i] - '0');

        if (i >= k - 1) {
            if (!seen[hash]) {
                seen[hash] = true;
                count++;

                if (count == total) {
                    free(seen);
                    return true;
                }
            }
        }
    }

    free(seen);
    return false;
}