char str[105][12];

int cmp(const void *a, const void *b) {
    char ab[25], ba[25];

    sprintf(ab, "%s%s", *(char **)a, *(char **)b);
    sprintf(ba, "%s%s", *(char **)b, *(char **)a);

    return strcmp(ba, ab);   // descending order
}

char* largestNumber(int* nums, int numsSize) {
    char *arr[105];

    for (int i = 0; i < numsSize; i++) {
        sprintf(str[i], "%d", nums[i]);
        arr[i] = str[i];
    }

    qsort(arr, numsSize, sizeof(char *), cmp);

    if (arr[0][0] == '0') {
        char *res = (char *)malloc(2);
        strcpy(res, "0");
        return res;
    }

    char *res = (char *)malloc(numsSize * 12 + 1);
    res[0] = '\0';

    for (int i = 0; i < numsSize; i++)
        strcat(res, arr[i]);

    return res;
}