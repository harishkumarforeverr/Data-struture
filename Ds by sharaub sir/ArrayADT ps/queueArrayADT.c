#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queueADT{
 int capacity;
 int front;
 int rear;
 int *arr;
};
struct queueADT * create_queueADT(int capacity){
    struct queueADT *temp=(struct queueADT *)malloc(sizeof(struct queueADT));
    if(!temp){
        printf("\n\t runtime error 1");
        return NULL;
    }
    temp->capacity=capacity;
    temp->front=-1;
    temp->rear=-1;
    temp->arr=(int * )malloc(sizeof(int)*temp->capacity);
    if(!temp->arr){
    printf("\n\t runtime error 2");
    return NULL;
    }
    return temp;
}
int is_queue_is_empty(struct queueADT *Q){
    if(Q->front==-1)
     return 1;
    else
     return 0;
}
int is_queue_is_full(struct queueADT *Q){
    if(Q->front==0&&Q->rear==Q->capacity-1) // base condition
        return 1;
    else if(Q->rear+1==Q->front)  // if we assume queue as a circular queue
        return 1;
    else
        return 0;
}
int queueu_capacity(struct queueADT *Q){
     return (Q->capacity);
}
void double_the_sizeof_Queue(struct queueADT *Q){
    Q->capacity=2*Q->capacity;
    int *temp=(int *)malloc(sizeof(int)*Q->capacity);
    if(!temp){
        printf("\n\t runtime error 3");
        return ;
    }
    int i,j;
    for(i=Q->front, j=0;i!=Q->rear;j++){
        // i=3               3!=1 true 3==3 i=0,  0!=1 0==3 , 1!=1
        // rear 1
        temp[j]=Q->arr[i];
        if(i==(Q->capacity/2)-1&&i!=Q->rear)
            i=0;
        else
            i++;
    }
    // last rear lo unndi pothundi so im writing these
    temp[j]=Q->arr[i];
    free(Q->arr);
    Q->arr=temp;
    Q->front=0;
    Q->rear=(Q->capacity/2)-1;
}
void half_the_queue(struct queueADT *Q){
    int *temp;
    int i,j,l;
    temp=(int *)malloc(sizeof(int)*Q->capacity/2);
    if(!temp){
        printf("\n\t runtime error ");
        return ;
    }
    for(i=0,j=Q->front;j!=Q->rear;i++){
        temp[i]=Q->arr[j];
        if(j==Q->capacity-1)
            j=0;
        else
            j++;
    }
    temp[i]=Q->arr[j];
    free(Q->arr);
    Q->arr=temp;
    Q->front=0;
    Q->rear=(Q->capacity/2)-1;
    Q->capacity=(Q->capacity/2);
}
void enqueue(struct queueADT *Q, int value ){
    if(Q->capacity<1){
        printf("\n\t invalid capcity ");
    }
    else{
        if(is_queue_is_empty(Q)){
            Q->arr[0]=value;
            Q->front=0;
            Q->rear=0;
        }
        else if(is_queue_is_full(Q)){
            double_the_sizeof_Queue(Q);
            Q->rear=Q->rear+1;
            Q->arr[Q->rear]=value;
        }
        else{
            if(Q->rear==Q->capacity-1)
                   Q->rear=0;
            else
                Q->rear=Q->rear+1;
          Q->arr[Q->rear]=value;
        }
    }
}
void dequeue(struct queueADT *Q){
     int i,size=0;
     if(is_queue_is_empty(Q)){
        printf("\n\t list is empty ");
     }
     else if(Q->front==Q->rear){
        Q->front=Q->rear=-1;
     }
     else if(Q->front==Q->capacity-1){
        Q->front=0;
     }
     else{
        Q->front=Q->front+1;
     }
     if(Q->front>-1){
        for(i=Q->front;i!=Q->rear;){
            size++;
            if(i==Q->capacity-1)
                i=0;
            else
                i++;
        }
        size++;
        if(size==Q->capacity/2)
            half_the_queue(Q);
     }
}
struct queueADT * deleteQueue(struct queueADT *Q){
   free(Q->arr);
   free(Q);
   return NULL;
}
void viewQueue(struct queueADT *Q){
    int i;

   if(!is_queue_is_empty(Q)){
   printf("\n\t queueADT values : ");
   for(i=Q->front;i!=Q->rear;i++){
   if(Q->capacity-1==i&&i!=Q->rear)
        i=0;
       printf("%d ",Q->arr[i]);
   }
   printf("%d ",Q->arr[i]);
   }
}
// create_queueADT
// is_queue_is_empty
// is_queue_is_full
// queueu_capacity
// double_the_sizeof_Queue
// half_the_queue
// enqueue
// dequeue
int main(){
   struct queueADT *Q=create_queueADT(4);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   enqueue(Q,0);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   enqueue(Q,1);
   enqueue(Q,2);
   enqueue(Q,3);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   enqueue(Q,4);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);
   dequeue(Q);
   viewQueue(Q);
   printf("\n\t queue capacity , front , rear =  %d  :  %d  :  %d ",Q->capacity,Q->front,Q->rear);

Q=deleteQueue(Q);
getch();
return 0;
}
