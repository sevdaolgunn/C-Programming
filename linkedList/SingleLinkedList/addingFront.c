#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};

typedef struct node node;

int main(){
    

    node *head;
    node *temp;

    head = (node*)malloc(sizeof(node*));
    head -> data = 10;
    printf("İLK ELEMAN: %d\n", head->data);
    head ->next = NULL;

    for(int i=1; i<=5; i++){
        temp = (node*)malloc(sizeof(node));
        temp -> data = i*5;
        temp->next = head;
        head = temp;
    }

    int i=1;
    while(head!=NULL){
            
            printf("%d. eleman: %d\n",i,head->data);
            i++;
            head = head->next;
            
            }
           


    
     
}
