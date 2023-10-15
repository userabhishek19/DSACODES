#include<iostream>
using namespace std;

const int k = 5; 

class node {
public:
    int data;
    node** children;
    node(int value) {
        this->data = value;
        this->children = new node*[k];
        for (int i = 0; i < k; ++i) {
            this->children[i] = NULL;
        }
    }
};

node* insertKary(node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }
    for (int i = 0; i < k; ++i) {
        if (root->children[i] == NULL) {
            root->children[i] = insertKary(root->children[i], val);
            break;
        }
    }
    return root;
}

void preOrder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < k; ++i) {
        preOrder(root->children[i]);
    }
}

void postOrder(node* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < k; ++i) {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void inOrder(node* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < k; ++i) {
        inOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void insert(node* &root, int val) {
    root = insertKary(root, val);
}

int main() {
    node* root = NULL;
    int elements[] = {10, 76, 2, 19, 45, 5};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; ++i) {
        insert(root, elements[i]);
    }

    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(root);
    cout << endl;

    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    return 0;
}
