
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
            temp=first;
            while (temp != NULL){//post condition
                i++;
                cout<<temp->data<<", ";
                temp=temp->next;
            }
        }
    }

void list::make_empty(){ //function to make list empty

        Node*temp;//declaring the variable
        while(first != NULL){//looping
            temp=first;
            first=first->next;
            delete temp;
        }
        }
void list::insert(Item entry){//function to insert
            Node*prev;
            if(first==NULL||entry<first->data){first=get_node(entry,first);}//pre condition
            else{
                prev=first;
                while(prev->next != NULL && prev->next->data<entry){
                    prev=prev->next;}//post condition
                prev -> next = get_node(entry, prev->next);
            }

        }
void list::remove(Item target)//to remove
    {
        Node * prev; //declare pointers
        Node * temp;
        prev=first;
        if(first->data==target){//pre condition
            first=first->next;
            delete prev;
        }
        else{
            while(prev->next->data != target){//post condition

                prev=prev->next;}
                temp= prev->next;
                prev->next=temp->next;
                delete temp;


        }
    }
bool list::present(const Item& target){
        Node* p;
        p=first;
        while(p != NULL && p->data != target){//loop to get to that value
            p=p->next;
            return (p!=NULL);}


    }
int list::length(){ //check the length
    Item count = 1;
    Node * temp;
    temp = first;
    while (temp->next != NULL){ //starting the loop by increasing counter
        temp=temp->next;
        count++;//increasing the counter according to condition
    }
    return count;
}
int list::even_count(){
Item Count=0;
Node *temp;
temp=first;
while(temp->next !=NULL){
    if((temp->data)%2==0){Count++;}
    temp=temp->next;}
    return Count;

}
int list::SUm(){
Node * p;
Item sum=0;
p=first;
while(p != NULL){
    sum=sum+p->data;
    p=p->next;
}
return sum;
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
bool list::empty(){ //check if list is empty or not
    if(first==NULL){//pre condition
        //cout<<"The list is empty."<<endl;
        return true;
    }
    else{//post condition
        //cout<<"The list is NOT empty."<<endl;
        return false;
    }

}
list::Node* list::get_node(const Item value, Node* link){
    Node*temp;
    temp= new Node;
    temp->data=value;
    temp->next=link; //getting the value of particular node
    return temp;
 }

int list::kth(int target)//finding the kth item from list
{
    Node*p;
    int Count=1;
    p=first;
    while(p != NULL && p->data != target&& Count<target){//pre condition
        Count++;
        p=p->next;
    }
    cout<<"The "<<target<<"th element of the list is "<<p->data<<endl; //displaying the item to the screen.
    return Count;
}
