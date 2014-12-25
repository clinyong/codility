/*
 * Brackets
 * Determine whether a given string of parentheses is properly nested.
 * Link: https://codility.com/demo/take-sample-test/brackets
 * */

struct node {
    char element;
    struct node *next;
};
struct stack {
    struct node *head;
    int len;
};
void push(struct node *head, char ch)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    
    p->element = ch;
    p->next = head->next;
    head->next = p;
}
char pop(struct node *head)
{
    char e = '0';
    struct node *p;
    
    if(head->next == NULL) {
        return e;    
    }
        
    p = head->next;
    head->next = p->next;
    e = p->element;
    free(p);
    
    return e;
}
int match(char ch1, char ch2) {
    if(ch1 == '(' && ch2 == ')') {
    }else if(ch1 == '[' && ch2 == ']'){
    }else if(ch1 == '{' && ch2 == '}'){
    }else{
        return 0;
    }     
        
    return 1;
}
int solution(char *S) {
    // write your code in C99
    int len = strlen(S);
    int i;
    char ch;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    
    s->head->next = NULL;
    s->len = 0;
    
    for(i = 0; i < len; i++) {
        if(S[i] == '(' || S[i] == '{' || S[i] == '[') {
            push(s->head, S[i]); 
            s->len++;
        } else {
            if(s->len == 0) {
                return 0;    
            }
            ch = pop(s->head);
            s->len--;
            if(!match(ch, S[i])) {
                return 0;    
            }
        }    
    }
    
    if(s->len != 0) {
        return 0;    
    }
    
    return 1;
}
