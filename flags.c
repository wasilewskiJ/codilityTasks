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

int getNumOfFlags(Flags* flags, int* A, int N) {
    if (flags->size == 1)
        return 1;
    
    int i = flags->size > (int) sqrt((N)) + 1 ? (int) sqrt((N)) + 1 : flags->size;
    //printf("i is equal to: %d\n", i);
    int max = 0;
    for(; i >= 1; i--) {
        int current = 1;
        int lastF = 0;
        for(int j = 1; j < flags->size; j++) {
            if (flags->flagsIndexes[j] - flags->flagsIndexes[lastF] >= i) {
                current++;
                lastF = j;
            }
            if (current == i)
                break;
        }
        if (max > current)
            return max;
        else
            max = current;
    }  
    return max;
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
    int result = getNumOfFlags(flags, A, N);
    freeFlags(flags);
    return result;
}