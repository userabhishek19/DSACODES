#include <iostream>
#include <queue>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = NULL;
    }

    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);

        if (!root) {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        TreeNode* parent = NULL;
        bool isLeftChild = true;

        while (current) {
            parent = current;
            isLeftChild = (val < current->data);

            if (isLeftChild) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (isLeftChild) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void printInorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    std::cout << "Inorder traversal of the binary tree: ";
    tree.printInorder();

    return 0;
}
