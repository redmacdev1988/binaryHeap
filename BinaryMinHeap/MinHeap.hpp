//
//  MinHeap.hpp
//  BinaryMinHeap
//
//  Created by  Ricky Tsao on 9/20/16.
//  Copyright © 2016 Epam. All rights reserved.
//

#include <stdio.h>


class MinHeap {
    
private:
    int * data; //int pointer, points to a chunk of int data
    int heapSize;
    int arraySize;
    
    int getLeftChildIndex (int nodeIndex) ; //gets the index of the left child
    int getRightChildIndex(int nodeIndex);  //gets the index of the right child
    int getParentIndex    (int nodeIndex);  //gets the index of the node's parent
    
    void floatUp( int nodeIndex);           //float the smallest number up at this index
    void floatDown( int nodeIndex);         //float the smallest number down the tree
    
    void switchValues(int * a, int * b);
    
public:
    
    MinHeap(int size);
    ~MinHeap();
    
    int getMinimum();
    bool isEmpty();
    
    void insert(int value);
    void removeMin();
    
    void print();
};