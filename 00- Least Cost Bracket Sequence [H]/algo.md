
# Optimal Construction of Regular Bracket Sequences

**Problem Reference:** [Codeforces 3D - Least Cost Bracket Sequence](https://codeforces.com/contest/3/problem/D)  
**Algorithm:** Greedy with Regret (Priority Queue Optimization)  
**Complexity:** $O(N \log N)$ Time | $O(N)$ Space  



## 1. Problem Definition
The objective is to complete a bracket pattern string $S$ (containing `(`, `)`, and `?`) to form a **Regular Bracket Sequence (RBS)** at the minimum possible cost. 

For each `?`, we are given:
* $a_i$: Cost to replace `?` with `(`.
* $b_i$: Cost to replace `?` with `)`.

### Requirements for a Regular Sequence:
1.  **Prefix Property:** At any index $i$, the number of open brackets must be $\ge$ the number of closed brackets ($\text{balance} \ge 0$).
2.  **Equilibrium Property:** At the final index $N$, the total number of open brackets must exactly equal the total number of closed brackets ($\text{balance} = 0$).



## 2. The Algorithmic Challenge
A traditional Dynamic Programming approach $O(N \cdot \text{balance})$ would require a $50,000 \times 25,000$ table. This would exceed the **64 MB memory limit** and the **1-second time limit**. 

To solve this efficiently, we use a **Greedy approach with a Priority Queue**, allowing the algorithm to "undo" suboptimal choices when they threaten the sequence's validity.





## 3. The "Greedy with Regret" Strategy

### Phase 1: The Optimistic Choice
We process the string from left to right. To minimize cost initially, we make a "cheap" assumption for every `?`:
* We treat the `?` as a closing bracket `)`.
* We add the cost $b_i$ to our total cost.
* We decrement our `balance` counter.

### Phase 2: Storing the "Regret"
Since we might be forced to change this `)` to a `(` later to satisfy the Prefix Property, we store a **Regret Note** in a **Min-Priority Queue**. This note contains:
* **Cost Difference ($\Delta$):** $(a_i - b_i)$. This is the exact price we pay to "flip" our choice.
* **Position:** The index of the character in the string.

### Phase 3: The Emergency Correction
If the `balance` ever drops below $0$:
1.  We have too many closing brackets. The sequence is currently invalid.
2.  We reach into our Priority Queue and extract the **cheapest flip** (the smallest $\Delta$).
3.  We update the character at that index to `(`.
4.  We update the total cost: `TotalCost += Δ`.
5.  We update the balance: `balance += 2` (Changing a $-1$ to a $+1$ results in a net gain of 2).





## 4. Illustrative Trace
**Input:** `(??)`  
**Costs:** `?1 (1, 2)`, `?2 (2, 8)`

| Index | Char | Action | Balance | Cost | Priority Queue ($\Delta$) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | `(` | Fixed | 1 | 0 | `[]` |
| 1 | `?` | Assume `)` | 0 | 2 | `[ (1-2) = -1 ]` |
| 2 | `?` | Assume `)` | **-1** | $2+8=10$ | `[ -1, (2-8)=-6 ]` |
| **FIX** | - | **Flip idx 2**| **1** | $10 + (-6) = \mathbf{4}$ | `[ -1 ]` |
| 3 | `)` | Fixed | 0 | 4 | `[ -1 ]` |

**Final Result:** `()()` with Total Cost **4**.



## 5. Implementation Complexity
* **Time Complexity:** $O(N \log N)$. Each character is visited once, and Priority Queue operations take logarithmic time.
* **Space Complexity:** $O(N)$. We store the string and the cost-difference notes for each `?`.

## 6. Conclusion
The "Greedy with Regret" approach is the most robust solution for the **Least Cost Bracket Sequence** problem. It ensures that the strict mathematical properties of bracket nesting are met while mathematically guaranteeing the global minimum cost through a Min-Heap optimization.


*Written by: George Yanni*