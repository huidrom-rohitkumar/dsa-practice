# Jump Game IX

**Link:** [LeetCode: Jump Game IX](https://leetcode.com/problems/jump-game-ix/)

## Problem Description
You are given an integer array `nums`. From any index `i`, you can jump to another index `j` under the following rules:
- **Forward Jump:** `j > i` is allowed only if `nums[j] < nums[i]`.
- **Backward Jump:** `j < i` is allowed only if `nums[j] > nums[i]`.

For each index `i`, find the maximum value in `nums` that can be reached by following any sequence of valid jumps starting at `i`. Return an array `ans` where `ans[i]` is the maximum value reachable starting from index `i`.

## Core Pattern
**Prefix-Suffix Connectivity Cut** via **Hidden Undirected Graphs**.

## Key Observations
1. **Symmetry of Jumps:** A forward jump from `A` to `B` requires `nums[B] < nums[A]`. A backward jump from `B` to `A` requires `nums[A] > nums[B]`. These are the *exact same condition*. The graph of valid jumps is completely **undirected**.
2. **Component Maximums:** Since the graph is undirected, the maximum reachable value from `i` is simply the maximum value within `i`'s connected component.
3. **The Cut Condition:** A prefix `[0...i]` is disconnected from the suffix `[i+1...n-1]` if and only if no element in the prefix can jump to any element in the suffix. This happens exactly when the maximum element in the prefix is less than or equal to the minimum element in the suffix (`preMax[i] <= sufMin`).

## Concise Approach
1. Precompute a prefix maximum array, `preMax`, where `preMax[i]` represents the largest value in `nums[0...i]`.
2. Iterate through the array from right to left, maintaining a suffix minimum variable, `sufMin`.
3. At each index `i`, check if `preMax[i] > sufMin`. 
   - If true, the prefix and suffix are connected. The maximum reachable value from `i` is the same as `i+1`, so `ans[i] = ans[i+1]`.
   - If false, the prefix is isolated. The best we can reach is the local prefix maximum, so `ans[i] = preMax[i]`.
4. Update `sufMin` with `nums[i]` after processing `i`.

## Complexity
- **Time Complexity:** $O(N)$ — One forward pass to build `preMax`, one backward pass to build `ans`.
- **Space Complexity:** $O(N)$ — To store `preMax` and `ans` arrays.
