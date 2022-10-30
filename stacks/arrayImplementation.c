#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct{
    int data[STACK_SIZE];
    int *top;
}stack;

void reset(stack *stk) {
    stk->top = -1;
    
}

void push(stack *stk, int c){ 

    if(stk->top == STACK_SIZE - 1)
    printf("stack is full");

    else{ //stk->data[++stk->top]=c;
        stk->top++;
        stk->data[stk->top] = c;

    }


}

int pop(stack *stk){

    if(stk->top==-1){
    printf("stack is empty");

    return 0;
    }
    
    else {

        int x = stk->data[stk->top];
        stk->top --;
        return x; //return stk->data[stk->top--]

    }

}
int main(){
    int ch, num,loop=1; 

    stack *stk = (stack*)malloc(sizeof(stack));

        
    while (1)
    {
        printf("\n1 - Reset\n2 - Push\n3 - Pop\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            reset(stk);
            break;
        case 2:
            printf("Number :");
            scanf("%d", &num);
            push(stk, num);
            break;
        case 3:
            num = pop(stk);
            printf("(Element at top of the stack :%d\n", num);
            break;
        } 

    }
}



