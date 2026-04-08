#include <iostream>
using namespace std;

void inputArray(int A[], int n) {
    cout << "Enter elements:\n";
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
}

void displayArray(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int findMax(int A[], int n) {
    int max = A[1];
    for (int i = 2; i <= n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countingSort(int A[], int B[], int n, int k) {
    int C[100];

    // Initialize count array
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    // Count frequency
    for (int j = 1; j <= n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    // Cumulative count
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // Build output array (stable)
    for (int j = n; j >= 1; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}

int main() {
    int A[100], B[100];
    int n = 0;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enter array\n";
        cout << "2. Display array\n";
        cout << "3. Sort using Counting Sort\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                inputArray(A, n);
                break;

            case 2:
                if (n == 0)
                    cout << "Array is empty.\n";
                else
                    displayArray(A, n);
                break;

            case 3:
                if (n == 0) {
                    cout << "Enter array first.\n";
                } else {
                    int k = findMax(A, n);
                    countingSort(A, B, n, k);
                    cout << "Sorted array:\n";
                    displayArray(B, n);
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}