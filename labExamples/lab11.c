//priority queue
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 11


typedef struct priority_queue{
   int A[QUEUE_SIZE+1];
   int cnt;
} pqueue;

void swap(int a, int b) {
  int temp = b;
  b = a;
  a = temp;
}

void initialize_Queue(pqueue *p){
    p->cnt = 0;
}

void insert_data(pqueue *p, int key){
    if(p->cnt == QUEUE_SIZE)

       printf("\nQueue is fully");

    else {
        p->cnt++;
        p->A[p->cnt] = key;
        int iter = p->cnt;
        while(iter!=1 && p->A[iter]< p->A[iter/2]){
            int temp = p->A[iter];
            p->A[iter/2] = temp;
            iter = iter/2;
        }
    }   
}

void print_Queue(pqueue *p){
    if(p->cnt==0)
      printf("Queue is empty");
    else{
        int i;
        for(i=1; i<=p->cnt; i++)
           printf("%5d", p->A[i]);
    }  
}

int delete_data(pqueue *p){
    if(p->cnt == 0){
        printf("Queue is empty.");
        return -1;
    }
    else{
        int key = p->A[1];
        p->A[1] = p->A[p->cnt];
        p->cnt--;
        int iter = 1;
        while (2*iter <= p->cnt && p->A[iter]>p->A[2*iter] || p->A[iter]>p->A[2*iter+1]){
            if (p->A[2*iter]< p->A[2*iter+1]){
                swap(p->A[iter], p->A[2*iter]);
                iter=2*iter;
            }
            else{
                swap(p->A[iter], p->A[2*iter+1]);
                iter = 2*iter +1;
            }
            

        }
        
        
    }

}

int main(){

    pqueue p;

    initialize_Queue(&p);
    insert_data(&p,21);
    insert_data(&p,15);
    insert_data(&p,18);
    insert_data(&p,11);
    insert_data(&p,13);
   
    
    print_Queue(&p);
    printf("\n");
    delete_data(&p);
    print_Queue(&p);
    

    
}
