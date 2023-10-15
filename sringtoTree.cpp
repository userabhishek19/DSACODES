#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
    node(string data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildInorderTree(string arr[], int s, int e) {
    if (s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    node* root = new node(arr[mid]);
    root->left = buildInorderTree(arr, s, mid -1);
    root->right = buildInorderTree(arr, mid + 1, e);
    return root;
}

void printPreOrder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    string arr[] = {"C", "B", "D", "A", "F", "E","G"};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* root = buildInorderTree(arr, 0, n - 1);
    cout << "pre order is: ";
    printPreOrder(root);
    return 0;
}
