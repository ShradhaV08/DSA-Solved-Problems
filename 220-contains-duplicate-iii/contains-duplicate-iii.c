#include <stdlib.h>

long getBucketId(long num, long width) {
    if (num >= 0)
        return num / width;
    return ((num + 1) / width) - 1;
}

typedef struct Bucket {
    long id;
    long value;
    struct Bucket *next;
} Bucket;

#define SIZE 200003

Bucket* table[SIZE];

int hash(long id) {
    long h = id % SIZE;
    if (h < 0) h += SIZE;
    return h;
}

Bucket* findBucket(long id) {
    Bucket *cur = table[hash(id)];
    while (cur) {
        if (cur->id == id)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void insertBucket(long id, long value) {
    int h = hash(id);

    Bucket *node = (Bucket*)malloc(sizeof(Bucket));
    node->id = id;
    node->value = value;
    node->next = table[h];
    table[h] = node;
}

void removeBucket(long id) {
    int h = hash(id);

    Bucket *cur = table[h], *prev = NULL;

    while (cur) {
        if (cur->id == id) {
            if (prev)
                prev->next = cur->next;
            else
                table[h] = cur->next;

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize,
                                   int indexDiff, int valueDiff) {

    if (valueDiff < 0)
        return false;

    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    long width = (long)valueDiff + 1;

    for (int i = 0; i < numsSize; i++) {

        long num = nums[i];
        long bucket = getBucketId(num, width);

        if (findBucket(bucket))
            return true;

        Bucket *left = findBucket(bucket - 1);
        if (left && labs(num - left->value) <= valueDiff)
            return true;

        Bucket *right = findBucket(bucket + 1);
        if (right && labs(num - right->value) <= valueDiff)
            return true;

        insertBucket(bucket, num);

        if (i >= indexDiff) {
            long oldBucket = getBucketId(nums[i - indexDiff], width);
            removeBucket(oldBucket);
        }
    }

    return false;
}