#include<iostream>
using namespace std;

class node{
    public:
int data;
node* next;

node(int data){
    this->data=data;
    this->next=NULL;

}

};


node*  insertAtTail(node* &tail){
    int data;
    cout<<"Enter the data  : ";
    cin>>data;
    cout<<endl;

  if(data== -1){
    return NULL;
  }
tail = new node(data);
cout<<"Enter the tail data after : "<<data<<" ";
tail->next= insertAtTail(tail->next);

return tail;



}
int search(node* head,int d){
 
    node* currrent= head;
    while(currrent!=NULL){
        if(currrent->data == d){
            return 1;
        }
        currrent= currrent->next;

    }
    return 0;
}

void print( node* tail){
    node* temp= tail;
    if(temp!=NULL){
     cout<<temp->data<<"->";
     print(temp->next);
    }
    cout<<endl;
}

int sums( node* head){
    if(head==NULL){
        return 0;
    }
 int sum =head->data+ sums(head->next);
 return sum;
}

int main(){
    node* tail=NULL;
    node* head=NULL;
  insertAtTail(tail);
  print(tail);
  cout<<endl;

  int s= search(tail,4);
  if(s== 1){
    cout<<"present"<<endl;
  }else
  cout<<" not present "<<endl;
  //cout<<" the element you searched is : "<< s<<endl;
cout<<endl;
  int add= sums(tail);
  cout<<" the sum of linked list is " <<add;
    return 0;
}