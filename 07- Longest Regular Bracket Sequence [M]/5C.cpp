// Longest Regular Bracket Sequence
// George Yanni
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string RBS;
    cin >> RBS;
    int n = RBS.length();

    // This will store the length of the RBS ending at index i
    vector<int> dp(n, 0);
    stack<int> s; // To store indices of '('

    for (int i = 0; i < n; i++)
    {
        if (RBS[i] == '(')
        {
            s.push(i);
        }
        else
        {
            // We found a ')', check if there's a matching '('
            if (!s.empty())
            {
                int open_idx = s.top();
                s.pop();

                // The length of the match between open_idx and i
                int current_match_len = i - open_idx + 1;

                // ADDITION: If there was an RBS ending right before our open_idx,
                // we must add its length to our current one.
                if (open_idx > 0)
                {
                    current_match_len += dp[open_idx - 1];
                }

                dp[i] = current_match_len;
            }
        }
    }

    // Now we look for the max value and its frequency
    int max_len = 0;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            count = 1;
        }
        else if (dp[i] == max_len && max_len > 0)
        {
            count++;
        }
    }

    if (max_len == 0)
    {
        cout << "0 1" << endl;
    }
    else
    {
        cout << max_len << " " << count << endl;
    }

    return 0;
}
