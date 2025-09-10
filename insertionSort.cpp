//Insertion Sort
#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    vector<int> data = {12, 11, 13, 5, 6};

    cout << "Unsorted array: ";
    printVector(data);

    insertionSort(data);

    cout << "Sorted array:   ";
    printVector(data);

    return 0;
}