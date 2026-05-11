#include <iostream>
using namespace std;


int partition(int *arr, int start, int end) {
    int idx = start - 1;

    for (int j = start; j<end; j++) {
        if (arr[j]<=arr[end]) {
            idx ++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quick_sort(int *arr, int start, int end) {
    if (start<end) {
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot+1, end);
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