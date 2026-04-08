#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "q1.cpp"
#include "q2.cpp"
#include "q3.cpp"
#include "q4.cpp"

using namespace std;

int main() {
    srand(time(0));
    ofstream csv("results.csv");
    csv << "Size,Insertion_Avg,Merge_Avg,Heap_Avg,Quick_Avg\n";

    const int numSizes = 100;
    const int minSize = 30;
    const int maxSize = 1000;
    const int instances = 10;

    for (int i = 0; i < numSizes; i++) {
        int size = minSize + i * (maxSize - minSize) / (numSizes - 1);
        if (size > maxSize) size = maxSize;

        double insertSum = 0, mergeSum = 0, heapSum = 0, quickSum = 0;

        for (int inst = 0; inst < instances; inst++) {
            int original[1000];
            for (int j = 0; j < size; j++) {
                original[j] = rand() % 10000;
            }

            // Insertion
            int arr1[1000];
            copy(original, original + size, arr1);
            insertSum += insertionSort(arr1, size);

            // Merge
            int arr2[1000];
            copy(original, original + size, arr2);
            mergeSum += mergeSort(arr2, 0, size - 1);

            // Heap
            int arr3[1000];
            copy(original, original + size, arr3);
            heapSum += heapSort(arr3, size);

            // Quick
            int arr4[1000];
            copy(original, original + size, arr4);
            quickSum += quickSort(arr4, 0, size - 1);
        }

        double insertAvg = insertSum / instances;
        double mergeAvg = mergeSum / instances;
        double heapAvg = heapSum / instances;
        double quickAvg = quickSum / instances;

        csv << size << "," << insertAvg << "," << mergeAvg << "," << heapAvg << "," << quickAvg << "\n";
    }

    csv.close();
    cout << "Benchmarking complete. Results saved to results.csv" << endl;
    return 0;
}
