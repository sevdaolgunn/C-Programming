#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct node {
    int data;
    struct node *next;
};

typedef struct {
    int cnt;
    struct node *top;
}stack;


void initialize(stack *stk){

    stk->cnt=0;
    stk->top=NULL;
}

void push(stack *stk, int c){

    if(stk->cnt==STACK_SIZE)
        printf("stack is full");

    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt ++;

    }
    
}

int pop(stack *stk){

    if(stk->cnt == 0){
        printf("stack is empty");
        return 0;
    }
    
    else{
        int x = stk->top->data;
        struct node *temp = stk->top->next;
        free(temp);
        stk->cnt--;
        return x;

    }    
}

void printStack(stack *stk){

    printf("STACK:");
    
    while(stk->top=NULL){
        printf("%d\n", stk->top->data);
        stk->top--;
    }
}

int main(){


    stack *stk = (stack*)malloc(sizeof(stack));

    initialize(stk);


    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);

    printStack(stk);

    
}
