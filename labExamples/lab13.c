#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node *next;

};

typedef struct node node;
int randomNum;

int main(){

    node *head = NULL;
    srand(time(NULL));
   
   for(int i=0; i<100; i++){

    randomNum = rand()%1000+1;

    addFirst(&head,randomNum);

   }
   printf("----Sıralamadan önce-----");
    printf("\n");

    printList(head);
    bubbleSort(head);

    printf("-------sıralamadan sonra-----");
    printf("\n");
    printList(head);
  
    

}
void addFirst(struct node **head, int value)
{
     
      struct node *newNode = malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = *head;
        *head = newNode;

}

 void printList(struct node *head){
    struct node *temp = head;


    while(temp != NULL)
    {
         printf("%d  ", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
    


void bubbleSort(struct node *head){

    int i,swapped;
    struct node *ptr1;
    struct node *ptr2 = NULL;

    if(head == NULL)
       return;

    do{
    swapped = 0;   
    ptr1 = head;   



    while(ptr1->next != ptr2){
        if(ptr1->data < ptr1->next->data){
            swap(ptr1, ptr1->next);
            swapped = 1;

        }
        ptr1 = ptr1->next;

    }
    ptr2 = ptr1;
}

while(swapped);


}
void swap(struct node *a, struct node *b){

    int temp = a->data;
    a->data = b->data;
    b->data = temp;

}