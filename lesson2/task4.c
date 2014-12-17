/*
 * MaxCounters
 * Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
 * link: https://codility.com/demo/take-sample-test/max_counters
 * */


struct Results solution(int N, int A[], int M) {
    struct Results result;
    int i, j;
    int max = 0;
    int lastMax = 0;

    result.C = calloc(sizeof(int), N);
    result.L = N;
      
    for(i = 0; i < M; i++) {
        j = A[i];
        if(j == N+1) {
            lastMax = max;              
        } else {
            j--;
            
            if(result.C[j] < lastMax) {
                result.C[j] = lastMax + 1;    
            } else {
                result.C[j]++;    
            }
            
            if(result.C[j] > max) {
                max = result.C[j];    
            }                
        }
    }
    
    for(i = 0; i < N; i++) {
        if(result.C[i] < lastMax) {
            result.C[i] = lastMax;    
        }    
    } 

    return result;
}
