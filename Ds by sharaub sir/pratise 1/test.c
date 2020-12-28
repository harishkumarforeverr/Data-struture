  #include<stdio.h>
  #include<conio.h>
void swap(char *a, char *b)
{
    char t=*a;
     *a=*b;
     *b=t;
}
  int main()
  {
     char a[]="harish";
     char b[]="forever";
     printf("\n\t before swaping = %s and %s ",a,b);
     swap(a,b);
     printf("\n\t After swaping = %s and %s ",a,b);


  }
