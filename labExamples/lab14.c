#include <stdio.h>
#include <stdlib.h>
#define N 5


int degree(int A[][N], int v, int n){
    int i, result = 0;
    for(i = 0; i<n; i++)
        result += A[v][i];

    return result;
}
int edges(int A[][N], int n){
    int result = 0,i,j;
    for(i=0; i<n; i++){
        for(j = 0; j<n; j++ )
        result += A[i][j];
    }
    return result/2;
}

int main(){
    int sum;
    
    int diagram[N][N] = {
        {0,1,1,1,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {1,1,1,0,1},
        {0,0,1,1,0}
    };

    for(int i = 0; i<N; i++){
        sum = degree(diagram,i,5);
        printf("degree of vertex %d is %d\n", i+1,sum);
    }
   


}
