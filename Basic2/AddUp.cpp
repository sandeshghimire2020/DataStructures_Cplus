//CSCI 301
/*This program simply adds up every digits of the input number. The input is taken from the main function.
The function AddUp is called with the input integer as parameter. The function AddUp starts with the post condition
which terminates the recursion if satisfied and returns the left over value. If the base condition is satisfied the function
adds the digit and then stores it to a variable i.e. Sum. Finally, the value of Sum is returned printing the value and then
terminating the program.
*/
#include <iostream>
using namespace std;

int AddUp(int);	//declaring and initializing the function

int main()	//the main function

{
	int Num;	//declaring a variable
	cout << "Enter an Integer: ";	//displaying massage for input
	cin >> Num;	//Input and store value to Num
	cout << AddUp(Num);	//calling the function AddUp with the input number as parameter
	return 0;
}

int AddUp(int Num1)
{
	//The AddUp function starts
	int Sum = Num1 % 10;	//taking out the last digit of a Number
	if (Num1 < 10)
	{
		//post condition
		return Num1;	//return value and terminate the recursion
	}
	else
	{
		//base condition
		Sum = Sum + AddUp(Num1 / 10);	//recall the function

	}

	return Sum;	//return the last value
}
