#include<iostream>
using namespace std;
class Node
{
public :
    int key,data;
    Node *next;
    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k, int d)
    {
        key=k;
        data=d;
    }
};
class singleLinkedList
{
public :
    Node *head;
    singleLinkedList()
    {
        head=NULL;
    }
    singleLinkedList(Node *n)
    {
        head=n;
    }

    // 1. CHeck if node exists using key value};
    Node * nodeExists(int k)
    {
        Node *t=NULL,*temp=head;
        while(temp!=NULL){
            if(temp->key==k){
                t=temp;
                return t;
            }
            temp=temp->next;
        }
        return t;
    }
    // 2. Append a node to the list
    void appendNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            printf("\n\t dupliacte key values : insert a data with new key Value ");
        }
        else if(head==NULL)
        {
            head=n;
            printf("\n\t Node is inserted as a Head Node ");
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            printf("\n\t Node is append ");
        }
    }
    // 3. Prepend Node - Attach a node at the start
    void prependNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            printf("\n\t dupliacte key values : insert a data with new key Value ");
        }
        else
        {
            n->next=head;
            head=n;
        }
    }

    // 4. Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node * n)
    {
        Node *ptr=nodeExists(k);
        if(ptr==NULL)
        {
            printf("\n\t invalid key you passed");
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                printf("\n\t dupliacte key values : insert a data with new key Value ");
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                printf("\n\t Node Inserted");
            }
        }
    }

    // 5. Delete node by unique key
    void deleteNodeByKey(int k)
    {
        if(head==NULL)
        {
            printf("\n\t list is empty ");
            return ;
        }
        else
        {
            Node *rNode=NULL;
            if(head->key==k)
            {
                rNode=head;
                head=head->next;
                delete rNode;
                cout << "\n\t Node UNLINKED with keys value : " << k ;
            }
            else
            {
              Node *temp=NULL;
              Node *cptr=head->next;
              Node *pptr=head;
              while(cptr!=NULL){
                if(cptr->key==k)
                {
                 temp=cptr;
                 cptr=NULL;
                }
                else{
                 pptr=pptr->next;
                 cptr=cptr->next;
                }
              }
              if(temp!=NULL){
                pptr->next=temp->next;
                delete temp;
              }
              else{
                cout << "\n\t Node Doesn't exist with key value : " << k;
              }
            }
        }
    }

  // 6th update node
  void updateNodeByKey(int k, int d) {
      Node *temp=nodeExists(k);
      if(temp!=NULL){
        temp->data=d;
        cout << "\n\t Node Data Updated Successfully" ;
      }
      else{
         cout << "\n\t Node Doesn't exist with key value : " << k ;
      }
  }
  // 7th printing
  void printList() {
      if(head==NULL){
        printf("\n\t list is empty ");
      }
      else{
        Node *temp=head;
        while(temp!=NULL){
            cout<<"("<<temp->key<<","<<temp->data<<") --> ";
        temp=temp->next;
        }
        cout<<" NULL ";
      }
  }
};

int main() {

  singleLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      n1->next=NULL;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      n1->next=NULL;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      n1->next=NULL;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
























