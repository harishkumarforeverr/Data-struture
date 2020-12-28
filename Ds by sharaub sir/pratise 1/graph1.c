#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct Graph{
  int V;
  int E;
  int **arr;
};
struct Graph* adjustMatrix(){
    int u,v;
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
    if(!G){
        printf("\n\t Graph is not created runtime ERROR");
        return NULL;
    }
    printf("\n\t enter the no of vertex and edges : ");
    scanf("%d%d",&G->V,&G->E);
    G->arr=(int *)malloc(G->V*G->V*sizeof(int));
    if(!G->arr){
        printf("\n\t memeory is not alocated for 2-D array Runtime error ");
        return NULL;
    }
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            *(G->arr+i*G->V+j)=0;
        }
    }
    printf("\n\t enter the edges from source to destination : \n");
    for(int i=0;i<G->E;i++){
     scanf("%d %d",&u,&v);
            *(G->arr+u*G->V+v)=1;
            *(G->arr+v*G->V+u)=1;
    }


    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
             printf("%d  ",*(G->arr+i*G->V+j));
        }
        printf("\n");
    }
    return G;
}
int main(){
    struct Graoh *G=NULL;
    G=adjustMatrix();
    return 0;
}
