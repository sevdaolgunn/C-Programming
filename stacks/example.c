#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
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
    int ch, num,loop=1; 

    stack *stk = (stack*)malloc(sizeof(stack));

        
    while (loop)
    {
        printf("\n1 - initialization\n2 - push\n3 - pop\n");
        printf("0 - Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            initialize(stk);
            break;
        case 2:
            printf("Number :");
            scanf("%d", &num);
            push(stk, num);
            break;
        case 3:
            num = pop(stk);
            printf("(pop)Element at top of the stk :%d\n", num);
            break;
        case 0:
            loop = 0;
            break;
        } 

    }
}

