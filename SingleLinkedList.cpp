//
//  SingleLinkedList.cpp
//  assignment3
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#include "SingleLinkedList.hpp"



SingleLinkedList::SingleLinkedList(){
    
    head = NULL;
    
    lsize = 0;
    
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList &list2)

{
    
    *this = list2;
    
}

SingleLinkedList::SingleLinkedList(int val){
    
    pushBack(val);
    
}

void SingleLinkedList::printList()const{
    
    node* walk = head;
    
    while(walk != NULL){
        
        cout<<walk->data<<" ";
        
        walk = walk->next;
        
    }
    
    cout<<endl;
    
    //cout<<"this-> "<<this<<endl;
    
}

void SingleLinkedList::pushBack(int val){
    
    node* temp = new node;
    
    temp->data = val;
    
    temp->next = NULL;
    
    
    
    if(head == NULL)
        
        head = temp;
    
    else{
        
        node* last = head;
        
        while(last->next != NULL)
            
            last = last->next;
        
        last->next = temp;
        
        
        
    }
    
    
    
    lsize++;
    
}

void SingleLinkedList::pushFront(int val){
    
    node* first = new node;
    
    first->data = val;
    
    first->next = head;
    
    head = first;
    
    lsize++;
    
}

void SingleLinkedList::popFront(){
    
    if(head == NULL)
        
        return;
    
    else{
        
        node* first = head;
        
        head = head->next;
        
        delete first;
        
        first = NULL;
        
        lsize--;
        
    }
    
    
    
    
    
}

void SingleLinkedList::popBack(){
    
    if(head == NULL)
        
        return;
    
    else{
        
        node* curr = head;
        
        node* prev = NULL;
        
        while( curr->next != NULL){
            
            prev = curr;
            
            curr = curr->next;
            
        }
        
        
        
        if(curr == head) //deleting head node which is the only 1 in list
            
            head = NULL;
        
        else
            
            prev->next = NULL;
        
        
        
        delete curr;
        
        curr = NULL;
        
        
        
        lsize--;
        
    }
    
}

void SingleLinkedList::insert(int index, int val)

{
    
    int idx = 0;
    
    node *curr = head, *prev = NULL;
    
    
    
    
    
    while(curr != NULL){
        
        if(idx == index){
            
            node *temp = new node;
            
            temp->data = val;
            
            temp ->next = NULL;
            
            if(prev == NULL){
                
                temp->next = head;
                
                head = temp;
                
            }
            
            else{
                
                temp->next = curr;
                
                prev->next = temp;
                
            }
            
            lsize++;
            
            break;
            
        }
        
        idx ++;
        
        prev = curr;
        
        curr = curr->next;
        
    }
    
}

void SingleLinkedList::deleteDuplicates(int val)

{
    
    node* curr = head;
    
    node* prev = NULL;
    
    
    
    while(curr != NULL){
        
        if(curr->data == val){
            
            if(prev != NULL){
                
                prev->next = curr->next;
                
                delete curr;
                
                curr = NULL;
                
                curr = prev->next;
                
            }
            
            else{
                
                head = curr->next;
                
                delete curr;
                
                curr = NULL;
                
                curr = head;
                
            }
            
        }
        
        else{
            
            prev = curr;
            
            curr = curr->next;
            
        }
        
    }
    
}

int SingleLinkedList::mtoLastElement(int m)

{
    
    if(m >= lsize || head == NULL)
        
        return -1;
    
    int neededIdx = lsize - 1 - m ;
    
    node *curr = head;
    
    for(int i = 0; i < neededIdx; i++)
        
        curr = curr->next;
    
    return curr->data;
    
}

void SingleLinkedList::reverseList()

{
    
    if(head == NULL || head->next == NULL )
        
        return;
    
    
    
    node *first = NULL;
    
    node *second = head;
    
    node *third = head->next;
    
    
    
    while(third != NULL)
        
    {
        
        second->next = first;
        
        first = second;
        
        second = third;
        
        third = third->next;
        
    }
    
    second->next = first;
    
    head = second;
    
}

void SingleLinkedList::deleteList(){
    
    node* temp;
    
    while(head != NULL){
        
        temp = head;
        
        head = head->next;
        
        delete temp;
        
        temp = NULL;
        
    }
    
    head = NULL;
    
    lsize = 0;
    
}

SingleLinkedList::~SingleLinkedList(){
    
    cout<<"in destructor"<<endl;
    
    deleteList();
    
    
    
}

bool SingleLinkedList::operator==(const SingleLinkedList& rhs){
    
    if(head == rhs.head)
        
        return true;
    
    if(lsize != rhs.lsize)
        
        return false;
    
    node* lhshead = head;
    
    node* rhshead = rhs.head;
    
    
    
    int sz = lsize;
    
    while(sz -- != 0){
        
        if(lhshead->data != rhshead->data)
            
            return false;
        
        lhshead = lhshead->next;
        
        rhshead = rhshead->next;
        
    }
    
    return true;
    
}

int SingleLinkedList::size()const {
    
    return lsize;
    
}

ostream& operator<<(ostream& out, const SingleLinkedList& rhs){
    
    out<<"[head->"<<rhs.head<< "]: ";
    
    rhs.printList();
    
    
    
    //cout<<"this-> "<<this<<endl;
    
    return out;
    
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& rhs){
    
    if(rhs.head == NULL)
        
        deleteList();
    
    else{
        
        deleteList();
        
        node* rhshead = rhs.head;
        
        while(rhshead != NULL){
            
            pushBack(rhshead->data);
            
            rhshead = rhshead->next;
            
            
            
        }
        
    }
    
    return *this;
    
    
    
}
