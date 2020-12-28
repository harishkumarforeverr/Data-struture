#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayADY{
  int capacity;
  int lastIndes;
  int *ptr;
};
struct arrayADY * create_arrayADT(int capacity){
    struct arrayADY *arr=(struct arrayADY *)malloc(sizeof(struct arrayADY));
    if(!arr){
        printf("\n\t runtime error ");
        return NULL;
    }
    arr->capacity=capacity;
    arr->lastIndes=-1;
    arr->ptr=(int *)malloc(sizeof(int)*arr->capacity);
    if(!arr->ptr){
        printf("\n\t runtime error ");
        return NULL ;
    }
    return arr;
}
void insert_a_value_at_given_index(struct arrayADY *arr, int index, int value){
      if(arr==NULL){
        printf("\n\t ArrayADT is not created Run-time Error ");
        return ;
      }
      else if(arr->lastIndes==arr->capacity-1){
        printf("\n\t overflow ");
        return ;
      }
      else if(index<0|| index>arr->lastIndes+1){
        printf("\n\t invalid index  ");
        return ;
      }
      else if(index==arr->lastIndes+1){
        arr->lastIndes=arr->lastIndes+1;
        arr->ptr[arr->lastIndes]=value;
      }
      else{
        arr->lastIndes=arr->lastIndes+1;
        int i=arr->lastIndes;
        while(i!=index){
            arr->ptr[i]=arr->ptr[i-1];
            i--;
        }
        arr->ptr[index]=value;
      }
}
int count_no_of_item_in_arrayADT(struct arrayADY *arr){
    if(arr==NULL){
        printf("\n\t ArrayADT is not created Run-time Error ");
        return 0;
    }
    else
        return (arr->lastIndes+1);
}
void view_arrayADT(struct arrayADY *arr){
    if(arr==NULL){
        printf("\n\t ArrayADT is not created Run-time Error ");
        return ;
    }
    else{
        printf("\n\t array valeus : ");
        for(int i=0;i<count_no_of_item_in_arrayADT(arr);i++){
            printf(" %d ",arr->ptr[i]);
        }
    }
}
int get_a_item_by_index(struct arrayADY *arr,int index ){
    if(index<0|| index>arr->lastIndes){
        // 1>4 2>4 3>4 4>4 false
        // 5>4 true
        printf("\n\t invalid Index to retturn a  value ");
        return 0;
    }
    else{
        return arr->ptr[index];
    }
}
int edit_a_item_by_index(struct arrayADY *arr,int index , int value){
    if(index<0|| index>arr->lastIndes){
        // 1>4 2>4 3>4 4>4 false
        // 5>4 true
        printf("\n\t invalid Index to perfrom insertion ");
        return 0;
    }
    else{
            arr->ptr[index]=value;
            printf("\n\t updating a value at given insdex is successfull ");
           return 1;
    }
}
void remove_a_item_at_given_index(struct arrayADY *arr, int index){
    if(index<0|| index>arr->lastIndes){
        // 1>4 2>4 3>4 4>4 false
        // 5>4 true
        printf("\n\t invalid Index to perfrom deletion ");
        return ;
    }
    else{
        if(index==arr->lastIndes){
            arr->lastIndes=arr->lastIndes-1;
            printf("\n\t deletion is sucessfulll ");
        }
        else{
            int i=index;
            while(i<arr->lastIndes){
                // lastindex 3 and index 2
                // 2<3 OK
                // 3<3 False and no problem
                arr->ptr[i]=arr->ptr[i+1];
                i++;
            }
            arr->lastIndes=arr->lastIndes-1;
            printf("\n\t deletion is sucessfulll ");
        }
    }
}
void find_the_element_by_passing_value(struct arrayADY *arr, int value ){
    if(arr->lastIndes==-1){
        printf("\n\t list is empty to perform finding operation ");
        return ;
    }
    else{
        for(int i=0;i<=arr->lastIndes;i++)
            if(arr->ptr[i]==value){
            printf("\n\t value is found at : %d index ",(i+1));
           return ;
           }
         printf("\n\t element is not found  searching failed ");;
    }
}
void sortion_the_array_elements(struct arrayADY *arr){
    for(int i=0;i<arr->lastIndes;i++){
        for(int j=0;j<arr->lastIndes-i;j++){
            if(arr->ptr[j]>arr->ptr[j+1]){
                int t=arr->ptr[j];
                arr->ptr[j]=arr->ptr[j+1];
                arr->ptr[j+1]=t;
            }
        }
    }
}
/*
create_arrayADT
insert_a_value_at_given_index
count_no_of_item_in_arrayADT
view_arrayADT
get_a_item_by_index
edit_a_item_by_index
remove_a_item_at_given_index
find_the_element_by_passing_value
sortion_the_array_elements
*/
int main(){
    struct arrayADY *arr=create_arrayADT(7);
    insert_a_value_at_given_index(arr,0,9);
    insert_a_value_at_given_index(arr,1,0) ;
    insert_a_value_at_given_index(arr,2,6) ;
    insert_a_value_at_given_index(arr,3,3) ;
    insert_a_value_at_given_index(arr,4,4) ;
    insert_a_value_at_given_index(arr,5,8) ;
    insert_a_value_at_given_index(arr,6,1) ;
    insert_a_value_at_given_index(arr,7,5) ;
    insert_a_value_at_given_index(arr,8,10) ;

    view_arrayADT(arr);
    printf("\n\t search result of a item : %d ",get_a_item_by_index(arr,2));
    view_arrayADT(arr);
    edit_a_item_by_index(arr,0,25);
    view_arrayADT(arr);
    remove_a_item_at_given_index(arr,0);
    view_arrayADT(arr);
    find_the_element_by_passing_value(arr,3);

    sortion_the_array_elements(arr);
    view_arrayADT(arr);
    getch();
    return 0;
}
