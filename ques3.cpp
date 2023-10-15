#include<iostream>
using namespace std;

class tree {
public:
    char data;
    tree* left;
    tree* right;

    tree(char val) {
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
tree* buildTree(tree* &root){
    int data;
    cout<<"enter the data: ";
    cin>>data;

    if(data==-1){
        return NULL;
    }
    tree* root=new tree(data);
    if(data!=-1){
        cout<<"Enter the data "
    }
}

int main(){
    return 0;

}