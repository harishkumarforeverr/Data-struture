#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayStack{
 int top;
 int capacity;
 int *array;
};
struct arrayStack * createarrayStack(int capacity){
    struct arrayStack *stack=(struct arrayStack *)malloc(sizeof(struct arrayStack));
    if(!stack){
        printf("\n\t runtime error ");
        return NULL;
    }
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int *)malloc(sizeof(int)*stack->capacity);
    return stack;
}
int isStackFull(struct arrayStack *stack){
   if(stack->top==stack->capacity-1)
    return 1;
   else
    return 0;
}
int isEmptyStack(struct arrayStack *stack){
  if(stack->top==-1)
    return 1;
  else
    return 0;
}
void push(struct arrayStack *stack, int data){
   if(isStackFull(stack))
    printf("\n\t overflow");
   else{
    stack->top=stack->top+1;
    stack->array[stack->top]=data;
   }
}
void pop(struct arrayStack *stack){
  if(isEmptyStack(stack)){
    printf("\n\t underflow ");
  }
  else{
    stack->top=stack->top-1;
  }
}
void view(struct arrayStack *stack){
  if(isEmptyStack(stack)){
    printf("\n\t stack is empty ");
  }
  else{
      printf("\n\t stack value : ");
      for(int i=0;i<=stack->top;i++){
        printf("%d ",stack->array[i]);
      }
  }
}
int main(){
  struct arrayStack *stack=createarrayStack(4);
  push(stack,10);
  push(stack,20);
  push(stack,30);
  push(stack,40);
  push(stack,50);
  push(stack,60);
  view(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  pop(stack);
  view(stack);
getch();
return 0;
}


