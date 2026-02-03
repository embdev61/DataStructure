# Meta Binary Search (Binary-search-on-answer)

Meta Binary Search is a modified version of binary search where we use bit manipulation. We are to find the target array index one bit at a time (MSB → LSB) by using bit manipulation. It is also adaptable to arrays of unknown length (with bounds checks).

### How it works (short)
- Find Bits: Determine the number of bits required for the array size ($bits = \lceil \log_2(n) \rceil$).
- Start with `idx = 0` and iterate bits from MSB -> LSB:
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
int meta_binary_search_one_sided(int arr[], int n, int target) {
    if (n <= 0) return -1;
    
    // 1. Check index 0 separately to simplify the bitwise logic
    if (arr[0] == target) return 0;

    int bits = 0;
    while ((1 << bits) < n) bits++;

    int idx = 0; 
    for (int b = bits - 1; b >= 0; --b) {
        int cand = idx | (1 << b);

        if (cand < n) {
            if (arr[cand] == target) return cand;
            if (arr[cand] < target) {
                idx = cand; // Only update idx if the value is smaller
            }
        }
    }

    // Final check in case the loop landed one step behind the target
    return (idx < n && arr[idx] == target) ? idx : -1;
}
```
**See also:** [Binary Search](./BinarySearch.md), [Sentinel Linear Search](./Sentinel_Linear_Search.md)
