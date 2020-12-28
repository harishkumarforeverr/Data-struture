#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static int count=0;
struct node
{
     int data;
     struct node *left;
     struct node *right;
};
struct node * insertNode(struct node *Q, int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    // printf("\n\t im IN ");
    if(Q==NULL)
    {
        count++;
         Q=temp;
         //printf("\n\t 1st elememt is inserted %d",Q->data);
    }
    else
    {
        struct node *par=Q;
        while(par!=NULL)
        {
           // printf(" hi harish ");
            if(par->data>data)
            {
                if(par->left==NULL){
                        count++;
                    par->left=temp;
         //           printf("data inserted left %d ",(par->left)->data);
                    par=par->left;
                }
                par=par->left;
            }
            else if(par->data<data)
            {
                if(par->right==NULL){
                        count++;
                    par->right=temp;
       //             printf("data inserted right %d ",(par->right)->data);
                    par=par->right;
                }
                par=par->right;
            }
        }
    }
     //printf("\n\t %d data is inserted ",data);
     return Q;
};
void inOrder(struct node * Q)
{
    if(Q)
    {
     inOrder(Q->left);
     printf(" %d ",Q->data);
     inOrder(Q->right);
    }
}

struct node * findNode(struct node *Q,int data)
{
    if(Q==NULL)
        return NULL;
    if(Q->data>data)
        return (findNode(Q->left,data)) ;
    else if(Q->data<data)
        return (findNode(Q->right,data));
    return Q;
}
struct node * findMaxNode(struct node *Q)
{
    while(Q!=NULL&&Q->right!=NULL)
    {
        Q=Q->right;
    }
    return Q;
};
struct node * deleteNode(struct node *Q, int data)
{
    if(Q==NULL)
    {
        printf("\n\t no such data is found ");
    }
    else if(Q->data>data)
    {
        Q->left=deleteNode(Q->left,data);
    }
    else if(Q->data<data)
    {
        Q->right=deleteNode(Q->right,data);
    }
    else
    {
        if(Q->left&&Q->right)
        {
            struct node *temp=findMaxNode(Q->left);
            Q->data=temp->data;
            Q->left=deleteNode(Q->left,Q->data);
        }
        else
        {
             if(Q->left==NULL)
             {
                 struct node *tt=Q;
                 Q=Q->right;
                 free(tt);
             }
             else if(Q->right==NULL)
             {
                 struct node *qq=Q;
                 Q=Q->left;
                 free(qq);
             }
        }
    }
    return Q;
};
struct Queue
{
  //  int capacity;
  /*  im commiting becox i didnot got any necassary of capacity in my program */
    int rear;
    int front;
    struct node *arr[10];
};
struct Queue * createQueue()
{
   struct Queue *Q=(struct Queue *)malloc(sizeof(struct Queue));
    if(!Q)
    {
        printf("\n\t Queue is not createds ");
        return NULL;
    }
    else
    {
       // Q->capacity=count;
  /*  im commiting becox i didnot got any necassary of capacity in my program */
        Q->rear=-1;
        Q->front=-1;
    }
};
int isEmptyQueue(struct Queue *Q)
{
    return (Q->front>Q->rear);
}
void enQueue(struct Queue *Q, struct node *root)
{
    Q->rear++;
    Q->arr[Q->rear]=root;
    if(Q->front==-1)
    {
        Q->front=Q->rear;
    }
}
struct node * deQueue(struct Queue *Q)
{
//    if(Q->front==Q->rear) //
/*i wrote these condition becox in Queue we have one case when front and rear
 have index 1 and if we decrement font will become 2 and rear will be having
index 1
i.e rear<front which is wrong
but now i kept in commmet becoz im assuming only base/goood condition
*/

//    {
//        return Q->arr[Q->front];
//        Q->front=-1;
//        Q->rear=-1;
//    }
//    else
//    {
        struct node *temp= Q->arr[Q->front];
        Q->front++;
        return temp;
//}
}
void levelOrder(struct node *root)
{
    struct node *temp;
    struct Queue *Q=createQueue();
    if(!root)
    {
        printf("\n\t BST is empty ");
        return ;
    }
    else
    {
         enQueue(Q,root);
         while(!isEmptyQueue(Q))
         {
             temp=deQueue(Q);
             printf(" %d ",temp->data);
             if(temp->left)
             {
                 enQueue(Q,temp->left);
             }
             if(temp->right)
             {
                 enQueue(Q,temp->right);
             }
         }
    }

}

int main()
{
    struct node *Q=NULL;
    printf("\n\t insertig node and ");
    Q=insertNode(Q,80);
    insertNode(Q,70);
    insertNode(Q,90);
    insertNode(Q,30);
    insertNode(Q,75);
    insertNode(Q,85);
    insertNode(Q,95);
    printf(" insertion is completed ");
    printf("\n\n\t we are Displaying the data inOrder  ");
    printf("\n\t values = ");
    levelOrder(Q);
    printf("\n\t no of elements in the list = %d",count);

    printf("\n\n\n\n\n\n");
    return 0;
}
