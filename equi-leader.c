
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
    int count = 0, candidate = A[index], half = N / 2;
    int counts[N];  // This will store cumulative counts of the candidate up to each index.
    int leaders = 0;

    // Fill cumulative count array
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate)
            count++;
        counts[i] = count;
    }

    // Ensure the candidate is a leader in the entire array
    if (count <= half)
        return 0;

    // Check for equi leaders
    for (int i = 0; i < N - 1; i++) {
        int leftCount = counts[i];
        int rightCount = count - counts[i];
        int leftSize = i + 1;
        int rightSize = N - i - 1;

        if (leftCount > leftSize / 2 && rightCount > rightSize / 2)
            leaders++;
    }

    return leaders;
}



int solution(int A[], int N) {
    int candidateIndex = findCandidate(A, N);
    if (candidateIndex == -1)
        return 0;
    else
        return testCandidate(candidateIndex, A, N);
}