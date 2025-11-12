#include <bits/stdc++.h>
using namespace std;

// Computes b^n with O(n) recursive multiplication
long long powerRecursiveLinear(long long b, long long n) {
    if (n == 0) return 1;
    return b * powerRecursiveLinear(b, n - 1);
}

int main() {
    long long b, n;
    cin >> b >> n;
    cout << powerRecursiveLinear(b, n) << "\n";
    return 0;
}
