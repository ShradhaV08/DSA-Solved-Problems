#include <stdlib.h>

typedef struct {
    int maxHeap[50001], maxSize; // lower half
    int minHeap[50001], minSize; // upper half
} MedianFinder;

void maxHeapPush(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p] >= heap[i])
            break;

        int temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;

        i = p;
    }
}

int maxHeapPop(int heap[], int *size) {
    int res = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < *size && heap[left] > heap[largest])
            largest = left;

        if (right < *size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }

    return res;
}

void minHeapPush(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p] <= heap[i])
            break;

        int temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;

        i = p;
    }
}

int minHeapPop(int heap[], int *size) {
    int res = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return res;
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if (obj->maxSize == 0 || num <= obj->maxHeap[0])
        maxHeapPush(obj->maxHeap, &obj->maxSize, num);
    else
        minHeapPush(obj->minHeap, &obj->minSize, num);

    // Balance heaps
    if (obj->maxSize > obj->minSize + 1) {
        int x = maxHeapPop(obj->maxHeap, &obj->maxSize);
        minHeapPush(obj->minHeap, &obj->minSize, x);
    }

    if (obj->minSize > obj->maxSize) {
        int x = minHeapPop(obj->minHeap, &obj->minSize);
        maxHeapPush(obj->maxHeap, &obj->maxSize, x);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {

    if (obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return ((double)obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}