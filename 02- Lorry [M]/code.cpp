// Written by: George Yanni
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Boat
{
    int id;
    int capacity;
};

// Comparison function to sort boats from strongest to weakest
bool compareBoats(const Boat &a, const Boat &b)
{
    return a.capacity > b.capacity;
}

int main()
{
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long V;
    cin >> n >> V;

    vector<Boat> kayaks, catamarans;

    for (int i = 1; i <= n; i++)
    {
        int type, cap;
        cin >> type >> cap;
        if (type == 1)
            kayaks.push_back({i, cap});
        else
            catamarans.push_back({i, cap});
    }

    // Sort both groups by capacity descending
    sort(kayaks.begin(), kayaks.end(), compareBoats);
    sort(catamarans.begin(), catamarans.end(), compareBoats);

    // Prefix sums for Kayaks
    int k_count = kayaks.size();
    vector<long long> sum1(k_count + 1, 0);
    for (int i = 0; i < k_count; i++)
    {
        sum1[i + 1] = sum1[i] + kayaks[i].capacity;
    }

    // Prefix sums for Catamarans
    int c_count = catamarans.size();
    vector<long long> sum2(c_count + 1, 0);
    for (int i = 0; i < c_count; i++)
    {
        sum2[i + 1] = sum2[i] + catamarans[i].capacity;
    }

    long long max_capacity = -1;
    int best_k = 0, best_c = 0;

    // Try every possible number of kayaks (i)
    // i cannot exceed the total number of kayaks we have
    // i cannot exceed the total volume V
    for (int i = 0; i <= k_count && i <= V; i++)
    {
        long long current_capacity = sum1[i];
        long long remaining_v = V - i;

        // How many catamarans can we fit in the remaining volume?
        // Each catamaran takes 2 slots.
        int can_take_c = min((long long)c_count, remaining_v / 2);

        current_capacity += sum2[can_take_c];

        if (current_capacity > max_capacity)
        {
            max_capacity = current_capacity;
            best_k = i;
            best_c = can_take_c;
        }
    }

    // Output the max capacity found
    cout << max_capacity << "\n";

    // Output the IDs of the boats used
    bool first = true;
    for (int i = 0; i < best_k; i++)
    {
        if (!first)
            cout << " ";
        cout << kayaks[i].id;
        first = false;
    }
    for (int i = 0; i < best_c; i++)
    {
        if (!first)
            cout << " ";
        cout << catamarans[i].id;
        first = false;
    }
    cout << endl;

    return 0;
}