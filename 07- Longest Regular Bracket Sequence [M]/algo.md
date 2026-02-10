# Longest Regular Bracket Sequence

**Problem Reference:** [Codeforces 5A - Longest Regular Bracket Sequence](https://codeforces.com/contest/5/problem/C)  
**Algorithm:** Stack + Dynamic Programming  
**Complexity:** $O(n)$ Time | $O(n)$ Space  

## 1. Problem Definition
Given a string containing only `(` and `)`, find:
- The length of the longest **Regular Bracket Sequence (RBS)** in the string
- The number of occurrences of this maximum length

A Regular Bracket Sequence is a balanced sequence where:
- Every opening bracket `(` has a matching closing bracket `)`
- The sequence is properly nested

## 2. Key Insight
The challenge is that valid RBS sequences can be **adjacent** to each other. For example, in `()()`, we have two adjacent RBS of length 2, but we want to recognize that they can be combined.

## 3. The Algorithm: Stack + DP

### Phase 1: Matching Brackets with Stack
We use a stack to track the indices of opening brackets `(`:
- When we see `(`, push its index onto the stack
- When we see `)`, if the stack is not empty, we have a match

### Phase 2: Dynamic Programming
Let `dp[i]` be the length of the longest RBS ending at index `i`.

When we find a matching pair `(open_idx, i)`:
1. The base length is `i - open_idx + 1` (the matched pair itself)
2. **Critical addition:** If there was a valid RBS ending right before `open_idx`, we add its length:
   - `dp[i] = (i - open_idx + 1) + dp[open_idx - 1]`

This handles the case where multiple RBS are adjacent: `()()` becomes `dp[3] = 2 + dp[1] = 2 + 2 = 4`.

### Phase 3: Finding Maximum and Count
After processing all characters:
- Find the maximum value in `dp[]`
- Count how many times this maximum appears
- If maximum is 0, output `0 1` (no valid RBS, but we still need to output a count)

## 4. Example Walkthrough
Input: `()(())`

| Index | Char | Stack | dp[i] | Explanation |
|-------|------|-------|-------|-------------|
| 0 | `(` | [0] | 0 | Opening bracket |
| 1 | `)` | [] | 2 | Match with index 0, length = 2 |
| 2 | `(` | [2] | 0 | Opening bracket |
| 3 | `(` | [2,3] | 0 | Opening bracket |
| 4 | `)` | [2] | 2 | Match with index 3, length = 2 |
| 5 | `)` | [] | 6 | Match with index 2, length = 4, plus dp[1] = 2, total = 6 |

Maximum length: 6, count: 1

## 5. Complexity Analysis
- **Time Complexity:** $O(n)$ - single pass through the string
- **Space Complexity:** $O(n)$ - stack and DP array

## 6. Conclusion
The combination of stack-based matching and dynamic programming elegantly handles both nested and adjacent RBS sequences. The key insight is adding the length of any RBS that ends immediately before the current opening bracket.

*Written by: George Yanni*
