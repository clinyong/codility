/*
 * Name: CommonPrimeDivisors
 * Description: Check whether two numbers have the same prime divisors.
 * Link: https://codility.com/demo/take-sample-test/common_prime_divisors
 */

int find_gcd(int a, int b)
{
    if(a % b == 0) {
        return b;
    }

    return find_gcd(b, a%b);
}

int has_same_prime_divisors(int a, int b)
{
    int gcd_val, a_gcd, b_bcd;

    /* The gcd contains all the common prime divisors */
    gcd_val = find_gcd(a, b);
    while(a != 1) {
        a_gcd = find_gcd(a, gcd_val);
        if(a_gcd == 1) {
            break;
        }

        a /= a_gcd;
    }

    if (a != 1) {
        return 0;
    }

    while(b != 1) {
        b_bcd = find_gcd(b, gcd_val);
        if (b_bcd == 1) {
            break;
        }

        b /= b_bcd;
    }

    return b == 1;
}

int solution(int A[], int B[], int Z) {
    int i;
    int count = 0;

    for(i = 0; i < Z; i++) {
        if ( has_same_prime_divisors(A[i], B[i]) ) {
            count++;
        }
    }

    return count;
}
