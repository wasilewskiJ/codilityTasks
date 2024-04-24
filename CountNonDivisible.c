#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Results {
    int *C;
    int L;
};

struct Results solution(int A[], int N) {
    struct Results result;
    result.C = (int *)calloc(N, sizeof(int));
    result.L = N;
    int max_val = 0;

    // Find max value to limit the range of the sieve
    for (int i = 0; i < N; i++) {
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int *freq = (int *)calloc(max_val + 1, sizeof(int));
    
    // Frequency map
    for (int i = 0; i < N; i++) {
        freq[A[i]]++;
    }
    
    int *divisorCount = (int *)calloc(max_val + 1, sizeof(int));
    
    // Calculate number of times each number is a divisor
    for (int i = 1; i <= max_val; i++) {
        if (freq[i] > 0) {
            for (int j = i; j <= max_val; j += i) {
                divisorCount[j] += freq[i];
            }
        }
    }
    
    // Calculate non-divisors count for each element in A
    for (int i = 0; i < N; i++) {
        result.C[i] = N - divisorCount[A[i]];
    }

    free(freq);
    free(divisorCount);
    return result;
}

int main() {
    int A[] = {3, 1, 2, 3, 6};
    struct Results result = solution(A, 5);
    for (int i = 0; i < result.L; i++) {
        printf("%d ", result.C[i]);
    }
    printf("\n");
    free(result.C);
    return 0;
}
