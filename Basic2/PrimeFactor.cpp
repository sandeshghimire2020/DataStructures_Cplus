//CSCI 301
/*
This program finds the prime factor of any numbers. The input from a user is taken from the main function.
After receiving the input a function (PrimeFactor) is called with the input integer and value of i as parameter.
This function starts with the base condition which runs the 2nd condition if satisfied. the second condition finds a
prime factor, prints it and recalls the function. With the post condition it terminates the recursion printing the last
remaining number.
*/
#include <iostream>
#include <cmath>	// including cmath library to use sqrt function
using namespace std;

int PrimeFactor(int, int);	//declaring the function

//The main function
int main()

{
	int Num;	//declaring the variable that holds input
	cout << "Enter a positive Integer: ";	//asking an integer
	cin >> Num;	//Assigning the input to Num variable
	int i = 2;	//initializing the value of i
	cout << "The prime factors of " << Num << " are: ";	//Comment that displays the prime factors
	PrimeFactor(Num, i);	//calling the PrimeFactor function
	return 0;
}

//PrimeFactor function
int PrimeFactor(int Num1, int i)
{
	if (i < sqrt(Num1))
	{
		//starting the base condition
		if (Num1 % i == 0)
		{
			//2nd condition where code looks for prime factor and prints it
			cout << i << " ";	//printing the factor
			PrimeFactor(Num1 / i, i);	//recalling the function

		}
		else
		{
			i = i + 1;	//increasing the value of i
			PrimeFactor(Num1, i);	//recalling the function
		}
	}
	else
	{
		//post condition

		cout << Num1 << " ";	//if not negative print the last value of remaining factor
		return i;	//terminating the recursion

	}
}
