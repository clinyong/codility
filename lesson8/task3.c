/*
 * Name: Peaks
 * Description: Divide an array into the maximum number of same((-))sized blocks, each of which should contain an index P such that A[P - 1] < A[P] > A[P + 1].
 * Link: https://codility.com/demo/take-sample-test/peaks
*/

int solution(int A[], int N) {
    int i, j;
    int peaks_until_here[N];
    int blocks = 0;
    int flag;
    
    for(i = 0; i < N; i++) {
        peaks_until_here[i] = 0;
    }
    
    // count how many peaks exist from beginning to current
    for(i = 1; i < N-1; i++) {
        peaks_until_here[i] = peaks_until_here[i-1];
        if(A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks_until_here[i]++;
            peaks_until_here[i+1] = peaks_until_here[i];
            i++;
        } 
    }
    
    // The array is too short to have a peak. OR 
    // There is no peak in this array.
    if(N < 3 || peaks_until_here[N-2] == 0) {
        return 0;    
    }
    peaks_until_here[N-1] = peaks_until_here[N-2];
    
    // In each block, if there is a peak, 
    // the first index in peaks_until_here must not equil with the last index.
    // Unless that the peak in the first index.
    for(i = 2; i <= N; i++) {
        flag = 0;
        if(N % i == 0) {
            for(j = i-1; j < N; j += i) {
                if(peaks_until_here[j-i+1] == peaks_until_here[j]) {
                    //The peak in first index
                    if(j-i > 0 && peaks_until_here[j-i] < peaks_until_here[j-i+1]) {
                        continue;    
                    }
                
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0) {
                blocks = N/i;
                break;
            }
        }        
    }

    return blocks;
}
