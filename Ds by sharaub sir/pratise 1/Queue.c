#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct ArrayQueue
{
     int front,rear;
     int capacity;
     int *array;
};
struct ArrayQueue * createQueue(int capacity )
{
     struct ArrayQueue *Q=(struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
     if(!Q)
     {
          printf("\n\t  ArrayQueue is not created ");
          return NULL;
     }
     Q->front=-1;
     Q->rear=-1;
     Q->capacity=capacity;
     Q->array=(int *)malloc(sizeof(capacity*(sizeof(int))));
     if(!Q->array)
     {
         printf("\n\t  memory for array is not created ");
         return NULL;
     }
     return Q;

}
int isEmptyQueue(struct ArrayQueue *Q)
{
     if(Q->front==-1||Q->rear==-1)
      return 1;
     else
       return 0;
}
int isFullQueue(struct ArrayQueue *Q)
{

    if(Q->front==(Q->rear+1)%Q->capacity)
        return 1;
    else
        return 0;
}
int queueSize(struct ArrayQueue *Q)
{
     if(isEmptyQueue(Q))
        return 0;
     if(isFullQueue(Q))
        return Q->capacity;
     else
        return ((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
void enQueue(struct  ArrayQueue *Q, int data)
{
     if(isFullQueue(Q))
     {
         printf("\n\t Overrflow ");
         return ;
     }
     Q->rear=(Q->rear+1)%Q->capacity;
     Q->array[Q->rear]=data;
     if(Q->front==-1)
        Q->front=Q->rear;
}
void deQueue(struct ArrayQueue *Q)
{
     if(isEmptyQueue(Q))
     {
         printf("\n\t underflow ");
         return ;
     }
     else
     {
         int data=Q->array[Q->front];
         if(Q->front==Q->rear)
            Q->rear=Q->front=-1;
         else
         Q->front=(Q->front+1)%Q->capacity;
         printf(" \n\t element is deleted =  %d",data);
     }
}
void viewQueue(struct ArrayQueue *Q)
{
       if(isEmptyQueue(Q))
     {
         printf("\n\t Queue is empty  ");
         return ;
     }
     else
     {
         if(Q->front>Q->rear){
         for(int i=Q->front;i<Q->capacity;i++)
         printf("\n\t value = %d",Q->array[i]);
         for(int i=0;i<=Q->rear;i++)
         printf("\n\t value = %d",Q->array[i]);
         }
         else{
         for(int i=Q->front;i<=Q->rear;i++)
         printf("\n\t value = %d",Q->array[i]);
         }
     }
}
void deleteQueue(struct ArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}
int main()
{
    struct ArrayQueue *Q=createQueue(4);
    int size=queueSize(Q);
    deQueue(Q);
    printf("\n\t Queue size at initial = %d",size);
    enQueue(Q,9);
    enQueue(Q,0);
    enQueue(Q,6);
    enQueue(Q,3);
    enQueue(Q,4);
    viewQueue(Q);
    size=queueSize(Q);
    printf("\n\t Queue size = %d",size);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    size=queueSize(Q);
    printf("\n\t Queue size = %d",size);
    viewQueue(Q);
    printf("\n\t ");
    return 0;
}
