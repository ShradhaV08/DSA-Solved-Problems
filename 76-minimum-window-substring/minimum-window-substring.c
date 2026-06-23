char* minWindow(char* s, char* t) {
    int need[128] = {0};
    int required = strlen(t);

    for (int i = 0; t[i]; i++)
        need[(unsigned char)t[i]]++;

    int left = 0, start = 0;
    int minLen = INT_MAX;

    for (int right = 0; s[right]; right++) {
        if (need[(unsigned char)s[right]] > 0)
            required--;

        need[(unsigned char)s[right]]--;

        while (required == 0) {
            int len = right - left + 1;

            if (len < minLen) {
                minLen = len;
                start = left;
            }

            need[(unsigned char)s[left]]++;

            if (need[(unsigned char)s[left]] > 0)
                required++;

            left++;
        }
    }

    if (minLen == INT_MAX) {
        char *res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    char *res = (char*)malloc(minLen + 1);
    strncpy(res, s + start, minLen);
    res[minLen] = '\0';

    return res;
}