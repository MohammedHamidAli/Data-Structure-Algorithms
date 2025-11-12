#include <bits/stdc++.h>
using namespace std;

// Naive divide-and-conquer that leads to O(n) time:
// T(n) = 2T(n/2) + O(1) -> O(n)
long long powerDAC_ON(long long b, long long n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        long long half = powerDAC_ON(b, n / 2);     // recompute twice
        long long half2 = powerDAC_ON(b, n / 2);    // causes O(n) overall
        return half * half2;
    } else {
        return b * powerDAC_ON(b, n - 1);
    }
}

int main() {
    long long b, n;
    cin >> b >> n;
    cout << powerDAC_ON(b, n) << "\n";
    return 0;
}
