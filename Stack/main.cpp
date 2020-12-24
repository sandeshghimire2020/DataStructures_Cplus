//CSCI 301
/*
This program finds the prime factor of any numbers. The input from a user is taken from the main function.
After receiving the input a function (PrimeFactor) is called with the input integer and value of i as parameter.
This function starts with the base condition which runs the 2nd condition if satisfied. the second condition finds a
prime factor, prints it and recalls the function. With the post condition it terminates the recursion printing the last
remaining number.
*/

#include <iostream>
//#include <cassert>
#include "stack.h"
#include "stack.cpp"
#include <cmath>
using namespace std;
void PrimeFactor(int, int);
int main()

{
    Stack l;
	int Num;

	cout << "Enter a positive Integer from 0 to stop ";	//asking an integer
	cin >> Num;	//Assigning the input to Num variable
	int i = 2;	//initializing the value of i
	cout << "The prime factors of " << Num << " are: ";	//Comment that displays the prime factors
	PrimeFactor(Num, i);	//calling the PrimeFactor function

	return 0;
}
void PrimeFactor(int Num1, int i)
{
    Stack l;
    int value;
    bool check=false;
	while (check==false){

	if(i <= sqrt(Num1))
	{
		//starting the base condition
		if (Num1 % i == 0)
		{
			//2nd condition where code looks for prime factor and prints it
			l.push(i);	//pushing the factor
			Num1=Num1/i;
		}
		else
		{
			i = i + 1;	//increasing the value of i
		}
	}
	else
	{
		//post condition

		l.push(Num1);
		check=true;
        }
    }

    while (l.Size()>0){
        cout<<l.pop()<<" ";
        }

}
