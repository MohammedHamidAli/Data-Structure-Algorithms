#include <iostream>
using namespace std;

void fibonacci(int n) {
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    fibonacci(n);
    return 0;
}
