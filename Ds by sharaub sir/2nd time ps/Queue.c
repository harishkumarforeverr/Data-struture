#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
 int front,rear;
 int capacity;
 int *array;
};
struct node * createQueue(int capacity){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  if(!temp){
    printf("\n\t runtime error ");
    return NULL;
  }
  temp->front=-1;
  temp->rear=-1;
  temp->capacity=capacity;
  temp->array=(int *)malloc(sizeof(int)*temp->capacity);
  if(!temp->array){
    printf("\n\t runtime error ");
    return NULL;
  }
  return temp;
}
int isEmptyQueue(struct node *Q){
  return (Q->front==-1);
}
int isFullQueue(struct node *Q){
 return ((Q->rear+1)%Q->capacity==Q->front);
}
int queueSize(struct node *Q){
      if(isEmptyQueue(Q))
        return 0;
      else if(isFullQueue(Q))
        return Q->capacity;
      else
        return ((Q->capacity+1-Q->front+Q->rear)%Q->capacity);
}
void enQueue(struct node *Q, int data){
  if(isFullQueue(Q)){
    printf("\n\t overflow ");
    return ;
  }
  else{
    Q->rear=((Q->rear+1)%Q->capacity);
    Q->array[Q->rear]=data;
    if(Q->front==-1)
        Q->front=0;
  }
}

void deQueue(struct node *Q){
   if(isEmptyQueue(Q)){
    printf("\n\t underflow");
    return ;
   }
   else{
    if(Q->front==Q->rear)
        Q->front=Q->rear=-1;
    else
    Q->front=(Q->front+1)%Q->capacity;
   }
}
void freeThequeue(struct node *Q){
   if(Q){
     if(Q->array){
        free(Q->array);
     }
     free(Q);
   }
}
void view(struct node *Q){
    if(isEmptyQueue(Q)){
        printf("\n\t list is empty ");
        return ;
    }
    printf("\n\t QUEUE values : ");
    int i;
   for(i=Q->front;i!=Q->rear;){
    printf("%d ",Q->array[i]);
    if(i==Q->capacity-1&&Q->rear!=i)
    i=0;
    else
        i++;
   }
  printf("%d ",Q->array[i]);

}
 /*
     freeThequeue
  deQueue
  enQueue
    createQueue
    isEmptyQueue
     isFullQueue
  queueSize
 */

int main(){
    struct node *Q=createQueue(4);
    view(Q);
    printf("\n\t front rear size : %d %d %d",Q->front,Q->rear,queueSize(Q));
    enQueue(Q,10);
    enQueue(Q,20);
    enQueue(Q,30);
    enQueue(Q,40);
    view(Q);
    printf("\n\t front rear size : %d %d %d",Q->front,Q->rear,queueSize(Q));

    deQueue(Q);
    deQueue(Q);
    enQueue(Q,40);
    enQueue(Q,40);
    printf("\n\t front rear size : %d %d %d",Q->front,Q->rear,queueSize(Q));
    view(Q);
getch();
return 0;
}
