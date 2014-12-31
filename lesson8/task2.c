/*
 * Name: MinPerimeterRectangle
 * Description: Find the minimal perimeter of any rectangle whose area equals N.
 * Link: https://codility.com/demo/take-sample-test/min_perimeter_rectangle
 */

int solution(int N) {
    long long i, j;
    
    j = 0;
    for(i = 1; i * i < N; i++) {
        if(N % i == 0) {
            j = i;
        }    
    }
    
    if(i * i == N) {
        return 4*i;    
    } else {
        return 2 * (j + N/j); 
    }
}
