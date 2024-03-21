// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdlib.h>

int * sum_duos(int A[], int N) {
    int pairs = N-1;
    int *sums = malloc(sizeof(int) * pairs);
    int j = 0;
    for (int i = 0; i < N-1; i++) {
        sums[j] = A[i] + A[i+1];
        j++;
    }
    return sums;
}

int * sum_three(int A[], int N) {
    int pairs = N-2;
    int *sums = malloc(sizeof(int) * pairs);
    int j = 0;
    for (int i = 0; i < N-2; i++) {
        sums[j] = A[i] + A[i+1] + A[i+2];
        j++;
    }
    return sums;
}

void print_array(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int findMinIndex(int A[], int N) {
    int min = A[0];
    int minIndex = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int compareAvg(int minDuoIndex, int minTrioIndex, int A[]) {
    double duoAvg = (A[minDuoIndex] + A[minDuoIndex+1]) / 2.0;
    double trioAvg = (A[minTrioIndex] + A[minTrioIndex+1] + A[minTrioIndex+2]) / 3.0;
    if (duoAvg < trioAvg) {
        return minDuoIndex;
    } else if (duoAvg > trioAvg) {
        return minTrioIndex;
    }
    else
        return min(minDuoIndex, minTrioIndex);
}

int solution(int A[], int N) {
    int *sumsDuo = sum_duos(A, N);
    int minDuoIndex = findMinIndex(sumsDuo, N-1);
    if (N > 2) {
        int *sumsThree = sum_three(A, N);
        int minTrioIndex = findMinIndex(sumsThree, N-2);
        //print_array(sumsThree, N-2);
        return compareAvg(minDuoIndex, minTrioIndex, A);
    } else {
        return minDuoIndex;
    }
}

int main() {
    int A[] = {4, 2, 2, 5, 1, 5, 8};
    int N = 7;
    printf("%d\n", solution(A, N));
    return 0;
}
