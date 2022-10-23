#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;

};

typedef struct n node;

int main(){
    node * head;
    head = (node * )malloc(sizeof(node));
    head -> x = 10;
    head -> next = (node * )malloc(sizeof(node));
    head -> next -> x = 20;
    head -> next -> next = (node *) malloc(sizeof(node));
    head -> next -> next -> x = 30;
    head -> next -> next ->next = NULL;

    printf("1. eleman: %d\n",head ->x );

    node * temp;
    temp = head;
    printf("1. eleman: %d\n",temp ->x );
    temp = temp -> next;
    printf("2. eleman: %d\n",temp ->x );
    temp = temp -> next;
    printf("3. eleman: %d\n",temp ->x );




   

}