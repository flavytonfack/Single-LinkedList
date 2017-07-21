//
//  main.cpp
//  assignment3
//
//  Created by Flavy Tonfack on 7/09/17.
//  Copyright © 2017 Flavy Tonfack. All rights reserved.
//

#include <iostream>

#include "SingleLinkedList.hpp"

int main(){
    
    
    
    SingleLinkedList one;
    
    SingleLinkedList two;
    
    
    
    SingleLinkedList* three = new SingleLinkedList();
    
    
    
    for(int i = 0; i < 5; i++)
        
        one.pushBack(i);
    
    for(int i = 0; i < 5; i++)
        
        two.pushFront(i);
    
    for(int i = 10; i < 15; i++)
        
        three->pushBack(i);
    
    
    
    *three = two;
    
    three->pushBack(25);
    
    two.pushBack(99);
    
    
    
    cout<<one;
    
    cout<<"address of one : "<<&one<<endl;
    
    cout<<two;
    
    cout<<"address of two : "<<&two<<endl;
    
    cout<<*three;
    
    cout<<"address of three : "<<three<<endl;
    
    
    
    
    
    cout << "list1: " << one;
    
    cout << "list2: " << two;
    
    cout << "list3: " << *three;
    
    
    
    if(one == two)
        
        cout<<"lists 1 and 2 are same"<<endl;
    
    else
        
        cout<<"list 1 is not equal to list2"<<endl;
    
    
    
    
    
    cout << "creating list 4 from list 2 using copy constructor " <<endl;
    
    SingleLinkedList four(two);
    
    cout << "list4: " << four << endl;
    
    if(four == two)
        
        cout<<"lists 4 and 2 are same"<<endl;
    
    else
        
        cout<<"list 4 is not equal to list2"<<endl;
    
    
    
    
    
    SingleLinkedList five;
    
    five = one;
    
    cout << "list5 assigned list 1, using assignment opertaor " << endl << five << endl;
    
    
    
    
    
    cout << "insert 100 at index 3 in list 1 " << endl;
    
    one.insert(3, 100);
    
    cout << "list1: " << one << endl;
    
    
    
    cout << "getting element 2 to last element from list1 = " << one.mtoLastElement(2) << endl;
    
    
    
    cout<< "reversing list1" << endl;
    
    one.reverseList();
    
    
    
    cout <<"list1: " << one << endl;
    
    
    
    cout << "pop front and pop back from list1" << endl;
    
    one.popFront();
    
    one.popBack();
    
    cout <<"list1: " << one << endl;
    
    
    
    cout <<"pushBack 3 in list1 " << endl;
    
    one.pushBack(3);
    
    cout <<"list1: " << one << endl;
    
    
    
    cout <<"deleteDuplicates 3 in list1 " << endl;
    
    one.deleteDuplicates(3);
    
    cout <<"list1: " << one << endl;
    
    
    
    
    
    delete three;
    
    
    
    
    
    return 0;
    
}
