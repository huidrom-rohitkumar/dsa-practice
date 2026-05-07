# Pattern: Tree Identity Check and Serialization

---

## Core Idea

Many tree problems reduce to asking: "Is this subtree structurally and value-identical to that subtree?" The answer requires a symmetric simultaneous traversal of two trees. When this identity check must be applied at every node of a larger tree, the problem becomes "traverse + match," which has a clean recursive structure.

A deeper transformation: any binary tree can be uniquely represented as a string via preorder serialization with explicit null markers and delimiters. This reduces tree comparison problems to string matching problems, enabling the use of algorithms like KMP.

---

## Recognition Signals

- Problem involves two trees, and asks whether one "appears in" or "matches" the other.
- Problem asks to find a node in tree A such that the subtree rooted there equals tree B.
- Problem involves checking structural equality between any two tree nodes or subtrees.
- Any problem that says "identical," "same," "mirror," or "subtree" applied to two trees.

---

## Core Technique

**Tree Identity (areIdentical):**  
Simultaneously traverse both trees. At each step: if both are null → identical; if exactly one is null → not identical; if values differ → not identical; recurse on both children. This is O(min(M, N)) per call.

**Subtree Search:**  
Traverse the host tree T in any order. At each node, invoke `areIdentical(node, S)`. Return true on first match. Worst case O(N * M).

**Serialization Reduction:**  
Serialize a tree by preorder traversal, appending a special null marker (e.g., `"#,"`) for null children and a delimiter between real values. Two trees are identical iff their serializations are equal. S is a subtree of T iff serialize(S) is a substring of serialize(T). Use KMP for O(N + M).

**Why null markers are non-negotiable:**  
Without null markers, different tree shapes can produce the same traversal string. For example:
```
  1          1
 /            \
2              2
```
Both yield `{1, 2}` in preorder without null markers. With null markers: `"1,2,#,#,#,"` vs `"1,#,2,#,#,"` — clearly distinct.

---

## Where This Pattern Appears

- **Check if Subtree** (GFG, LC 572)
- **Same Tree** (LC 100) — direct identity check, no traversal needed
- **Symmetric Tree** (LC 101) — identity check between left and right subtrees mirrored
- **Count Univalue Subtrees** (LC 250)
- **Find Duplicate Subtrees** (LC 652) — serialize every subtree, use a hash map to find duplicates
- **Serialize and Deserialize Binary Tree** (LC 297) — the serialization technique in full generality
- **Subtree of Another Tree** (LC 572) — direct mirror of this problem

---

## Related Concepts

- KMP string matching: the right tool when substring search appears after serialization
- Tree hashing: assign each subtree a hash based on its structure and values; subtree matching becomes hash comparison in O(N + M) with O(N) space
- Merkle trees: the same idea used in distributed systems — hash subtrees to detect changes efficiently
