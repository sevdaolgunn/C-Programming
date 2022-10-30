#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 3
struct node{
    int data;
    struct node *next;
};
typedef struct{
    int cnt;
    struct node *top;
}stack;

void initialize(stack *stk){
    stk->cnt = 0;
    stk->top = NULL;

}

void push(stack *stk, int c){

    if (stk->cnt == STACK_SIZE ){
        printf("stack is full");
    }

    else{
        struct node *temp = (stack*)malloc(sizeof(stack));
        temp -> data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt ++;
    }
}

int pop(stack *stk){

    if (stk->cnt==0)
    
        printf("stack is empty");
    

    else {
        int x = stk->top->data;
        struct node *temp = stk->top->next;
        free(temp);
        stk->cnt --;
        return x;

    }
}

int main(){

    stack *stk = (stack*)malloc(sizeof(stack));
    


    initialize(&stk);
    push(&stk, 4);
    push(&stk, 10);
    push(&stk, 8);
    push(&stk, 5);
    
    printf("\n%d", pop(&stk));
    printf("\n%d", pop(&stk));
    printf("\n%d", pop(&stk));
    printf("\n%d", pop(&stk));
    

}