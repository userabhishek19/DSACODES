#include <iostream>
#include <queue>
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



void printInorder(node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}



int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}


node* findMinValueNode(node* root) {
    node* temp = root;
    if (temp == NULL) {
        return NULL;
    }
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

node* deleteFromBst(node* root, int val) {
    if (root == NULL) {
        return root;
    }
    if (root->data == val) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->right != NULL && root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = findMinValueNode(root->right)->data;
            root->data = mini;
            root->right = deleteFromBst(root->right, mini);
        }
    }
    else if (root->data > val) {
        root->left = deleteFromBst(root->left, val);
        return root;
    }
    else {
        root->right = deleteFromBst(root->right, val);
        return root;
    }
}
bool isAVLTree(node* root) {
    if (root == NULL) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isAVLTree(root->left) &&
        isAVLTree(root->right)) {
        return true;
    }

    return false;
}

int main() {
    node* root = NULL;
    cout << "Enter the BST tree data (-1 to stop input): ";
    input(root);
    cout << endl;
  
    cout << "In-order traversal:" << endl;
    printInorder(root);
  
   
    bool check= isAVLTree(root);
      if (check == true) {
        cout << "The tree is AVL Tree" << endl;
    }
    else {
        cout << "The tree is not AVL Tree" << endl;
    }

    deleteFromBst(root,38);
    deleteFromBst(root,50);
    deleteFromBst(root,10);
    cout<<" the updated avl tree is: "<<endl;
    printInorder(root);

 
    return 0;
}
