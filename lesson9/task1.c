/*
 * Name: CountSemiprimes
 * Description: Count the semiprime numbers in the given range [a..b]
 * Link: https://codility.com/demo/take-sample-test/count_semiprimes
*/

struct Results solution(int N, int P[], int Q[], int M) {
    struct Results result;
    int sieve[N+1];
    int i, j, k;
    int count = 0;
    int prime_prefix_sum[N+1];
    int min_index, max_index;
     
    for(i = 0; i < N+1; i++) {
        sieve[i] = 0;
        prime_prefix_sum[i] = 0;
    }
    
    min_index = P[0];
    max_index = Q[0];
    for(i = 1; i < M; i++) {
        if(P[i] < min_index) {
            min_index = P[i];
        }    
        if(Q[i] > max_index) {
            max_index = Q[i];    
        }
    }
        
    result.A = malloc(sizeof(int) * M);
    result.M = M;

    // sieving the none prime
    for(i = 2; i*i < N+1; i++) {
        if(sieve[i] == 0) {
            for(j = i*i; j < N+1; j += i) {
                sieve[j] = i;
            }
        }
    }
    
    // count the semiprime prefix sum
    for(i = min_index; i <= max_index; i++) {
        prime_prefix_sum[i] = prime_prefix_sum[i-1];
        if(sieve[i] != 0) {
            j = i / sieve[i];
            if(sieve[j] == 0) {
                prime_prefix_sum[i]++;    
            }
        }
    }
    
    for(i = 0; i < M; i++) {
        j = Q[i];
        k = P[i]-1;
        result.A[i] = prime_prefix_sum[j] - prime_prefix_sum[k];    
    }

    return result;
}
