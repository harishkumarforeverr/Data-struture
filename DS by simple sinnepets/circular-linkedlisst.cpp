#include<iostream>
using namespace std;
class Node{
  public : int data,key;
           Node *next;
           Node(){
           data=0;
           key=0;
           next=NULL;
           }
           Node(int k, int d){
           key=k;
           data=d;
           next=NULL;
           }
};
class CircularLinkedList{
   public : Node *head;
           CircularLinkedList(){
           head=NULL;
           }
           CircularLinkedList(Node *n){
           head=n;
           n->next=head;
           }

   // 1. CHeck if node exists using key value
    Node * nodeExists(int k) {
    Node *ptr=head;
    Node *temp=NULL;
    if(head==NULL){
    return temp;
    }
    else {
        do{
            if(ptr->key==k){
                temp=ptr;
                ptr=head;
            }
            else{
                ptr=ptr->next;
            }
        }while(ptr!=head);
        return temp;
    }
   }

  // 2. Append a node to the list
  void appendNode(Node * n) {
      if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key entry  ");
        return ;
      }
      else {

       if(head==NULL){
        head=n;
        head->next=n;
        printf("\n\t Node is append as a head Node ");
      }

      else {
        Node *ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        n->next=head;
        ptr->next=n;
        printf("\n\t Node Appended");
      }
      }
  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
      if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key entry  ");
      }
      else {
      if(head==NULL){
        head=n;
        head->next=n;
        printf("\n\t Node is prepend as a head Node ");
      }
      else{
        Node *ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=head;
        head=n;
        printf("\n\t Node Prepended");
      }
    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
   Node *ptr=nodeExists(k);
   if(ptr==NULL){
    printf("\n\t invalid key , insert a node after a praticular key is failed ");
   }
   else {
      if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key entry  ");
      }
      else {
        // if the ptr is single || if the ptr is at end
          if(ptr->next==head){
           n->next=head;
           ptr->next=n;
           printf("\n\t Node Inserted at the End");
          }
        // if the ptr is at middle
           else {
             n->next=ptr->next;
             ptr->next=n;
             printf("\n\t Node Inserted in between");
           }
      }
   }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    Node *ptr=nodeExists(k);
    if(ptr==NULL){
     printf("\n\t invalid key , insert a node after a praticular key is failed ");
    }
    else {
        Node *cptr=head;
         while(cptr->next!=ptr){
            cptr=cptr->next;
         }
         Node *lNode=head;
         while(lNode->next!=head){
            lNode=lNode->next;
         }
        // ptr is a single node
        if(ptr->next==head && head->next==head){
          printf("\n\t only a single Node present i.e Head Node, deleted ");
          delete head;
          head=NULL;
        }
         // if the node is to deleted as a 1st Ndde and remaing node are left as is it
        else if(head->key==k){
           Node *t=head;
           head=head->next;
           lNode->next=head;
           delete t;
         }
        // if ptr is a last Node
         else if(ptr->next==head){
          cptr->next=head;
          delete ptr;
        }
        // if ptr is a middle node
        else {
            cptr->next=ptr->next;
            delete ptr;
        }
    }
  }

  // 6th update node
  void updateNodeByKey(int k, int new_data) {
    Node *ptr=nodeExists(k);
    if(ptr==NULL){
     printf("\n\t invalid key , updating a Node is failed ");
    }
    else{
     ptr->data=new_data;
    }
  }


  // 7th printing
  void printList() {
      if(head==NULL){
        printf("\n\t list is empty ");
      }
      else{
        Node *ptr=head;
        printf("\n\t ");
        while(ptr->next!=head){
            printf(" ( %d, %d ) --> ",ptr->key,ptr->data);
            ptr=ptr->next;
        }
        printf(" ( %d, %d )  --> NULL ",ptr->key,ptr->data);
      }
  }

};



int main() {

  CircularLinkedList obj;
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
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

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

