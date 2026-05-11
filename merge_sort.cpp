#include <iostream>
using namespace std;

template <typename T>
int merge(T *arr, int start, int mid, int end) {
    int len = end-start+1;
    T *temp = new T[len];
    int k = 0, i = start, j = mid+1, comp = 0;

    while ( i<=mid && j<=end) {
        if (arr[i]<=arr[j]) {
            comp++;
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i<=mid) {
        temp[k++] = arr[i++];
    }

    while (j<=end) {
        temp[k++] = arr[j++];
    }

    for (int idx = 0; idx<len; idx++) {
        arr[start+idx] = temp[idx];
    }

    delete[] temp;
    return comp;
}


template <typename T>
int merge_sort(T *arr, int start, int end){
    int comp =0;
    if (start<end) {
        int mid = start+ (end-start)/2;
        merge_sort(arr, start, mid); //left side
        merge_sort(arr, mid+1, end); //right side
        comp+=merge(arr, start, mid, end);
    }   
    return comp;
}



int main (){
    int choice;
    int *arr;
    int len;
    int comp;

    do{
        cout<<"========Menu Merge Sort==========="<<endl;
        cout<<"Chose an option:"<<endl;
        cout<<"1> Insert elements in the array."<<endl;
        cout<<"2> Sort the elements."<<endl;
        cout<<"3> Print the array."<<endl;
        cout<<"4> Print the number of comparisons"<<endl;
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
                break;
            case 2:
                comp = merge_sort(arr, 0, len);
                break;
            case 3:
                for (int k=0; k<len; k++){
                    cout<<arr[k]<<" ";
                }
                cout<<endl;
                break;
            case 4:
                cout<<"Comparisons: "<<comp<<endl;
                break;
            case 9:
                delete[] arr;
                break;
            default:
                cout<<"invalid option"<<endl;
        }


    }while(choice!=9);


    return 0;
}