# Pattern: In-place Matrix Marking

---

## 🧠 Idea
Reuse matrix itself to store state instead of using extra arrays.

---

## 🔁 Technique
- First row → column markers
- First column → row markers
- Extra variable → preserve first column state

---

## 🚨 Why Needed
Avoid O(m + n) space while still tracking dependencies.

---

## 🧩 Recognition Signals
- "Modify matrix in-place"
- "Set entire row/column"
- Space constraint: O(1)

---

## 🔗 Related Problems
- Set Matrix Zeroes
- Game of Life
- Surrounded Regions (variation)
