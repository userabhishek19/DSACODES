#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
    bool isLeftThreaded;
    bool isRightThreaded;
    node(string data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->isLeftThreaded = false;
        this->isRightThreaded = false;
    }
};

node* buildDoubleThreadedInorderTree(string arr[], int s, int e, node* prev) {
    if (s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    node* root = new node(arr[mid]);
    if (prev != NULL) {
        if (prev->data > arr[mid]) {
            if (!prev->isLeftThreaded) {
                prev->left = root;
                prev->isLeftThreaded = true;
            }
            root->right = prev;
        } else {
            if (!prev->isRightThreaded) {
                prev->right = root;
                prev->isRightThreaded = true;
            }
            root->left = prev;
        }
    }
    node* leftPrev = root;
    node* rightPrev = root;
    root->left = buildDoubleThreadedInorderTree(arr, s, mid - 1, leftPrev);
    leftPrev->right = root;
    root->right = buildDoubleThreadedInorderTree(arr, mid + 1, e, rightPrev);
    rightPrev->left = root;
    return root;
}

void printPreOrder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    if (!root->isLeftThreaded) {
        printPreOrder(root->left);
    }
    if (!root->isRightThreaded) {
        printPreOrder(root->right);
    }
}

int main() {
    string arr[] = {"C", "B", "D", "A", "F", "E", "G"};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* prev = NULL;
    node* root = buildDoubleThreadedInorderTree(arr, 0, n - 1, prev);
    cout << "pre order is: ";
    printPreOrder(root);
    return 0;
}
