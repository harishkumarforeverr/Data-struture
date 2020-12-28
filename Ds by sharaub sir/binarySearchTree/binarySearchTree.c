#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};
void viewBSTNode(struct BSTNode *Q)
{
     while(Q)
     {
          viewBSTNode(Q->left);
          printf("\n\t value = %d ",Q->data);
          viewBSTNode(Q->right);
     }
}
struct BSTNode * insertData(struct BSTNode *Q, int data)
{
    struct BSTNode *temp=(struct BSTNode *)malloc(sizeof(struct BSTNode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
     printf("\n\t im here 1 ");
    if(Q==NULL){
        Q=temp;
        printf("\n\t im here %d ",Q->data);
    }
    else
    {
         struct BSTNode *parr=Q;
         while(parr!=NULL)
         {
             if(parr->data>data)
             {
                 if(parr->left==NULL){
                    parr->left=temp;
                    printf("\n\t im here left %d ",(parr->left)->data);
                 }
                  parr=parr->left;
             }
             else if(parr->data<data)
             {
                  if(parr->right==NULL){
                    parr->right=temp;
                    printf("\n\t im here right %d ",(parr->left)->data);
                  }
                  parr=parr->right;
             }
         }

    }
    printf("\n\t  end = %d ",data);
    return Q;
}
int main()
{
    struct BSTNode *Q=NULL;
    Q=insertData(Q,80);
    insertData(Q,70);
    insertData(Q,90);
    viewBSTNode(Q);


}
