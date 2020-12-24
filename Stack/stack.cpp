
#include <iostream>
#include "stack.h"
using namespace std;

void Stack::push(int entry){

    data[used]=entry;
    ++used;

}
int Stack::pop(){

--used;

return data[used];

}

