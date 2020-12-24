#include <iostream>
#include <cassert>
#include "list.h"
using namespace std;



list::~list() //distructor
   {
        Node*temp; //initalizing the temp pointer
        while(first != NULL){ //using precondition loop
            temp=first;
            first=first->next;
            delete temp;
            }
      }

void list::Display(){
        Node * temp; //declare the variable
        if (first==NULL){cout<<"The list is empty.";} //pre condition
        else{
            int i=0;
            temp=first;//give value to temp
            while (temp != NULL){//post condition
                i++;
                cout<<temp->data;//output the data inside pointer
                temp=temp->next;//points to next pointer
            }
        }
    }
void list::append(const Item& entry){//function to insert
    Node*temp;
    temp= new Node;//new node is declared
    Node* prev;
    prev=first;//give first value to temp

    if (first==NULL){//checking if the first value is NULL or not

        first=get_node(entry,last,first);//insert value
    }else{
    while(prev->next != NULL){//loop to get to the last pointer

        prev=prev->next;//giving next address to prev pointer
    }

    temp->data=entry;//inserting data
    prev->next=temp;//pointing next value

    temp->next=last;
    temp->back=prev;//pointing back
        }

}


ostream& operator<<(ostream& out_s, const list& b){ //overloading the << operator
    list::Node*n;
    n= b.first;
    cout<<n->data<<"";//displaying if null
    while (n->next != NULL)
    {
        n=n->next;
        out_s<<n->data<<"";//displaying if data are present
    }
    return out_s;

}


void list::remove_last(const Item& target)//to remove
    {
        Node * prev; //declare pointers
        Node * temp;
        prev=first;
        if(first->data==target){//pre condition
            first=first->next;
            delete prev;
        }
        else{
            while (prev->next && prev->next->next != NULL)//loop started to check the last item
                {
                    prev = prev->next;//pointing to next address
                }
                delete prev->next;//deleting the prev address
                prev->next = NULL;//pointing to NULL
            }

    }


bool list::empty(){ //check if list is empty or not
    if(first==NULL&&last==NULL){//pre condition
        return true;
    }
    else{//post condition

        return false;
    }

}

list::Node* list::get_node(const Item value, Node* link, Node* backward){
    Node*temp;
    temp= new Node;//decclearing new node
    temp->data=value;//giving data
    temp->next=link;//getting the value of particular node
    temp->back=backward;//pointing backwards
    return temp;//returning the value of temp
 }

