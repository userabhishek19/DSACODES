    #include<iostream>
    using namespace std;

    class heap{
        public:
        int arr[100];
        int size;
        heap(){
            size=0;
            arr[0]=1;

        }

    void insertMaxHeap(int val){
        size = size+1;
        int index=size;
        arr[index]= val;

        while(index >1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
                index= parent;
            }
            else {
                break; 
            }
        } 
    }
    void print(){
        for(int i=1;i<size;i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;
    }
    };


    int main(){
        heap h;
    h.insertMaxHeap(70);
    h.insertMaxHeap(40);
    h.insertMaxHeap(60);
    h.insertMaxHeap(75);
    h.insertMaxHeap(20);

    h.print();

    return 0;



    }