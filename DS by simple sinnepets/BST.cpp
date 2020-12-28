#include<iostream>
using namespace std;
#define SPACE 10
class TreeNode
{
public :
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v)
    {
        val=v;
        left=NULL;
        right=NULL;
    }
};
class BST
{
public :
    TreeNode *root;
    BST()
    {
        root=NULL;
    }
    bool isTreeEmpty()
    {
        if(root==NULL)
            return true;
        else
            return false;
    }
    void insertNode(TreeNode * new_node)
    {
        if(root==NULL){
            root=new_node;
            printf("\n\t Value Inserted as root node!");
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(temp->val==new_node->val)
                {
                    printf("\n\t duplicate value ");
                    return ;
                }
                else if(temp->val>new_node->val && temp->left==NULL){
                    temp->left=new_node;
                    printf("\n\t Value Inserted as left node!");
                    break;
                }
                else if(temp->val>new_node->val){
                    temp=temp->left;
                }
                else if(temp->val<new_node->val && temp->right==NULL){
                    temp->right=new_node;
                    printf("\n\t Value Inserted as right node!");
                    break;
                }
                else if(temp->val<new_node->val){
                    temp=temp->right;
                }
            }
        }
    }


   void print2D(TreeNode * r, int space) {
       if(r==NULL)
        return ;
      space =space+5;
      print2D(r->right,space);
      cout<<endl;
      for(int i=5;i<space;i++){
        cout<<" ";
      }
      cout<<r->val<<endl;
      print2D(r->left,space);
   }

  void printPreorder(TreeNode * r) //(current node, Left, Right)
  {
      if(r==NULL){
        return ;
      }
      cout<<" "<<r->val;
      printPreorder(r->left);
      printPreorder(r->right);
  }
   void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
      if(r==NULL){
        return ;
      }
      printInorder(r->left);
      cout<<" "<<r->val;
      printInorder(r->right);
  }

  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
      if(r==NULL)
        return ;
      printPostorder(r->left);
      printPostorder(r->right);
      cout<<" "<<r->val;
  }

  TreeNode * iterativeSearch(int v) {
       if(root==NULL){
        return root;
       }
       else{
         TreeNode *temp=root;
              while(temp!=NULL){
                if(temp->val==v)
                    return temp;
                else if(temp->val>v)
                  temp=temp->left;
                else
                  temp=temp->right;
              }
       }
       return NULL;
  }
 TreeNode * recursiveSearch(TreeNode *r, int val) {
    if(r==NULL)
        return NULL;
    if(r->val==val)
    return r;
    else if(r->val>val)
    return recursiveSearch(r->left,val);
    else
    return recursiveSearch(r->right,val);
 }

  int height(TreeNode *r) {
     if(r==NULL)
        return -1;
     else {
        int lheight=height(r->left);
        int rheight=height(r->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return rheight+1;
     }
  }
  void printGivenLevel(TreeNode * r, int level) {
      if(r==NULL)
        return ;
      else if(level==0)
        cout<<" "<<r->val;
      else{
        printGivenLevel(r->left,level-1);
        printGivenLevel(r->right,level-1);
      }
  }
  void printLevelOrderBFS(TreeNode * r)
  {
     int h=height(r);
     for(int i=0;i<=h;i++){
        printGivenLevel(r,i);
     }
  }


 TreeNode * minValueNode(TreeNode * node) {
     TreeNode *ptr=node;
     while(ptr->left!=NULL)
        ptr=ptr->left;
     return ptr;
 }

  TreeNode * deleteNode(TreeNode * r, int v) {
      if(r==NULL)
        return NULL;
      else if(r->val>v){
        r->left=deleteNode(r->left,v);
      }
      else if(r->val<v){
        r->right=deleteNode(r->right,v);
      }
      else{
        if(r->left==NULL)
        {
          TreeNode *temp=r->right;
          delete r;
          return temp;
        }
        else if(r->right==NULL)
        {
           TreeNode *temp=r->right;
           delete r;
           return temp;
        }
        else
        {
          TreeNode *temp=minValueNode(r->right);
          r->val=temp->val;
          r->right=deleteNode(r->right,temp->val);
        }
      }
     return r;
  }
};

int main() {
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
      cin >> val;
      new_node->val = val;
      obj.insertNode(new_node);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root);
      cout << endl;
      	      cout <<"PRE-ORDER: ";
      	      obj.printPreorder(obj.root);
      	      cout<<endl;
      	      cout <<"IN-ORDER: ";
      	      obj.printInorder(obj.root);
      	      cout<<endl;
      	      cout <<"POST-ORDER: ";
      	      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
