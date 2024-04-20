#include <stdlib.h>
#include <stdio.h>


int isPrime(int a) {
    if (a == 1 || a % 2 == 0)
        return 0;
    
    for (int i = 3; i * i < a; i++) {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

void checkPrime(int* A, int N) {
    for (int i= 0; i < N; i++ ) {
        if(isPrime(A[i]))
            printf("%d is prime\n", A[i]);
        else
            printf("%d is NOT prime\n", A[i]);

    }
}

int main () {
    int A[5] = {49, 7, 18, 47, 15};
    checkPrime(A, 5); 
    return 0;
}

