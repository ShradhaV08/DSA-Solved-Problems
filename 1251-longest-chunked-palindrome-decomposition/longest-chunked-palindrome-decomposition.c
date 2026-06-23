int longestDecomposition(char* text) {
    int n = strlen(text);
    int i = 0, j = n - 1;
    int ans = 0;

    while (i <= j) {
        int len = 1;

        while (i + len - 1 < j - len + 1) {
            if (strncmp(text + i, text + j - len + 1, len) == 0)
                break;
            len++;
        }

        if (i + len - 1 >= j - len + 1) {
            ans += 1;
            break;
        }

        ans += 2;
        i += len;
        j -= len;
    }

    return ans;
}