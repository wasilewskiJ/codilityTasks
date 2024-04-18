

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int dividers(int N) {
    int count = 0;
    int i;
    for (i = 1; (long) i * i < N; i++)
        if (N % i == 0)
            count += 2;
    if ((long) i * i == N)
        count++;
    return count;
}

int solution(int N) {
    return dividers(N);

}

