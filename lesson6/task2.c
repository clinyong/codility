/*
 * EquiLeader
 * Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
 * Link: https://codility.com/demo/take-sample-test/equi_leader
 * */

int solution(int A[], int N) {
    int i;
    int size = 0;
    int value = 0;
    int count = 0;
    int count_so_far = 0;
    int equi_leaders = 0;
    
    for(i = 0; i < N; i++) {
        if(size == 0) {
            value = A[i];
            size++;
        } else {
            if(value != A[i]) {
                size--;    
            } else {
                size++;    
            }  
        }
    }
     
    for(i = 0; i < N; i++) {
        if(A[i] == value) {            
            count++;
        }    
    }
    
    if(count < (N / 2)) {
        return 0;    
    }
    
    for(i = 0; i < N; i++) {
        if(A[i] == value) {
            count_so_far++;    
        } 

        if(count_so_far > (i+1)/2 && (count-count_so_far) > (N-i-1)/2) {
            equi_leaders++;    
        }
    }
    
    return equi_leaders;
}
