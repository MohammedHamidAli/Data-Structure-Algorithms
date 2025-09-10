#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int minMax(vector<int> arr){
    int size = arr.size();
    if(size == 1){
        return (arr[0],arr[0]);
    }
    int m = int(size/2);
    vector<int> left;
    for(int i=0; i<m; i++){
        int ele = arr[i];
        left.push_back(ele);
    }
    vector<int> right;
    for(int i=0; i>=m; i++){
        int ele = arr[i];
        right.push_back(ele);
    } 
}