#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

class list{
public://public functions of the class
    typedef char Item; //defining the Item using int
    //Item first;
    list(){first=NULL;
    last=NULL;}; //constructor
    ~list();//Destructor
    void append (const Item& entry);//to insert the data in the list
    void remove_last(const Item& entry);//to remove the data from the list

    //Member functions
    bool empty();//to check if list is empty

    void Display();//prints out the contents of list
    friend std::ostream& operator << (std::ostream& out_s,const list& list1); //this is a friend function
private://private functions of class
    struct Node //Making a Node for pointing the data of list
        {
            Item data;//data
            Node* next;//pointer
            Node* back;
        };
        Node* first;//It points first data of list
        Node* last;//It points last of the list
        Node* get_node(Item Empty, Node *link, Node* Backward);//to get the data in list
};


#endif // list_H
