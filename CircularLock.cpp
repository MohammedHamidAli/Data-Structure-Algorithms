#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

// Use the standard namespace to avoid prefixing std::
using namespace std;

/**
 * @brief Calculates the minimum number of moves to change a circular lock from a starting combination to a target combination.
 * * Each wheel has 10 digits (0-9). For each wheel, the function calculates the shortest
 * distance between the start and target digit, which is the minimum of moving
 * forward or backward.
 * * @param start The starting combination of the lock as a string.
 * @param target The target combination of the lock as a string.
 * @return The minimum total number of moves required. Returns -1 if combinations have different lengths.
 */
int minMovesCircularLock(const string& start, const string& target) {
    // Check if the combinations are of the same length. If not, it's impossible.
    if (start.length() != target.length()) {
        return -1; 
    }

    int totalMoves = 0;
    int n = start.length();

    // Iterate through each wheel of the lock
    for (int i = 0; i < n; ++i) {
        // Convert char digits to int
        int startDigit = start[i] - '0';
        int targetDigit = target[i] - '0';

        // Calculate the absolute difference between the digits
        int diff = abs(startDigit - targetDigit);

        // The number of moves for the current wheel is the minimum of moving
        // forward (diff) or backward (10 - diff) around the circle.
        int movesForWheel = min(diff, 10 - diff);
        
        totalMoves += movesForWheel;
    }

    return totalMoves;
}

// --- Example Usage ---
int main() {
    string startCombination = "129";
    string targetCombination = "341";

    cout << "Starting combination: " << startCombination << endl;
    cout << "Target combination:   " << targetCombination << endl;

    int moves = minMovesCircularLock(startCombination, targetCombination);

    if (moves != -1) {
        cout << "------------------------------" << endl;
        cout << "Minimum number of moves required: " << moves << endl;
        // Explanation:
        // Wheel 1 (1 -> 3): min(|3-1|, 10-|3-1|) = min(2, 8) = 2 moves
        // Wheel 2 (2 -> 4): min(|4-2|, 10-|4-2|) = min(2, 8) = 2 moves
        // Wheel 3 (9 -> 1): min(|1-9|, 10-|1-9|) = min(8, 2) = 2 moves
        // Total moves = 2 + 2 + 2 = 6
    } else {
        cout << "Error: Combinations must be of the same length." << endl;
    }

    return 0;
}
