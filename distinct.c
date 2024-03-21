#include <stdlib.h>

//hashMap
struct {
    int key;
    int value;
} hashMap[2000001];

int hash(int key) {
    return key + 1000000;
}

void insert(int key) {
    int index = hash(key);
    hashMap[index].key = key;
    hashMap[index].value++;
}

int exists(int key) {
    int index = hash(key);
    return hashMap[index].value;
}

int fillHashMap() {
    for (int i = 0; i < 2000001; i++) {
        hashMap[i].key = 0;
        hashMap[i].value = 0;
    }
}

int solution(int A[], int N) {
    int distinct = 0;
    fillHashMap();
    for (int i = 0; i < N; i++) {
        if (!exists(A[i])) {
            insert(A[i]);
            distinct++;
        }
    }
    return distinct;
}