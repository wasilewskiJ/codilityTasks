// find the biggest maxSlice
// then eliminate smallest points from it's surrounding
#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) {return a > b ? a : b; }

int maxSlice(int* A, int N) {
    int LR[N];
    int RL[N];
    LR[N-1] = 0; LR[0] = 0;
    RL[N-1] = 0; RL[0] = 0;

    int leftSum = 0, rightSum = 0;
    for (int i = 1, j = N-2; i <= N-2; i++, j--) {
        leftSum += A[i];
        rightSum += A[j];
        if (leftSum < 0)
            leftSum = 0;
        if (rightSum < 0)
            rightSum = 0;
        
        LR[i] = leftSum;
        RL[j] = rightSum;
    }

    int m = 0;
    for (int i = 0; i < N-2; i++) {
        m = max(m, LR[i] + RL[i+2]);
    }

    return m;
}

int solution(int A[], int N) {
    if (N == 3)
        return 0;
    int result = maxSlice(A, N);
    return result;
}

int main() {
    int A[7] = {25, -50, 1, 1, 1, 1, 1}; 
    solution(A, 7);
}
