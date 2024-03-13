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

int getValue(char ch) {
    switch(ch) {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
    }
}

struct Results solution (char *S, int P[], int Q[], int M) {
    struct Results result;
    result.A = malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        printSequence(S, P, Q, i);
        //min is highest value in 1st iteration. we will search for smaller values.
        char min = 'T';

        for (int j = P[i]; j <= Q[i]; j++) {
            char nucleotid = S[j];
            if (nucleotid < min)
                min = nucleotid;
        }
    
        result.A[i] = getValue(min);
    }

    return result;
}


int main() {
    char S[] = "CAGCCTA";
    int P[] = {2, 5, 0};
    int Q[] = {4,5,6};
    int M = 3;
    struct Results result = solution(S,P,Q,M);
    for (int i = 0; i < M; i++) {
        printf("%d\n", result.A[i]);
    }
}

//pomysl jest, zeby zapisywac pod kolejnymi indeksami wzrost/spadek wzgledem poprzedniego elementu