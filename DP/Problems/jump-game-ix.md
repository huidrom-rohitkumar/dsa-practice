# Jump Game IX (LC 3660)

https://leetcode.com/problems/jump-game-ix/

---

Problem:
You are given an integer array nums.

From index i, you can jump to index j (j > i) if:
- nums[j] > nums[i] and all elements between i and j are smaller than nums[i]
OR
- nums[j] < nums[i] and all elements between i and j are greater than nums[i]

Return the minimum cost to reach the last index.

---

Pattern: Monotonic Stack + DP

---

Core Idea:
For every index:
- find next greater valid jump
- find next smaller valid jump

Then use DP to compute minimum cost.

---

Key Observations:
- Valid jumps resemble Next Greater / Next Smaller Element
- Monotonic stacks help build transitions efficiently
- DP computes minimum reachable cost

---

Approach:
1. Build graph using monotonic stacks
2. For each valid jump:
   - relax DP transition
3. Return dp[n-1]

---

Complexity:
Time: O(n)
Space: O(n)
