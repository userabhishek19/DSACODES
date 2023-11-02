#include<iostream>
using namespace std;

class heaps{
    public:
    int arr[100];
    int size;
    heaps(){
        arr[0]=-1;
        size=0;
}


void intsertInMinHeap(int val){
    size=size+1;
    int index= size;
    arr[index]=val;

    while(index<=size){
        int parent= index/2;
        if(arr[parent]>arr[index]){
            swap(arr[index],arr[parent]);
            index= parent;
        }
else{
    break;
}
    }
}
void print(){
     cout<<"The min heaps are: ";
    for(int i=1;i<=size;i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void remove(){
    if(size == 0){
        cout<<"sir khali hai min heap ";
        return ;
    }
    arr[1]=arr[size];

   int i=1;
   while(i<size){
    int leftIndex= 2*i;
    int rightIndex= 2*i+1;
    if(leftIndex < size && arr[leftIndex] < arr[i]){
        swap(arr[leftIndex], arr[i]);
        size--;
    }
    if(rightIndex < size && arr[rightIndex] < arr[i]){
        swap(arr[rightIndex], arr[i]);
        size--;
    }else{
        return;
    }

   } 

    
}
};

int main(){
  
    heaps h;
    h.intsertInMinHeap(65);
    h.intsertInMinHeap(30);
    h.intsertInMinHeap(70);
    h.intsertInMinHeap(5);
    h.intsertInMinHeap(3);
    
    h.print();
    h.remove();
    


    h.print();

      return 0;

}