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

#### Simple C example (standard binary search)
```c
int binary_search(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### 2) Exponential (galloping) search ⚡
- **What:** Expand range exponentially until target within range, then binary search inside.
- **Complexity:** O(log n) comparisons.
- **Use when:** array length unknown or searching in streamed/linked data.

#### Simple C example (galloping then binary)
```c
int exponential_search(int arr[], int n, int target) {
    if (n == 0) return -1;
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < n && arr[i] <= target) i *= 2;
    // binary search in [i/2, min(i, n-1)]
    int lo = i / 2, hi = (i < n) ? i : n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### 3) Fibonacci search 📐
- **What:** Probe positions using Fibonacci numbers instead of halving.
- **Complexity:** O(log n).
- **Use when:** historical contexts or when divisions are costly.

#### Simple C example (Fibonacci search)
```c
int fib_search(int arr[], int n, int target) {
    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;
    while (fib < n) { fib2 = fib1; fib1 = fib; fib = fib2 + fib1; }
    int offset = -1;
    while (fib > 1) {
        int i = (offset + fib2 < n - 1) ? offset + fib2 : n - 1;
        if (arr[i] < target) {
            fib = fib1; fib1 = fib2; fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > target) {
            fib = fib2; fib1 = fib1 - fib2; fib2 = fib - fib1;
        } else return i;
    }
    if (fib1 && offset + 1 < n && arr[offset + 1] == target) return offset + 1;
    return -1;
}
```

### 4) Interpolation search 🎯
- **What:** Estimate probe position using value distribution (interpolate), then narrow range.
- **Complexity:** O(log log n) expected for uniform data, O(n) worst-case.
- **Use when:** keys roughly uniformly distributed.

#### Simple C example (interpolation search)
```c
int interpolation_search(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (lo == hi) return (arr[lo] == target) ? lo : -1;
        int pos = lo + ((target - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}
```

### 5) k-ary / multiway search 🌲
- **What:** Split search into k parts (k>2) at each step (used in B-trees and multiway indices).
- **Use when:** optimizing for cache or disk I/O.

### 6) Ternary search (for unimodal functions) 🎚️
- **What:** For unimodal arrays/functions (increase to peak then decrease), split into three and discard one third; find maximum/minimum.
- **Complexity:** O(log n) steps.
- **Use when:** optimizing unimodal functions (not a replacement for sorted searches).

#### Simple C example (find max in unimodal array)
```c
#include <stdio.h>

int ternary_search_max(int arr[], int n) {
    int lo = 0, hi = n - 1;
    while (hi - lo >= 3) {  // until range small
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        if (arr[mid1] < arr[mid2]) {
            lo = mid1;  // discard left third
        } else {
            hi = mid2;  // discard right third
        }
    }
    // check remaining 3 elements
    int max_idx = lo;
    for (int i = lo + 1; i <= hi; ++i) {
        if (arr[i] > arr[max_idx]) max_idx = i;
    }
    return max_idx;
}
```

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