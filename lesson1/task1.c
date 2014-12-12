// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99
    int i, j;
    int min = 9999;
    int minuend[N-1];
    int subtrahend[N-1];
    int temp = 0;
    
    minuend[0] = A[0];    
    for(i = 1; i < N - 1; i++) {
        minuend[i] = minuend[i-1] + A[i];
    }

    subtrahend[N-2] = A[N-1];
    for(i = N - 2; i > 0; i--) {
        subtrahend[i-1] = subtrahend[i] + A[i];
    }
    
    for(i = 0;i < N - 1; i++) {
        temp = abs(minuend[i] - subtrahend[i]);
        if(temp < min) {
            min = temp;   
        }
    }
    
    return min;  
}
