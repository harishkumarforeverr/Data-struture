#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int top;
 int capacity;
 int *arr;
};
struct node * createStack(int capacity)
{
    struct node *stack=(struct node *)malloc(sizeof(struct node));
    stack->top=-1;
    stack->capacity=capacity;
    stack->arr=(int *)malloc(sizeof(int)*capacity);
    return stack;
}
int  isFull(struct node *stack)
{
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct node *stack)
{
    if( stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct node *stack)
{
    if(isFull(stack))
    {
        printf("\n\t overflow ");
        return ;
    }
    else
    {
        int data;
        scanf("%d",&data);
        stack->top++;
        stack->arr[stack->top]=data;
    }
}
void pop(struct node *stack)
{
    if(isEmpty(stack))
    {
            printf("\n\t underflow ");
            return ;
    }
    else
    {
        printf("\n\t value deleted = %d ",stack->arr[ stack->top]);
        stack->top--;
    }
}
void view(struct node *stack)
{
    if(isEmpty(stack))
    {
        printf("\n\t list is empty ");
        return ;
    }
    else
    {
      for(int i=0;i<=stack->top;i++)
      {
          printf("\n\t values in the list are = %d ",stack->arr[i]);
      }
    }
}
int main()
{
    struct node *n=createStack(5);
    printf("\n\t enter the value = ");
    for(int i=0;i<5;i++)
    push(n);
    view(n);
    for(int i=0;i<3;i++)
    pop(n);
    view(n);
}
