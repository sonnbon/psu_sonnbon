#include <iostream>
#include <cctype>
using namespace std;

//Connor Williams
//Function pre-recorded lecture example
//Adding machine program now implemented using some functions

//Prototype - declaring to the compiler that a function exists but we can
//call the function beforehand


//RETURN TYPE   FUNCTION NAME   (ARGUMENT LIST); //comment
//Void means nothing to return

void welcome();       //display the welcome information about how to get started
char get_operation(); //get a + or a - and will do all of the error checking
int get_data();       //get the data the user wants to add or subtract
bool again();         //Returns true if we want to do this again, false otherwise

int main()
{
    int total=0;    //running total
    int operation = ' ';   //+ or a -
    int data = 0;
    
    welcome();        //call the welcom function

    do
    {
      operation = get_operation();   //prompt, read in, error check for me
      data = get_data();             //prompt, read in the data from the user

      //Test to see what needs to be done
      if ('+' == operation)
          total += data;
      else
          total -= data;

    //Again?
    } while (again());

    cout << "The result is: " << total << endl << endl;

    return 0;

}




//The welcome function will output messages to the user about how to get started
//and what this program is all about. It takes no arguments and returns nothing
void welcome()       //display the welcome information about how to get started
{
  cout << "Welcome to the adding machine program!! " << endl << endl;

}

char get_operation() //get a + or a - and will do all of the error checking
{
    //Local variable
    char op = ' ';

    //Prompt
    cout << "Please enter the operation to perform + or - : ";

    //Read in
    cin >> op;

    while (op != '+' && op != '-')
    {
        cout << "Error - invalid operation. Try again: ";
        cin >> op;
    }
    return op;
}

int get_data()       //get the data the user wants to add or subtract
{
    int data = 0; //Local variable

    //Prompt the user
    cout << "Please enter the data to add or subtract: ";
    
    //Read in the data
    cin >> data;

    return data;
}

bool again()         //Returns true if we want to do this again, false otherwise
{
    char response = 'N';

    do
    {
      //Prompt the user
      cout << "Would you like to do this again? Y or N : ";
      cin >> response;
    } while (toupper(response) != 'Y' && toupper(response) != 'N');

    //Return true if we have a Y, false otherwise
    if (toupper(response) == 'Y')
        return true;
    return false;
}
