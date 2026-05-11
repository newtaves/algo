#include <iostream>
using namespace std;

int bubble(int *arr, int n) {
    int comp = 0;
    for (int i = 0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                comp++;
                swap(arr[j], arr[j+1]);
            }
        }
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
                comp = bubble(arr, len);
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