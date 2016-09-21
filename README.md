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

left child index = 2 * i + 1
right child index = 2 * i + 2
parent index = (i-1) / 2 

<h3>Heap Insertion</h3>
