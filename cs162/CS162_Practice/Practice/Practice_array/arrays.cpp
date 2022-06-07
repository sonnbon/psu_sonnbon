#include <iostream>
#include <cstring>
using namespace std;

// Connor Williams
// Topic 1 lecture on arrays
// We are going to read in the user's name, age, and email address

const int NAME = 21;
const int EMAIL = 41;

int main()
{
    //Variables
    char name[NAME];    //The user's full name
    char email[EMAIL];  //The user's email address
    int age;

    for (int counter = 0; counter < 2; ++counter)
    {
      //Let's read in the information from the user
      cout << "Please enter your full name: ";
      cin.get(name, NAME, '\n');
      cin.ignore(100, '\n');

      cout << "Please enter you email address: ";
      cin.width(EMAIL);    //Since you're not dealing with any spaces
      cin >> email;
      cin.ignore(100, '\n');

      cout << "And, what is your age: ";
      cin >> age;
      cin.ignore(100, '\n');

      //Echo out this information
      cout << name << '\t' << email << "\tage is: " << age << endl;
    } 
    return 0;

}
