#include <iostream>

using namespace std;

int partition(int A[], int low, int high, int &comparisons) {
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    return (i + 1);
}

int quickSort(int A[], int low, int high) {
    int comparisons = 0;
    if (low < high) {
        int pi = partition(A, low, high, comparisons);

        comparisons += quickSort(A, low, pi - 1);
        comparisons += quickSort(A, pi + 1, high);
    }
    return comparisons;
}

// int main() {
//     int A[100];
//     int n = 0;
//     int choice;

//     while (true) {
//         cout << "\n--- QUICK SORT MENU ---" << endl;
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
//                     int comps = quickSort(A, 0, n - 1);
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