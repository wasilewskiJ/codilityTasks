#include <stdio.h>
#include "maxSlice.h"
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

inline int max(int a, int b) {return a > b ? a : b; }

int maxSlice(int* A, int N) {
    if (N < 2)
        return 0;
    int max_ending = 0, max_slice = 0;
    int start = N-1;
    for (int i = N-2; i >= 0; i--) {
        if (A[i] > A[start]) {
            start = i;
            continue;
        }
        max_ending = max(max_ending, A[start] - A[i]);
        max_slice = max(max_slice, max_ending);
    }
    return max_slice;
}


int solution(int A[], int N) {
    int result = maxSlice(A, N);
    return result;
}

