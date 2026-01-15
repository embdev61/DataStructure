# Jump Search Algorithm — Quick Explanation ✅

## What it is
Jump search is a searching algorithm for **sorted arrays** that jumps ahead by a fixed block size (usually $\sqrt{n}$) to find the block containing the target, then performs a linear search within that block. It serves as a middle ground between Linear Search and Binary Search.

---

## How it Works (Steps) 🔧

1.  **Determine block size:** $m = \sqrt{n}$.
2.  **Jump Phase:** Start from index 0 and jump ahead by `m` until you find a block where `arr[i] >= target` (or reach the end of the array).
3.  **Linear Search Phase:** Once the potential block is identified, perform a linear search from the previous jump point to find the exact match.
4.  **Result:** If found, return the index; otherwise, return "Not Found."



---

## Example
**Sorted Array:** `[1, 3, 5, 7, 9, 11, 13, 15]`  
**Target:** `9` | **n:** `8`

* **Block size:** $\sqrt{8} \approx 3$.
* **Jump 1:** Index 3 (Value: `7`). Since $7 < 9$, jump again.
* **Jump 2:** Index 6 (Value: `13`). Since $13 > 9$, the target must be in the block between index 3 and 6.
* **Linear Search:** Check from index 3 to 6. Find `9` at **index 4**.

---

## Complexity
* **Time Complexity:** $O(\sqrt{n})$
    * Jumping takes $O(n/m)$ steps.
    * Linear search within the block takes $O(m)$ steps.
    * Optimized when $m = \sqrt{n}$.
* **Space Complexity:** $O(1)$ — No extra space or recursion needed.

---

## When to Use 💡

* **Large Sorted Arrays:** When you want something faster than Linear Search but simpler than Binary Search.
* **Limited Random Access:** Useful in systems where jumping backward is more expensive than jumping forward (though it still requires some backward movement for the linear phase).
* **Not Ideal For:** Very small arrays (where Linear Search is faster) or when $O(\log n)$ performance is strictly required.

---

## Comparison

| Algorithm | Complexity | Comparison to Jump Search |
| :--- | :--- | :--- |
| **Linear Search** | $O(n)$ | Jump Search is faster for large $n$. |
| **Binary Search** | $O(\log n)$ | Binary Search is faster, but Jump Search is easier to implement and requires no recursion. |

## Example Implementation (C)
```c
#include <stdio.h>
#include <math.h>

int jump_search(int arr[], int n, int target) {
    int block_size = sqrt(n);
    int prev = 0;
    while (arr[(prev + block_size < n ? prev + block_size : n) - 1] < target) {
        prev += block_size;
        if (prev >= n) return -1;
    }
    // Linear search in block
    for (int i = prev; i < n && i < prev + block_size; ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```