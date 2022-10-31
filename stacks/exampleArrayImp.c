#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

typedef struct {
    int data[STACK_SIZE];
    int top;
}stack;

int counter = 0;


void reset(stack *stk){
    stk->top = -1;
}

void push(stack *stk, int c){

    if(stk->data[STACK_SIZE -1])
       
       printf("stack is full");

    else {
        stk->top++;
        stk->data[stk->top]=c;
        counter++;

    }

}

int pop(stack *stk){

    if (stk->top == -1)
    {
        printf("stack is empty");

        return 0;
    }

    else{

        int x = stk->data[stk->top];
        stk->top--;
        counter --;
        return x;
    
    }
}

int printStack(stack *stk){

    printf("Stack:\n");

    for(int i=counter-1; i>=0; i--){
        printf("%d\n", stk->data[i]);
    }

}

int main(){
   
    stack *stk = (stack*)malloc(sizeof(stack));

    reset(stk);


    push(stk, 12);
    push(stk, 34);
    push(stk, 23);
    push(stk, 9);
    push(stk, 21);

    printStack(stk);

    

    printf("---------------\n");

    pop(stk);


    printStack(stk);



   
}


