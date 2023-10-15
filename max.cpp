#include<iostream>
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

node* binaryTree() {
    int data;
    cout << "Enter the data: ";
    cin >> data;
    cout << endl;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);

    cout << "Enter the left of the binary Tree " << data << " ";
    root->left = binaryTree();
    cout << endl;

    cout << "Enter the right of the binary tree " << data << " ";
    root->right = binaryTree();
    cout << endl;

    return root;
}

int sum(node* root) {
    if (root == NULL) {
        return 0; 
    }
    
    int sumLeft = sum(root->left); 
    int sumRight = sum(root->right);
    int ans = sumLeft + sumRight + root->data;
    return ans;
}
int maxT(node* root,int d){
    if(root==NULL){
        return;
    }
    if(d==1){
     
    }
  

}
int sumLeft(node* root){
    if(root==NULL){
        return 0;
    }
    int sumLeft=sum(root->left);
    int ans=sumLeft+root->data;
    return sumLeft;
}
int SumRight(node* root){
    if(root==NULL){
        return 0;
    }
    int SumRight=sum(root->right);
    int ans=SumRight+root->data;
    return SumRight;
}

int main() {
    node* root = binaryTree();
    int totalSum = sum(root);
    cout << "Sum of all elements in the tree is: " << totalSum << endl;
    cout<<"sum of left elementts in the tree isl "<<sumLeft(root)<<endl;  
    cout<<"sum of right elementts in the tree isl "<<SumRight(root)<<endl;  

    return 0;
}
