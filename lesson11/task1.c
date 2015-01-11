/*
 * Name: Ladder
 * Description: Count the number of different ways of climbing to the top of a ladder.
 * Link: https://codility.com/demo/take-sample-test/ladder
 * Hint: To climb to A[i] rungs,
 *       you could either come from A[i]-1 with an one-step jump
 *       OR come from A[i]-2 with a two-step jump for a given N rungs,
 *       the number of different ways of climbing is the (N+1)th element in the Fibonacci numbers.
 */

struct Results solution(int A[], int B[], int L) {
    struct Results result;
    int i;
    int max;
    int fib[L+2];

    result.C = malloc(sizeof(int) * L);
    result.L = L;

    max = B[0];
    for(i = 1; i < L; i++) {
        if(B[i] > max) {
            max = B[i];
        }
    }

    // To avoid big interger in fib
    // x % (2^n) == x & ((1 << n) - 1)
    long mod_limit = (1 << max) - 1;

    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i < L+2; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) & mod_limit;
    }

    for(i = 0; i < L; i++) {
        result.C[i] = fib[A[i]+1] & ((1 << B[i]) - 1);
    }

    return result;
}
