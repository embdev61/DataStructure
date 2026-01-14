# Divide-and-Conquer Search Algorithms — Quick Reference ✅

A compact summary of common divide-and-conquer search patterns, what they do, and when to use them.

## Overview
Divide-and-conquer search splits the search space into parts and discards those that cannot contain the answer. Below are frequently used variants and where they shine.

## Algorithms

### 1) Binary search (and variants) 🔎
- **What:** Repeatedly split a sorted array in half. 
- **Variants:** leftmost/rightmost (lower/upper bound), branchless, safe-integer patterns.
- **Complexity:** O(log n).
- **Use when:** data is sorted and you need an index/position or a boundary.

### 2) Exponential (galloping) search ⚡
- **What:** Expand range exponentially until target within range, then binary search inside.
- **Complexity:** O(log n) comparisons.
- **Use when:** array length unknown or searching in streamed/linked data.

### 3) Fibonacci search 📐
- **What:** Probe positions using Fibonacci numbers instead of halving.
- **Complexity:** O(log n).
- **Use when:** historical contexts or when divisions are costly.

### 4) Interpolation search 🎯
- **What:** Estimate probe position using value distribution (interpolate), then narrow range.
- **Complexity:** O(log log n) expected for uniform data, O(n) worst-case.
- **Use when:** keys roughly uniformly distributed.

### 5) k-ary / multiway search 🌲
- **What:** Split search into k parts (k>2) at each step (used in B-trees and multiway indices).
- **Use when:** optimizing for cache or disk I/O.

### 6) Ternary search (for unimodal functions) 🎚️
- **What:** For unimodal arrays/functions, split into three and discard a third; find maximum/minimum.
- **Use when:** optimizing unimodal functions (not a replacement for sorted searches).

### 7) Meta binary search (binary-search-on-answer) 🧭
- **What:** Binary search over a numeric parameter using a monotonic feasibility check, or build index bit-by-bit (Skiena’s one-sided variant).
- **Complexity:** O(log(range) * T_check) or O(log n) bitwise.
- **Use when:** optimization problems (min capacity, scheduling, partitioning).

### 8) Parallel & cache-aware strategies ⚙️
- **What:** Multi-probe or multiway splits tuned for parallelism or cache/Disk behavior.
- **Use when:** performance tuning on modern hardware or parallel algorithms.

## Quick tips 💡
- Use classic **binary search** for sorted lookups.
- Choose **exponential** if length unknown; **interpolation** for uniform keys.
- Use **meta binary search** for optimization/feasibility problems.
- For hardware-sensitive performance, consider **k‑ary / cache aware** splits.

## See also
- `BinarySearch.md`, `Meta_Binary_Search.md`, `Sentinel_Linear_Search.md` (in this folder)

---

If you'd like, I can add short C snippets for selected algorithms or a comparison table to the doc—would you like examples added? ✅