#include <stdlib.h>

typedef struct {
    int x;
    int h;
} Event;

typedef struct {
    int *data;
    int size;
} MaxHeap;

int cmp(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->x != e2->x)
        return e1->x - e2->x;

    return e1->h - e2->h;
}

void heapPush(MaxHeap *heap, int val) {
    int i = heap->size++;
    heap->data[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap->data[p] >= heap->data[i])
            break;

        int temp = heap->data[p];
        heap->data[p] = heap->data[i];
        heap->data[i] = temp;

        i = p;
    }
}

void heapPop(MaxHeap *heap) {
    if (heap->size == 0)
        return;

    heap->data[0] = heap->data[--heap->size];

    int i = 0;

    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size && heap->data[left] > heap->data[largest])
            largest = left;

        if (right < heap->size && heap->data[right] > heap->data[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;

        i = largest;
    }
}

int heapTop(MaxHeap *heap) {
    return heap->size ? heap->data[0] : 0;
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize,
                 int* returnSize, int** returnColumnSizes) {

    Event *events = malloc(2 * buildingsSize * sizeof(Event));

    int idx = 0;

    for (int i = 0; i < buildingsSize; i++) {
        events[idx++] = (Event){buildings[i][0], -buildings[i][2]};
        events[idx++] = (Event){buildings[i][1], buildings[i][2]};
    }

    qsort(events, idx, sizeof(Event), cmp);

    int capacity = 2 * buildingsSize;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    MaxHeap heap;
    heap.data = malloc(2 * buildingsSize * sizeof(int));
    heap.size = 0;

    heapPush(&heap, 0);

    int prev = 0;
    *returnSize = 0;

    for (int i = 0; i < idx; i++) {

        if (events[i].h < 0) {
            heapPush(&heap, -events[i].h);
        } else {

            int target = events[i].h;

            for (int j = 0; j < heap.size; j++) {
                if (heap.data[j] == target) {
                    heap.data[j] = heap.data[heap.size - 1];
                    heap.size--;
                    break;
                }
            }

            for (int j = heap.size / 2; j >= 0; j--) {
                int cur = j;

                while (1) {
                    int largest = cur;
                    int left = 2 * cur + 1;
                    int right = 2 * cur + 2;

                    if (left < heap.size && heap.data[left] > heap.data[largest])
                        largest = left;

                    if (right < heap.size && heap.data[right] > heap.data[largest])
                        largest = right;

                    if (largest == cur)
                        break;

                    int temp = heap.data[cur];
                    heap.data[cur] = heap.data[largest];
                    heap.data[largest] = temp;

                    cur = largest;
                }
            }
        }

        int curr = heapTop(&heap);

        if (curr != prev) {
            result[*returnSize] = malloc(2 * sizeof(int));
            result[*returnSize][0] = events[i].x;
            result[*returnSize][1] = curr;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;

            prev = curr;
        }
    }

    return result;
}