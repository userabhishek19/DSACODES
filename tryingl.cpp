#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode** children;
    int numChildren;

    TreeNode(int value, int k) : data(value), numChildren(k) {
        children = new TreeNode*[k];
        for (int i = 0; i < k; ++i) {
            children[i] = nullptr;
        }
    }
};

class KaryTree {
public:
    TreeNode* root;
    int K;

    KaryTree(int k) : K(k), root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value, K);
        }

        for (int i = 0; i < K; ++i) {
            if (node->children[i] == nullptr) {
                node->children[i] = insertRecursive(nullptr, value);
                break;
            }
        }
        return node;
    }

    void preOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        for (int i = 0; i < K; ++i) {
            preOrder(node->children[i]);
        }
    }
};

int main() {
    KaryTree karyTree(3);
    int elements[] = {10, 20, 30, 40, 50, 45, 35, 25, 15, 5, 8, 18, 28, 38, 48};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; ++i) {
        karyTree.insert(elements[i]);
    }

    cout << "Pre-order traversal of K-ary tree:" << endl;
    karyTree.preOrder(karyTree.root);
    cout << endl;

    return 0;
}
