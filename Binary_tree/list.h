#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

class Tree{
public://public functions of the class
    typedef int Item; //defining the Item using int
    struct Node
    {
        Item data;
        Node* left;
        Node* right;
    };
    Node*root;

    Tree(){root=NULL;}//constructor

    bool Empty(){return root==NULL;}//check if the tree is empty or not

   ~Tree(); //destructor

    int Length();//find out the length of tree
    int r_length(Node *r);
    bool Present(Item target);//Is a particular value present in tree
    void Insert(Item entry);//To insert data into tree
    void Remove(Item target);//To remove data from tree
    void help_remove(Node * &t,Item target);//recursive for remove
    void remove_node(Node * &t);//to remove a node
    void Display();//to display the content of tree
    void destroy(Node *r);//to destroy the tree
    void help_display(Node *r);//to help display function recursively
    friend std::ostream& operator << (std::ostream& out_s, Tree& Tree1); //this is a friend function


};


#endif // LIST_H
