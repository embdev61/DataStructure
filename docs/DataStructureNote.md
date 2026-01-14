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
- [Searching Algorithms](#searching-algorithms)
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

## Searching Algorithms
- Binary Search

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
```  

## Resources
- [Introduction to Algorithms (CLRS)](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)
- [GeeksforGeeks — Data Structures](https://www.geeksforgeeks.org/data-structures/)
- Implementation examples: `linklist.c` in [linklistOps](http://_vscodecontentref_/0)


## Note
Here are practical alternatives to Mermaid and when to use each — I’ll also show quick examples and how to embed them in your Markdown. My next step is to help you pick one and add a rendered image or source file to the repo if you want. ✅

🔧 Best options (summary)
PlantUML — expressive UML, sequence, activity diagrams; source-based (good for versioning).
Graphviz (DOT) — great for graphs and flowcharts; mature and scriptable.
diagrams.net (draw.io) / Figma / Excalidraw — visual editors for polished diagrams (export as SVG/PNG).
Kroki — single service that renders many formats (PlantUML, Graphviz, mermaid, etc.) from short URLs.
SVG/PNG images — simplest: export from any tool and embed in Markdown; SVG preferred for quality.
ASCII / ditaa — for quick console-friendly diagrams or simple text diagrams.
📌 When to choose which
Want source-controlled text (editable + diffable) → use PlantUML or Graphviz.
Want visual, drag-and-drop design → use diagrams.net / Figma / Excalidraw and export SVG.
Need many diagram formats without local tools → use Kroki or a CI job to render images.
Need the diagram to render on GitHub without extra extensions → commit an exported SVG/PNG and reference it in Markdown.

Mermaid is a popular choice and when to pick other tools. Next, I'll list concise benefits, limitations, and a quick recommendation.## Why use Mermaid? ✅

Text-first & versionable 🔧
Mermaid diagrams are written as plain text (mermaid blocks), so they live in your repo, are diffable, and easy to update.

Renders in Markdown (GitHub-friendly) 🌐
GitHub supports Mermaid rendering in README/MD files, so your docs show diagrams without exporting images.

Fast to author and maintain ✍️
Simple syntax for flowcharts, sequence diagrams, Gantt, class diagrams, etc. Great for evolving docs and tutorials.

Supports styling & lightweight visuals 🎨
Use classDef/class to add colors and styles without external tools.

Good local workflows 🧭
Edit in VS Code and preview (with a Mermaid extension); or have CI render diagrams to SVG for stable artifacts.

When to choose a different tool ⚠️
Need precise layout, advanced UML features, or publication-quality graphics → consider PlantUML or Graphviz.
Want a polished, drag-and-drop design → use diagrams.net / Figma / Excalidraw and export SVG.
If you need many formats rendered automatically, consider Kroki or a CI job that renders diagram sources to images.
Note: Mermaid is great for most documentation diagrams, but may have parser quirks for complex labels or advanced styling across different renderers — keep labels simple or quote them.


