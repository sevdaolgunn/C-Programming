#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BTREE;


BTREE *newNode(int data){

    BTREE *p;
    p = (BTREE*)malloc(sizeof(BTREE));
    p->data = data;
    p->left = p->right = NULL;
    
    return p;
}

BTREE *insertData(BTREE *root, int data){
    if(root!=NULL){
        if(data < root->data)
           root->left = insertData(root->left,data);
        else
           root->right = insertData(root->right,data);   
    }
    else 
      root = newNode(data);

    return root;  
}

void printInorder(BTREE *root){
    if(root!=NULL){
        printInorder(root->left);
        printf("\n%d", root->data);
        printInorder(root->right);
    }
}

void printPreorder(BTREE *root){
    if(root!=NULL){
        printf("\n%d", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(BTREE *root){
    if(root!=NULL){
        printPostorder(root->left);
        printPostorder(root->right);
        printf("\n%d", root->data);
    }
}

int size(BTREE *root){
    if(root!=NULL)
       return (size(root->left) + 1 + size(root->right));

    else
       return 0;   
}

int maxDepth(BTREE *root){

    int LDepth;
    int RDepth;

    if(root == NULL) 
       return 0;

    else{
        //compute the depth of each subtree
        LDepth = maxDepth(root->left);
        RDepth = maxDepth(root->right);

         if(LDepth > RDepth)
            return (LDepth + 1);
        else
            return (RDepth + 1);    
    }   

}

int main(){

    BTREE *myRoot = NULL;
    int x = 0;

    printf("enter root: ");
    scanf("%d", &x);

    printf("enter other data ");
    while(x!=-1){
        myRoot = insertData(myRoot,x);
        scanf("%d", &x);
    }

    printf("\nINORDER:");
    printInorder(myRoot);

    printf("\nPREORDER:");
    printPreorder(myRoot);

    printf("\nPOSTORDER:");
    printPostorder(myRoot);

    printf("\nthe size of binary tree:%d", size(myRoot));
    

    printf("\nthe depth of binary tree: %d",maxDepth(myRoot));
    




}

