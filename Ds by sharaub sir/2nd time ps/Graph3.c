#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define INF 9999
struct Graph{
int V;
int E;
int **adj;
};
void printfSolution(struct Graph *G){
 for(int i=0;i<G->V;i++)
 {
     for(int j=0;j<G->V;j++){
        if(*(G->adj+i*G->V+j)==9999)
            printf("%7s ","INF");
        else
            printf("%7d ",*(G->adj+i*G->V+j));
     }
     printf("\n");
 }
}
void floydvarshalAlgoritham(struct Graph *G){
  int dist[G->V][G->V];
  int n=G->V;
     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
       dist[i][j]=*(G->adj+i*G->V+j);

     for(int k=0;k<G->V;k++)
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         if(dist[i][k]+dist[k][j]<dist[i][j])
           dist[i][j]=dist[i][k]+dist[k][j];

     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
       *(G->adj+i*G->V+j)=dist[i][j];


}
int main(){
 int n=4;
 int matrix[4][4]={
                      {0,5,INF,10},
                     {INF,0,3,INF},
                     {INF,INF,0,1},
                     {INF,INF,INF,0},
                 };
  struct Graph *G=(struct Graph * )malloc(sizeof(struct Graph));
  G->V=4;
  G->E=4;
  G->adj=(int *)malloc(sizeof(int)*G->V*G->V);
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        *(G->adj+i*G->V+j)=matrix[i][j];
  printf("\n\t values before : \n");
  printfSolution(G);
  floydvarshalAlgoritham(G);
  printf("\n\n\t values after : \n");
  printfSolution(G);
}
