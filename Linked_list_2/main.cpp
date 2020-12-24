#include <iostream>
#include <cassert>
#include "list.h"
#include "list.cpp"

using namespace std;



int main(){ //The main function
    list l;

    char choice;
    string Inp;
    cout<<"Enter a line of characters: "<<endl;//displaying message
    cin>>Inp;//input in a veriable
    cout<<"The previous value is "<<endl;//printing the original string
    cout<<Inp<<endl;
    for (int i=0;i<Inp.length();i++)//starting the loop
    {
        if(Inp[i]=='#'){//if value is # then
            l.remove_last(Inp[i-1]);}//remove the value


        else{
            l.append(Inp[i]);//otherwise insert value to the list


}
    }
    cout<<"The after operation is "<<endl;
    l.Display();//display the whole list
}
