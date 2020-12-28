#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define INF 9999
struct Graph{
 int V,E;
 int **arr;
};
void printSolution(struct Graph *);
void flyodVarshalAlgorith(struct Graph *);
int main(){
    int matrix[4][4]={  {0,5,INF,10},
                       {INF,0,3,INF},
                       {INF,INF,0,1},
                       {INF,INF,INF,0}
                    };
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph ));
    if(!G){
        printf("Runtime Eroor : 1");
        return NULL;
    }
    G->V=4;
    G->E=4;
    G->arr=(int *)malloc(sizeof(int)*G->V*G->V);
    if(!G->arr){
        printf("Runtime Eroor : 1");
        return NULL;
    }

     for(int i=0;i<G->V;i++)
            for(int j=0;j<G->V;j++)
                *(G->arr+i*G->V+j)=matrix[i][j];
     printf("\n\t Graph before solving : \n");
     printSolution(G);
     flyodVarshalAlgorith(G);
     printf("\n\n");
     printf("\n\t Graph after solving : \n");
     printSolution(G);
getch();
return 0;
}
void flyodVarshalAlgorith(struct Graph *G){
    int dist[G->V][G->V];
     for(int i=0;i<G->V;i++)
            for(int j=0;j<G->V;j++)
                dist[i][j]=*(G->arr+i*G->V+j);

      for(int k=0;k<G->V;k++){
        for(int i=0;i<G->V;i++){
           for(int j=0;j<G->V;j++){
            if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
        }
      }
    }

      for(int i=0;i<G->V;i++)
            for(int j=0;j<G->V;j++)
                *(G->arr+i*G->V+j)=dist[i][j];

}
void printSolution(struct Graph *G){
     for(int i=0;i<G->V;i++){
            for(int j=0;j<G->V;j++){
                    if(*(G->arr+i*G->V+j)==INF)
                      printf("%7s","INF");
                    else
                      printf("%7d",*(G->arr+i*G->V+j));
            }
        printf("\n");
     }
}
