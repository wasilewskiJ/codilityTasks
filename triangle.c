#include <stdlib.h>
#include <stdio.h>

void printArray(int array[], int N);

void merge(int leftArray[], int rightArray[], int array[], int N) {
    int leftSize = N / 2;
    int rightSize = N - leftSize;
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < leftSize && r < rightSize) {
        //left element bigger
        if(leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            l++; i++;
        }
        else {
            array[i] = rightArray[r];
            r++; i++;
        }
    }

    while(r < rightSize) {
        array[i] = rightArray[r];
        i++; r++;
    }

    while (l < leftSize) {
        array[i] = leftArray[l];
        i++; l++;
    }
    free(leftArray);
    free(rightArray);
    return;
}

void mergeSort(int array[], int N) {
    if(N <= 1)
        return;
    
    int leftSize = N / 2;
    int rightSize = N - leftSize;

    int * leftArray = malloc(sizeof(int) * leftSize);
    int * rightArray = malloc(sizeof(int) * rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[i];
        rightArray[i] = array[i+leftSize];
    }

    if (rightSize > leftSize) 
        rightArray[rightSize-1] = array[N-1];

    mergeSort(leftArray, leftSize);
    mergeSort(rightArray, rightSize);
    merge(leftArray, rightArray, array, N);
}

void printArray(int array[], int N) {
    for(int i = 0; i < N; i++) {
        printf("%d", array[i]);
    }
}

int solution(int A[], int N) {
    if (N < 3)
        return 0;
    mergeSort(A, N);
    for (int i = 0; i < N-2; i++) {
        if ((long long)A[i] + (long long)A[i+1] > (long long)A[i+2])
            return 1;
    }
    
    return 0;
}

int main() {
    const int N = 6;
    int A[4]= {10, 50, 1, 5};
    printf("%d", solution(A, 4));
}
