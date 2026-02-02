#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   vector<string> g(3);
   int x_count = 0, o_count = 0;
   for (int i = 0; i < 3; i++)
   {
      cin >> g[i];
      for (char c : g[i])
      {
         if (c == 'X')
            x_count++;
         else if (c == '0')
            o_count++;
      }
   }

   bool x_won = false, o_won = false;

   // Check rows and columns
   for (int i = 0; i < 3; i++)
   {
      if (g[i][0] == 'X' && g[i][1] == 'X' && g[i][2] == 'X')
         x_won = true;
      if (g[0][i] == 'X' && g[1][i] == 'X' && g[2][i] == 'X')
         x_won = true;
      if (g[i][0] == '0' && g[i][1] == '0' && g[i][2] == '0')
         o_won = true;
      if (g[0][i] == '0' && g[1][i] == '0' && g[2][i] == '0')
         o_won = true;
   }

   // Check diagonals
   if (g[0][0] == 'X' && g[1][1] == 'X' && g[2][2] == 'X')
      x_won = true;
   if (g[0][2] == 'X' && g[1][1] == 'X' && g[2][0] == 'X')
      x_won = true;
   if (g[0][0] == '0' && g[1][1] == '0' && g[2][2] == '0')
      o_won = true;
   if (g[0][2] == '0' && g[1][1] == '0' && g[2][0] == '0')
      o_won = true;

   // --- State Logic ---

   // 1. Illegal conditions
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
   // 2. Win conditions
   else if (x_won)
   {
      cout << "the first player won" << endl;
   }
   else if (o_won)
   {
      cout << "the second player won" << endl;
   }
   // 3. Game state conditions
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

