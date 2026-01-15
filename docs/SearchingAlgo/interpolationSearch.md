# Interpolation Search Algorithm 🔍

Interpolation Search is an optimized searching algorithm for **sorted arrays** with **uniformly distributed values**. It is an improvement over Binary Search for specific datasets, mimicking how humans look for a name in a telephone directory.

---

## 1. How it Works
Unlike Binary Search, which always checks the middle element ($mid = \frac{low + high}{2}$), Interpolation Search estimates the position of the target using a mathematical formula.

### The Formula
The position `pos` is calculated as:
$$pos = low + \left[ \frac{(target - arr[low]) \cdot (high - low)}{arr[high] - arr[low]} \right]$$

---

## 2. C Implementation 💻

```c
#include <stdio.h>

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    // Target must be within array bounds
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        
        if (low == high) {
            return (arr[low] == target) ? low : -1;
        }

        // Estimate the position of the target
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        // Target found
        if (arr[pos] == target)
            return pos;

        // Target is in the right/upper part
        if (arr[pos] < target)
            low = pos + 1;
        
        // Target is in the left/lower part
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 70;

    int result = interpolationSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
```