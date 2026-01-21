📘 Comprehensive Guide to Fibonacci Search
Fibonacci Search is an efficient, comparison-based searching algorithm for sorted arrays. It is a "Divide and Conquer" algorithm that uses Fibonacci numbers to narrow down the search space.

1. The Mathematical Concept 🧮

The Fibonacci SequenceThe sequence is defined as: $0, 1, 1, 2, 3, 5, 8, 13, 21, 34 \dots$
The formula is: $F(m) = F(m-1) + F(m-2)$.

Why use Fibonacci?
Unlike Binary Search, which splits an array into two equal $50/50$ halves, Fibonacci Search splits the array into unequal parts (~$62/38$).

The Main Advantages:

No Division: Uses only + and -. Binary Search uses / 2. On many CPUs, division is significantly slower than addition.

CPU Cache Friendly: In very large arrays, Fibonacci search tends to look at elements that are closer together in memory during the early stages.

2. The Logic Walkthrough 🚶‍♂️
The algorithm uses three Fibonacci numbers ($fM, fM1, fM2$) to maintain the search range.

The Three Variables

$fM$: The current "Window" size ($m^{th}$ Fibonacci number).
$fM1$: The $(m-1)^{th}$ Fibonacci number.
$fM2$: The $(m-2)^{th}$ Fibonacci number.

The Decision Rules

If arr[i] < target (Target is on the Right):
    Action: Move 1 step down the Fibonacci ladder.Update: 
    fM = fM1, fM1 = fM2, fM2 = fM - fM1.
    Offset: Update offset = i. (We discard the left side).
    
If arr[i] > target (Target is on the Left):

    Action: Move 2 steps down the Fibonacci ladder.
    Update: fM = fM2, fM1 = f1 - f2, fM2 = fM - f1.
    Offset: Keep same offset. (We discard the right side).
    
3. Complete C Implementation 

```C
#include <stdio.h>

// Helper to find the smaller of two numbers
int min(int x, int y) { return (x <= y) ? x : y; }

int fibonacciSearch(int arr[], int n, int x) {
    // Initialize Fibonacci numbers
    int f2 = 0; // (m-2)
    int f1 = 1; // (m-1)
    int fM = f2 + f1; // m-th Fibonacci

    // Find the smallest Fibonacci number >= n
    while (fM < n) {
        f2 = f1;
        f1 = fM;
        fM = f2 + f1;
    }

    // Offset marks the eliminated range from the front
    int offset = -1;

    while (fM > 1) {
        // Determine the index to check
        int i = min(offset + f2, n - 1);

        // CASE 1: Target is greater than current element
        if (arr[i] < x) {
            fM = f1;
            f1 = f2;
            f2 = fM - f1;
            offset = i; // Bookmark the new starting point
        }
        // CASE 2: Target is smaller than current element
        else if (arr[i] > x) {
            fM = f2;
            f1 = f1 - f2;
            f2 = fM - f1;
        }
        // CASE 3: Found!
        else return i;
    }

    // Final check: check the last remaining element
    if (f1 && arr[offset + 1] == x) return offset + 1;

    return -1; // Not found
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 85;
    
    int result = fibonacciSearch(arr, n, target);
    if(result != -1) printf("Element found at index: %d", result);
    else printf("Not found");
    
    return 0;
}
```

5. Interview Q&A (Preparation) 💡

Q: What is the time complexity? A: $O(\log n)$, the same as Binary Search.

Q: Why do we use offset + f2 for the index? A: Because $f2$ divides the range into a smaller Fibonacci portion. If the target is on the left, we only need to search the $f2$ area. If it's on the right, we search the $f1$ area.

Q: When is it better than Binary Search? A: On systems where division is expensive (embedded systems, older microcontrollers) and when the array is so large that cache locality matters.

Q: Does it work on unsorted arrays? A: No. Like Binary Search, it requires the data to be sorted.