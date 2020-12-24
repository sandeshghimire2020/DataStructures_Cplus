//CSCI 301
/*this program checks if the phrase is palindrome or not. firstly, the main function asks input to the users and then
calls the function (Palindrome) with the input string as parameter. In the function (Palindrome) some static value is declared
and then base condition is set. After going through base condition, another condition is applied to remove spaces and special characters.
finally, the post condition returns true or false.
*/
#include <iostream>
#include <strings.h >	//using the library of strings
using namespace std;
bool Palindrome(string);	//declaring the function
int main()
{
	string Str = " ";	//initializing and declaring the variable
	cout << "Enter a line that might be a palindrome, " << endl;	//displaying the input message
	getline(cin, Str);	//storing the input in Str variable
	if (Palindrome(Str) == true)
	{
		//pre-condition
		cout << "The string is a palindrome." << endl;
	}
	else
	{
		cout << "The string is NOT a palindrome." << endl;
	}

	return 0;
}

bool Palindrome(string Str1)
{
	//function to find Palindrome
	static int i = 0;	//initializing the variable i which is static that means it only declares once
	static int j = Str1.length() - 1;	//initializing the variable j which is static
	if (i <= Str1.length() - 1 && tolower(Str1[i]) == tolower(Str1[j]) && j >= 0)
	{
		//base condition
		i = i + 1;	//incrementing the value of i
		j = j - 1;	//incrementing the value of j
		Palindrome(Str1);	//recalling the function

	}
	else if ((Str1[i]<'A' && Str1[i] > 'Z' ) || (Str1[i]<'a' && Str1[i] > 'z'))
	{
		//second condition for removal of any spaces for i
		i = i + 1;	//incrementing the value of i
		Palindrome(Str1);	//recalling the function
	}
	else if ((Str1[j]<'A' && Str1[j] > 'Z' ) || (Str1[j]<'a' && Str1[j] > 'z' ))
	{
		//second condition for removal of any spaces for j
		j = j - 1;	//incrementing the value of j
		Palindrome(Str1);	//recalling the function

	}
	else
	{
		//condition to terminate the recursion its a post condition

		return false;
	}

	return true;	//post condition
}
