#include <iostream>
using namespace std;

const int t = 3; // Adjust 't' to set the order of the B-tree

class BTreeNode {
public:
    int *keys;
    BTreeNode **children;
    int numKeys;
    bool leaf;

    BTreeNode(bool isLeaf = true) : leaf(isLeaf), numKeys(0) {
        keys = new int[2 * t - 1];
        children = new BTreeNode*[2 * t];
    }

    void insertNonFull(int key) {
        int i = numKeys - 1;

        if (leaf) {
            while (i >= 0 && key < keys[i]) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
            numKeys++;
        } else {
            while (i >= 0 && key < keys[i])
                i--;

            if (children[i + 1]->numKeys == (2 * t - 1)) {
                splitChild(i + 1, children[i + 1]);

                if (key > keys[i + 1])
                    i++;
            }
            children[i + 1]->insertNonFull(key);
        }
    }

    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->leaf);
        numKeys++;

        for (int j = numKeys - 1; j > i; j--) {
            keys[j] = keys[j - 1];
        }
        keys[i] = y->keys[t - 1];

        for (int j = numKeys; j > i + 1; j--) {
            children[j] = children[j - 1];
        }
        children[i + 1] = z;

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
            y->keys[j + t] = 0; // Clear keys in y
        }
        for (int j = 0; j < t; j++) {
            z->children[j] = y->children[j + t];
            y->children[j + t] = nullptr; // Clear children in y
        }

        y->numKeys = t - 1;
        z->numKeys = t - 1;
    }

    void insert(int key) {
        if (numKeys == (2 * t - 1)) {
            BTreeNode *newRoot = new BTreeNode(false);
            newRoot->children[0] = this;
            newRoot->splitChild(0, this);
            newRoot->insertNonFull(key);
        } else {
            insertNonFull(key);
        }
    }

    // Implement additional functions for searching, deleting, and printing the tree as needed

    ~BTreeNode() {
        delete[] keys;
        delete[] children;
    }
};

int main() {
    BTreeNode *root = new BTreeNode();
    int keys[] = {3, 1, 5, 4, 2, 6};

    for (int key : keys) {
        root->insert(key);
    }

   

    delete root; 

    return 0;
}
