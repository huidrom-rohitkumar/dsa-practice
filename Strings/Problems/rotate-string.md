# Rotate String (LC 796)

https://leetcode.com/problems/rotate-string/

---

Problem:
Given two strings s and goal, return true if and only if s can become goal after some number of shifts.

A shift moves the leftmost character of s to the end.

---

Pattern: String Rotation / Concatenation Trick

---

Core Idea:
A string can be rotated into another if and only if:
goal is a substring of (s + s)

---

Key Observations:
- Rotation preserves length → lengths must match
- All rotations of s are contained in s + s
- If goal is inside s + s → valid rotation exists

---

Approach:
1. If lengths differ → return false
2. Check if goal is substring of s + s

---

Complexity:
Time: O(n)
Space: O(n)
