/*
 * Name: CountFactors
 * Description: Count factors of given number n.
 * Link: https://codility.com/demo/take-sample-test/count_factors
 */

int solution(int N) {
    long long i;
    int result = 0;
    
    for(i = 1; i * i < N; i++) {
        if(N % i == 0) {
            result += 2;    
        }        
    }
    
    if(i * i == N) {
        result++;   
    }
    
    return result;
}
