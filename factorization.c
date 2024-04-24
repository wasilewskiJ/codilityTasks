#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int* primeArray;
    int size;
} FactorsArray;

int* arrayF(int N) {
    int* A = calloc(N+1, sizeof(int));
    int i = 2;
    while (i * i <= N) {
        if (A[i] == 0) {
            int k = i * i;
            while (k <= N) {
                if (A[k] == 0)
                    A[k] = i;
                k += i;
            }
        }
        i++;
    }
    return A;
}

FactorsArray* primeNumbers(int* array, int N) {
    int* primeArray = malloc(sizeof(int) * (int) sqrt(N));
    int counts = 0;
    while (array[N] > 0) {
        primeArray[counts++] = array[N];
        N /= array[N];
    }
    primeArray[counts++] = N;
    primeArray = realloc(primeArray, counts * sizeof(int));
    FactorsArray* factorsArray = malloc(sizeof(FactorsArray));
    factorsArray->primeArray = primeArray;
    factorsArray->size = counts;
    return factorsArray;
}

FactorsArray* factorization(int N) {
    int* array = arrayF(N);
    FactorsArray* primeArray = primeNumbers(array, N);
    free(array);
    return primeArray;
}

void printArray(int* A, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int N = 105;
    FactorsArray* A = factorization(N);
    printArray(A->primeArray, A->size);
    free(A->primeArray);
    free(A);
    return 0;
}