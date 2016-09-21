# binaryMinHeap
A priority queue built by using binary minimum heap


Queues are a standard mechanism for ordering tasks on a first-come, first-served basis.
However, some tasks may be more important or timely than others (higher priority).

Hence, we use min/max heaps to solve this. 

A heap is a specific tree based data structure in which all the nodes of tree are in a specific order. Let’s say if X is a parent node of Y, then the value of X follows some specific order with respect to value of Y and the same order will be followed across the tree.


The bottom most level may be partially filled (from left
to right)


<b>Heap-order</b> property (for a "MinHeap")

For every node X, key(parent(X)) ≤ key(X)
Except root node, which has no parent

<ul>
<li>Minimum key always at root</li>
<li>Duplicates are allowed</li>
<li>No order implied for elements which do not
share ancestor share ancestor-descendant relationship</li>
</ul>

<b>Height</b> of a complete binary tree with N elements is O(log n)
