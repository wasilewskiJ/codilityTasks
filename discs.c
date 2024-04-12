// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct disc {
    long int left;
    long int right;
};

void initializeDiscs(struct disc discs[], int N, int A[]) {
    for (long int i = 0; i < N; i++) {
        discs[i].left = i - (long int) A[i];
        discs[i].right = i + (long int) A[i];
    }
}

void merge(struct disc *discs, int start, int middle, int end, bool sortByLeft);

void printDiscsArray(struct disc * discs, int N);

void printDiscsArrayPoints(struct disc * discs, int left, int right) {
    for (int i = left; i <= right; i++) {
        printf("element: %ld\n", discs[i].left);
    }
}
void mergeSort(struct disc discs[], int start, int end, bool sortByLeft) {
    //printf("wchodzi array do mergesort:\n");
    //printDiscsArrayPoints(discs, start,end);
    if(start >= end)
        return;
    
    int middle = start + (end - start) / 2;
    mergeSort(discs, start, middle, sortByLeft);
    //printf("jade prawa: half: %d\n", half);
    //printf("N-1: %d\n", N-1);
    //printf("N: %d\n", N);
    mergeSort(discs, middle+1, end, sortByLeft);
    merge(discs, start, middle, end, sortByLeft);

}

void merge(struct disc *discs, int start, int middle, int end, bool sortByLeft) {
    int leftSize = middle - start + 1;
    int rightSize = end - middle;
    //printf("PRZED SORTOWANIEM: \n");
    struct disc leftDiscs[leftSize];
    struct disc rightDiscs[rightSize];
    //printDiscsArrayPoints(discs, start, end);
    memcpy(leftDiscs, discs + start, leftSize * sizeof(struct disc));
    memcpy(rightDiscs, discs + middle + 1, rightSize * sizeof(struct disc));
    int l = 0, r = 0, a = start;
    while(l < leftSize && r < rightSize) {
        if(sortByLeft) {
            if(leftDiscs[l].left > rightDiscs[r].left) {
                discs[a++] = rightDiscs[r++];
            } else {
                discs[a++] = leftDiscs[l++];
            }
        }
        else {
            if(leftDiscs[l].right > rightDiscs[r].right) {
                discs[a++] = rightDiscs[r++];
            } else {
                discs[a++] = leftDiscs[l++];
            }
        }
    }

    if (l < leftSize) {
        memcpy(discs+a, leftDiscs+l, sizeof(struct disc) * (leftSize - l));
    }


    if (r < rightSize) {
        memcpy(discs+a, rightDiscs+r, sizeof(struct disc) * (rightSize - r));
    }

    //printf("PO SORTOWANIU: \n");
    //printDiscsArrayPoints(discs, start, end);
    //printf("pierwsze czytanie\n");
    //printDiscsArray(discs, N);
}

void printDiscsArray(struct disc * discs, int N) {
    for(int i = 0; i < N; i++) {
        printf("left of disc: %ld\n", discs[i].left);
    }
}

int binarySearchLeft(struct disc* discs, int N, long int right, int index) {
    int L = index;
    int R = N - 1;
    int result = -1; // Initialize to -1 to handle cases where no valid index is found

    while (L <= R) {
        int m = L + (R - L) / 2; // This prevents potential overflow

        if (discs[m].left <= right) {
            result = m; // This is a potential candidate, move right to find more
            L = m + 1;
        } else {
            R = m - 1;
        }
    }

    return result; // Will return -1 if no suitable index was found, otherwise the highest valid index
}

long int solution(int A[], int N) {
    struct disc discsLeft[N];
    struct disc discsRight[N];
    initializeDiscs(discsLeft, N, A);
    //memcpy(discsRight, discsLeft, sizeof(struct disc) * N);
    mergeSort(discsLeft, 0, N-1, true);
    //mergeSort(discsRight, 0, N-1, false);
    //printDiscsArray(discsLeft, N);
    long int total_pairs = 0;
    for (int i = 0; i < N; i++) {
        //printf("disc right: %ld\n", discsLeft[i].right);
        int index = binarySearchLeft(discsLeft, N, discsLeft[i].right, i);
        if (index != -1) {
            total_pairs += index - i;
            if (total_pairs > 10000000)
                return -1;
        }
    }
    return total_pairs;
}

int main() {
    int A[5] = {1,0,1,0,1};
    printf("%ld",solution(A, 5));
    return 0;
}