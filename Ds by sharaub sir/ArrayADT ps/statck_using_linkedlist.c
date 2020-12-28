#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
struct node * createNode(){
   struct node *temp=(struct node *)malloc(sizeof(struct node ));
   return temp;
}
void push(struct node **s , int data){
     struct node *temp=createNode();
     if(temp){
     temp->data=data;
     temp->next=*s;
     (*s)=temp;
     }
     else{
        printf("\n\t runtime error ");
     }
}
int peek_firstValue(struct node **s){
    if(*s==NULL){
       printf("underflow 1");
        return -1;
    }
    else
        return ((*s)->data);
}
void pop(struct node **s){
    if(*s==NULL){
       printf("underflow 1");
        return ;
    }
    else{
        struct node *t=*s;
        if((*s)->next==NULL){
            *s=NULL;
        }
        else
        (*s)=(*s)->next;
         free(t);

    }
}
void remove_statk(struct node **s){
    while(*s!=NULL)
        pop(s);
}
int main(){
  struct node *stack=NULL;
  push(&stack,10);
  push(&stack,20);
  push(&stack,30);
  push(&stack,40);
  printf("\n\t value at 1st : %d",peek_firstValue(&stack));
  pop(&stack);
  remove_statk(&stack);
  }





















