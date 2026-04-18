# Pattern: Triangle DP / Layered Construction

---

## 🧠 Idea
Build structure layer by layer using previous layer

---

## 🔁 Transition
current[i][j] = prev[i-1][j-1] + prev[i-1][j]

---

## 🚨 Recognition Signals
- Row depends on previous row
- Triangular structure
- Incremental building

---

## 🔄 Alternative View
Same structure can often be represented using combinatorics (nCr)

---

## 🔗 Related Problems
- Pascal’s Triangle II
- Triangle Minimum Path Sum
- DP grid problems
