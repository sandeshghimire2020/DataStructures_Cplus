#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

class list{
public://public functions of the class
    typedef int Item; //defining the Item using int
    //Item first;
    list(){first=NULL;}; //constructor
    ~list();//Destructor
    void make_empty();//to make list empty
    void insert (Item Empty);//to insert the data in the list
    void remove(Item target);//to remove the data from the list

    //Member functions
    int SUm();
    bool Empty(){ //checks if the list is empty or not
    return first=NULL;}
    int length();//finds the length of list
    bool present(const Item& target);// finds if the item is present in list or not
    bool empty();
    int even_count();
    Item kth(Item position);//finds the value of kth position
    void Display();//prints out the contents of list
    void add3(Item p);
    friend std::ostream& operator << (std::ostream& out_s,const list& list1); //this is a friend function
private://private functions of class
    struct Node //Making a Node for pointing the data of list
        {
            Item data;//data
            Node* next;//pointer
        };
        Node* first;//It points first data of list
        Node* get_node(Item Empty, Node *link);//to get the data in list
};


#endif // list_H
