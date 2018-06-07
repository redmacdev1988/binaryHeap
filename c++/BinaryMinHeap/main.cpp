//
//  main.cpp
//  BinaryMinHeap
//
//  Created by  Ricky Tsao on 9/20/16.
//  Copyright © 2016 Epam. All rights reserved.
//

#include <iostream>
#import "MinHeap.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    MinHeap * mhp = new MinHeap(88);
    mhp->insert(37);
    mhp->insert(23);
    mhp->insert(16);
    mhp->insert(65);
    mhp->insert(88);
    mhp->insert(1);
    mhp->insert(78);
    mhp->insert(90);
    mhp->insert(2);
    mhp->insert(3);
    mhp->insert(44);
    mhp->insert(66);
    
    mhp->print();
    
    mhp->removeMin();
    
    mhp->print();
    
    return 0;
}
