# Exponential Search Algorithm 🚀

Exponential Search is a two-stage algorithm used to find a target in a **sorted array**. It is particularly powerful for searching in **infinite or unbounded arrays** where the size of the dataset is unknown.

---

## 1. How it Works
The algorithm works in two distinct phases:

1.  **Range Finding:** Start at index 1 and keep doubling the index ($1, 2, 4, 8, 16...$) until you find an element greater than the target or reach the end of the array.
2.  **Binary Search:** Once the range $[i/2, i]$ is identified, perform a standard Binary Search within that specific block.



---

## 2. C Implementation 💻

```c
#include <stdio.h>

// Helper function: Standard Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Exponential Search
int exponentialSearch(int arr[], int n, int x) {
    // 1. Check if the target is at the very first position
    if (arr[0] == x) return 0;

    // 2. Find range by doubling the index
    int i = 1;
    while (i < n && arr[i] <= x) {
        i = i * 2;
    }

    // 3. Perform Binary Search on the discovered range
    // Range is between the previous 'i' and the current 'i'
    int low = i / 2;
    int high = (i < n) ? i : n - 1;

    return binarySearch(arr, low, high, x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 80, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = exponentialSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
```

## 3. Revision Notes 

📝Key CharacteristicsTime Complexity: $O(\log i)$, where $i$ is the index of the element.Note: If the element is near the start, it is faster than a full Binary Search $O(\log n)$.Space Complexity: * $O(1)$ for iterative implementation.$O(\log i)$ for recursive implementation (due to stack space).Pre-requisite: The array must be sorted.

When to Use 💡Infinite/Unbounded Lists: When the size of the array is unknown (e.g., streaming data).Search Near Beginning: When you expect the target to be located in the first few indices of a massive array.Memory Efficiency: It is more efficient than Jump Search ($O(\sqrt{n})$).