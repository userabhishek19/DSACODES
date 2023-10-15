#include <iostream>
using namespace std;

class AVLTree {
public:
    int data;
    int height;
    AVLTree* left;
    AVLTree* right;

    AVLTree(int value) : data(value), height(1), left(NULL), right(NULL) {}
};

int getHeight(AVLTree* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(AVLTree* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLTree* rotateRight(AVLTree* y) {
    AVLTree* x = y->left;
    AVLTree* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLTree* rotateLeft(AVLTree* x) {
    AVLTree* y = x->right;
    AVLTree* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

AVLTree* insert(AVLTree* node, int key) {
    if (node == NULL)
        return new AVLTree(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (key < node->left->data) {
            return rotateRight(node);
        }
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (key > node->right->data) {
            return rotateLeft(node);
        }
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void printInorder(AVLTree* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    AVLTree* avl = NULL;

    int keys[] = {10, 5, 15, 2, 7, 12, 17};

    for (int key : keys) {
        avl = insert(avl, key);
    }

    cout << "In-order traversal: ";
    printInorder(avl);
    cout << endl;

    return 0;
}
