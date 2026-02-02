// Written by: George Yanni
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int d, sumTime;
    if (!(cin >> d >> sumTime)) return 0;

    vector<int> minTime(d), maxTime(d);
    int minTotal = 0, maxTotal = 0;

    for (int i = 0; i < d; ++i) {
        cin >> minTime[i] >> maxTime[i];
        minTotal += minTime[i];
        maxTotal += maxTime[i];
    }

    // Check if it's even possible
    if (sumTime < minTotal || sumTime > maxTotal) {
        cout << "NO" << endl;
        return 0;
    }

    // If we reach here, the answer is YES
    cout << "YES" << endl;

    // Start everyone at their minimum
    vector<int> schedule = minTime;
    int currentSum = minTotal;

    // Distribute the remaining hours needed
    for (int i = 0; i < d; ++i) {
        // How much more can we add to this specific day?
        int canAdd = maxTime[i] - minTime[i];
        
        // How much do we still need to reach sumTime?
        int stillNeed = sumTime - currentSum;

        if (stillNeed > 0) {
            // Take either what we need, or the maximum the day allows
            int amountToAdd = min(canAdd, stillNeed);
            schedule[i] += amountToAdd;
            currentSum += amountToAdd;
        }
    }

    // Print the final timetable
    for (int i = 0; i < d; ++i) {
        cout << schedule[i] << (i == d - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
