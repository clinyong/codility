/*
 * MaxProfit
 * Given a log of stock prices compute the maximum possible earning.
 * Link: https://codility.com/demo/take-sample-test/max_profit
 * */

int solution(int A[], int N) {
    int max_profit, profit;
    int i, bought_day;
    
    profit = max_profit = 0;
    bought_day = 0;
    for(i = 1; i < N; i++) {
        profit = A[i] - A[bought_day];
        if(profit < 0) {
            bought_day = i;  
        } else {
            if(profit > max_profit) {
                max_profit = profit;        
            }
            
        }
    }
    
    return max_profit;
}
