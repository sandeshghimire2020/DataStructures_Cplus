
#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue(){ //constructor
        front=0;
        rear=CAPACITY-1;
        count=0;
        }
void Queue::enqueue(int entry){//inserts the value into queue
    rear=next_index(rear);
    data[rear]=entry;
    ++count;

}
Queue::Item Queue::dequeue()//removes the item from queue
{
    Item temp;
    temp=data[front];
    front=next_index(front);
    --count;
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


