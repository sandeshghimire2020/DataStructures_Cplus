#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

class Stack{
public://public functions of the class
    typedef int Item; //defining the Item using int
    //Item first;
    static const int CAPACITY=20;
    Stack(){used=0;}; //constructor
    void push(int entry);//to make list empty
    int pop();//to insert the data in the list

    //Member functions
    int Size(){return used;};

private://private functions of class
    Item data[CAPACITY];
    int used;
};


#endif // list_H
