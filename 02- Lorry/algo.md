
## Problem Link
[Codeforces - 3B. Lorry](https://codeforces.com/contest/3/problem/B)

## Problem Statement
A rectangular lorry with a capacity of $V$ is to be loaded with waterborne vehicles. There are two types of vehicles:
1. **Kayaks**: volume is 1, carrying capacity is $p_i$.
2. **Catamarans**: volume is 2, carrying capacity is $p_i$.

Find the maximum total carrying capacity that can be carried by the lorry and the indices of the vehicles to be loaded.

## Logic
The problem is a variation of the Knapsack problem. Since the volume $V$ can be up to $10^9$, a standard Dynamic Programming approach is not feasible. However, because there are only two types of items (volumes 1 and 2), we can use a **Greedy + Prefix Sums** approach:

1. **Sort Greedily**: Separate the vehicles into two lists (Kayaks and Catamarans). Sort both lists in descending order of their carrying capacity. This ensures that if we pick $k$ vehicles of a certain type, they are the most valuable ones.
2. **Prefix Sums**: Precalculate the cumulative capacity for both lists. This allows us to calculate the total capacity of $k$ items in $O(1)$ time.
3. **Exhaustive Search**: 
   - Iterate through the number of Kayaks ($k$) we could potentially take (from 0 to the total number of kayaks available, or up to volume $V$).
   - For each $k$, calculate the remaining volume: $V_{rem} = V - k$.
   - The number of Catamarans we can then fit is $c = \min(\text{total catamarans}, \lfloor V_{rem} / 2 \rfloor)$.
   - The total capacity for this configuration is $\text{prefixSumKayaks}[k] + \text{prefixSumCatamarans}[c]$.



4. **Complexity**: Sorting takes $O(N \log N)$, and the iteration takes $O(N)$.The overall complexity is $O(N \log N)$, which fits within the time limit.

*Written by: George Yanni*