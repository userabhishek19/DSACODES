#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* down;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

void printOriginalList(Node* head) {
    if (head == NULL) {
        return;
    }
    cout << " " << head->data << " ";
    if (head->down) {
        cout << "[";
        printOriginalList(head->down);
        cout << "]";
    }
    printOriginalList(head->next);
}

Node* flattenList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* next = head->next;
    head->next = flattenList(head->down);

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = flattenList(next);
    return head;
}

int main() {
    Node* one = new Node(1);
    one->down = new Node(2);
    one->down->down = new Node(3);
    one->down->down->next = new Node(4);
    one->down->next = new Node(5);
    one->next = new Node(6);

    cout << "Original List:" << endl;
    printOriginalList(one);

    Node* flattened = flattenList(one);

    cout << "\nFlattened List:" << endl;
    printOriginalList(flattened);

    return 0;
}


