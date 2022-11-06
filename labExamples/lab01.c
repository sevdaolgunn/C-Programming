#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;


struct node *addfront(node *head, int key){

    struct node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = key;
    temp->next = head;
    head = temp;

    return head;

}

struct node *addlast(node *head, int key){

    struct node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = key;
    temp->next = NULL;

    if(head = NULL){
        head = temp; // no first value.
    }

    else {
        struct node *last = head;
        while (last->next != NULL){
            last = last->next;
        }
        last->next = temp;
    }

    return head;

}

void printList(struct node *head){
    if(head==NULL)
      printf("The list is empty");

    else{
        while(head!=NULL){
            printf("\n%d", head->data);
            head = head->next;
        }
    }  
}

void printReverse(struct node *head){

    if(head == NULL)
       return;

    printf(head->next);
    printf("%d\n", head->data);   
    
}

int count (struct node *head){

    int count = 0;

    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    struct node *head  = NULL;

    int data, choice;

    while(1){
        printf("\n1-insert at front: \n");
        printf("2-insert at end: \n");
        printf("3-print the list \n");
        printf("4-print reverse \n");
        printf("0-exit");
        printf("\nChoice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("enter the data to insert to the front");
            scanf("%d", &data);
            head = addfront(head, data);
            break;
        case 2:
            printf("enter the data to insert to the add");
            scanf("%d", &data);
            head = addlast(head, data);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printReverse(head);
            break;     
        case 0:
            exit(1);
            break;

        default:
            printf("Wrong choice!!!");
            break;
        }
    }
}

