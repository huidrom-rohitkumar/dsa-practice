# Pascal’s Triangle (LC 118)

🔗 https://leetcode.com/problems/pascals-triangle/

---

## 🧠 Pattern
2D DP Construction / Combinatorics

---

## 💡 Core Idea
Each element depends on the previous row:

value = prev[j-1] + prev[j]

OR directly:
value = nCr

---

## ⚡ Key Observations
- First and last elements of every row = 1
- Row i has i+1 elements
- Entire structure builds from previous row

---

## 🚀 Approach
Build row by row:
- Initialize row with 1s
- Fill middle using previous row

---

## ⏱ Complexity
- Time: O(n²)
- Space: O(n²) (output)

Optimal since output size is O(n²)
