#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
struct node{
    int data;
    struct node *next;
};
typedef struct {
    int cnt;
    struct node *front;
    struct node *rear;
    
}queue;

void initialize(queue *q){
    q->cnt = 0;
    q->front = q->rear = NULL;

}

int isFull(queue *q){
    if(q->cnt == QUEUE_SIZE){
        printf("queue is full");
        return 1;
    }

    else
        return 0;
    
}

int isEmpty(queue *q){
    if(q->cnt == 0){
        printf("queue is empty");
        return 1;
    }

    else 
        return 0;

}

void enque(queue *q, int x){
    if (isFull(q))
        printf("queue is full");

    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        if(isEmpty(q))
            q->front = q->rear = temp;

        else{
             q->rear->next = temp;
             q->rear = temp;
        }

        q->cnt++;
        printf("\ncounter: %d", q->cnt);
    }        
    
}

int deque(queue *q){
    if(isEmpty(q)){
        printf("queue is empty");
        return -1;
    }

    else{
        struct node *temp = q->front;
        int x = temp->data;
        q->front = temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}
void printQueue(queue *q){

    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp = q->front;
    

    printf("QUEUE: ");

    

    while(temp!=NULL){
    for ( int i=1; i<=q->cnt; i++){

            printf("item at position %d is %d\n", i, q->front->data);
            q->front = q->front->next;

        }

        free(temp);
        
    }

}


int main(){
    int choice;
    int num;

    queue *q;

    

    while(1) {
        printf("\n1-initialize \n2-enqueue \n3-dequeue \n4-print\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initialize(q);
            break;
        
        case 2: 
            printf("number: ");
            scanf("%d", &num);
            enque(q,num);
            break;

        case 3:
            deque(q);    

        case 4: 
            printQueue(q);
            break;
            
        default: 
            printf("wrong choice!!!");
            break;          

        
        }
        


    }

    

}