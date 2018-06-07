//
//  MinHeap.cpp
//  BinaryMinHeap
//
//  Created by  Ricky Tsao on 9/20/16.
//  Copyright © 2016 Epam. All rights reserved.
//

#include "MinHeap.hpp"
#import <iostream>

using namespace std;

#pragma mark - Life Cycle
MinHeap::MinHeap(int size) {
    
    //int pointer "data" will point to the first element of a newly
    //created of memory. That block of memory represents 'size' number of ints.
    
    this->data = new int [size]; //arrow is used by pointers to access properties
    heapSize = 0;
    arraySize = size;
}


MinHeap::~MinHeap() {
    
    delete [] this->data; //delete array of ints
}


#pragma mark - utility and index methods

//O(1)
int MinHeap::getLeftChildIndex (int nodeIndex) //gets the index of the left child
{
    return 2 * nodeIndex + 1;
}

//O(1)
int MinHeap::getRightChildIndex(int nodeIndex) //gets the index of the right child
{
    return 2 * nodeIndex + 2;
}

//O(1)
int MinHeap::getParentIndex    (int nodeIndex) //gets the index of the node's parent
{
    return (nodeIndex - 1)/2;
}


//O(1)
void MinHeap::switchValues(int * a, int * b) {
    
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool MinHeap::isEmpty() {
    return (heapSize <= 0);
}

#pragma mark - Recursive helper methods


// recursively switches value at nodeIndex with the smaller child node, where
// the smaller value is assigned up, and the larger value is assigned down.

//O(log n)
void MinHeap::floatDown(int nodeIndex) {
    
    cout    << "\n\nfloatDown (at index " << nodeIndex << ") with value "
            << data[nodeIndex] << endl;
    
    int leftChildIndex, rightChildIndex, minIndex;
    
    leftChildIndex  = this->getLeftChildIndex(nodeIndex);
    rightChildIndex = this->getRightChildIndex(nodeIndex);
    
    if(rightChildIndex >= heapSize) {
        
        cout    << "!!------- warning --------!!" << endl;
        cout    << "Right index " << rightChildIndex << ", is larger or equal to heapSize of "
                << this->heapSize <<  endl;
        cout    << "Let's see if the left index is within the heapSize" << endl;
        cout    << "--------------------" << endl;
        
        
        if(leftChildIndex >=heapSize) {
            cout << "\n==================================" << endl;
            cout    << "Error: Left child index of " << leftChildIndex
            << ", cannot be >= than heapSize of: " << this->heapSize << endl;
            cout << "Accessing elements with invalid index is not allowed." << endl;
            cout << "==================================" << endl;
            return;
        }
        else minIndex = leftChildIndex;
        
    } else {
        
        cout    << "\n left index: " << leftChildIndex
                << ", and right index:" << rightChildIndex
                << ", both within heap size index of: " << this->heapSize <<  endl;
        
        cout << "\nget smallest child node" << endl;
        if (this->data[leftChildIndex] <= this->data[rightChildIndex])
            minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }
    

    cout << "switch parent and child nodes" << endl;
    if (data[nodeIndex] > data[minIndex]) {
        this->switchValues(&this->data[minIndex], &this->data[nodeIndex]);
        floatDown(minIndex);
    }
    
}


//O(log n)
//recursively floats smaller values up to the root

void MinHeap::floatUp(int nodeIndex) {
    
    //if more than 1 element, we gotta make sure the min floats to the top
    if(nodeIndex != 0) {
        
        int parentIndex = this->getParentIndex(nodeIndex);
        
        //if the parent data is larger than the current data
        //we need to switch them. AKA, float our smaller value to the top
        if(data[parentIndex] > data[nodeIndex]) {
            
            this->switchValues(&this->data[parentIndex], &this->data[nodeIndex]);
            this->floatUp(parentIndex);
        }
    }
    
    //if we're on index 0, that means there's nothing to do cuz only 1 element
}




#pragma mark - Public methods

//O(log n)
void MinHeap::insert(int value) {
    
    if(this->heapSize == this->arraySize) {
        cout << "ERROR, heap size overflow" << endl;
        return;
    } else {
        
        heapSize++;
        data[heapSize-1] = value;
        this->floatUp(heapSize-1); //log
        
    }
}


//O(log n) where log n + log 1
//O(log n) - binary recursion where it floats the number down into the tree
//O(1) - for the root and last element swithch.
void MinHeap::removeMin() {
    
    if (this->isEmpty()) {
        cout << "HEAP is Empty" << endl;
        return;
    } else {
        
        data[0] = data[heapSize - 1]; //first, assign the last element over to the top
        data[heapSize-1] = -1;
        heapSize--;
        
        if(heapSize > 0)
            floatDown(0); //float the root number down correctly
    }
}

//just for demo purposes
//O(n)
void MinHeap::print() {

    for ( int i = 0; i < this->heapSize; i++) {
        cout << data[i] << endl;
    }

}



