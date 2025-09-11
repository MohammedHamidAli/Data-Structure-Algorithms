#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // Required for std::pair

// Use the standard namespace to avoid prefixing std::
using namespace std;

/**
 * @brief Calculates the minimum number of platforms required for a train station.
 * This function determines the minimum number of platforms needed to ensure
 * no train has to wait for another to leave.
 * @param arrivals A vector of train arrival times.
 * @param departures A vector of train departure times.
 * @return The minimum number of platforms required. Returns -1 if the number of arrivals and departures do not match.
 */
int findMinPlatforms(vector<int> arrivals, vector<int> departures) {
    if (arrivals.size() != departures.size()) {
        return -1; // Mismatched data
    }

    // Sort both arrival and departure times in ascending order.
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    int platforms_needed = 1;
    int result = 1;
    int i = 1; // Pointer for arrivals
    int j = 0; // Pointer for departures
    int n = arrivals.size();

    // Iterate through all events (arrivals and departures) chronologically.
    while (i < n && j < n) {
        // If the next event is an arrival, we need one more platform.
        if (arrivals[i] <= departures[j]) {
            platforms_needed++;
            i++;
        }
        // If the next event is a departure, one platform becomes free.
        else {
            platforms_needed--;
            j++;
        }

        // Update the maximum number of platforms needed so far.
        if (platforms_needed > result) {
            result = platforms_needed;
        }
    }

    return result;
}

// --- Example Usage ---
int main() {
    vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departures = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Train Arrival Times:   ";
    for (int time : arrivals) {
        cout << time << " ";
    }
    cout << endl;

    cout << "Train Departure Times: ";
    for (int time : departures) {
        cout << time << " ";
    }
    cout << endl;
    cout << "------------------------------" << endl;

    int minPlatforms = findMinPlatforms(arrivals, departures);

    if (minPlatforms != -1) {
        cout << "Minimum number of platforms required: " << minPlatforms << endl;
    } else {
        cout << "Error: The number of arrival and departure times must be the same." << endl;
    }

    return 0;
}
