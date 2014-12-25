/*
 * Nesting
 * Determine whether given string of parentheses is properly nested.
 * Link: https://codility.com/demo/take-sample-test/nesting*/

int solution(char *S) {
    int len = strlen(S);
    int i;
    int count = 0;

    for(i = 0; i < len; i++) {
        if(S[i] == '(') {
            count++;    
        } else {
            if(count == 0) {
                return 0;    
            }    
            count--;
        }
    }
    
    if(count != 0) {
        return 0;    
    }
    
    return 1;
}
