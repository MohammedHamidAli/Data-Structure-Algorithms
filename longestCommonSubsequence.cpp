#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Use the standard namespace to avoid prefixing std::
using namespace std;

/**
 * @brief Calculates the length of the Longest Common Subsequence of two strings.
 * This function uses a dynamic programming approach to find the length of the LCS.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The length of the longest common subsequence.
 */
int findLCSLength(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a DP table (matrix) to store the lengths of LCSs.
    // dp[i][j] will store the length of LCS of s1[0..i-1] and s2[0..j-1].
    // Initialize with all zeros.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in a bottom-up manner.
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If the characters at the current positions match,
            // the LCS is one character longer than the LCS of the strings without these characters.
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            // If the characters do not match, the LCS is the longer of the two possibilities:
            // 1. LCS of s1[0..i-2] and s2[0..j-1]
            // 2. LCS of s1[0..i-1] and s2[0..j-2]
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The value at the bottom-right corner of the table is the length of the LCS
    // for the entire strings.
    return dp[m][n];
}

// --- Example Usage ---
int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "------------------------------" << endl;

    int length = findLCSLength(str1, str2);

    cout << "Length of the Longest Common Subsequence is: " << length << endl;
    // For "AGGTAB" and "GXTXAYB", the LCS is "GTAB", so the length is 4.

    return 0;
}
