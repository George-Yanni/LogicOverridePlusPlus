# Registration System

**Problem Reference:** [Codeforces 4C - Registration System](https://codeforces.com/contest/4/problem/C)  
**Algorithm:** Hash Map Counting (plus naive baseline)  
**Complexity:** $O(n \log n)$ Time | $O(n)$ Space  

## 1. Problem Definition
We receive $n$ username requests.  
For each name:
- If it is new, output `OK`.
- If it already exists, output the name plus the smallest positive integer suffix that makes it unique.

## 2. Key Idea
Maintain a dictionary `name -> count` that stores how many times a base name was used.
- First time: output `OK`, set count to 1.
- Next time: output `name + count`, then increment count.

This guarantees the smallest available suffix because the count tracks the next free number.

## 3. Two Implementations
This folder contains two solutions of the same problem:
- `code_1.cpp`: a naive vector + linear search approach (clear but too slow for large inputs).
- `code_2.cpp`: a map-based approach that is efficient and accepted.

## 4. Complexity Analysis
- **Naive (code_1.cpp):** $O(n^2)$ worst-case time due to repeated linear searches.
- **Map (code_2.cpp):** $O(n \log n)$ time using an ordered map.  
  (Can be $O(n)$ average with `unordered_map`.)

## 5. Conclusion
Counting occurrences with a hash map provides the smallest available suffix in one step, and scales to large inputs.

*Written by: George Yanni*
