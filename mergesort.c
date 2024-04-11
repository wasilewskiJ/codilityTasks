#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int N);

void merge(int leftArray[], int rightArray[], int array[], int N) {
    int leftSize = N / 2;
    int rightSize = N - leftSize;
    int i = 0; //iterator that will ensure checking all of elements. sort till (i < rightSize)
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
    return;
}

void mergeSort(int array[], int N) {
    if (N <= 1)
        return;

    //first stage - split into two arrays
    int middle = N / 2;
    int * leftArray = malloc(sizeof(int) * middle);
    int * rightArray = malloc(sizeof(int) * N-middle);

    for(int i = 0; i+middle-1 < N; i++) {
        leftArray[i] = array[i];
        rightArray[i] = array[i+middle];
    }

    if (N % 2 != 0) {
        rightArray[middle] = array[N-1];
    }

    mergeSort(leftArray, middle);
    mergeSort(rightArray, N-middle);
    merge(leftArray, rightArray, array, N);
}

void printArray(int array[], int N) {
    for(int i = 0; i < N; i++) {
        printf("%d", array[i]);
    }
}

int main() {
    int a[8] = {3,7,8,5,4,2,6,1};
    mergeSort(a, 8);
    printArray(a, 8);
}