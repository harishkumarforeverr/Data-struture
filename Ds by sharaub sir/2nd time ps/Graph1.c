#include<stdio.h>
#include<conio.h>
struct Graph{
 int V;
 int E;
 int **arr;
};
struct Graph * createGraph(){
  int u,v;;
  struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
  if(!G){
    printf("\n\t runtime error 1");
    return ;
  }
  printf("\n\t enter the no of vertex and edges : ");
  scanf("%d%d",&G->V,&G->E);
  G->arr=(int *)malloc(sizeof(int)*G->V*G->V);
  if(!G->arr){
    printf("\n\t runtime error 1");
    return ;
  }
  for(int i=0;i<G->V;i++)
    for(int j=0;j<G->V;j++)
     *(G->arr+i*G->V+j)=0;
  printf("\n\t enter the nodes connectiong each in a pair : \n ");
  for(int i=0;i<G->E;i++){
    scanf("%d%d",&u,&v);
     *(G->arr+u*G->V+v)=1;
     *(G->arr+v*G->V+u)=1;
  }
  printf("\n\t values : \n");
  for(int i=0;i<G->V;i++)
  {
    for(int j=0;j<G->V;j++){
        printf("%d ",*(G->arr+i*G->V+j));
    }
    printf("\n");
  }
}
int main(){
 struct Graph * G=createGraph();
}
