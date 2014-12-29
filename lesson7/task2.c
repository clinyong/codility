/*
 * Nmae: MaxSliceSum
 * Description: Find a maximum sum of a compact subsequence of array elements.
 * Link: https://codility.com/demo/take-sample-test/max_slice_sum
 * */


int max(int a, int b)
{
    if(a > b) {
        return a;    
    }    
    
    return b;
}

int solution(int A[], int N) {
    int i;
    int max_ending, max_slice;
         
    max_ending = max_slice = A[0];
    for(i = 1; i < N; i++) {
        max_ending = max(A[i], max_ending+A[i]);
        max_slice = max(max_ending, max_slice);
    }
    
    return max_slice;
}
