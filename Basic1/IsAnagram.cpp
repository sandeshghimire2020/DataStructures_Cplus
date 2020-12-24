//CSCI 301
//Computer Science 2
//This program asks user to enter two phrases and outputs if they are anagram or not
//The input is taken from the main function with the validation
//check. It checks if the input of user has characters more then 60 or not.
//It keeps on displaying the error message until the user inputs strings less then 60 characters.
//The both input is used to call a function that firstly deletes any
//spaces, numbers and special characters. After that this function calls another function to sort the
//strings. After sorting the function checks if the two strings are equal or not.
//If they are equal function returns true(a boolean value) to the main function and if they are
//not equal it returns false.
//In the end the main function displays if the entered strings are anagram or not.

#include <iostream>
#include<cstring>

using namespace std;

string Ssort(string);
bool areAnagram(string, string);

//This function sorts the formatted strings taken from user.
string Ssort(string abc1) {

  for (int index = 0; index < abc1.size() - 1; index++) { //starting outer loop for sorting
    for (int i = index + 1; i < abc1.size(); i++) { //Starting inner loop for sorting

      if (abc1[index] > abc1[i]) // comparing two characters
        swap(abc1[i], abc1[index]); //swapping if the condition is mate

    }
  }

  return abc1; //returns sorted value to " areAnagram" function
}

//function to find if the lines are anagram or not
bool areAnagram(string abc1, string abc2) {

  string ForStr1, ForStr2; //strings to store the phrase without special characters,numbers and spaces.

  //taking out the spaces, numbers and special characters.

  for (int i = 0; i < abc1.length(); i++) //starting the loop
  {
    if ((abc1[i] >= 'A' && abc1[i] <= 'Z') || (abc1[i] >= 'a' && abc1[i] <= 'z')) {
      ForStr1.push_back(tolower(abc1[i]));
    }

  }

  for (int i = 0; i < abc2.length(); i++) {
    if ((abc2[i] >= 'A' && abc2[i] <= 'Z') || (abc2[i] >= 'a' && abc2[i] <= 'z')) {
      ForStr2.push_back(tolower(abc2[i]));
    }

  }

  ForStr1 = Ssort(ForStr1); //sorting the phrase using "Ssort" function
  ForStr2 = Ssort(ForStr2); //sorting the phrase using "Ssort" function

  if (ForStr1 == ForStr2) { //checking if two phrases are same or not
    return true;
  } // returning the boolean value to the main function if true.
  else {
    return false;
  }

}
//the main function

int main() {
  string abc1 = " "; //declaring and initializing the variable for input 1.
  string abc2 = " "; //declaring and initializing the variable for input 2.
  bool check = true; //declaring a boolean value.
  do { //starting the loop.

    cout << "Enter two line that might be anagram: " << endl; //asking the input from users
    cout << "Line 1: ";
    getline(cin, abc1); //storing the input to abc1 variable.

    if (abc1.length() >= 60) { //validation check: if the string is greater then 60 keep not..
      cout << "Error: Please enter only the phrase that is less then or equal to 60 characters" << endl; //error message
      check = false; //set the value to false
    } else { //if condition is false
      check = true; //set value to true
      cout << "Line 2: "; //asking another phrase
      getline(cin, abc2);
      if (abc2.length() >= 60) { ////validation check: if the string is greater then 60 keep not..
        cout << "Error: Please enter only the phrase that is less then or equal to 60 characters" << endl; //error message.
        check = false;
      } else {
        check = true;
      } //if statement is false
    }

  } while (check == false); //ending the loop with condition.

  if (areAnagram(abc1, abc2) == true) //calling the areAnagram() function
    cout << "The two phrases are anagram with each other"; //print this value if true
  else
    cout << "The two phrases are not anagram with each other"; //print this value if false
  return 0;
}
