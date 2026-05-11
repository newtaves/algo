#include <iostream>
using namespace std;


template <typename T>
int insertion_sort(T *arr, int n){
    int comp=0;

    for (int i=1; i<n; i++){
        int prev = i-1;
        int cur = arr[i];
        while(prev>=0 && arr[prev]>cur){
            comp++;
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = cur;
    }
    return comp;
}

int main (){
    int choice;
    char *arr;
    int len;
    int comp;

    do{
        cout<<"========Menu Insertion Sort==========="<<endl;
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
                arr = new char[len];
                cout<<"Enter the elements: "<<endl;
                for (int i = 0; i<len; i++){
                    cin>>arr[i];
                }
                break;
            case 2:
                comp = insertion_sort(arr, len);
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
                break;
            default:
                cout<<"invalid option"<<endl;
        }


    }while(choice!=9);


    return 0;
}