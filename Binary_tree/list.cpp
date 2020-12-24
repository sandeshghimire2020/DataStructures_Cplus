
#include <iostream>
#include "list.h"
using namespace std;

Tree::~Tree() //destructor
{
    destroy(root);//function to delete the tree
}
int Tree::Length()//find the length of tree
{
    return r_length(root);//calling the function
}
int Tree::r_length(Node *r){//find the length
if (r==NULL){return 0;}//starting the pre-condition
    else{return r_length(r->left)+1+r_length(r->right);}//if not satisfied
}
bool Tree::Present(Item target)//function to check if the value is present in tree or not
{
    Node *p=root;//declaring a pointer
    while(true)//starting the pre condition
    {
        if (p==NULL)//condition
            return false;
        else if (target<p->data)//condition
            p=p->left;
        else if(target=p->data)//condition
            return true;
        else//execute this if not satisfied any of above condition
            p=p->right;
    }
}

void Tree::Insert(Item entry)//to insert data
{
    Node *p, *back, *temp;//decalaring the pointers
    p=root;//giving root value
    back=NULL;//giving NULL value
    //searching the place to put the new value
    while (p!=NULL)//starting the loop
    {
        back=p;
        if(entry<p->data)
            p=p->left;
        else
            p=p->right;
    }
    //making a new node
    temp= new Node;
    temp->data=entry;
    temp->left=NULL;
    temp->right=NULL;
    //attaching the new node
    if(back==NULL)//condition
        root=temp;
    else if(entry<back->data)
        back->left=temp;
    else//if not satisfied execute this
        back->right=temp;
}

void Tree::Remove(Item target)//function to remove data from tree
{
    help_remove(root,target);//sub function of the function Remove()
}
void Tree::help_remove(Node *&t,Item target)
{
    if(t->data==target)//starting condition
        remove_node(t);
    else if(target<t->data)//another condition
        help_remove(t->left,target);
    else//execute this if not satisfied
        help_remove(t->right,target);
}
void Tree::remove_node(Node * &t) //to remove the node
{
    Node *ptr, *back;//declare pointers
    if(t->left==NULL && t->right==NULL)//starting the base condition
    {
        delete t;//delete the node
        t=NULL;
    }
    else if(t->left==NULL)//else delete left
    {
        ptr=t;
        t=t->right;
        delete ptr;
    }
    else if(t->right==NULL)//else delete right
    {
        ptr=t;
        t=t->left;
        delete ptr;
    }
    else//if not satisfied execute this part
    {
        back=t;
        ptr=t->right;
        while(ptr->left!=NULL)//starting the loop to remove
        {
            back=ptr;
            ptr=ptr->left;
        }
        t->data=ptr->data;
        if (back==t)//starting condition
            remove_node(back->right);
        else//if not satisfied
            remove_node(back->left);
    }
}
void Tree::Display(){//to display the contents
   help_display(root);//call the recursive fuction to display data
    }
void Tree::help_display(Node *r)//function to display the data recursively
{
     if (r != NULL)
    {
        help_display(r->left);//call left
        cout<<r->data<<" ";//print data
        help_display(r->right);//call right
    }
}


ostream& operator<<(ostream& out_s, const Tree& b){ //overloading the << operator
    Tree::Node*n;
    Tree::Node*m;
    n= b.root;
    m=b.root;
    cout<<n->data<<"";//displaying if null
    while (n->right != NULL && n->left !=NULL)
    {
        n=n->left;
        m=m->right;
        out_s<<n->data<<"";//displaying if data are present
        out_s<<m->data<<"";
    }
    return out_s;

}
void Tree::destroy(Node *r)//function to destroy the whole tree used in destructor
    {
        if(r!=NULL){
            destroy(r->left);//recursion
            destroy(r->right);//recursion
            delete r;//remove r node
        }
    }
