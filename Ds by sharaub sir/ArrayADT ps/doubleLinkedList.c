s#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 struct node {
   struct node *prev;
   int data;
   struct node *next;
 };

 void insert_A_Node(struct node **s,int data){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->prev=NULL;
    t->next=*s;
    if(*s==NULL)
        *s=t;
    else{
    (*s)->prev=t;
    *s=t;
    }
 }

 void view_my_list(struct node **s){
   struct node *t=*s;
   printf("\n\t list values  left to right : ");
    while(t!=NULL){
        printf(" %d",t->data);
        t=t->next;
    }
//    t=*s;
//    printf("\n\t list values  right to left : ");
//    while(t->next!=NULL){
//        t=t->next;
//    }
//    while(t!=NULL){
//        printf(" %d",t->data);
//        t=t->prev;
//    }
 }
 void insert_At_Lasr(struct node **s, int data){
     struct node *temp=(struct node *)malloc(sizeof(struct node ));
     temp->data=data;
     temp->next=NULL;
     temp->prev=NULL;
    if(*s==NULL){
     *s=temp;
    }
    else{
        struct node *t=*s;
        while(t->next!=NULL)
        t=t->next;
        t->next=temp;
        temp->prev=t;
    }
 }

 void insert_After_A_Node(struct node **s,struct node *ptr, int data){
     if(ptr==NULL){
        printf("\n\t invalid insertion of a Node ");
        return ;
     }
     struct node *t=(struct node *)malloc(sizeof(struct node ));
     t->data=data;
     t->prev=ptr;
     t->next=ptr->next;
     if(ptr->prev==NULL){
        ptr->next->prev=t;
        (*s)->next=t;
     }
     else if(ptr->next==NULL){
        ptr->next=t;
     }
     else{
        ptr->next->prev=t;
        ptr->next=t;
     }
 }
 struct node * find_the_current_Node(struct node **s, int data){
    if(*s==NULL){
        printf("\n\t underflow ");
        return NULL;
    }
    else{
        struct node *t=*s;
        while(t!=NULL){
        if(t->data==data)
        return t;
         t=t->next;
        }
        return NULL;
    }
 }
void delete_firstNode(struct node **s){
     if(*s==NULL){
        printf("\n\t list is empty ");
     }
     else{
        struct node *temp=*s;
        (*s)=(*s)->next;
        (*s)->prev=NULL;
        free(temp);
        printf("\n\t deletion is sucessfull ");
     }
}
void delete_lastNode(struct node **s){
    if(*s==NULL){
    printf("\n\t list is empty ");
    }
    else{
    struct node *t=*s;
    while(t->next!=NULL)
     t=t->next;
     if((*s)->next==NULL)
        *s=NULL;
     else
     t->prev->next=NULL;
     free(t);
     printf("\n\t deletion is sucessfull ");
     }
}
void delete_a_praticular_node(struct node **s, struct node *ptr){
    struct node *temp=*s;
    if(*s==NULL){
    printf("\n\t list is empty ");
    }
    else{
         if(temp->prev==NULL){
            (*s)=(*s)->next;
             (*s)->prev=NULL;
             free(temp);
             printf("\n\t deletion is sucessfull 1");
         }
         else if(ptr->next==NULL){
              ptr->prev->next=NULL;
              free(ptr);
              printf("\n\t deletion is sucessfull 2");
         }
         else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
         }
    }

}
int get_first_value(struct node **s){
    if((*s)==NULL){
        printf("\n\t underflow ");
    }
    else
      return ((*s)->data);
}
int get_last_value(struct node **s){
     struct node *temp=*s;
     if((*s)==NULL){
        printf("\n\t underflow ");
     }
     else{
        while(temp->next!=NULL)
            temp=temp->next;
        return (temp->data);
     }
}
 /*    insert_A_Node
 //    insert_At_Lasr
 //    insert_After_A_Node
 //     find_the_current_Node
        delete_firstNode
        delete_lastNode
        delete_a_praticular_node
        get_first_value
        get_last_value
 */
 int main(){
       struct node *start=NULL;
       struct node *ptr=NULL;
       insert_A_Node(&start,30);
       insert_A_Node(&start,20);
       insert_A_Node(&start,10);
       insert_At_Lasr(&start,40);
       insert_At_Lasr(&start,50);
       insert_At_Lasr(&start,60);
       ptr=find_the_current_Node(&start,20);
       insert_After_A_Node(&start,ptr,25);
       view_my_list(&start);
       delete_firstNode(&start);
       view_my_list(&start);
       delete_lastNode(&start);
       view_my_list(&start);
       ptr=find_the_current_Node(&start,30);
       delete_a_praticular_node(&start,ptr);
       view_my_list(&start);
       printf("\n\t 1st value in the list : %d ",get_first_value(&start));
       printf("\n\t last value in the list : %d ",get_last_value(&start));
 getch();
 return 0;
 }

