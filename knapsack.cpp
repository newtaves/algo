#include <iostream>
#include <algorithm>

using namespace std;

// Defining maximum limits for the practical exam
#define MAX_ITEMS 50
#define MAX_WEIGHT 100

int knapsack(int W, int weights[], int values[], int n) {
    // 2D Array for DP table
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Build the table bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: No items or 0 capacity
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // If current item can fit in the remaining capacity
            else if (weights[i - 1] <= w) {
                // Max of (including the item) or (excluding the item)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            }
            // If current item weight exceeds current capacity, exclude it
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int values[MAX_ITEMS], weights[MAX_ITEMS];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Check if input exceeds our defined MAX limits
    if (n > MAX_ITEMS || W > MAX_WEIGHT) {
        cout << "Input exceeds predefined limits." << endl;
        return 1;
    }

    cout << "Maximum Value: " << knapsack(W, weights, values, n) << endl;

    return 0;
}