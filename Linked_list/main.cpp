#include <iostream>
#include <cassert>
#include "list.h"
#include "list.cpp"
void display();//declaring the function
using namespace std;

void display(){ //function to display menu

    cout<<"This program responds to commands the user enters to manipulate an ordered "<<endl<<
    "list of integers, which is initially empty. In the following commands, k is a position in the list, and v is an integer."<<endl;
    cout<<"i v -- Insert the value v into the list."<<endl;
    cout<<"r v -- Remove the value v from the list."<<endl;
    cout<<"m -- Is the list empty?"<<endl;
    cout<<"l -- Report the length of the list."<<endl;
    cout<<"p v -- Is the value v present in the list?"<<endl;
    cout<<"k k1 -- Report the k1th value in the list."<<endl;
    cout<<"w -- Write out the list."<<endl;
    cout<<"s -- print sum."<<endl;
    cout<<"e -- print num of even data"<<endl;
    cout<<"h -- See this menu."<<endl;
    cout<<"q -- Quit."<<endl;

}


int main(){ //The main function
    list l;
    display();
    char choice;
    int num;

    bool quit = false;
    while(choice != 'q') //using loop to stay on the program
    {
        cout<<" --> ";
		cin>>choice;
        switch (choice)
        {
            case 'i':
                cin >> num;
                l.insert(num);
                break;

            case 's':

                cout<<"The sum is: "<<l.SUm()<<endl;

                break;
             case 'e':

                cout<<"The num of even data are: "<<l.even_count()<<endl;

                break;

            case 'r': //if choice is r call remove
               {
                   cin>>num;
                   l.remove(num);
                   break;
               }
            case 'm': //check if empty
                    if (l.empty())
                        cout << " The list is empty."<<endl;
                    else
                        cout << " The list is NOT empty."<<endl;
                    break;
            case 'l': //if choice is l call length
                {
                    int len=l.length();
                    cout<<"The list contains "<<len <<" elements"<<endl;
                    break;
                }
            case 'p': //if choice is p call present
            {
                cin>>num;
                if (l.present(num)){
                    cout<<"The value "<<num<<" is present in the list"<<endl;

                    }
                else{
                    cout<<"The value "<<num<<" is not present in the list"<<endl;

                }
                break;

            }
            case 'w': //if choice is w call display
                {
                    cout<<"The list: (";
                    l.Display();
                    cout<<")"<<endl;
                    break;
                }
            case 'k': //give the value of kth element
                    cin >> num;
                    if ((l.empty()) || (num > l.length()))
                        cout << " Not the valid selection."<<endl;
                    else
                    cout<<" The "<<num<<"th element of the list is: "<<l.kth(num-1)<<endl;
                    break;
            case 'h': //if choice is h call display menu
                {
                    display();
                    break;
                }
            case 'q':{ //if choice is q call quit the program
                quit=true;
                break;
        }
            default:{ //if entered extra then menu
                cout<<"Wrong choice"<<endl;
                break;
        }
            if (quit) //if not quit
            {
                break;
            }
            cin>>choice;
        }
}
}



