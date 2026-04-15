#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a Job
struct Job {
    char id;      // Job ID
    int dead;     // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

// Comparator function to sort jobs in descending order of profit
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n) {
    // 1. Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);

    vector<int> result(n); // To store result (Sequence of jobs)
    vector<bool> slot(n, false); // To keep track of free time slots
    int totalProfit = 0;
    int countJobs = 0;

    // 2. Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                totalProfit += arr[i].profit;
                countJobs++;
                break;
            }
        }
    }
    // Print the sequence
    cout << "Following is the maximum profit sequence of jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\nTotal Jobs Scheduled: " << countJobs;
    cout << "\nTotal Profit: " << totalProfit << endl;
}
int main() {
    // Example set of jobs
    Job arr[] = { {'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27},
                  {'D', 1, 25}, {'E', 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printJobScheduling(arr, n);
    return 0;
}
