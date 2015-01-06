/*
 * Name: CountNonDivisible
 * Description: Calculate the number of elements of an array that are not divisors of each element.
 * Link: https://codility.com/demo/take-sample-test/count_non_divisible
 * Hint: Finding the counts of the element in array A.
 *       Finding all factors of A's elements.
*/

int find_max(int A[], int N)
{
    int max;
    int i;

    max = A[0];
    for(i = 0; i < N; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    return max;
}

struct Results solution(int A[], int N) {
    struct Results result;
    int i, j, k;
    int count, max;

    result.C = malloc(sizeof(int) * N);
    result.L = N;

    max = find_max(A, N);
    int element_counts[max+1];
    int factors[max+1];

    for(i = 0; i <= max; i++) {
        element_counts[i] = 0;
        factors[i] = 0;
    }

    // counts of the element of array A
    for(i = 0; i < N; i++) {
        element_counts[A[i]]++;
    }

    // Finding all factors of A's element
    for(i = 0; i < N; i++) {
        if(factors[A[i]] == 0) { // A[i]'s factors may be counted before
            for(j = 1; j*j <= A[i]; j++) {
                if(A[i] % j == 0) {
                    factors[A[i]] += element_counts[j];
                    k = A[i] / j;
                    if(k != j) {
                        factors[A[i]] += element_counts[k];
                    }
                }
            }
        }
    }

    for(i = 0; i < N; i++) {
        result.C[i] = N - factors[A[i]];
    }

    return result;
}
