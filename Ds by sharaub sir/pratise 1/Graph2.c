#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ListNode{
    int VertexNo;
    struct ListNode *next;
};
struct Graph  {
  int V;
  int E;
  struct ListNode *arr;
};
struct Graph * adjustListgraph(){
    struct ListNode *temp,*t;
    int x,y;
    struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph ));
    if(!G){
        printf("\n\t memeory is not allocated runtime ERROR : 1");
        return NULL;
    }
    printf("\n\t enter the no of vertex and edges : ");
    scanf("%d%d",&G->V,&G->E);
    G->arr=(struct ListNode *)malloc(sizeof(struct ListNode)*G->V);
    if(!G->arr){
        printf("\n\t memeory is not allocated runtime ERROR : 2");
        return NULL;
    }
    for(int i=0;i<G->V;i++){
        (G->arr+i)->VertexNo=i;
        (G->arr+i)->next=G->arr+i;
    }
    for(int i=0;i<G->E;i++){
        printf("\n\t enter the source and destination : ");
        scanf("%d%d",&x,&y);
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->VertexNo=y;
        temp->next=G->arr+x;
        t=G->arr+x;
        while(t->next!=G->arr+x)
        t=t->next;
        t->next=temp;
    }
    printf("\n\t values of list : ");
    for(int i=0;i<G->V;i++){
            t=G->arr+i;
            printf("\n\t %d Node connecting routes  : ",i);
            while(t->next!=G->arr+i){
              printf(" %d",t->VertexNo);
              t=t->next;
            }
            printf(" %d",t->VertexNo);
    }
    return G;
}
int main(){
  struct Graph *G=NULL;
  G=adjustListgraph();
}
