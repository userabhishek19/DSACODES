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

node* buildLevelOrderTraversal(node* &root) {
    int data;
    cout << "Enter the root data: ";
    cin >> data;
if (data == -1){
    return NULL;
}
   //base case
    root = new node(data);
    queue<node*> q;
    q.push(root);
    

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        int leftData;
        cout << "Enter the data for the left child of " << temp->data << " (-1 to skip): ";
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the data for the right child of " << temp->data << " (-1 to skip): ";
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

void printLevelOrderTraversal(node* root) {
    if (!root) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans= max(left,right)+1;
    return ans;
}
int minheight(node* root){
    if(root==NULL){
        return 0;

    }
     int left=minheight(root->left);
    int right=minheight(root->right);
    int minAns= min(left,right)+1;
    return minAns;
}

int diameter(node* root){
    if(root==NULL){
        return 0;

    }
    int l = diameter(root->left);
    int r=diameter(root->right);
    int tot=height(root->left)+height(root->right)+1;
    int out=max(l,max(r,tot));
    return out;
}
int minWidth(node* root){
    if(root == NULL){
        return 0;
    }
    int l=minWidth(root->left);
    int r=minWidth(root->right);
    int tot=minheight(root->left)+minheight(root->right)+1;
    int outMin= min(l,min(r,tot));
    return outMin;

}
bool isBalance(node* root){
    if(root ==NULL){
        return true;

    }

    bool left= isBalance(root->left);
    bool right= isBalance(root->right);
    bool tot= abs(height(root->left)- height(root->right)) <=1;
    if(left && right && tot){
        return true;
    }
    return false;
}

int main() {
    node* root = NULL;

     buildLevelOrderTraversal(root);
    cout << "Level Order Traversal: " << endl;
    printLevelOrderTraversal(root);
    cout<<endl;
    int heightOfTree=height(root);
    cout<<"the height of tre is: "<<heightOfTree<<endl;
    int diameters= diameter(root);
    cout<<"the max width of tree is:  "<<diameters<<endl;

    int minHeightTree = minheight(root);

    cout<<"The minimum height of the Tree isL "<<minHeightTree<<endl;

    int minWidthOfTree = minWidth(root);
    cout<<"The minimum width of The local Tree is: "<<minWidthOfTree<<endl;
   
   int check=isBalance(root);
   if(check == true){
   cout<<"The tree is balanced:  "<<endl;
   }else{
   cout<<"The tree is not balanced : "<<endl;
   }
    return 0;
}
