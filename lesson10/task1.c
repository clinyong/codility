/*
 * Name: ChocolatesByNumbers
 * Description: There are N chocolates in a circle. Count the number of chocolates you will eat.
 * Link: https://codility.com/demo/take-sample-test/chocolates_by_numbers
 */

int find_gcd(int a, int b)
{
    if(a % b == 0) {
        return b;
    }

    return find_gcd(b, a%b);
}

int solution(int N, int M)
{
    int gcd;

    gcd = find_gcd(N, M);

    return N/gcd;
}
