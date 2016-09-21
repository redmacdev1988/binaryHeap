# binaryMinHeap
A priority queue built by using binary minimum heap


Queues are a standard mechanism for ordering tasks on a first-come, first-served basis.
However, some tasks may be more important or timely than others (higher priority).

Hence, we use min/max heaps to solve this. 

A heap is a specific tree based data structure in which all the nodes of tree are in a specific order. Let’s say if X is a parent node of Y, then the value of X follows some specific order with respect to value of Y and the same order will be followed across the tree.

A <b>binary heap</b> is a complete binary tree
Each level except, possibly the bottom most level) is completely filled.

The bottom most level may be partially filled (from left
to right)


<b>Heap-order</b> property (for a "MinHeap")
For every node X key(parent(X)) For every node X, key(parent(X)) ≤ key(X)
Except root node, which has no parent

<b>Height</b> of a complete binary tree with N elements is O(log n)
