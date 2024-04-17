// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
inline int max(int a, int b) {return a > b ? a : b; }

int maxSlice(int* A, int N) {
    int max_ending = 0, max_slice = -2147483648;
    for (int i = 0; i < N; i++) {
        max_ending = max(A[i], max_ending + A[i]);
        max_slice = max(max_ending, max_slice);
    }
    return max_slice;
}
int solution(int A[], int N) {
    return maxSlice(A, N);
}