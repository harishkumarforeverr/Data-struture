#include<iostream>
using namespace std;

class Node{
 public : int key,data;
          Node *next,*prev;
          Node(){
          key=0;
          data=0;
          prev=NULL;
          next=NULL;
          }
          Node(int k, int d){
          key=k;
          data=d;
          prev=NULL;
          next=NULL;
          }
};
class DoublyLinkedList {
  public : Node *head;
           DoublyLinkedList(){
           head=NULL;
           }
           DoublyLinkedList(Node *n){
           head=n;
           }
  // 1. CHeck if node exists using key value
     Node * nodeExists(int k) {
         Node *temp=NULL;
         Node *ptr=head;
         while(ptr!=NULL){
            if(ptr->key==k) {
             temp=ptr;
             ptr=NULL;
            }
            else{
                ptr=ptr->next;
            }
         }
         return temp;
     }

  // 2. Append a node to the list

  void appendNode(Node * n) {
      if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key, appendNode failed ");
      }
      else if(head==NULL){
        head=n;
        printf("\n\t Node is append as a Head Node ");
      }
      else{
         Node *ptr=head;
         while(ptr->next!=NULL){
            ptr=ptr->next;
         }
         ptr->next=n;
         n->prev=ptr;
        cout << "Node appended" << endl;
      }
  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
      if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key, appendNode failed ");
      }
      else if(head==NULL){
        head=n;
        printf("\n\t Node is preappend as a Head Node ");
      }
      else{
        n->next=head;
        head->prev=n;
        head=n;
      cout << "Node Prepended" << endl;
      }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node *ptr=nodeExists(k);
    if(ptr==NULL){
        printf("\n\t no Node eixst with key value : %d",k);
    }
    else {
        if(nodeExists(n->key)!=NULL){
        printf("\n\t duplicate key, appendNode failed ");
        }
        // if node is inserted at end
        else if(ptr->next==NULL){
          ptr->next=n;
          n->prev=ptr;
      cout << "\n\t Node Inserted at the END" ;

        }
        // inserted at middle
        else{
           n->prev=ptr;//3
           n->next=ptr->next;//1
           ptr->next->prev=n;//2
           ptr->next=n;//4
           printf("\n\t Node Inserted in Between");
        }
    }
  }


  // 5. Delete node by unique key. Basically De-Link not delete
  void deleteNodeByKey(int k) {
      Node *rNode;
    // if key is workong
    Node *ptr=nodeExists(k);
    rNode=ptr;
    if(ptr==NULL){
        printf("\n\t no Node eixst with key value : %d",k);
    }
    else{
      // if node as a first node
      if(head->key==k){
        rNode=head;
        head=head->next;
        delete rNode;
      }
      // if node as a middle nodee
      else if(ptr->next==NULL){
          ptr->prev->next=NULL;
          delete rNode;
          printf("\n\t Node Deleted at the END");
      }
      // if node as aa end node
      else {
         ptr->prev->next=ptr->next;
         ptr->next->prev=ptr->prev;
         delete rNode;
         printf("\n\t Node Deleted in Between");
      }
    }
  }


  // 6th update node
  void updateNodeByKey(int k, int d) {
    Node *ptr=nodeExists(k);
    if(ptr!=NULL){
    ptr->data=d;
    printf("Node Data Updated Successfully");
    }
    else{
    printf("\n\t no Node eixst with key value : %d",k);
    }
  }

  // 7th printing
  void printList() {
      if(head==NULL){
        printf("\n\t lisst is empty ");
        return;
      }else{
       Node *ptr=head;
       while(ptr!=NULL){
        printf("( %d, %d ) <--> ",ptr->key,ptr->data);
        ptr=ptr->next;
       }
       printf(" NULL ");
      }
  }
};


int main() {

  DoublyLinkedList obj;
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
