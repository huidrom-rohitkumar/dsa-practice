# Set Matrix Zeroes

🔗 https://leetcode.com/problems/set-matrix-zeroes/

---

## 🧠 Pattern
In-place Matrix Marking / State Encoding

---

## 💡 Core Idea
Use first row and first column as markers to track which rows and columns should be zeroed.

---

## ⚡ Key Observations
- matrix[i][j] == 0 → mark:
  - matrix[i][0] = 0
  - matrix[0][j] = 0
- First column needs separate handling (cannot rely on matrix[0][0])

---

## ⚠️ Edge Cases
- First row contains zero
- First column contains zero
- matrix[0][0] ambiguity
- Single row / column

---

## 🚀 Optimal Approach
1. Traverse matrix → mark rows & cols
2. Traverse again → apply zeros
3. Handle first row separately
4. Handle first column using flag

---

## ⏱ Complexity
- Time: O(m * n)
- Space: O(1)
