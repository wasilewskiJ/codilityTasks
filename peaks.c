#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int* flagsIndexes;
    int size;
} Flags;

void freeFlags(Flags* flags) {
    free(flags->flagsIndexes);
    free(flags);
}

Flags* getFlagsIndexes(int* A, int N) {
    int* flagsIndexes = malloc(sizeof(int) * N-2);
    int counts = 0;
    for (int i = 1; i < N-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            flagsIndexes[counts] = i;
            counts++;
        }
    }
    flagsIndexes = realloc(flagsIndexes, counts * sizeof(int));
    Flags* flags = malloc(sizeof(Flags));
    flags->flagsIndexes = flagsIndexes;
    flags->size = counts;
    return flags;
}

int getNumOfBlocks(Flags* flags, int* A, int N) {
    if (flags->size == 1)
        return 1;
    
    for(int i = flags->size; i >= 1; i--) {
        if (N % i != 0)
            continue;
        
        int blockSize = N / i;
        int startIndex = 0;
        int stopIndex = startIndex + blockSize - 1;
        
        for(int j = 0; j < flags->size; j++) {
            if (flags->flagsIndexes[j] >= startIndex && flags->flagsIndexes[j] <= stopIndex) {
                startIndex += blockSize;
                stopIndex = startIndex + blockSize - 1;
            }
        }

        if (stopIndex >= N)
            return i;
        //print current i and stopIndex
        printf("I: %d STOPINDEX: %d BLOCKSIZE: %d\n", i, stopIndex, blockSize); 
    }
    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int solution(int A[], int N) {
    if (N < 3)
        return 0;
    
    Flags* flags = getFlagsIndexes(A, N);
    //printArray(flags->flagsIndexes, flags->size);
    int result = getNumOfBlocks(flags, A, N);
    freeFlags(flags);
    return result;
}


int main() {
    int A[] = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    int N = 12;
    printf("%d\n", solution(A, N));
    return 0;
}