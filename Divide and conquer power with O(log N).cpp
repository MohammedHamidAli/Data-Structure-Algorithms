#include <bits/stdc++.h>
using namespace std;

// Efficient exponentiation (binary exponentiation)
long long powerDAC_OlogN(long long b, long long n) {
    if (n == 0) return 1;
    long long half = powerDAC_OlogN(b, n / 2);
    long long sq = half * half;
    if (n % 2 == 0) return sq;
    return sq * b;
}

int main() {
    long long b, n;
    cin >> b >> n;
    cout << powerDAC_OlogN(b, n) << "\n";
    return 0;
}
