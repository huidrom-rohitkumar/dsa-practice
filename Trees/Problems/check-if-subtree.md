# Check if Subtree

**Link:** https://www.geeksforgeeks.org/problems/check-if-subtree/1  
**Difficulty:** Medium  
**Topic:** Binary Trees  
**Pattern:** Tree Identity Check / Tree Serialization

---

## Problem

Given two binary trees T (root1, n nodes) and S (root2, m nodes), determine whether S is a subtree of T. S is a subtree of T if there exists a node in T such that the subtree rooted at that node is structurally identical to S with all node values matching exactly.

---

## Key Observations

1. "Subtree" means an exact structural and value match — not just a sub-path or partial match. The subtree of T rooted at some node must equal S in full.
2. An empty S is always a subtree of any T (vacuously true).
3. Duplicate values in T mean multiple candidate roots may need to be checked.
4. Naive comparison at each node costs O(N * M) — feasible for moderate inputs but avoidable.
5. Serialization with null markers reduces the problem to string substring search in O(N + M) time.

---

## Approach 1 — Recursive Identity Check (O(N * M))

For every node in T (preorder traversal), invoke `areIdentical(node, S)`. The identity check recurses simultaneously on both trees, returning false at the first mismatch. Early termination makes this fast in practice even if worst-case is quadratic.

```
isSubtree(T, S):
    if S == null  → true
    if T == null  → false
    if areIdentical(T, S) → true
    return isSubtree(T.left, S) || isSubtree(T.right, S)

areIdentical(a, b):
    if both null → true
    if one null  → false
    return a.val == b.val && areIdentical(a.left, b.left) && areIdentical(a.right, b.right)
```

---

## Approach 2 — Serialization + Substring Search (O(N + M))

Serialize both trees using preorder traversal with explicit null markers (e.g., `"#"`) and value delimiters (e.g., `","`). S is a subtree of T iff serialize(S) is a substring of serialize(T). Use KMP for guaranteed O(N + M).

**Critical detail:** null markers are mandatory. Without them, structurally different trees can produce the same serialization string.

---

## Complexity

| Approach | Time | Space |
|---|---|---|
| Recursive identity check | O(N * M) | O(H_T) stack |
| Serialization + KMP | O(N + M) | O(N + M) |

Where H_T is the height of T, N = nodes in T, M = nodes in S.

---

## Pattern

Tree identity check is a fundamental primitive. Recognizing that subtree checking decomposes into "traverse T" + "check identity at each node" is the core abstraction. The serialization approach connects tree problems to string matching — a powerful transformation to remember.
