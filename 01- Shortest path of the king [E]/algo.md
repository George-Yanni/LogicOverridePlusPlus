# Shortest Path of the King

**Problem Reference:** [Codeforces 3A - Shortest path of the king](https://codeforces.com/contest/3/problem/A)  
**Algorithm:** Greedy Coordinate Alignment (Chebyshev Distance)  
**Complexity:** $O(1)$ Time | $O(1)$ Space (Fixed 8x8 Board)



## 1. Problem Definition
On a standard $8 \times 8$ chessboard, a King is placed at a starting square $s$ and needs to reach a target square $t$ in the minimum number of moves. 

### King's Movement Rules:
A King can move exactly one square in any direction:
* **Horizontal:** Left (`L`), Right (`R`)
* **Vertical:** Up (`U`), Down (`D`)
* **Diagonal:** Combined moves like `LU`, `LD`, `RU`, `RD`

The goal is to output the total number of moves and the exact sequence of strings representing those moves.



## 2. Geometric Interpretation
In a grid system where diagonal moves cost the same as straight moves (1 step), the distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ is defined by the **Chebyshev Distance**:

$$D = \max(|x_2 - x_1|, |y_2 - y_1|)$$



While a "Manhattan" distance (taxicab) would force us to travel the horizontal and vertical distances separately ($|dx| + |dy|$), the King's ability to move diagonally allows us to "overlap" these distances.


## 3. The Algorithm: Greedy Alignment
To minimize the steps, we must maximize the number of diagonal moves. A diagonal move is possible as long as the King is not yet aligned with the target on *either* the x-axis or the y-axis.

### Step-by-Step Logic:
1.  **Coordinate Conversion:** Translate the algebraic notation (e.g., `a1`, `h8`) into a coordinate system $(0-7, 0-7)$.
    * `x = char - 'a'`
    * `y = char - '1'`
2.  **Distance Calculation:** The total number of moves is $\max(|dx|, |dy|)$.
3.  **Path Execution:** While the King's current position $(x_1, y_1)$ is not equal to the target $(x_2, y_2)$:
    * **Horizontal Check:** If $x_1 < x_2$, move `R`. If $x_1 > x_2$, move `L`.
    * **Vertical Check:** If $y_1 < y_2$, move `U`. If $y_1 > y_2$, move `D`.
    * Combine these directions into a single string (e.g., `R` + `U` = `RU`).
    * Print the move and update the current coordinates by $\pm 1$ accordingly.





## 4. Illustrative Trace
**Input:** `a8` (Start) to `h1` (Target)

* **Initial:** $x_1=0, y_1=7$ | $x_2=7, y_2=0$
* **$dx = 7, dy = -7$** $\rightarrow$ **Total Moves: 7**

| Step | Current | Target | Move String | Logic |
| :--- | :--- | :--- | :--- | :--- |
| 1 | `a8` | `h1` | `RD` | $x_1 < x_2$ and $y_1 > y_2$ |
| 2 | `b7` | `h1` | `RD` | Diagonal move continued |
| ... | ... | ... | ... | ... |
| 7 | `g2` | `h1` | `RD` | Target reached at `h1` |



## 5. Complexity Analysis
* **Time Complexity:** $O(1)$. Since the board is limited to $8 \times 8$, the maximum number of iterations is 7. In a generalized $N \times N$ board, the complexity would be $O(N)$.
* **Space Complexity:** $O(1)$. We only store a few integer variables and the move strings.

## 6. Conclusion
The problem is a straightforward application of the Chebyshev distance. By greedily moving diagonally as often as possible, the King reduces the distance in both dimensions simultaneously, ensuring the path is the shortest possible.


*Written by: George Yanni*