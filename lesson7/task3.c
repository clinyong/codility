/*
 * Name: MaxDoubleSliceSum
 * Description: Find the maximal sum of any double slice.
 * Link: https://codility.com/demo/take-sample-test/max_double_slice_sum
 * Hint: If the array elements are all negative, the function should return 0
 * */

int max(int a, int b)
{
    if(a > b) {
        return a;    
    }
    
    return b;
}

int solution(int A[], int N) {
    int max_ending[N], max_beginning[N];
    int i, temp, max_double_slice;
    
    for(i = 0; i < N; i++) {
        max_ending[i] = 0;
        max_beginning[i] = 0;
    }
    
    /*
    * We should travel the array twice. 
    */
    
    temp = 0;
    for(i = 1; i < N-1; i++) {
        temp = max(0, temp+A[i]);
        max_ending[i] = temp;
    }
    
    temp = 0;
    for(i = N-2; i > 0; i--) {
        temp = max(0, temp+A[i]);
        max_beginning[i] = temp;
    }
    
    /*
    * If the first subarray ends at position i, the second subarray starts at position i+2.
    */
    max_double_slice = 0;
    for(i = 0; i < N-2; i++) {
        max_double_slice = max(max_double_slice, max_ending[i] + max_beginning[i+2]);
    }
    
    return max_double_slice;
}
