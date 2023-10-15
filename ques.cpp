/*Q1.WAP to insert 10,20,30, 40, 50, 60, 70, 75, 80 in the given sequence in a BST. Given the root node as an
argument,Write a function recursive/non recursive to return height of the tree. WAP to find below traversals
of a given root node in a non-recursive manner.
A) Inorder
B) Preorder
C) Post order
D) Level order
*/
#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertAtBst(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertAtBst(root->right, d);
    }
    else {
        root->left = insertAtBst(root->left, d);
    }
    return root;
}

void input(node*& root) {
    int data;
    cin >> data;
    
    while (data != -1) {
        root = insertAtBst(root, data);
        cin >> data; // Read the next data element
    }
}
void printlevelOrder(node* root){
    if(!root){
        return ;
    }
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int sizeOfTree= q.size();
        for(int i=0;i<sizeOfTree;i++){
            node* temp= q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);

            }
            if(temp->right){
                q.push(temp->right);
            }
        
        }
        cout<<endl;

    }

}
void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
   printInorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    
   postorder(root->right);
   cout<<root->data<<" ";
}
void pre(node* root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" ";
    pre(root->left);
    
   pre(root->right);
  
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
int left= height(root->left);
int right= height(root->right);
int ans= max(left,right)+1;
return ans;


}
bool isbalance(node* root){
    if(root==NULL){
        return false;
    }
    int left=height(root->left);
    int right= height(root->right);
  bool tot=abs(height(root->left)-height(root->right))<=1;
  if(left && right && tot){
    return true;
  }else
  return false;

}
node* minval(node* root){
     node* temp= root;
    if(temp== NULL){
        return 0;
    }
    while(temp!=NULL){
   temp->left= minval(temp->left);
    }
    return temp;
}
node* deleteFromBst(node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left && root->right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left !=NULL && root->right == NULL){
            node* temp= root->left;
            delete root;
            return temp;
        }
       if(root->right !=NULL && root->left == NULL){
            node* temp= root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right)->right;
            root->data= mini;
            root->right= deleteFromBst(root->right,mini);
        }

    }else if(root->data>val){
        root->left = deleteFromBst(root->left,val);
        return root;
    }else{
        root->right = deleteFromBst(root->right);
        return root;
    }
}
int main() {
    node* root = NULL;
    cout << "Enter the BST tree data (-1 to stop input): ";
    input(root);      
    cout << endl;
    printlevelOrder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    pre(root);
    cout<<endl;
    int treeHeight= height(root);
    cout<<"the height of the tree is: "<<treeHeight<<endl;
  int balnce= bool(root);
  if(balnce==true){
      cout<<"the node is balanced "<<endl;

  }else{
    cout<<"the node is not balanced"<<endl;
  }
  minval(root);


    return 0;
}
