#include<iostream>
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

// Define a custom queue using a linked list
class MyQueue {
public:
    node* data;
    MyQueue* next;

    MyQueue(node* val) : data(val), next(nullptr) {}
};

class CustomQueue {
public:
    MyQueue* front;
    MyQueue* rear;

    CustomQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(node* val) {
        MyQueue* newNode = new MyQueue(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    node* dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            exit(1);
        }
        MyQueue* temp = front;
        node* data = temp->data;
        front = front->next;
        delete temp;
        return data;
    }
};

node* buildLevelOrderTraversal(node* &root) {
    int data;
    cout << "Enter the root data: ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    // Base case
    root = new node(data);
    CustomQueue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        node* temp = q.dequeue();

        int leftData;
        cout << "Enter the data for the left child of " << temp->data << " (-1 to skip): ";
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.enqueue(temp->left);
        }

        int rightData;
        cout << "Enter the data for the right child of " << temp->data << " (-1 to skip): ";
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.enqueue(temp->right);
        }
    }

    return root;
}

void printLevelOrderTraversal(node* root) {
    if (!root) {
        return;
    }

    CustomQueue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        int levelSize = 0;
        MyQueue* current = q.front;
     

        while (current != nullptr) {
            levelSize++;
            current = current->next;
        }

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.dequeue();
            cout << temp->data << " ";

              if (temp->left) {
                q.enqueue(temp->left);
            }
            if (temp->right) {
                q.enqueue(temp->right);
            }
          
            
        }
        cout << endl;
    }
}

int main() {
    node* root = NULL;
    root = buildLevelOrderTraversal(root);
    cout << "Level Order Traversal: " << endl;
    printLevelOrderTraversal(root);
    cout << endl;

    return 0;
}
