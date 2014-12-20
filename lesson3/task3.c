/*
 * MinAvgTwoSlice
 * Find the minimal average of any slice containing at least two elements.
 * link: https://codility.com/demo/take-sample-test/min_avg_two_slice
 * Todo: Why length of two or three, having the minimal average value among all the slices. */

int solution(int A[], int N) {
    double min_sum = 9999.0;
    double temp;
    int start_pos = 0;
    int i;
    
    for(i = 0; i < N-2; i++) {
        temp = (A[i] + A[i+1]) / 2.0;
        if(temp < min_sum) {
            min_sum = temp;  
            start_pos = i;
        }
        
        temp = (A[i] + A[i+1] + A[i+2]) / 3.0;
        if(temp < min_sum) {
            min_sum = temp; 
            start_pos = i;
        }
    }
    
    temp = (A[N-2] + A[N-1]) / 2.0;
    if(temp < min_sum) {
        min_sum = temp;   
        start_pos = N-2;
    }   
    
    return start_pos;
}
