#include<iostream>
using namespace std;
class node{
    public:
int data;
node* left;
node* down;
node(int val){
    this->data=val;
    this->left=NULL;
    this->down=NULL;
}

};
node* buildMiltiList(node* &head){
    int data;
    cout<<"Enter node: ";
    cin>>data;
    head=new node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter left data after "<<data<<endl;
    head->left=buildMiltiList(head->left);

     cout<<"Enter down data after "<<data<<endl;
    head->down=buildMiltiList(head->down);

    return head;





}
void list(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->left;
    }
    cout<<endl;
}
void flatten(node* &head){
    if(head==NULL){
        return;

    }

    node* temp;
    node* tail=head;
    while(tail->left!=NULL){
        tail=tail->left;
    }
    node* cur=head;
    while(tail!=cur){
        if(cur->down!=NULL){
            tail->left=cur->down;

            temp=cur->down;
            while(temp->left!=NULL){
                temp=temp->left;
                tail=temp;
            }
        }
        cur=cur->left;

    }

}
int main(){
    node* head=NULL;
    buildMiltiList(head);
    flatten(head);
    list(head);


    return 0;

}