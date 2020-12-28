#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void insert_the_node(struct node **root, int data){
   struct node *temp=(struct node *)malloc(sizeof(struct node ));
   struct node *t=*root;
   if(!temp){
    printf("\n\t runtime error ");
    return ;
   }
   temp->data=data;
   temp->left=temp->right=NULL;
   if(t==NULL){
    (*root)=temp;
   }
   else{
    struct node *parent=*root;
       while(parent!=NULL){

          if(data>parent->data){
               if(parent->right==NULL){
                parent->right=temp;
                parent=parent->right->right;
               }
               else
               parent=parent->right;
          }
          else if(data<parent->data){
            if(parent->left==NULL){
                parent->left=temp;
                parent=parent->left->left;
            }
            else
            parent=parent->left;
          }
       }
   }
}
void preOrder(struct node *root){
  if(root){
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void inOrder(struct node *root){
  if(root){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}
int main(){
    struct node *root=NULL;
     insert_the_node(&root,80);
     insert_the_node(&root,70);
     insert_the_node(&root,90);
     insert_the_node(&root,30);
     insert_the_node(&root,75);
     insert_the_node(&root,85);
     insert_the_node(&root,95);
     printf("\n\t values : ");
     inOrder(root);
 getch();
 return 0;
}
