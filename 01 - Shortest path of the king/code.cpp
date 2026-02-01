// Written by: George Yanni
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    // Convert algebraic notation (a1) to coordinates (0,0)
    int x1 = s[0] - 'a', y1 = s[1] - '1';
    int x2 = t[0] - 'a', y2 = t[1] - '1';

    // Total moves is the max of the horizontal and vertical differences
    int total_moves = max(abs(x2 - x1), abs(y2 - y1));
    cout << total_moves << endl;

    while (x1 != x2 || y1 != y2) {
        string move = "";

        // Horizontal component
        if (x1 < x2) {
            move += "R";
            x1++;
        } else if (x1 > x2) {
            move += "L";
            x1--;
        }

        // Vertical component
        if (y1 < y2) {
            move += "U";
            y1++;
        } else if (y1 > y2) {
            move += "D";
            y1--;
        }

        cout << move << endl;
    }

    return 0;
}