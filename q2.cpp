#include <iostream>
using namespace std;

int merge(int A[], int p, int q, int r)
{
    int comparisons = 0;
    int nL = q - p + 1;
    int nR = r - q;

    int L[100], R[100];

    // Copy A[p..q] into L[]
    for (int i = 0; i < nL; i++)
        L[i] = A[p + i];

    // Copy A[q+1..r] into R[]
    for (int j = 0; j < nR; j++)
        R[j] = A[q + j + 1];

    int i = 0, j = 0, k = p;

    // Merge L and R back into A[p..r]
    while (i < nL && j < nR)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    return comparisons;
}

int mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        int leftComparisons = mergeSort(A, p, q);
        int rightComparisons = mergeSort(A, q + 1, r);
        int mergeComparisons = merge(A, p, q, r);
        return leftComparisons + rightComparisons + mergeComparisons;
    }
    return 0;
}

// void display(int A[], int n)
// {
//     for (int i = 0; i < n; i++)
//         cout << A[i] << " ";
//     cout << endl;
// }

// int main()
// {
//     int A[100], n, choice, comparisons;

//     do
//     {
//         cout << "\n--- MENU ---\n";
//         cout << "1. Enter Array\n";
//         cout << "2. Sort using Merge Sort\n";
//         cout << "3. Display Array\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             cout << "Enter number of elements: ";
//             cin >> n;
//             cout << "Enter elements:\n";
//             for (int i = 0; i < n; i++)
//                 cin >> A[i];
//             break;

//         case 2:
//             comparisons = mergeSort(A, 0, n - 1);
//             cout << "Array sorted successfully.\n";
//             cout << "Number of comparisons: " << comparisons << endl;
//             break;

//         case 3:
//             cout << "Array elements:\n";
//             display(A, n);
//             break;

//         case 4:
//             cout << "Exiting program.\n";
//             break;

//         default:
//             cout << "Invalid choice.\n";
//         }
//     } while (choice != 4);

//     return 0;
// }
