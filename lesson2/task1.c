/*
 * PermCheck
 * Check whether array A is a permutation.
 * */

int solution(int A[], int N) {
    int sum = 0;
    int i;
    
    for(i = 0; i < N; i++) {
        sum = sum ^ (i + 1) ^ A[i];
    }
    
    if(sum == 0) {
        return 1;
    }
    
    return 0;
}
