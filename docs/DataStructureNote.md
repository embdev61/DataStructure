# Data Structures Notes

## Table of Contents
- [Introduction](#introduction)
- [Complexity](#complexity)
- [Arrays](#arrays)
- [Linked List](#linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Trees](#trees)
- [Graphs](#graphs)
- [Hash Table](#hash-table)
- [Sorting Algorithms](#sorting-algorithms)
- [C Examples](#c-examples)
- [Resources](#resources)

## Introduction
Short, practical notes on common data structures and their complexity. Use the examples as starting points for implementation and experiments.

## Complexity
- Time complexity: O(1), O(log n), O(n), O(n log n), O(n^2) etc.
- Space complexity: constant, linear, etc.

## Arrays
- Static contiguous memory, O(1) access, O(n) insertion/deletion (unless at end).

## Linked List
- Singly vs Doubly vs Circular
- Operations: insert, delete, search
- Complexity: insert/delete at head O(1), search O(n)

## Stack
- LIFO; push/pop O(1)
- Use-case: function call stack, DFS, expression evaluation

## Queue
- FIFO; enqueue/dequeue O(1)
- Variants: circular queue, priority queue

## Trees
- Binary Tree, Binary Search Tree (BST)
- Traversals: inorder, preorder, postorder (recursive & iterative)
- Balanced trees overview (AVL, Red-Black) — use libraries or advanced study

## Graphs
- Representations: adjacency list (preferred), adjacency matrix
- Traversals: BFS (shortest unweighted), DFS
- Complexity depends on |V| and |E|

## Hash Table
- Average O(1) lookup/insert/delete
- Collisions: chaining vs open addressing

## Sorting Algorithms
- Quick sort (avg O(n log n)), Merge sort (stable), Heap sort
- When to use which depends on data and constraints

## C Examples
### Simple singly linked list node
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;