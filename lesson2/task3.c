/*
 * MissingInteger
 * Find the minimal positive integer not occurring in a given sequence.
 * Link: https://codility.com/c/intro/demoJKTRJT-MBG
 * Hint: There are N integers in the input. So for the
 *       first N+1 positive integers, at least one of 
 *       them must be missing.
 **/

int solution(int A[], int N) {
    int i, j;
    int B[N+1];
    
    for(i = 0; i < N+1; i++) {
        B[i] = 0;    
    }
    
    for(i = 0; i < N; i++) {
        if(A[i] > 0 && A[i] <= N+1) {
            j = A[i] - 1;
            B[j] = 1;
        }    
    }
    
    for(i = 0; i< N+1; i++) {
        if(B[i] == 0) {
            return i + 1;    
        }    
    }
    
    return -1;
    
}
