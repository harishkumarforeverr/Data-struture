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
void inOrder(struct node *root){
  if(root){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}
struct node * findTheNode(struct node *root, int data){
   if(root==NULL)
    return NULL;
   else if(data>root->data)
    return (findTheNode(root->right,data));
   else if (data<root->data)
    return (findTheNode(root->left,data));
   else
    return root;
}
struct node * findMaxNode(struct node *root){
    struct node *t=root;
    while(t&&t->right)
        t=t->right;
    return t;
}
struct node * delete_the_node(struct node *root, int data){
    if(root==NULL)
        printf("\n\t list is empty ");
    else if(data>root->data)
        root->right=delete_the_node(root->right,data);
    else if(data<root->data)
        root->left=delete_the_node(root->left,data);
    else{
       struct node *t;
        if(root->left&&root->right){
            t=findMaxNode(root->left);
            root->data=t->data;
            root->left=delete_the_node(root->left,root->data);
        }else{
           t=root;
            if(root->left==NULL){
                root=root->right;
                free(t);
            }
            else if(root->right==NULL){
                root=root->left;
                free(t);
            }
        }
    }
    return root;
}
int main(){
    struct node *root=NULL;
    struct node *temp=NULL;
    insert_the_node(&root,80);
    insert_the_node(&root,70);
    insert_the_node(&root,90);
    insert_the_node(&root,30);
    insert_the_node(&root,75);
    insert_the_node(&root,85);
    insert_the_node(&root,95);
    insert_the_node(&root,25);
    printf("\n\t values : ");
    inOrder(root);
    temp=findTheNode(root,75);
    if(temp)
        printf("\n\t data is found and seaching operation is successfull ");
    else
        printf("\n\t data is NOT found and seaching operation is failed ");
   root=delete_the_node(root,90);
    printf("\n\t values : ");
    inOrder(root);
 getch();
 return 0;
}
