

class Node {
  constructor(val, priority) {
    this.value = val;
    this.priority = priority;
    this.next = null;
  }
}

class PriorityQueue {

  constructor() {
    this.heap = []; // array, with first null element
  }

  print(index) {
    console.log("----- PRINTING HEAP --------")
    let next = 2 * index + 1;
    console.log("***")
    for (let v = 0; v < this.heap.length; v++) {
        if (v === next) {
          console.log("\n***");
          // then recalculate
          next = 2 * v + 1;
        }
        process.stdout.write(`${this.heap[v].value}, ${this.heap[v].priority} | `);
    }
    console.log("\n--------- finished printing heap -----------");
  }

  // worse case, number of levels, translates to O(log n)

  insert (value, priority) {
      const newNode = new Node(value, priority);
      this.heap.push(newNode);
      let currentNodeIdx = this.heap.length-1;
      let currentNodeParentIdx = Math.ceil( (currentNodeIdx-2) / 2);
      while(this.heap[currentNodeParentIdx] &&
        newNode.priority > this.heap[currentNodeParentIdx].priority) {
          const parent = this.heap[currentNodeParentIdx];
          this.heap[currentNodeParentIdx] = newNode;
          this.heap[currentNodeIdx] = parent;
          currentNodeIdx = currentNodeParentIdx;
          currentNodeParentIdx = Math.ceil((currentNodeIdx-2)/2);
      }
  } // insert

  getLeftChildIndex(currentIndex) {return 2 * currentIndex + 1;}
  getRightChildIndex(currentIndex) {return 2 * currentIndex + 2;}
  getLeftChild(currentIndex) {return this.heap[this.getLeftChildIndex(currentIndex)];}
  setLeftChild(currentIndex, newNode) {this.heap[this.getLeftChildIndex(currentIndex)] = newNode;}
  getRightChild(currentIndex) {return this.heap[this.getRightChildIndex(currentIndex)];}
  setRightChild(currentIndex, newNode) { this.heap[this.getRightChildIndex(currentIndex)] = newNode;}
  getCurrentNode(currentIndex) { return this.heap[currentIndex]; }
  setCurrentNode(currentIndex, newNode) {this.heap[currentIndex] = newNode;}

  exchangeCurrentAndLeftChild(currentIndex, left) {
    let temp = this.getCurrentNode(currentIndex);
    this.setCurrentNode(currentIndex, left);
    this.setLeftChild(currentIndex, temp);
  }

  exchangeCurrentAndRightChild(currentIndex, right) {
    let temp = this.getCurrentNode(currentIndex);
    this.setCurrentNode(currentIndex, right);
    this.setRightChild(currentIndex, temp);
  }

  topToBottomHeapify(currentIndex) {
    let current = this.getCurrentNode(currentIndex);
    if (!current) {return null;} else {
      console.log(`processing index ${currentIndex} for value: ${this.heap[currentIndex].value}`);
    }
    let left = this.getLeftChild(currentIndex);
    let right = this.getRightChild(currentIndex);

    if (left && !right && left.priority > current.priority) {
      this.exchangeCurrentAndLeftChild(currentIndex, left);

    } else if (!left && right && right.priority > current.priority) {
      this.exchangeCurrentAndRightChild(currentIndex, right);

    } else if (left && right && (left.priority > current.priority || right.priority > current.priority)) {
      console.log(`both left and right exists: ${left.priority}, ${right.priority}, and one of them is larger than parent`);
      if (left.priority > right.priority) {
        this.exchangeCurrentAndLeftChild(currentIndex, left);
      } else {
        this.exchangeCurrentAndRightChild(currentIndex, right);
      }
    }
    this.topToBottomHeapify(2*currentIndex+1);
    this.topToBottomHeapify(2*currentIndex+2);
  }

  remove() {
    let toProcess = this.heap[0];
    console.log(`√ Processing task ${toProcess.value}`);
    this.heap[0] = this.heap[this.heap.length-1];
    this.heap.pop();
    this.topToBottomHeapify(0);
  }

}

let a = new PriorityQueue();

a.insert("6680", 6680);
a.insert("8620", 8620);
a.insert("1115", 1115);
a.insert("7792", 7792);
a.insert("32895", 32895);
a.insert("51518", 51518);
a.insert("81187", 81187);
a.insert("1390", 1390);

a.print(0);

console.log(`------------ deleting ------------`)
a.remove();
a.print(0);


console.log(`------------ deleting ------------`)
a.remove();
a.print(0);


console.log(`------------ deleting ------------`)
a.remove();
a.print(0);


console.log(`------------ deleting ------------`)
a.remove();
a.print(0);


console.log(`------------ deleting ------------`)
a.remove();
a.print(0);

console.log(`------------ deleting ------------`)
a.remove();
a.print(0);

console.log(`------------ deleting ------------`)
a.remove();
a.print(0);

console.log(`------------ deleting ------------`)
a.remove();
a.print(0);



/*
// good
a.insert("100", 100);
a.insert("60", 60);
a.insert("90", 90);
a.insert("30", 30);
a.insert("50", 50);
a.insert("20", 20);
a.insert("89", 89);
a.print(0);

console.log(`------------ deleting ------------`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);


console.log(`\n\n------------ deleting ------------\n\n`)
a.delete();
a.print(0);
*/
