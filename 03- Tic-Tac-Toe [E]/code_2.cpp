#include <bits/stdc++.h>
using namespace std;

// Predefined winning configurations as bitmasks
const int wins[] = {
    7, 56, 448,   // Rows: 000000111, 000111000, 111000000
    73, 146, 292, // Cols: 001001001, 010010010, 100100100
    273, 84       // Diagonals: 100010001, 001010100
};

bool check_win(int mask)
{
    for (int win_mask : wins)
    {
        if ((mask & win_mask) == win_mask)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x_mask = 0, o_mask = 0;
    int x_count = 0, o_count = 0;

    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        if (c == 'X')
        {
            x_mask |= (1 << i);
            x_count++;
        }
        else if (c == '0')
        {
            o_mask |= (1 << i);
            o_count++;
        }
    }

    bool x_won = check_win(x_mask);
    bool o_won = check_win(o_mask);

    // Illegal Checks
    if (o_count > x_count || x_count > o_count + 1 || (x_won && o_won))
    {
        cout << "illegal" << endl;
    }
    else if (x_won && x_count != o_count + 1)
    {
        cout << "illegal" << endl;
    }
    else if (o_won && x_count != o_count)
    {
        cout << "illegal" << endl;
    }
    // Result Checks
    else if (x_won)
    {
        cout << "the first player won" << endl;
    }
    else if (o_won)
    {
        cout << "the second player won" << endl;
    }
    else if (x_count + o_count == 9)
    {
        cout << "draw" << endl;
    }
    else if (x_count == o_count)
    {
        cout << "first" << endl;
    }
    else
    {
        cout << "second" << endl;
    }

    return 0;
}

