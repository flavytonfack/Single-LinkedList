//
//  SingleLinkedList.hpp
//  assignment3
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#endif /* SingleLinkedList_hpp */

#include <stdio.h>
#include <iostream>

using namespace std;

#pragma once

struct node{
    
    int data;
    
    node* next;
    
};

class SingleLinkedList{
    
    
    
private:
    
    node* head;
    
    int lsize;
    
    
    
public:
    
    SingleLinkedList();
    
    SingleLinkedList(int val);
    
    SingleLinkedList(const SingleLinkedList &other);
    
    ~SingleLinkedList();
    
    void printList() const;
    
    void pushBack(int val);
    
    void pushFront(int val);
    
    void popBack();
    
    void popFront();
    
    void insert(int index, int val);
    
    void deleteDuplicates(int val);
    
    int mtoLastElement(int m);
    
    void reverseList();
    
    void deleteList();
    
    bool operator==(const SingleLinkedList& rhs);
    
    int size() const;
    
    friend ostream& operator<<(ostream& out, const SingleLinkedList& rhs); //
    
    SingleLinkedList& operator=(const SingleLinkedList& rhs);
    
    
    
};
