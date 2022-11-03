#include <stdio.h>
#include <stdlib.h>

int *array;
int front = 0, rear = 0;
int size = 2;

int deque(){
    if(front == rear ){
        printf("queue is empty");
        return -1;
    }
   return array[front++];
}
void delete(){
    if(front == 0)
       return;
    for(int i=0; i<size; i++){
        array[i] = array[i+front];
    }  
    rear -= front;
    front = 0;
}
void enque(int a) {
    if(array == NULL){
        array = (int*)malloc(sizeof(int)*2);
    }
    if(rear >= size){
        size*=2;
        int *array2 = (int*)malloc(sizeof(int)*size);
        for (int i=0; i<size/2; i++)
                  array2[i] = array[i];
        free(array);
        array = array2;           
    }
    array[rear++] = a;

}
int main(){
    for(int i=0; i<20; i++){
        enque(i*10);
    }

    printf("DURUM --> boyut: %d sirabasi: %d  sirasonu: %d", size,front,rear);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", deque());
    }
    delete();
    printf("\nDURUM --> boyut: %d sirabasi: %d  sirasonu: %d", size,front,rear);



    for(int i=0; i<20; i++){
        enque(i*10);
    }
    printf("\nDURUM --> boyut: %d sirabasi: %d  sirasonu: %d", size,front,rear);
    for (int i = 0; i < 30; i++)
    {
        printf("%d\n", deque());
    }
    printf("\nDURUM --> boyut: %d sirabasi: %d  sirasonu: %d", size,front,rear);

    
    
}
