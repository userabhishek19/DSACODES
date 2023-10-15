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

node* binaryTree(node * root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;
    cout << endl;

    if (data == -1) {
        return NULL;
    }

     root = new node(data);

    cout << "Enter the left of the binary Tree " << data << " ";
    root->left = binaryTree(root->left);
    cout << endl;

    cout << "Enter the right of the binary tree " << data << " ";
    root->right = binaryTree(root->right);
    cout << endl;

    return root;
}

void printInorder(node* root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}
int height(node* root){
    if (root==NULL){
        return 0;
    }
    int leftHeight= height(root->left);
    int rightHeight=height(root->right);
     
     int ans= max(leftHeight,rightHeight)+1;
     return ans;


}
void buildleverOrderTraversel(node* &root){
    queue<node*> q;
    int data;
    cout<<"enter the data :"<< " ";
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp= q.front();
        q.pop();
        cout<<"enter the data for the left "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
       if(leftData!=-1){
        temp->left= new node(leftData);
        q.push(temp->left);
       }
         cout<<"enter the data for the right "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
       if(rightData!=-1){
        temp->right= new node(rightData);
        q.push(temp->right);
       }

    
    }
}
void printLevelOftraversal(node* root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* temp=q.front();
    cout<<temp->data<<" ";

    q.pop();
    if(temp->left){
        q.push(temp->left);
    
    }
    if(temp->right){
    }
  }
    

}

int main() {
    node* root = nullptr;
    /* binaryTree(root);
    cout << "Inorder Traversal: ";
    printInorder(root);
    cout << endl;
    int heightBinaryTree= height(root);
    cout<<"the height of your given binary Tree is : "<<heightBinaryTree<<endl;
    */
   buildleverOrderTraversel(root);
  printLevelOftraversal(root);
   return 0;
}
