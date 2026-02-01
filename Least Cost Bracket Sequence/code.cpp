// Created By: George Yanni
#include <iostream>
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    string s;
    if (!(cin >> s))
        return 0;
 
    // Min-heap to keep track of the cheapest '?' to flip to '('
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
    ll total_cost = 0;
    int balance = 0;
 
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            balance++;
        }
        else if (s[i] == ')')
        {
            balance--;
        }
        else
        { // It's a '?'
            ll a, b;
            cin >> a >> b;
            s[i] = ')'; // Assume it's a closing bracket
            balance--;
            total_cost += b;
            pq.push({a - b, i}); // Store the "cost to regret"
        }
 
        // Emergency Fix
        if (balance < 0)
        {
            if (pq.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            pair<ll, int> best = pq.top();
            pq.pop();
            total_cost += best.first; // Pay the difference to make it '('
            s[best.second] = '(';
            balance += 2; // -1 becomes +1
        }
    }
 
    if (balance != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << total_cost << endl;
        cout << s << endl;
    }
 
    return 0;
}