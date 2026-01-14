# Sentinel Linear Search

**What it is**

Sentinel linear search is a variation of the standard linear (sequential) search that places the search key as a *sentinel* at the end of the array so the scanning loop can avoid a per-iteration bounds check. It slightly reduces the number of comparisons inside the loop and can be a small practical optimization in low-level code (C).

**Algorithm (brief)**

1. If the array is empty, return -1.
2. Save the last element of the array.
3. Place the search key at the last index (the sentinel).
4. Scan from index 0 forward until arr[i] == key (no bounds check in loop).
5. Restore the last element.
6. If the found index is less than n-1, key was in the array; otherwise compare the restored last element to the key to decide.

**C example**

```c
#include <stdio.h>

int sentinel_search(int arr[], int n, int key) {
    if (n == 0) return -1;

    int last = arr[n - 1];
    arr[n - 1] = key;           // place sentinel

    int i = 0;
    while (arr[i] != key) i++;  // no bounds check here

    arr[n - 1] = last;          // restore

    if (i < n - 1 || arr[n - 1] == key)
        return i;               // found
    return -1;                  // not found
}

// Example usage
int main() {
    int a[] = {5, 3, 7, 1, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int idx = sentinel_search(a, n, 7);
    printf("index: %d\n", idx); // index: 2
    return 0;
}
```

**Complexity**

- Time: O(n) worst-case (same as regular linear search)
- Space: O(1)

**Advantages** ✅

- Slightly fewer comparisons inside the main loop (no per-iteration bounds check).
- Small practical speedups in performance-critical C code.

**Caveats & when to avoid** ⚠️

- Temporarily mutates the array — not suitable for read-only arrays or shared data without copying.
- Must specially handle empty arrays.
- The speed improvement is small and may not justify the reduced clarity in most high-level or safety-critical code.

**When to use** 💡

Use sentinel linear search when you control the array, performance is critical, and mutating/restoring the last element is acceptable (e.g., embedded or low-level C code). For general-purpose code, prefer the simple, clearer linear search.

**See also**: [Binary Search](../SearchingAlgo/BinarySearch.md) — a different algorithm with O(log n) time but requires sorted input.
