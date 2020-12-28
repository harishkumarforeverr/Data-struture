#include<stdio.h>
#include<conio.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_as_a_first_node(){
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    if(!temp){
        printf("\n\t runtiime error ");
        return ;
    }
    printf("\n\t enter a data as a first node : ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else{
        start->prev=temp;
        temp->next=start;
        start=temp;
    }
}
void delete_as_a_firstNode(){
   if(start==NULL){
    printf("\n\t underflow ");
    return ;
   }
   else if(start->next==NULL){
    start=NULL;
   }
   else{
    struct node *r=start;
    start=start->next;
    start->prev=NULL;
    free(r);
    printf("\n\t deletion is done sucessfully ");
   }
}
void view_lastNode(){
   if(start==NULL){
    printf("\n\t list is empty ");
    return ;
   }
   else{
   struct node *t=start;
   printf("\n\t list value : ");
   while(t!=NULL){
        printf("  %d",t->data);
        t=t->next;
    }
   }
}
int main(){
    insert_as_a_first_node();
    insert_as_a_first_node();
    insert_as_a_first_node();
    insert_as_a_first_node();
    delete_as_a_firstNode();
    view_lastNode();
getch();
return 0;
}
