#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* down;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

node* multiLinkedList(node*& head) { // Pass head by reference
    int data;
    cout << "Enter the data: ";
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    head = new node(data);
    cout << "Enter the next element (to the right) of " << data << ": ";
    head->next = multiLinkedList(head->next);
    cout << "Enter the down element (down) of " << data << ": ";
    head->down = multiLinkedList(head->down);

    return head;
}

void print(node* head) {
    if (head == NULL) {
        return;
    }

    // Print elements in the current level (right)
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }

    // Traverse down elements and print them
    if (head->down != NULL) {
        cout << "->";
        print(head->down);
    }
}

int main() {
    node* head = NULL;
    cout << "Enter elements for the multi-level linked list:" << endl;
    multiLinkedList(head);
    cout << "Printing the multi-level linked list in series:" << endl;
    print(head);

    return 0;
}
