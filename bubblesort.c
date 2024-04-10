#include <stdlib.h>
#include <stdio.h>


void bubbleSort(int A[], int N) {
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if(A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main() {
    int A[] = {3, 2, 1, 5, 4};
    bubbleSort(A, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
}