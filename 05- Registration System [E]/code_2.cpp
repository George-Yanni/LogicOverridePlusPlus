#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // This map stores: name -> current count
    map<string, int> database;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (database.count(name) == 0) {
            // It's a brand new name
            cout << "OK\n";
            database[name] = 1; // Mark that we've seen it once
        } else {
            // We have seen this name before.
            // The suffix should be the current count stored in the map.
            cout << name << database[name] << "\n";

            // Increment the count for this name so the next person
            // gets the next number (e.g., name2, name3...)
            database[name]++;
        }
    }

    return 0;
}
