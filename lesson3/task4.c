/*
 * GenomicRangeQuery
 * Find the minimal nucleotide from a range of sequence DNA.
 * Link: https://codility.com/demo/take-sample-test/genomic_range_query
 * */

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    int n = strlen(S);
    int sum[n+1][4];
    int i, j, index, p, q;
    int map[20];

    result.A = malloc(sizeof(int) * M);
    result.M = M;
    
    map[0] = 1;
    map[2] = 2;
    map[6] = 3;
    map[19] = 4;
    
    for(i = 0; i < 4; i++) {
        sum[0][i] = 0;    
        sum[1][i] = 0;
    }
    index = S[0] - 'A';
    sum[1][map[index]-1] = 1;
    
    for(i = 2; i < n+1; i++) {
        for(j = 0; j < 4; j++) {
            sum[i][j] = sum[i-1][j];    
        }    
        index = S[i-1] - 'A';
        sum[i][map[index] - 1]++;
    }
    
    for(i = 0; i < M; i++) {
        p = P[i];
        q = Q[i];

        
        for(j = 0; j < 4; j++) {
            if (sum[q+1][j] - sum[p][j] > 0) {
                result.A[i] = j+1;
                break;
            }                
        }
    }
    
    return result;
}
