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
void printLevelOrderTraversal(node* root) {
    if (!root) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}
node* insertAtBst(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;

    }
    if(d>root->data){
        root->right=insertAtBst(root->right,d);
        //root k right me data detey jao dost
    }
    else{
        root->left=insertAtBst(root->left,d);
        //root k left me data detey jao dost
    }
    return root;


}

void input(node* &root){
 int data;
 cout<<"Enter data"<<" ";
 cin>>data;
 while(data!=-1){
    root= insertAtBst(root,data);
    cin>>data;


 }
}
//recursive way to search time complexsibility o(n^2)
bool searchInBst(node* root,int x){
    if(root==NULL){
        return false;
    }
    else if(root->data==x){
        return true;
    }
    if(root->data > x){
        return searchInBst(root->left,x);
    }else{
        return searchInBst(root->right,x);

    }


    }

    //itrative way to search 
   bool  searchItrative(node* root,int x){
    node* temp=root;
   while(temp!=NULL){
    if(temp->data==x){
        return true;
    }
    if(temp->data>x){
       temp= temp->left;
    }else{
    temp= temp->right;
   }
   }
   return false;
   
   }

int main(){
    node* root=NULL;

    input(root);
    cout<<"The sorted binary tree is: "<<endl;
    printLevelOrderTraversal(root);

    int x;
    cout<<"Enter the element you want to search "<<endl;
    cin>>x;

   int check = searchInBst(root,x);
   cout<<endl;
   if(check==true){
    cout<<"yes it is there "<<endl;
   }else{
   cout<<"No it is not there "<<endl;
   }
   int itrativeCheck= searchItrative(root,x);
   if(itrativeCheck==true){
    cout<<"yes it is there "<<endl;
   }else{
   cout<<"No it is not there "<<endl;
   }

    return 0;
}