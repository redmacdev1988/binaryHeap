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

<a href="http://shanghaiseagull.com/wp-content/uploads/2016/09/minheap.png"><img src="http://shanghaiseagull.com/wp-content/uploads/2016/09/minheap.png" alt="minheap" width="485" height="263" class="alignnone size-large wp-image-5125" /></a>

<a href="http://shanghaiseagull.com/wp-content/uploads/2016/09/heapinsert.png"><img src="http://shanghaiseagull.com/wp-content/uploads/2016/09/heapinsert.png" alt="heapinsert" width="565" height="529" class="alignnone size-full wp-image-5124" /></a>

<b>Height</b> of a complete binary tree with N elements is O(log n)

<h3>Implementing min heap as arrays</h3>

So in our project, you'll see that we allocate a chunk of memory for integers, AKA a row of integers.
We have an integer pointer at the head of the array.
<pre>
this->data = new int [size];
</pre>

<h3>Calculating the parent, left child, right child indexes</h3>

given that we start at index 0:

<ul>
<li>left child index = 2 * i + 1</li>
<li>right child index = 2 * i + 2</li>
<li>parent index = (i-1) / 2 </li>
</ul>

<h3>Heap Insertion O( log n ) </h3>

For insertion, we always append the new element at the end of the array. Then recursively float this integer up where it satisfies min-heap property such that the parent is smaller than the child. We do so by seeing if the parent is larger than us, if is, then we switch the values. If not, we are done.

<h3>Heap Deletion O( log n )</h3>

First, we copy the last value in the tree ( last element of the array ) onto the root. Then remove the last element, and decrease the heap size counter.

From there we recursively push the root value down the tree so that it satisfies the min-heap property of where key(parent) <= key(child). We decide on which child node to go down by comparing the two child nodes. We switch the parent value with the smallest of the 2 child nodes.

