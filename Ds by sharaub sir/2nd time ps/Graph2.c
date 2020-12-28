#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
 int data;
 struct node *next;
};
struct Graph{
 int V;
 int E;
 struct node *adj;
};
struct Graph * adjustintyNode(){
  int x,y;
  struct node *temp,*t;
  struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph ));
  if(!G){
    printf("\n\t runtime error 1");
    return NULL;
  }
   printf("\n\t enter the no of vertex and edges : ");
   scanf("%d %d",&G->V,&G->E);
   G->adj=(struct node * )malloc(sizeof(struct node)*G->V);
   if(!G->adj){
    printf("\n\t runtime error 2");
    return NULL;
   }
   for(int i=0;i<G->V;i++){
     (G->adj+i)->data=i;
     (G->adj+i)->next=(G->adj+i);
   }
   printf("\n\t enter the node in source and destination in a pair : \n");
   for(int i=0;i<G->E;i++){
      scanf("%d%d",&x,&y);
      temp=(struct node *)malloc(sizeof(struct node));
      if(!temp){
         printf("\n\t runtime error 3");
         return NULL;
      }
      temp->data=y;
      temp->next=(G->adj+x);
      t=(G->adj+x);
      while(t->next!=(G->adj+x))
        t=t->next;
       t->next=temp;
   }
   for(int i=0;i<G->V;i++){
       printf("\n\t %d node connection info  : ",i) ;
      t=(G->adj+i);
      while(t->next!=(G->adj+i)){
       printf("%d ",t->data);
       t=t->next;
      }
       printf("%d ",t->data);
   }

}
int main(){
 struct Graph * G =adjustintyNode();
}
