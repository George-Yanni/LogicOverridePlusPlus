# Mysterious Present

**Problem Reference:** [Codeforces 4D - Mysterious Present](https://codeforces.com/contest/4/problem/D)  
**Algorithm:** Sort + Dynamic Programming (LIS with parent reconstruction)  
**Complexity:** $O(n^2)$ Time | $O(n)$ Space  
 
## 1. Problem Definition
Given a card of size $(w, h)$ and $n$ envelopes $(w_i, h_i)$, find the longest chain where each envelope strictly fits into the next one:
- $w_i < w_j$ and $h_i < h_j$
- The first envelope in the chain must be strictly larger than the card

Output the maximum chain length and one valid sequence of envelope indices.

## 2. Key Idea
Filter out any envelope that cannot hold the card, then sort the remaining envelopes:
- Primary: width ascending
- Secondary: height ascending

This makes the chain check simple: for each pair $(j < i)$, we only need to ensure both dimensions are strictly increasing.

## 3. Dynamic Programming
Let $dp[i]$ be the length of the longest chain ending at envelope $i$ in the sorted list.

Transition:
- $dp[i] = 1 + \max(dp[j])$ for all $j < i$ where $w_j < w_i$ and $h_j < h_i$
- Maintain a `parent[i]` to reconstruct the path

## 4. Reconstruction
Track the index with the maximum $dp[i]$, then follow `parent` pointers backward to output the envelope indices in order.

## 5. Example (condensed)
Card: $(3, 3)$  
Envelopes: $(5, 4)$, $(12, 11)$, $(9, 8)$  
Sorted: $(5, 4) \to (9, 8) \to (12, 11)$  
Chain length: 3, path: 1, 3, 2

## 6. Conclusion
Filtering + sorting reduces the problem to a classic LIS-style DP with path reconstruction, which is efficient for $n \le 5000$.

*Written by: George Yanni*