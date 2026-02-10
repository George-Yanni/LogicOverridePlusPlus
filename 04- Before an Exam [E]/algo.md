# Before an Exam

**Problem Reference:** [Codeforces 4B - Before an Exam](https://codeforces.com/contest/4/problem/B)  
**Algorithm:** Feasibility Check + Greedy Distribution  
**Complexity:** $O(d)$ Time | $O(d)$ Space  
 
## 1. Problem Definition
We have $d$ days. Each day $i$ requires study time within a range $[l_i, r_i]$.  
Given a target total time $S$, decide if it is possible to choose daily study times that sum to $S$, and output any valid schedule.

## 2. Feasibility Bounds
Let:
* $L = \sum l_i$ (minimum possible total)
* $R = \sum r_i$ (maximum possible total)

If $S < L$ or $S > R$, no schedule can exist.

## 3. Greedy Construction
Start with the minimal schedule:
* `ans[i] = l_i`
* Remaining time: `rem = S - L`

Distribute `rem` day by day:
* Each day can receive at most `r_i - l_i` extra.
* Add `add = min(rem, r_i - l_i)` to `ans[i]`.
* Decrease `rem` by `add`.

This always succeeds because the remaining capacity over all days is $R - L$, and `rem <= R - L`.

## 4. Complexity Analysis
* **Time Complexity:** $O(d)$
* **Space Complexity:** $O(d)$

## 5. Conclusion
The solution relies on a simple feasibility check and a greedy distribution of the remaining time. Any distribution that respects the per-day limits will work.

*Written by: George Yanni*
