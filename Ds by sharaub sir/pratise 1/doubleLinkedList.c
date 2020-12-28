#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *start=NULL;
void iatfirst()
{
    int data;
    printf("\n\t enter a no = ");
    scanf("%d",&data);
    struct node *start1=(struct node *)malloc(sizeof(struct node));
    start1->next=NULL;
    start1->prev=NULL;
    start1->data=data;
    if(start==NULL)
        start=start1;
    else
    {
        start1->next=start;
        start->prev=start1;
        start=start1;
    }
}
void view()
{
    if(start==NULL)
    {
        printf("\n\t list is empty");
        return ;
    }
    else
    {
        struct node *temp;
        temp=start;
        printf("\n\t Data = ");
        while(temp!=NULL)
        {
        printf("%d ",temp->data);
        temp=temp->next;
        }
    }
}
void deleteAtFirst()
{
    if(start==NULL)
    {
        printf("\n\t list is empty ");
        return ;
    }
    else
    {
        start=start->next;
        start->prev=NULL;
    }

}
int main()
{
    for(int i=0;i<5;i++)
    iatfirst();
    view();
    for(int i=0;i<2;i++)
    deleteAtFirst();
    view();

}
