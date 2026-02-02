// written by George Yanni
#include <bits/stdc++.h>
using namespace std;

using namespace std;

struct Envelope
{
    int w, h, id;
};

// Sort by width, then by height
bool compareEnvelopes(const Envelope &a, const Envelope &b)
{
    if (a.w != b.w)
        return a.w < b.w;
    return a.h < b.h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cw, ch;
    if (!(cin >> n >> cw >> ch))
        return 0;

    vector<Envelope> envs;
    for (int i = 1; i <= n; ++i)
    {
        int w, h;
        cin >> w >> h;
        // Step 1: Filter - only keep envelopes larger than the card
        if (w > cw && h > ch)
        {
            envs.push_back({w, h, i});
        }
    }

    if (envs.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    // Step 2: Sort
    sort(envs.begin(), envs.end(), compareEnvelopes);

    int m = envs.size();
    vector<int> dp(m, 1);
    vector<int> parent(m, -1);

    // Step 3: DP - O(n^2)
    int max_len = 0;
    int best_idx = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (envs[i].w > envs[j].w && envs[i].h > envs[j].h)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > max_len)
        {
            max_len = dp[i];
            best_idx = i;
        }
    }

    // Step 4: Reconstruct Path
    cout << max_len << endl;
    vector<int> path;
    for (int i = best_idx; i != -1; i = parent[i])
    {
        path.push_back(envs[i].id);
    }

    // Print in correct order (smallest to largest)
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i] << (i == 0 ? "" : " ");
    }
    cout << endl;

    return 0;
}