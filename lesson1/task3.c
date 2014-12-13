/*
 * PermMissingElem
 * Find the missing element in a given permutation.
 * */

int solution1(int A[], int N) {
    long sum = N+1;
    int i;
    
    for(i = 0; i < N; i++) {
        sum = sum + (i + 1) - A[i];
    }
    
    return sum;
}

int solution2(int A[], int N) {
    int sum = N+1;
    int i;
    
    for(i = 0; i < N; i++) {
		// XOR never lead to overflow
        sum = sum ^ (i + 1) ^ A[i];
    }
    
    return sum;
}
