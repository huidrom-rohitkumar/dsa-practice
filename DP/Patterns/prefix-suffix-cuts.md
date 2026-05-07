# Pattern: Prefix-Suffix Cuts

## Pattern Idea
The Prefix-Suffix Cut pattern is used when determining if a sequence can be logically partitioned into independent left and right segments that do not interact or overlap in their constraints. It relies on comparing the most extreme value of the left side against the most extreme value of the right side.

## Recognition Signals
Apply this pattern when:
- The problem asks about partitioning an array into valid chunks.
- The problem involves reachability, jumps, or sorting, where traversing left-to-right involves bounding conditions.
- You see phrases like "left side must be entirely less than right side" or "can we isolate this segment?".

## Core Technique
1. **Precompute a Prefix Array:** Usually `preMax` (or `preMin`), tracking the running extreme value from index 0 to `i`.
2. **Iterate with a Suffix Variable:** Traverse backwards from `n-1` to 0, maintaining a running `sufMin` (or `sufMax`).
3. **Evaluate the Boundary:** At any index `i`, compare `preMax[i]` against the `sufMin` of the remaining elements. 
4. **Determine the Cut:** If `preMax[i] <= sufMin`, a clean logical cut exists between index `i` and `i+1`. No elements to the left overlap or interact with elements to the right.

## Where It Appears
- Finding disjoint intervals or chunks.
- Graph connectivity problems constrained by 1D array indexes and values (hidden bipartite graphs).
- Monotonicity checks across partitions.

## Related Problems
- Max Chunks To Make Sorted I & II
- Partition Array into Disjoint Intervals
- Jump Game IX
