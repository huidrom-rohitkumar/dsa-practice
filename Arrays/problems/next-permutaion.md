# Next Permutation (LC 31)

🔗 https://leetcode.com/problems/next-permutation/

---

## 🧠 Pattern
Greedy + Right-to-left scan + In-place rearrangement

---

## 💡 Core Idea
Find the next lexicographically greater permutation by making the smallest possible change.

---

## ⚡ Key Observations
- Traverse from right → find first decreasing element (pivot)
- Swap it with next greater element on right
- Reverse the suffix

---

## 🚀 Steps
1. Find index i such that nums[i] < nums[i+1] (rightmost)
2. Find j > i such that nums[j] > nums[i] (smallest such)
3. Swap nums[i], nums[j]
4. Reverse nums[i+1 → end]

---

## ⏱ Complexity
- Time: O(n)
- Space: O(1)
