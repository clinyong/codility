/*
 * Dominator
 * Find an index of an array such that its value occurs at more than half of indices in the array.
 * Link: https://codility.com/demo/take-sample-test/dominator
 * */

int solution(int A[], int N) {
    int i;
    int size = 0;
    int value;
    int index = -1;
    int count = 0;
    
    for(i = 0; i < N; i++) {
        if(size == 0) {
            value = A[i];
            size++;
        } else {
            if(value != A[i]) {
                size--;    
            }    
        }
    }
    
    for(i = 0; i < N; i++) {
        if(A[i] == value) {
            count++;
            index = i;
        }    
    }
    
    if(count > (N / 2)) {
        return index;    
    }
    
    return -1;
}
