#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;

    }
};

Node* insertAtBst(struct Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
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

void input(Node*& root) {
    int data;
    cin >> data;
    
    while (data != -1) {
        root = insertAtBst(root, data);
        cin >> data; // Read the next data element
    }
}
void printlevelOrder(Node* root){
    if(!root){
        return ;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sizeOfTree= q.size();
        for(int i=0;i<sizeOfTree;i++){
            Node* temp= q.front();
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

void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void pre(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

bool isbalance(Node* root){
    if(root==NULL){
        return true;
    }
    int left = height(root->left);
    int right = height(root->right);
    bool tot = abs(left - right) <= 1;
    return tot && isbalance(root->left) && isbalance(root->right);
}

node*  minval(Node* root){
    Node* temp= root;
    if(temp== NULL){
        return 0;
    }
    while(temp!=NULL){
        temp->left= minval(temp->left);
    }
    return temp;
}

Node* deleteFromBst(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        // 0 child
        if(root->left && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp= root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            Node* temp= root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right)->right;
            return mini;
            delete root;
            
        }
    }
    else if(root->data > val){
        root->left = deleteFromBst(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right, val);
        return root;
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter the BST tree data (-1 to stop input): ";
    input(root);
    cout << endl;
    
    cout << "Level Order Traversal:" << endl;
    printlevelOrder(root);
    cout << endl;
    
    cout << "Post-order Traversal:" << endl;
    postorder(root);
    cout << endl;
    
    cout << "Pre-order Traversal:" << endl;
    pre(root);
    cout << endl;

    int treeHeight = height(root);
    cout << "The height of the tree is: " << treeHeight << endl;

    bool balance = isbalance(root);
    if(balance) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    minval(root);
    return 0;
}
