#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    private : struct node
    {
        int item;
        node *next;
    };
    node *start;
    node * search(int data)
    {

        node *t;
        if(start==NULL)
            return NULL;
        t=start;
        while(t!=NULL)
        {
            if(t->item==data)
                return t;
            t=t->next;
        }
        return NULL;
    }
    public : A()
    {
        start=NULL;
    }
    void insertatfirst(int currdata)
    {
        node *t=new node;
        t->item=currdata;
        t->next=start;
        start=t;
    }
    void insertatlast(int data)
    {
        node *t,*n=new node;
        n->item=data;
        n->next=NULL;
        if(start==NULL)
            start=n;
        else
        {
            t=start;
            while(t->next!=NULL)
                t=t->next;
            t->next=n;
        }
    }
    void insertafter(int currdata, int data)
    {
        node *t=search(currdata);
        if(t==NULL)
            cout<<"\n\t insertion is not possible ";
        else{
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
        }
    }
    int deleteitemfromstart()
    {
        if(start==NULL)
        {
            cout<<"\n\t underflow ";
            return 0;
        }
        else
        {
            node *r=start;
            start=start->next;
            delete r;
            return 1;
        }
    }
   int deleteiteamfromlast()
   {

           if(start==NULL)
           {
            cout<<"\n\t overflow ";
            return 0;
           }
           if(start->next==NULL)
           {
               delete start;
               start=NULL;
               return 1;
           }
           node *t1,*t2;
           t1=t2=start;
           do
           {
               t2=t1;
               t1=t1->next;
           }while(t1->next!=NULL);
           delete t1;
           t2->next=NULL;
   }
   int deletefromcurrentitem(int currdata)
   {
       node *t=search(currdata);
       if(t==NULL)
       {
           cout<<"\n\t no such data is found ";
           return 0;
       }
       if(t->next==NULL)
        {
        deleteiteamfromlast();
       return 1;
        }
        while(t->next!=NULL)
        {
            t->item=(t->next)->item;
            t=t->next;
        }
        deleteiteamfromlast();
        return 1;
   }
   void edititem(int currdata,int data)
   {

       node *r=search(currdata);
       if(r==NULL)
       {
           cout<<"\n\t no such data is found ";
           return ;
       }
       else
       {
           r->item=data;
       }
   }
   int countitem()
   {
       int count=0;
       node *t;
       t=start;
       while(t!=NULL)
       {
           count++;
           t=t->next;
       }
       return count;
   }
   int getfirstitem()
   {
       if(start==NULL)
       {
           cout<<"\n\t list is empty ";
           return 0;
       }
       return (start->item);
   }
   int getlastiem()
   {
       if(start==NULL)
       {
           cout<<"\n\t list is empty ";
           return 0;
       }
       else{
        node *t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        return (t->item);
       }
   }
   void viewitem()
   {
       if(start==NULL)
       {
           cout<<"\n\t list is empty() ";
       }
       else{
            cout<<"\n\t values are = ";
        node *t=start;
        while(t!=NULL)
        {
            cout<<" "<<t->item;
            t=t->next;
        }
       }
   }
    int searchitem(int currdata)
    {

        if(start==NULL)
        {
           cout<<"\n\t list is empty ";
           return 0;
        }
        else
        {
            node *t=start;
            while(t!=NULL)
            {
                if(t->item==currdata)
                return 1;
                t=t->next;
            }
            return 0;
        }
    }
    void sortlist()
    {
        if(start==NULL)
        {
            cout<<"\n\t list is empty";
            return ;
        }
        else
        {
            node *t;
            int n=countitem();
            for(int i=0;i<=n-1;i++)
            {
                t=start;
                for(int j=0;j<=n-i-1;j++)
                {
                    if((t->item)>((t->next)->item))
                    {
                        int temp=t->item;
                        t->item=(t->next)->item;
                        (t->next)->item=temp;
                        cout<<"\n\t values swapped : "<< t->item<<" "<<(t->next)->item<<" i and j value "<<i<<ends<<j;
                    }
                    t=t->next;
                }
                cout<<" 1 loop itreation is completed ";
            }
        }
    }

};
int main()
{
  A o;
  o.viewitem();
  o.insertatfirst(9);
  o.insertatlast(1);
  o.insertatlast(6);
  o.insertatlast(3);
  o.insertatlast(4);
  o.insertatlast(8);
  o.insertatlast(18);
  o.insertatlast(14);
  o.insertatlast(114);
  o.insertatlast(16);
  o.viewitem();
  o.insertafter(1,11);
  o.viewitem();
  o.deleteitemfromstart();
  o.viewitem();
  o.deleteitemfromstart();
  o.viewitem();
  o.deleteiteamfromlast();
  o.viewitem();
  o.deleteiteamfromlast();
  o.viewitem();
  o.deletefromcurrentitem(8);
  o.viewitem();
  o.edititem(3,21);
  o.viewitem();
  cout<<"\n\t no of iteams are = "<<o.countitem();
  cout<<"\n\t 1st item in the list is = "<<o.getfirstitem();
  cout<<"\n\t last item in the list is = "<<o.getlastiem();
  if(o.searchitem(11))
    cout<<"\n\t elements is found ";
  else
  cout<<"\n\t elements is NOT found ";
  if(o.searchitem(24))
    cout<<"\n\t elements is found ";
  else
  cout<<"\n\t elements is NOT found ";
  o.sortlist();
  o.viewitem();


}
