int findCandidate(int* A, int N) {
    int top = 0, index = 0, value = 0;
    for (int i = 0; i < N; i++) {
        if (top == 0) {
            value = A[i];
            index = i;
            top++;
        } else {
            if (value != A[i])
                top--;
            else
                top++;
        }
    }
    if (top > 0)
        return index;
    else
        return -1;
}

int testCandidate(int index, int* A, int N) {
    int count = 0, candidate = A[index], half = N/2;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate)
            count++;
        if (count > half)
            return 1;
    }
    return -1;
}

int solution(int A[], int N) {
    int candidateIndex = findCandidate(A, N);
    if (candidateIndex == -1)
        return -1;
    else
        if(testCandidate(candidateIndex, A, N) == 1)
            return candidateIndex;
        else
            return -1;
}