//Recursive Binary Search

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int a[], int left, int right, int target){
    while(left <= right){
        int mid = (left + right)/2;
        if (a[mid] == target){
            return mid;
        }
        if (target > a[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int array[] = {1,4,2,6,4,8,5};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, array + size);
    cout << "Sorted Array:";
    for(int i=0; i <size;i++){
        cout << array[i] << " ";
    } cout << endl;
    int target;
    int low =0, high = size-1;
    cout << "Enter target: ";
    cin >> target;

    int x = binarySearch(array, low, high, target);
    if(x != -1){
        cout << "psition is: " << 1+x;
    } else cout << "Not found";
    cout << endl;
    return 0;
}