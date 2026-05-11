#include <iostream>
using namespace std;


int partition(int*arr, int start, int end) {
    int size = end-start-1;
    int *temp = new int[size];
    int idx = (start+end)/2;
    int i = start, j = end;
    
    while (i<=j) {
        while (arr[i]<arr[idx]) {i++;}
        while (arr[j]>arr[idx]) {j--;}
        swap(arr[i++], arr[j--]);
    } 
    cout<<"Value of I is : "<<i<<endl;
    return i;

}


void quick_sort(int *arr, int start, int end) {
    if (start<end){
        int pivot = partition(arr, start, end);

        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot, end);
    }
}


int main() {
    int a[] = {4,2,5,3,1};

    quick_sort(a, 0, 4);


    for (int k: a) {
        cout<<k<<" ";
    }
    cout<<endl;
    return 0;
}