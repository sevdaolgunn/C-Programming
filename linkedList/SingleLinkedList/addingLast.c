#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
typedef struct node node;

int main()
{
    int i=0;

    node * head;

    head = (node*)malloc(sizeof(node*));
    head -> data = 10;
    head -> next = (node * )malloc(sizeof(node));
    head -> next -> data = 20;
    head -> next -> next = NULL;

    node * temp;
    temp = head;

    
    while (temp->next != NULL){
        i++;
        printf("%d.inci eleman : %d\n",i,temp->data );
        temp = temp->next;
       
    }
        

    for(i=1; i<=5;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        temp->data = i*10;
        printf("%d.inci eleman : %d\n",i,temp->data );

        temp->next = NULL;

    }

    
}
