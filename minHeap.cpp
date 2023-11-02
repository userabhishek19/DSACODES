#include<iostream>
using namespace std;

void minHaepify(int arr[],int n, int i){
    int smallest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <=n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        minHaepify(arr,n,smallest);
    }
}

int main(){
    int arr[6]={-1,50,43,67,32,5};
    int n=5;
    for(int i =n/2; i>=1;i--){
        minHaepify(arr,n,i);
    }

    cout<<"The minHeapify is: ";
for(int i=1; i<=n; i++){
    cout<<arr[i]<< " ";
}

}