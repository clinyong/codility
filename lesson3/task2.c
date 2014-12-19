/*
 * CountDiv
 * Compute number of integers divisible by k in range [a..b].
 * link: https://codility.com/demo/take-sample-test/count_div*/

//It is completely a mathematic question.
int solution(int A, int B, int K) {
	return B / K - (A / K) + (A % K == 0 ? 1 : 0);
}
