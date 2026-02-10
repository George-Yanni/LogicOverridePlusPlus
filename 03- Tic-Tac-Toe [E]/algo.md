# Tic-Tac-Toe

**Problem Reference:** [Codeforces 3C - Tic-Tac-Toe](https://codeforces.com/contest/3/problem/C)   
**Approach 1:** Direct board scan (rows, columns, diagonals)  
**Approach 2:** Bitmask board representation  
**Complexity:** $O(1)$ Time | $O(1)$ Space
 
## 1. Problem Summary
Given a 3x3 Tic-Tac-Toe board state, determine whether it is a legal position and identify the correct outcome:
- `illegal`
- `the first player won`
- `the second player won`
- `draw`
- `first` (next move is X)
- `second` (next move is O)

The first player uses `X`, the second uses `0`.

## 2. Validity Rules
A position is illegal if:
- The counts are impossible: `O > X` or `X > O + 1`.
- Both players have a winning line.
- A player has a winning line but the counts do not match the turn order:
  - If `X` wins, then `X = O + 1`.
  - If `0` wins, then `X = O`.

If the position is legal and no one wins:
- If the board is full, it is a `draw`.
- Otherwise, if `X == O` then `first`, else `second`.

## 3. Approach 1: Direct Scan (`3C_1.cpp`)
1. Read the 3 lines, count `X` and `0`.
2. Scan all 3 rows, all 3 columns, and the 2 diagonals.
3. Apply the legality rules and print the correct outcome.

This is the straightforward method and mirrors the board exactly.

## 4. Approach 2: Bitmask (`3C_2.cpp`)
1. Map the 3x3 board into 9 bits (row-major order).
2. Build two masks: `x_mask` and `o_mask`.
3. Precompute the 8 winning bitmasks (3 rows, 3 cols, 2 diagonals).
4. A player wins if their mask fully contains any winning mask.
5. Apply the same legality and outcome rules as in Approach 1.

This method is compact and useful in problems where many boards are processed.

## 5. Conclusion
Both solutions implement the same rules, but differ in representation:
- `3C_1.cpp` uses direct grid checks for clarity.
- `3C_2.cpp` uses bit operations for conciseness.

*Written by: George Yanni*

