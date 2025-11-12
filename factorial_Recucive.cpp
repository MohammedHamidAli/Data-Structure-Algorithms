#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int factorial(int n){
    if(n==1){
        return n;
    }
    if(n>1){
        return n*factorial(n-1);
    }
    return -1;
}

int main(){
    int n;
    cout <<"Please is the value: ";
    cin >>n;
    int x = factorial(n);
    cout <<x <<endl;
    return 0;
}