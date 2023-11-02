#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }

    queue<Node*> q;
    q.push(root);
    bool NodeFound = false;

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (cur) {
            if (NodeFound) {
                return false;
            }

            q.push(cur->left);
            q.push(cur->right);
        } else {
            NodeFound = true;
        }
    }

    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBinaryTree(root)) {
        cout << "The binary tree is complete." << endl;
    } else {
        cout << "The binary tree is not complete." << endl;
    }

    return 0;
}
