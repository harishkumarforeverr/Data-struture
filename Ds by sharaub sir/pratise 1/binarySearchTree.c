#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
                    par->left=temp;
         //           printf("data inserted left %d ",(par->left)->data);
                    par=par->left;
                }
                par=par->left;
            }
            else if(par->data<data)
            {
                if(par->right==NULL){
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
void preOrder(struct node * Q)
{
    if(Q)
    {
     printf(" %d ",Q->data);
     preOrder(Q->left);
     preOrder(Q->right);
    }
}
void postOrder(struct node * Q)
{
    if(Q)
    {
     postOrder(Q->left);
     postOrder(Q->right);
     printf(" %d ",Q->data);
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
    inOrder(Q);
    printf("\n\n\t we are Displaying the data preOrder  ");
    printf("\n\t values = ");
    preOrder(Q);
    printf("\n\n\t we are Displaying the data postOrder  ");
    printf("\n\t values = ");
    postOrder(Q);
    printf("\n\t enter the element to be search = ");
    int n;
    scanf("%d",&n);
    struct node *find=findNode(Q,n);
    if(find!=NULL)
    {
        printf("\n\t data is found ");
    }
    else
    {
         printf("\n\t no data is found ")    ;
    }

    printf("\n\t enter the no to be delete = ");
    int info;
    scanf("%d",&info);
    deleteNode(Q,info);
    printf("\n\t elements after deleteing ");
    inOrder(Q);
    printf("\n\n\n\n\n\n");
    return 0;
}
