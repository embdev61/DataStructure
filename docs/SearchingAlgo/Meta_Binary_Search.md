# Meta Binary Search (Binary-search-on-answer)

## Skiena’s one-sided meta binary search (bit-by-bit index construction)

This variant (described by Steven Skiena as "one-sided binary search") builds the target array index one bit at a time (MSB → LSB). It is a binary-search alternative that constructs the index in O(log n) bit-choices and can be easier to implement without off-by-one or overflow bugs. It is also adaptable to arrays of unknown length (with bounds checks).

### How it works (short)
- Compute number of bits needed for the largest index: `bits = ceil(log2(n))`.
- Start with `idx = 0` and iterate bits from most-significant to least:
  - `cand = idx | (1 << b)` (try setting bit b).
  - If `cand >= n`, skip (bit must be 0).
  - Compare `arr[cand]` to target:
    - If equal → return `cand`.
    - If `arr[cand] < target` → keep bit (set `idx = cand`).
    - Else leave bit 0 and continue.
- After the loop, check `idx` for a final match; if none, return `-1`.

### Example (array: [-10, -5, 4, 6, 8, 10, 11], target = 10)
- n = 7 → bits = 3 (indices 0..6)
- Try bit 2 (candidate 4): arr[4] = 8 < 10 → set idx = 4
- Try bit 1 (candidate 6): arr[6] = 11 > 10 → leave bit 0
- Try bit 0 (candidate 5): arr[5] = 10 → found index 5

### C implementation (safe, O(log n))
```c
#include <stdio.h>

int meta_binary_search_one_sided(int arr[], int n, int target) {
    if (n <= 0) return -1;
    int bits = 0;
    while ((1 << bits) < n) bits++;   // number of bits to represent indices

    int idx = 0;
    for (int b = bits - 1; b >= 0; --b) {
        int cand = idx | (1 << b);
        if (cand >= n) continue;               // overshoot → bit = 0
        if (arr[cand] == target) return cand;  // found
        if (arr[cand] < target) idx = cand;    // set this bit
    }
    if (idx < n && arr[idx] == target) return idx;
    return -1; // not found
}
```

### Tradeoffs & notes
- Complexity: O(log n) comparisons (same asymptotic cost as regular binary search) but two parts of the algorithm (bit count + bits loop) — often similar or slightly slower in practice due to constants.
- Advantage: avoids some common off-by-one and mid-overflow mistakes and can be adapted to unknown-length arrays by treating out-of-bounds as "overshoot".
- Caveats: with duplicates it returns an arbitrary matching index (not guaranteed leftmost/rightmost); extra logic is needed for first/last occurrence.

---

**See also:** [Binary Search](./BinarySearch.md), [Sentinel Linear Search](./Sentinel_Linear_Search.md)
