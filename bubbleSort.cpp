//Bubble Sort
#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int size){
    int i,j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i;j++){
            if(array[j+1] < array[j]){
                swap(array[j+1], array[j]);
            }
        }
    }
}

int main(){
    int array[] = {1,5,4,3,8,20,0,2};
    int size = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, size);
    for(int i=0; i<size;i++) cout << array[i] <<" ";
    cout <<"\n";
    return 0;
}
