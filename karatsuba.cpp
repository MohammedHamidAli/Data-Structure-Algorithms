// karatsuba
#include <iostream>
#include <string> // It's good practice to include <string> for to_string
#include <cmath>
#include <algorithm> // It's good practice to include <algorithm> for max

using namespace std;

long long karatsuba(long long x, long long y){
    // Base case for recursion
    if (x < 10 || y < 10){
        return x * y;
    }

    // Calculate the size of the numbers
    int m = max(to_string(x).length(), to_string(y).length());
    int m2 = m / 2;

    // Split the numbers into two halves
    long long power = pow(10, m2);
    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    // Recursive steps
    long long ac = karatsuba(a, c);                // z2
    long long bd = karatsuba(b, d);                // z0
    long long ab_cd = karatsuba((a + b), (c + d)); // z1

    // Combine the results using the Karatsuba formula
    // The error was here: it should be + bd at the end, not - bd
    return (ac * pow(10, m2 * 2)) + ((ab_cd - ac - bd) * power) + bd;
}

int main(){
    long long x =1234, y=5678;
    // cout << "Enter first number: ";
    // cin >> x;
    // cout << "Enter second number: ";
    // cin >> y;
    long long result = karatsuba(x, y);
    cout << x << " * " << y << " = " << result << endl;
    cout << "Correct answer: " << x * y << endl; // For verification
    return 0;
}