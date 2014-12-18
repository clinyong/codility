/*
 * PassingCars
 * Count the number of passing cars on the road.
 * link: https://codility.com/demo/take-sample-test/passing_cars
 * */

int solution(int A[], int N) {
    int i;
    int num = 0;
    unsigned long sum = 0;
    
    for(i = 0; i < N; i++) {
        if(A[i] == 0) {
            num++;    
        } else {
            sum = sum + num; 
        }        
    }
    
    if(sum > 1000000000) {
        return -1;    
    }
    
    return sum;
}
