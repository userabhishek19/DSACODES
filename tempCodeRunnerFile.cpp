#include<iostream>
#include<string>
using namespace std;


class node {
public:
    string data;
    node* left;
    node* right;
    bool isThreaded;
    node(string data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->isThreaded=false;
    }
};
node* buildThreadedInorderTree(string arr[], int s, int e, node* prev){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=buildThreadedInorderTree(arr,s,mid-1,prev);
    if(prev!=NULL){
        prev->right=root;
        prev->isThreaded=true;
    }
    prev =root;
    root->right=buildThreadedInorderTree(arr,mid+1,e,prev);
    return root;

}

void printPreOrder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    if (!root->isThreaded) {
        printPreOrder(root->left);
    }
    printPreOrder(root->right);
}

int main(){
    string arr[] = {"C", "B", "D", "A", "F", "E", "G"};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* prev = NULL;
    node* root = buildThreadedInorderTree(arr, 0, n - 1, prev);
    cout << "pre order is: ";
    printPreOrder(root);

    return 0;
}