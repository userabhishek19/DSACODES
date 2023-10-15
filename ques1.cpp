#include<iostream>
using namespace std;

class tree {
public:
    int data;
    tree* left;
    tree* right;

    tree(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class queue {
public:
    tree* data;
    queue* next;

    queue(tree* d) {
        this->data = d;
        this->next = NULL;
    }
};

queue* front = NULL;
queue* rear = NULL;

void enqueue(tree* x) {
    queue* temp = new queue(x);
    if (front == NULL && rear == NULL) {
        rear = front = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

tree* dequeue() {
    if (front == NULL) {
        cout << "queue is empty" << endl;
        return NULL;
    }
    else {
        queue* temp = front;
        front = front->next;
        tree* dequeueNode = temp->data;
        delete temp;
        if (front == NULL) {
            rear = NULL;
        }
        return dequeueNode;
    }
}

tree* constructLevelOrder(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    tree* root = new tree(arr[0]);
    enqueue(root);
    int i = 1;
    while (arr!=NULL && i < n) { 
        tree* cur = dequeue();

        int leftData = arr[i++];
        if (leftData != 0) {
            cur->left = new tree(leftData);
            enqueue(cur->left);
        }

        int rightData = arr[i++];
        if (rightData != 0) {
            cur->right = new tree(rightData);
            enqueue(cur->right);
        }
    }
    return root;
}

void printTraversal(tree* root) {
    if (root == NULL) {
        return;
    }
    enqueue(root);
    while (front != NULL) {
        tree* temp = dequeue();

        cout << temp->data << " ";
        if (temp->left) {
            enqueue(temp->left);
        }
        if (temp->right) {
            enqueue(temp->right);
        }
        
    }

cout<<endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]); 

    tree* root = constructLevelOrder(arr, n);
    cout<<"print in level order traversal is; ";
    printTraversal(root);
    return 0;
}
