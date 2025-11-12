#include <iostream>
#include <climits>
using namespace std;

int fastPower(int a, int b) {
    if (b == 0) return 1;
    int half = fastPower(a, b / 2);
    if (b % 2 == 0) return half * half;
    else 
    return a * half * half;
}

int main(){
    cout << fastPower(2,4);

    return 0;
}
