//knapsack problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Solves the 0/1 Knapsack problem using dynamic programming.
 * * This function determines the maximum value that can be obtained by selecting
 * items from a given set, subject to a total weight constraint. Each item
 * can either be included in the knapsack or not (0/1 property).
 *
 * @param weights A constant reference to a vector of integers representing the weights of the items.
 * @param values A constant reference to a vector of integers representing the values of the items.
 * @param capacity The maximum weight capacity of the knapsack.
 * @return The maximum total value that can be carried in the knapsack.
 */
int knapsack_01(const vector<int>& weights, const vector<int>& values, int capacity) {
    // Get the number of items.
    int n = values.size();

    // Create a 2D DP table. 
    // dp[i][w] will store the maximum value that can be achieved with a capacity of 'w'
    // using only the first 'i' items.
    // The table size is (n+1) x (capacity+1) to handle base cases where i=0 or w=0.
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Iterate through each item
    for (int i = 1; i <= n; ++i) {
        // Iterate through each possible weight capacity from 1 to the max capacity
        for (int w = 1; w <= capacity; ++w) {
            // The current item's weight and value. We use i-1 because vector is 0-indexed.
            int current_weight = weights[i - 1];
            int current_value = values[i - 1];

            // If the current item's weight is greater than the current capacity 'w',
            // we cannot include it. So, the maximum value is the same as the value
            // without this item (from the row above).
            if (current_weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                // If the item can fit, we have two choices:
                // 1. Don't include the item: The value is dp[i-1][w].
                // 2. Include the item: The value is the current item's value plus the value
                //    of the remaining items with the remaining capacity.
                int value_without_item = dp[i - 1][w];
                int value_with_item = current_value + dp[i - 1][w - current_weight];

                // We choose the option that gives the maximum value.
                dp[i][w] = max(value_without_item, value_with_item);
            }
        }
    }

    // The bottom-right cell of the table contains the maximum value for all 'n' items
    // with the full 'capacity'.
    return dp[n][capacity];
}

// --- Example Usage ---
int main() {
    // Define the items with their respective values and weights
    vector<int> item_values = {60, 100, 120};
    vector<int> item_weights = {10, 20, 30};
    int knapsack_capacity = 50;

    // Call the function to find the maximum value
    int max_value = knapsack_01(item_weights, item_values, knapsack_capacity);

    // Print the results
    cout << "Item Values: {60, 100, 120}" << endl;
    cout << "Item Weights: {10, 20, 30}" << endl;
    cout << "Knapsack Capacity: " << knapsack_capacity << endl;
    cout << "------------------------------" << endl;
    // The optimal solution is to choose the items with weights 20 and 30 (total 50),
    // giving a total value of 100 + 120 = 220.
    cout << "Maximum value in knapsack: " << max_value <<endl; 

    return 0;
}

