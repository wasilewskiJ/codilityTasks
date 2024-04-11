// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct disc {
    int left;
    int right;
};

void initializeDiscs(struct disc discs[], int N, int A[]) {
    for (int i = 0; i < N; i++) {
        discs[i].left = i - A[i];
        discs[i].right = i + A[i];
    }
}

void merge(struct disc *discs, int start, int middle, int end);

void printDiscsArray(struct disc * discs, int N);

void printDiscsArrayPoints(struct disc * discs, int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("element: %d\n", discs[i].left);
    }
}
void mergeSort(struct disc discs[], int start, int end) {
    //printf("wchodzi array do mergesort:\n");
    //printDiscsArrayPoints(discs, start,end);
    if(start >= end)
        return;
    
    int middle = start + (end - start) / 2;
    mergeSort(discs, start, middle);
    //printf("jade prawa: half: %d\n", half);
    //printf("N-1: %d\n", N-1);
    //printf("N: %d\n", N);
    mergeSort(discs, middle+1, end);
    merge(discs, start, middle, end);

}

void merge(struct disc *discs, int start, int middle, int end) {
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    printf("PRZED SORTOWANIEM: \n");
    struct disc leftDiscs[leftSize];
    struct disc rightDiscs[rightSize];
    printDiscsArrayPoints(discs, start, end);
    memcpy(leftDiscs, discs + start, leftSize * sizeof(struct disc));
    memcpy(rightDiscs, discs + middle + 1, rightSize * sizeof(struct disc));
    int l = 0, r = 0, a = start;
    while(l < leftSize && r < rightSize) {
        if(leftDiscs[l].left > rightDiscs[r].left) {
            discs[a++] = rightDiscs[r++];
        } else {
            discs[a++] = leftDiscs[l++];
        }
    }

    if (l < leftSize) {
        memcpy(discs+a, leftDiscs+l, sizeof(struct disc) * (leftSize - l));
    }


    if (r < rightSize) {
        memcpy(discs+a, rightDiscs+r, sizeof(struct disc) * (rightSize - r));
    }

    printf("PO SORTOWANIU: \n");
    printDiscsArrayPoints(discs, start, end);
    //printf("pierwsze czytanie\n");
    //printDiscsArray(discs, N);
}

void printDiscsArray(struct disc * discs, int N) {
    for(int i = 0; i < N; i++) {
        printf("left of disc: %d\n", discs[i].left);
    }
}

int solution(int A[], int N) {
    struct disc discs[4] ={{4, 2}, {3, 2}, {2,2}, {1,2}};
    mergeSort(discs, 0, 3);
    printDiscsArray(discs, 3);
    return 0;
}

int main() {
    struct disc discs[4] = {{4, 2}, {3, 2}, {2,2}, {1,2}};
    mergeSort(discs, 0,3);
    printDiscsArray(discs, 4);
    return 0;
}