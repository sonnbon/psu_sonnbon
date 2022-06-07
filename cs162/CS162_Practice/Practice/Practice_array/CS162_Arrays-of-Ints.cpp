#include <iostream>
#include <cctype>
using namespace std;

//Connor Williams
//CS162 Lecture about arrays
//This program is going to wrk with an array of integers.
//We want to read them in and find the largest value in the array
//and output the total of all of them together

//Constant - for th size of the array
const int SIZE = 10;

int main()
{
    //Define all variables
    int numbers[SIZE]; //array of integers to hold all of the user's numbers
    int largest = 0;   //hold the value that is largest
    int sum = 0;       //hold the total of all values stored in the array
    int num_items = 0; //how many items are in the array
    char response = 'Y';  //do we want to do this again and again?
    int i = 0;            //index used as the loop control variable

    //Read in all of the integers and stop when we reach the end of the array
    //or when the user wants to quit
    for (i = 0; i < SIZE && 'Y' == toupper(response); ++i)
    {
      cout << "Please enter in a whole number: ";
      cin >> numbers[i]; //read in one number
      cin.ignore(100, '\n');

      if (i != (SIZE - 1))
      {
        cout << "Again? Y/N ";
        cin >> response;
        cin.ignore(100, '\n');
      }
    }
    num_items = i;

    //Now sum the values and find the largest
    for (i = 0; i < num_items; ++i)
    {
      sum += numbers[i];  //calculate "running total"
      if (largest < numbers[i])
        largest = numbers[i];   //keep track of the largest value
    }

    //Output our results
    cout << "The sum of all of the data is: " << sum << endl;
    cout << "The largest value is: " << largest << endl;

    return 0;
}
