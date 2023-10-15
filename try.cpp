#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* down;

    node(int data){
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

void multiLinkedList(node** head){
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(data == -1){
        *head = NULL;
        return;
    }

    *head = new node(data);
    cout << "Enter the next element (to the right) of " << data << ": ";
    multiLinkedList(&((*head)->next));
    cout << "Enter the down element (below) of " << data << ": ";
    multiLinkedList(&((*head)->down));
}

void print(node* head){
    if(head == NULL){
        return;
    }
    cout << head->data << "->";
    print(head->next);
    cout << endl;
}

int main(){
    node* head = NULL;
    multiLinkedList(&head);
    print(head);

    return 0;
}
