/*
 * FrogJmp
 * Count minimal number of jumps from position X to Y.
 * */

int solution(int X, int Y, int D) {
    // write your code in C99
    int m, n;
    
    m = Y - X;
    n = m / D;
    if(m % D) {
        n++;
    }
    
    return n;
}
