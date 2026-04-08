#include <iostream>

using namespace std;

int insertionSort(int A[], int n) {
    int comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++; 
            if (A[j] > key) {
                A[j + 1] = A[j];
                j = j - 1;
            } else {
                break;
            }
        }
        A[j + 1] = key;
    }
    return comparisons;
}

// int main() {
//     int A[100];
//     int n = 0;
//     int choice;

//     while (true) {
//         cout << "\n--- INSERTION SORT MENU ---" << endl;
//         cout << "1. Input Array" << endl;
//         cout << "2. Sort and Display Comparisons" << endl;
//         cout << "3. Display Array" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter number of elements: ";
//                 cin >> n;
//                 cout << "Enter " << n << " elements: ";
//                 for (int i = 0; i < n; i++) {
//                     cin >> A[i];
//                 }
//                 break;

//             case 2:
//                 if (n == 0) {
//                     cout << "Array is empty." << endl;
//                 } else {
//                     int comps = insertionSort(A, n);
//                     cout << "Sorted Successfully." << endl;
//                     cout << "Total Comparisons: " << comps << endl;
//                 }
//                 break;

//             case 3:
//                 for (int i = 0; i < n; i++) {
//                     cout << A[i] << " ";
//                 }
//                 cout << endl;
//                 break;

//             case 4:
//                 return 0;

//             default:
//                 cout << "Invalid choice." << endl;
//         }
//     }
// }