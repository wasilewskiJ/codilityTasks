// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdlib.h>

int * findMaxThree(int A[], int N) {
    int * maxThree = malloc(3 * sizeof(int));
    maxThree[0] = -1000;
    maxThree[1] = -1000;
    maxThree[2] = -1000;
    for (int i = 0; i < N; i++) {
        if (A[i] > maxThree[0]) {
            maxThree[2] = maxThree[1];
            maxThree[1] = maxThree[0];
            maxThree[0] = A[i];
        } else if (A[i] > maxThree[1]) {
            maxThree[2] = maxThree[1];
            maxThree[1] = A[i];
        } else if (A[i] > maxThree[2]) {
            maxThree[2] = A[i];
        }
    }
    return maxThree;
}

int * findMinTwo(int A[], int N) {
    int *minTwo = malloc(2 * sizeof(int));
    minTwo[0] = 1000;
    minTwo[1] = 1000;
    for (int i = 0; i < N; i++) {
        if(A[i] < minTwo[0]) {
            minTwo[1] = minTwo[0];
            minTwo[0] = A[i];
        } else if (A[i] < minTwo[1]) {
            minTwo[1] = A[i];
        }
    }
    return minTwo;
}

int biggerProduct(int maxThree[], int minTwo[]) {
    int product1 = maxThree[0] * maxThree[1] * maxThree[2];
    int product2 = maxThree[0] * minTwo[0] * minTwo[1];
    return product1 > product2 ? product1 : product2;
}

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int solution(int A[], int N) {
    int *maxThree = findMaxThree(A, N);
    int *minTwo = findMinTwo(A, N);
    int result = biggerProduct(maxThree, minTwo);
    free(maxThree);
    free(minTwo);
    return result;
}

int main() {
    int A[] = {-3, 1, 2, -2, 5, 6};
    int N = 6;
    printf("%d\n", solution(A, N));
    return 0;
}