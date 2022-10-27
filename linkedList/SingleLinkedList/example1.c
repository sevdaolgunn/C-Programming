#include <stdio.h>
#include <stdlib.h>


struct node {
    int x;
    struct node *next;

};

typedef struct node node;

void bastir(node *r){
    while (r!=NULL)
    {
        printf("%d  ", r->x);
        r = r->next; 
    }
    
}

void ekle(node *r, int x){
    while (r->next!=NULL)
    {
         r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;   
}

int main(){
    node *head;

    head = (node*)malloc(sizeof(node));
    head->next=NULL;
    head->x = 500;

    int i = 0;
    for ( i = 0; i < 5; i++)   // Araya ekleme
    {
        ekle(head, i*10);
    }


    printf("Öncesi:");
    bastir(head);

    node *temp;

    temp = head;

    for ( i = 0; i < 3; i++)
    {
        temp = temp ->next;
    }

    node *iter = (node *)malloc(sizeof(node));
    iter -> next = temp -> next;
    temp -> next = iter;
    iter -> x = 100;
    printf("\nSonrası: ");
    bastir(head);

}