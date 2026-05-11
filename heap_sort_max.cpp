#include <iostream>
using namespace std;


template <typename T>
class Heap {
public:
    T* arr;
    int size;


    Heap(T a[], int n) {
        arr = a;
        size = n;
    }
    Heap(){arr = nullptr; size = -1;}

    void heapify(int n, int i) {
        int largest = i;
        int left = 2*i +1; //Left child Index
        int right = 2*i +2; //right Child Index

        // Determine the largest Child of i
        if (left<n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right<n && arr[right] > arr[largest]) {
            largest = right;
        }

        //replace the root with the child which is greater than parent.
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest); //Heapify with replaced child as root.
        }
    }

    void build_max_heap() {
        for (int i= size/2-1; i>=0; i--){
            heapify(size, i);
        }
    }

    void sort() {
        build_max_heap();

        for (int i=size-1; i>0; i--) {
            swap(arr[0], arr[i]);
            heapify(i, 0);
        }
    }

    void display(){
        for (int i=0; i<size; i++) {
            cout<< arr[i]<<" ";
        }
        cout<<endl;
    }
};




int main (){
    int choice;
    int *arr;
    int len;
    Heap<int> h;

    do{
        cout<<"========Menu Heap Sort==========="<<endl;
        cout<<"Chose an option:"<<endl;
        cout<<"1> Insert elements in the array."<<endl;
        cout<<"2> Sort the elements."<<endl;
        cout<<"3> Print the array."<<endl;
        cout<<"9> To exit the program."<<endl;
        cout<<"Choice: "<<endl;
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