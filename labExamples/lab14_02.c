#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct node
{
    int data;
    struct nodes* next;
}node;
int indegree(struct node *heads[], int v, int n){
  int result = 0,i ;
  for(i = 0; i < n; i++){
    struct node *temp = heads[i]->next;
    while(temp != NULL){
      
      if(temp ->data == v)
         result++;
      temp = temp->next;   
    }
  }
}

int outdegree(struct node *head){
  int result = 0;
  struct node *temp = head ->next;
  while (temp!=NULL)
  {
    result++;
    temp = temp->next;

  }
  return result;
  
}

node *addEdge(node *head, int num){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    
    if (head == NULL)
    {
        head = temp;
    }else
    {
        node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }

    return head;
}

void printList(node *head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    } 
    printf("null\n");
}

int main(){
    node *heads[N] = {NULL};

    //vertex 1
    heads[0] = addEdge(heads[0], 1);
    heads[0] = addEdge(heads[0], 2);

    //vertex 2
    heads[1] = addEdge(heads[1], 2);
    heads[1] = addEdge(heads[1], 3);
    heads[1] = addEdge(heads[1], 5);

    //vertex 3
    heads[2] = addEdge(heads[2], 3);
    heads[2] = addEdge(heads[2], 5);
    heads[2] = addEdge(heads[2], 4);

    //vertex 4
    heads[3] = addEdge(heads[3], 4);
    heads[3] = addEdge(heads[3], 5);

    //vertex 5
    heads[4] = addEdge(heads[4], 5);
    heads[4] = addEdge(heads[4], 1);
    heads[4] = addEdge(heads[4], 4);

    for (int i = 0; i < N; i++)
    {
        printList(heads[i]);
    }
    
}

