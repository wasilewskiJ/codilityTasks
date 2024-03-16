/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
*/
#include <stdio.h>
#include <stdlib.h>

struct Results {
    int * A;
};

void printSequence(const char* S, const int P[], const int Q[], int index) {

    int startIndex = P[index];
    int endIndex = Q[index];

    printf("SEQUNCE: ");
    for (int index = startIndex; index <= endIndex; index++)
        printf("%c", S[index]);
    printf("\n");
    
    return;
}

int getStrLen( char * s) {

    int i = 0, length = 0;
    while (s[i] != '\0') { 
        length++;
        i++;
    }
    return length;
}

void calculatePrefixSums(int A[],int C[], int G[], int T[], char * S, int strLen) {
    for (int i = 0; i < strLen - 1; i++) {
        char ch = S[i];
        A[i + 1] = A[i];
        C[i + 1] = C[i];
        G[i + 1] = G[i];
        T[i + 1] = T[i];

        switch(ch) {
            case 'A':
                A[i + 1]++;
                break;
            case 'C':
                C[i + 1]++;
                break;
            case 'G':
                G[i + 1]++;
                break;
            case 'T':
                T[i + 1]++;
                break;
        }
    }
}

void printIntArray(int A[], int N) {

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int findMin(int startIndex, int endIndex, int A[], int C[], int G[], int T[]) {
    
    endIndex += 1; //due to nature of prefix sum arrays

    if (A[startIndex] != A[endIndex])
        return 1;
    else if (C[startIndex] != C[endIndex])
        return 2;
    else if (G[startIndex] != G[endIndex])
        return 3;
    else
        return 4;
}

struct Results solution (char *S, int P[], int Q[], int M) {

    struct Results result;
    result.A = malloc(sizeof(int) * M);
    int strLen = getStrLen(S) + 1;

    //arrays for prefix sums
    int * A = calloc(strLen, sizeof(int));
    int * C = calloc(strLen, sizeof(int));
    int * G = calloc(strLen, sizeof(int));
    int * T = calloc(strLen, sizeof(int));
    calculatePrefixSums(A,C,G,T, S, strLen);


    for (int i = 0; i < M; i++) {

        printSequence(S, P, Q, i);
        int min = findMin(P[i], Q[i], A, C, G, T);
        result.A[i] = min;

    }
    free(A);
    free(C);
    free(G);
    free(T);
    return result;
}


int main() {

    char S[] = "AC";
    int P[] = {0,0, 1};
    int Q[] = {0, 1, 1};
    int M = 3;
    struct Results result = solution(S,P,Q,M);
    printf("SOLUTION: ");

    for (int i = 0; i < M; i++) {
        printf("%d ", result.A[i]);
    }


    free(result.A);
    return 0;
}

