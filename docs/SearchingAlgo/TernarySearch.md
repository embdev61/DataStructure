# Ternary Search

## 1. Definition
A divide-and-conquer algorithm that partitions the search space into three parts instead of two. It is commonly used to find the maximum or minimum of a unimodal function.

## 2. Time Complexity
- **Best Case:** $O(1)$ (if the element is found at mid1 or mid2 immediately).
- **Average/Worst Case:** $O(\log_3 n)$.
- **Comparison with Binary Search:** While it has a logarithmic time complexity, Ternary Search performs more comparisons per iteration (2 comparisons) than Binary Search (1 comparison). Therefore, in practice, Binary Search is usually faster for simple array lookups.

## 3. Key Formulas
- $mid1 = low + \frac{high - low}{3}$
- $mid2 = high - \frac{high - low}{3}$

## 4. When to Use?
When the search space is non-linear but unimodal (increases then decreases, or vice versa). Useful in optimization problems where you need to find the peak of a curve.

## 5. Space Complexity
- **Iterative:** $O(1)$ (constant space).
- **Recursive:** $O(\log_3 n)$ (due to the recursion stack).

## Step-by-Step Implementation for Finding Minimum
We continue this until we reduce the search space to a small enough size to directly find the minimum.

### Steps:
1. Initialize `low = 0` and `high = n - 1`.
2. Create a variable `minIndex = -1` to store the answer.
3. Start a loop that runs while `low <= high`.
4. Calculate `mid1 = low + (high - low) / 3`.
5. Calculate `mid2 = high - (high - low) / 3`.
6. If `arr[mid1] == arr[mid2]`, then:
   - Set `low = mid1 + 1`.
   - Set `high = mid2 - 1`.
   - Set `minIndex = mid1`.
7. Else if `arr[mid1] < arr[mid2]`, then:
   - Set `high = mid2 - 1`.
   - Set `minIndex = mid1`.
8. Else (i.e., `arr[mid1] > arr[mid2]`), then:
   - Set `low = mid1 + 1`.
   - Set `minIndex = mid2`.
9. Repeat the loop until `low > high`.
10. Return `minIndex` as the result.

## Example Implementation (C, finding maximum in unimodal array)
```c
function findMinIndex(arr) {
    let low = 0, high = arr.length - 1;
    let minIndex = -1;

    while (low <= high) {

        // divide the range into three parts
        let mid1 = low + Math.floor((high - low) / 3);
        let mid2 = high - Math.floor((high - low) / 3);

        // if both arr[mid1] and arr[mid2] point to equal 
        // values narrow the search
        if (arr[mid1] === arr[mid2]) {

            // Move towards the center
            low = mid1 + 1;
            high = mid2 - 1;

            // tentatively store mid1 as
            // potential minimum
            minIndex = mid1;
        }

        // if arr[mid1] < arr[mid2], the minimum lies in the
        // left part (including mid1)
        else if (arr[mid1] < arr[mid2]) {
            high = mid2 - 1;

            // update with better candidate
            minIndex = mid1;
        }

        // is mid1 > mid2, the minimum lies in the
        // right part (including mid2)
        else {
            low = mid1 + 1;

            // update with better candidate
            minIndex = mid2;
        }
    }

    return minIndex;
}

int main() {
    int arr[] = {9, 7, 1, 2, 3, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int idx = findMinIndex(arr, n);
    printf("%d\n", idx);
    printf("%d\n", n);

    return 0;
}
```

## See Also
- [Binary Search](./BinarySearch.md)
- [Divide and Conquer Search](./Divide_and_Conquer_Search.md)
