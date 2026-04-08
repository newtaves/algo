#include <iostream>
using namespace std;

// Swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify subtree rooted at index i
int heapify(int arr[], int n, int i) {
    int comparisons = 0;
    int largest = i; // index of largest element
    int left = 2 * i + 1; //index of left child
    int right = 2 * i + 2; //index of right child

    // Compare left child
    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    // Compare right child
    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons += heapify(arr, n, largest);
    }
    return comparisons;
}

// Heap Sort function
int heapSort(int arr[], int n) {
    int totalComparisons = 0;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        totalComparisons += heapify(arr, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        totalComparisons += heapify(arr, i, 0);
    }
    return totalComparisons;
}

// // Display array
// void display(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }


// int main() {
//     int arr[100], n = 0;
//     int choice;

//     do {
//         cout << "\n--- Heap Sort Menu ---\n";
//         cout << "1. Input array\n";
//         cout << "2. Display array\n";
//         cout << "3. Sort array using Heap Sort\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//         case 1:
//             cout << "Enter number of elements: ";
//             cin >> n;
//             cout << "Enter elements:\n";
//             for (int i = 0; i < n; i++)
//                 cin >> arr[i];
//             break;

//         case 2:
//             if (n == 0)
//                 cout << "Array is empty.\n";
//             else
//                 display(arr, n);
//             break;

//         case 3:
//             if (n == 0) {
//                 cout << "Array is empty.\n";
//             } else {
//                 int comparisons = heapSort(arr, n);
//                 cout << "Sorted array:\n";
//                 display(arr, n);
//                 cout << "Number of comparisons: " << comparisons << endl;
//             }
//             break;

//         case 4:
//             cout << "Exiting program.\n";
//             break;

//         default:
//             cout << "Invalid choice!\n";
//         }
//     } while (choice != 4);

//     return 0;
// }
