#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val ){
        this->data= val;
        this->left=NULL;
        this->right=NULL;

    }
};


void printLevelOrder(node* root){
    if(!root){
        return;
    }
    queue<node*> q;
    

    q.push(root);

   while(!q.empty()){
    int levelSize= q.size();
    for(int i=0; i<levelSize;i++){
        node* temp= q.front();
        q.pop();
       cout<<temp->data<<" ";
       if(temp->left){
        q.push(temp->left);
       }
       if(temp->right){
        q.push(temp->right);
       }

    }
    cout<<endl;
   }



}

node* inserAtBst(node* root, int x){
    if (root == NULL) {
        root = new node(x);
        return root;
    }
    if (x > root->data) {
        root->right = inserAtBst(root->right, x);
    } else {
        root->left = inserAtBst(root->left, x);
    }
    return root;
}

void input(node* &root){
    int data;
 
    cin >> data;

    while(data != -1){
     root= inserAtBst(root, data);
        cin >> data;
    }
}


bool searchBst(node* root,int x){
    node* temp=root;
    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data>x){
            temp= temp->left;
        }
        else{
            temp= temp->right;
        }

    }
return false;

}
node* minValue(node* root){
    node* temp= root;
    while(temp->left!=NULL){
        temp= temp->left;
    }
    return temp;
}
node* maxvalue(node* root){
    node* temp= root;
    while(temp->right!=NULL){
        temp= temp->right;
    }
    return temp;
}
int main(){
    node* root=NULL;

    cout<<" enter the data to create bst ; "<<" ";
    input(root);
    printLevelOrder(root);
    int target;//what you want to search 
    cout<<" enter the element you want to search "<<endl;
    cin>>target;

    int check= searchBst(root,target);
cout<<" the elemnet you searched is "<<target<<" "<<check<<endl;

cout<<" the minumum value user entered in tree is : "<<minValue(root)->data<<endl;
cout<<" the minumum value user entered in tree is : "<<maxvalue(root)->data<<endl;


    return 0;
}