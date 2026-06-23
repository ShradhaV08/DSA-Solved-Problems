typedef struct {
    int *map;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    obj->map = (int*)malloc(1000001 * sizeof(int));

    for (int i = 0; i <= 1000000; i++)
        obj->map[i] = -1;

    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->map[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->map[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->map[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->map);
    free(obj);
}