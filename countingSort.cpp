#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element
using namespace std;

void printVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << std::endl;
}

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // 1. Find the maximum element to determine the range
    int max = *std::max_element(arr.begin(), arr.end());

    // 2. Create a count array and store the frequency of each element
    vector<int> count(max + 1, 0);
    for (int val : arr) {
        count[val]++;
    }

    // 3. Calculate cumulative counts
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // 4. Build the output array
    vector<int> output(arr.size());
    // Iterate from the end to maintain stability
    for (int i = arr.size() - 1; i >= 0; --i) {
        int val = arr[i];
        output[count[val] - 1] = val;
        count[val]--;
    }

    // 5. Copy the sorted elements back to the original array
    arr = output;
}

int main() {
    vector<int> data = {4, 2, 2, 8, 3, 3, 1};

    cout << "Unsorted array: ";
    printVector(data);

    countingSort(data);

    cout << "Sorted array:   ";
    printVector(data);

    return 0;
}