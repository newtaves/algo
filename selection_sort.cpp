#include <iostream>
using namespace std;

template <typename T>
int selection_sort(T*arr, int n){
    int comp = 0;

    for (int i =0, least, j; i<n-1; i++){
        least = i;
        for (j = i+1; j<n; j++){
            if (arr[j]<arr[least]){
                comp++;
                least = j;
            }
        }
        swap(arr[i], arr[least]);
    }
    return comp;
}


int main (){
    int choice;
    int *arr;
    int len;
    int comp;

    do{
        cout<<"========Menu Bubble Sort==========="<<endl;
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
                comp = selection_sort(arr, len);
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