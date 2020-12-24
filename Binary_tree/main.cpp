#include <iostream>
#include "list.h"
#include "list.cpp"
#include<iomanip>
#include<cstdlib>

#include <cmath>
/*Binary tree is a tree where may degree is two, and in which we distinguish left and right children.
Binary search tree is a tree where data are arranged in such an order that a greater value always goes to the right part of the tree.
In this project, we are implementing BST by using linked list. The feature of BST helps us to find data very easily.
*/

using namespace std;

void display(){ //function to display menu

    cout<<"This program responds to commands the user enters to "<<endl<<
  "manipulate an ordered list of integers, which is "<<endl<<
  "initially empty. In the following commands, v is any"<<endl<<
  "integer."<<endl;
    cout<<"e -- Re-initialize the list to be empty."<<endl;
    cout<<"i v -- Insert the value v into the list."<<endl;
    cout<<"r v -- Remove the value v from the list."<<endl;
    cout<<"l -- Report the length of the list."<<endl;
    cout<<"p v -- Is the value v present in the list?"<<endl;
    cout<<"w -- Write out the list."<<endl;
    cout<<"h -- See this menu."<<endl;
    cout<<"q -- Quit."<<endl;

}


int main(){ //The main function
    Tree l;
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
                l.Insert(num);
                break;

            case 'r': //if choice is r call remove
               {

                   cin>>num;
                   l.Remove(num);
                   break;
               }
            case 'l': //if choice is l call length
                {
                    int len=l.Length();
                    cout<<"The list contains "<<len <<" elements"<<endl;
                    break;
                }
            case 'p': //if choice is p call present
            {
                cin>>num;
                if (l.Present(num)){
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



