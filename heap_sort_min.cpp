#include <iostream>
using namespace std;


template <typename T>
class Heap {
public:
    T *arr;
    int size;

    Heap(T *a, int n){
        arr = a;
        size = n;
    }
    
    Heap(){
        arr = nullptr;
        size = -1;
    }

    void heapify(int n, int root_idx) {
        int smallest = root_idx;
        int left = 2*root_idx + 1;
        int right = 2*root_idx + 2;

        //check whether left or right child is larger.
        if (left<n && arr[left]< arr[smallest]) {
            smallest = left;
        }
        if (right<n && arr[right]< arr[smallest]) {
            smallest = right;
        }

        //swap the smallest element with root
        if (smallest!=root_idx) {
            swap(arr[smallest], arr[root_idx]); //change the root
            heapify(n, smallest); //Now heapify with the new root
        }
    }


    void build_min_heap() {
        for (int i = size/2-1; i>=0; i--) {
            heapify(size, i);
        }
    }

    void sort() {
        build_min_heap();

        for  (int i=size-1; i>0; i--) {
            swap(arr[0], arr[i]);
            heapify(i, 0);
        }
    }

    void display() {
        for (int i=0; i<size; i++) {
            cout<< arr[i]<< " ";
        }
        cout<<endl;
    }
};


int main() {
    int *arr;
    int len;
    Heap<int> h;
    int choice;


    do{
        cout<<"========Menu Heap Min Sort==========="<<endl;
        cout<<"Chose an option:"<<endl;
        cout<<"1> Insert elements in the array."<<endl;
        cout<<"2> Sort the elements."<<endl;
        cout<<"3> Print the array."<<endl;
        cout<<"9> To exit the program."<<endl;
        cout<<"Choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the length of the array: ";
                cin>>len;
                arr = new int[len];
                cout<<"Enter the elements: "<<endl;
                for (int i = 0; i<len; i++){
                    cin>>arr[i];
                }
                h.arr = arr;
                h.size = len;
                break;
            case 2:
                h.sort();
                break;
            case 3:
                h.display();
                break;
            case 9:
                break;
            default:
                cout<<"invalid option"<<endl;
        }


    }while(choice!=9);


    return 0;
}