#include <bits/stdc++.h>
using namespace std;

long long recursiveSum(const vector<long long>& a, int i) {
    if (i == (int)a.size()) return 0;
    return a[i] + recursiveSum(a, i + 1);
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << recursiveSum(a, 0) << "\n";
    return 0;
}