#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
        arr[0] = 1;
    }

    void insertMaxHeap(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break; 
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void del() {
        if(size ==0){
            cout<<"everything is already deleted:) ";
            return;
        }
        arr[1]= arr[size];
        size--;
        int i= 1;
        while (i<size)
        {
            /* code */
            int leftIndex= 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i= leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[rightIndex],arr[i]);
                i= rightIndex;
            }else
            return;
        }
        

    }
};

int main() {
    heap h;

    h.insertMaxHeap(50);
    h.insertMaxHeap(40);
    h.insertMaxHeap(60);
    h.insertMaxHeap(70);
    h.insertMaxHeap(20);

    h.print();
    h.del();
    h.print();

    return 0;
}
