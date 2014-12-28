/*
 * Fish
 * N voracious fish are moving along a river. Calculate how many fish are alive.
 * Link: https://codility.com/demo/take-sample-test/fish
 * Todo: Performance is only 25%
 * */

struct node {
    int size;
    struct node *next;
};
struct stack {
    struct node *head;
    int len;
};
void push(struct node *head, int size)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    
    p->size = size;
    p->next = head->next;
    head->next = p;
}
int top(struct node *head)
{
    return head->next->size;
}
void pop(struct node *head)
{
    struct node *p;
         
    p = head->next;
    head->next = p->next;
    free(p);
}

int solution(int A[], int B[], int N) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    int i;
    int size;
    int alive = 0;

    s->head->next = NULL;
    s->len = 0;

    for(i = 0; i < N; i++) {
        if(s->len == 0 && B[i] == 0) {
            alive++;        
        } else {
            if(B[i] == 1) {
                push(s->head, A[i]); 
                s->len++;                
            } else {
                while(s->len) {
                    size = top(s->head); 
                    if(A[i] > size){
                        pop(s->head);
                        s->len--;
                    } else {
                        break;    
                    }                
                }
                
                if(s->len == 0) {
                    alive++;    
                }
            }  
        }
    }
    
    alive += s->len;
    
    return alive;
}
