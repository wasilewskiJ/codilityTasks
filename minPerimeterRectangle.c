// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int minPerimeter(int N) {
    int perimeter = 2 * (N + 1);

    for (int i = 1; (long) i * i <= N; i++) {
        if (N % i == 0) {
            int temp = 2 * (N/i + i);
            if (temp < perimeter)
                perimeter = temp;
        }
    }
    return perimeter;
}

int solution(int N) {
    return minPerimeter(N);

}