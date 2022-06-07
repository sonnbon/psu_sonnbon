#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Connor Williams
// Topic 1 Array Examples
// The purpose is to read in up to 10 integers and count the number of odd
// values entered. SInce we want to experience an array in action, we will
// read in all of the data first AND then count
//
//constant definitions:
const int SIZE = 10;

int main()
{
    int array[SIZE];       //Can hold up to 10 integers at most
    int num = 0;           //Let us know how many integers we have entered
    int count = 0;         //number of odd values that were found in the array
    char response = 'Y';   //Initialized to Y

    //Read in up to 10 integers
    for (int i = 0; i < SIZE && toupper(response) == 'Y'; ++i, num = i)
    {
      cout << "Please enter a whole number: ";
      cin >> array[i];    //subscript

      cout << "Another: ";
      cin >> response;
    }

    //Count the number of odd values
    for (int i = 0; i < num; ++i)
    {
      if (array[i] %2 == 1)  //odd
        ++count;
    }
    cout << "We received " << count << " number of odd values " << endl;

    return 0;
}
