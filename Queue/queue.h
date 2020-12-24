#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue{
public://public functions of the class
    typedef int Item; //defining the Item using int
    //Item first;
    static const int CAPACITY=30;
    Queue();
    void enqueue(int entry);//to make list empty
    int dequeue();//to insert the data in the list

    //Member functions
    int Size(){return count;};//returns the size of queue
    bool empty(){return count==0;}//returns if queue is empty or not
    friend std::ostream& operator << (std::ostream& out_s, Queue& Queue1); //this is a friend function
private://private functions of class
    Item data[CAPACITY];
    int front;//points front of queue
    int rear;//points rear of queue
    int count; //counts the number of data in queue
    int next_index(int i){ //Private member function
    return (i+1)%CAPACITY;}
};


#endif // QUEUE_H
