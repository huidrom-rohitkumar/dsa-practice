# Count Elements With Strictly Smaller and Greater Elements (LC 2148)

🔗 https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

---

## 🧠 Pattern
Array Min/Max Filtering

---

## 💡 Core Idea
An element is valid if:
min < nums[i] < max

---

## ⚡ Key Observations
- Elements equal to min → invalid
- Elements equal to max → invalid
- Everything strictly between → valid

---

## 🚀 Approach
1. Find min and max
2. Count elements strictly between them

---

## ⏱ Complexity
- Time: O(n)
- Space: O(1)
