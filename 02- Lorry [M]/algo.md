# Lorry

**Problem Reference:** [Codeforces 3B - Lorry](https://codeforces.com/contest/3/problem/B)  
**Algorithm:** Greedy Selection with Prefix Sums  
**Complexity:** $O(N \log N)$ Time | $O(N)$ Space  
 

## 1. Problem Definition
A lorry with capacity $V$ must be loaded with waterborne vehicles of two types:
1. **Kayaks:** volume 1, carrying capacity $p_i$.
2. **Catamarans:** volume 2, carrying capacity $p_i$.

The goal is to maximize the total carrying capacity and output the chosen indices.


## 2. The Algorithmic Challenge
The classic knapsack DP is not feasible because $V$ can be as large as $10^9$.  
However, only two volumes exist (1 and 2), so we can optimize with sorting and prefix sums.


## 3. Greedy + Prefix Sums Strategy

### Phase 1: Sort by Value
Split the vehicles into two lists and sort each in descending order of $p_i$:
* Kayaks (volume 1)
* Catamarans (volume 2)

This guarantees that the top $k$ items of each list are the best possible choices.

### Phase 2: Prefix Sums
Compute prefix sums for both lists:
* `prefixKayaks[k]` = total capacity of the best $k$ kayaks.
* `prefixCats[c]` = total capacity of the best $c$ catamarans.

This lets us evaluate any selection in $O(1)$ time.

### Phase 3: Exhaustive Search on Kayaks
For each feasible number of kayaks $k$:
1. Remaining volume is $V_{rem} = V - k$.
2. Maximum catamarans is $c = \min(\text{total cats}, \lfloor V_{rem} / 2 \rfloor)$.
3. Total capacity is `prefixKayaks[k] + prefixCats[c]`.

Track the configuration with the highest total capacity and then output the indices of the chosen items.


## 4. Complexity Analysis
* **Time Complexity:** $O(N \log N)$ for sorting; the scan is $O(N)$.
* **Space Complexity:** $O(N)$ for the lists and prefix sums.


## 5. Conclusion
By sorting each type and using prefix sums, we reduce the problem to a single linear scan over the number of kayaks. This guarantees the maximum total capacity within the volume constraint.

*Written by: George Yanni*