//Linear search
#include <iostream>
using namespace std;

int search(int arr[], int target, int size){
    int i=0;
    while(i<size){
        if(arr[i] == target){
            return i;
        } 
        i++;
    }
    return -1;
}
int main(){
    int array[] = {1,4,2,6,4,8,5};
    int size = (sizeof(array)/sizeof(array[0]));
    int x = search(array, 8, size);
    if(x != -1){
        cout << "Target at position:" << x+1 <<endl;
    }
    else cout << "Not found" <<endl;

    return 0;
}
// Done