#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;

};

typedef struct node node;

struct node *addlast(struct node *head,int key){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    if(head == NULL){
        head = temp; 
    }else{
        struct node*last = head;
        while(last -> next != NULL)
            last = last ->next;

        last -> next = temp;
    }
    return head;
    
}

void print(struct node *head){
    if(head == NULL){
        printf("The list is empty \n");
    }else{
        while(head!=NULL){
            printf(" %d\n",head->data);
            head = head->next;

        }
    }
}

struct node *deleteNode(struct node *head, int data){
    
    struct node *temp;
    struct node *iter = head;


    

    if(head->data == data){

        temp = head;
        head = head->next;
        
        free(temp);
        return head;
    }

    else{
        while (iter->next != NULL && iter->next->data != data){
            iter = iter->next;
        }

        if(iter->next == NULL){
            printf("invaild number for delete. \n");
            return head;
        }

        temp = iter->next;
        iter->next =temp->next;
        free(temp);

        return head;
    }
}

int main(){
    struct node *head = NULL;
    int data, choice;
    while(1){
        
        printf("1-insert a node: \n");
        printf("2-print the list \n");
        printf("3-delete a node\n");
        printf("0-exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        { 
       case 1:
            printf("enter the value to insert:");
            scanf("%d",&data);
            head=addlast(head,data);
            break;

        case 2:
            print(head);
            break;

        case 3:
            printf("Enter the data you want to delete: ");
            scanf("%d", &data);
            deleteNode(head,data);
            break;    
        case 0:
            exit(1);


        }
    }
}






