// too slow solution for large inputs
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> registeredNames;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (find(registeredNames.begin(), registeredNames.end(), name) != registeredNames.end()) {
            int suffix = 1;
            string newName = name + to_string(suffix);
            while (find(registeredNames.begin(), registeredNames.end(), newName) != registeredNames.end()) {
                suffix++;
                newName = name + to_string(suffix);
            }
            registeredNames.push_back(newName);
            cout << newName << "\n";
        } else {
            registeredNames.push_back(name);
            cout << "OK\n";
        }
    }
}
