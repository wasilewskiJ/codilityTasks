

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Flags {
    int* flags;
    int size;
};

void freeFlags(struct Flags* flags) {
    free(flags->flags);
    free(flags);
}

struct Flags* flags(int* A, int N) {
    int* indexes = malloc(sizeof(int) * N);
    int counts = 0;
    for (int i = 1; i < N-1; i++) {
        if (A[i-1] < A[i] && A[i] > A[i+1]) {
            indexes[counts] = i;
            counts++;
        } 
    }
    struct Flags* flags = malloc(sizeof(struct Flags));
    indexes = realloc(indexes, sizeof(int) * counts);
    flags->flags = indexes;
    flags->size = counts;
    return flags;
}



void printArray(int*A, int N) {
    for (int i = 0; i < N; i++) {
        printf("element [%d]: %d\n", i+1, A[i]);
    }
}

int max(int* A, int N) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

int findMax(struct Flags* flags, int* A, int N) {
    if (N < 3 || flags->size == 0)
        return 0;
    if (flags->size == 1)
        return 1;

    int maxFlagCount = (int) sqrt(flags->flags[flags->size - 1] - flags->flags[0]) + 1;
    maxFlagCount = maxFlagCount < flags->size ? maxFlagCount : flags->size;
    int m = 0;

    for (int i = maxFlagCount; i >= 1; i--) {
        int lastF = 0;
        int c = 1;
        for (int j = 1; j < flags->size && c < i; j++) {
            if (flags->flags[j] - flags->flags[lastF] >= i) {
                c++;
                lastF = j;
            }
        }
        m = c > m ? c : m;
        if (m == i) break; // If you've placed `i` flags, that's the maximum for this `i`
    }
    return m;
}


int solution(int* A, int N) {
    struct Flags* flag = flags(A, N);
    int result = findMax(flag, A, N);
    freeFlags(flag);
    return result;
}

