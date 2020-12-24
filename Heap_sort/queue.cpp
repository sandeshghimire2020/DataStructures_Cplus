
#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue(){ //constructor
        front=0;
        rear=CAPACITY-1;
        count=0;
        }
void Queue::reheap_up(int child)
{
    int parent;
    parent=(child-1)/2;
    while(child>0 && data[child]>data[parent])
    {
        child=parent;
        parent=(child-1)/2;
    }
}


void Queue::reheap_down(int a[],int parent,int last)
{
    int max_child;
    bool done;
    done=false;
    while(2*parent+1<=last && !done){
        max_child=2*(parent+1);
        if(max_child<last &&a[max_child+1]>a[max_child]){
            ++max_child;
        }
        if (a[parent]<a[max_child])
        {
            swap(a[parent],a[max_child]);
            parent=max_child;
        }
        else{
            done=true;
        }
    }
}


void Queue::enqueue(int entry){//inserts the value into queue
    data[count]=entry;
    reheap_up(count);
    ++count;
}
Queue::Item Queue::dequeue()//removes the item from queue
{
    Item temp;
    temp=data[0];
    --count;
    data[0]=data[count];
    //reheap_down(0);
    return temp;
}

ostream& operator <<(ostream& out_s, Queue& q){//friend function
Queue::Item it;
int n;
n=q.Size();
for(int i=0;i<n;++i){
    it=q.dequeue();
    out_s<<it<<" ";
    q.enqueue(it);
}
return out_s;
}


