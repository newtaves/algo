#include <iostream>
using namespace std;

void count(int*arr, int n) {
    int k = arr[0];
    for (int i =0; i<n; i++) {
        if (arr[i]>k) {k = arr[i];}
    }

    int* count = new int[k + 1]();

    //fill the freaquency array
    for (int i = 0; i<n; i++) {
        count[arr[i]] +=1;
    }

    //create the cummulative array
    for (int i = 1; i<=k; i++) {
        count[i] = count[i]+count[i-1];
    }


    int *output = new int[n]();

    //recreate the sorted array
    for (int i = n-1; i>=0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i=0; i<n;i++) {
        arr[i] = output[i];
    }
}



int main() {
    int k[] = {55,4,4,2,1};
    
    count(k, 5);
    
    
    for (int i =0; i<5; i++) {
        cout<<k[i]<<" ";
    }
    cout<<endl;


    return 0;
}