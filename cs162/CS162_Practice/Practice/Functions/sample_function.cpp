#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 21;

//prototypes
void welcome(); //Introduce the program to the user
int read_name(char name[]); //Read in the user's name
int count_lower(char name[], int len); //returns number of lower case letters


int main()
{
    int length = 0; //length of a name
    int count = 0; //number of lower case letters
    char name[SIZE]; //holds the user's name

    welcome();
    length = read_name(name); //THIS IS THE FUNCION CALL passing in the array
    count = count_lower(name, length); //now we will count lower case letters

    cout << "The user's name is: " << name << " and it is " << length
         << " characters long." << endl << endl;
    cout << "There were " << count << " lower case letters." << endl << endl;


    return 0;
}

//Count the number of lower case letters
int count_lower(char name[], int len)
{
    int counter = 0; //holds the count of lower case

    for (int i = 0; i < len; ++i)
    {
      if (islower(name[i]))
        ++counter;
    }
    return counter;
}

//The purpose of this function is to prompt and read in the user's name
//returning the number of characters in the name
int read_name(char name[])
{
    //Prompt and read
    cout << "Please enter your name: ";
    cin.get(name, SIZE, '\n');
    cin.ignore(100, '\n');

    //Let's use the cstring library to find the number of characters
    return strlen(name);
}


//The purpose of this function is to introduce the program to the user
void welcome()
{
    cout << "Welcome to our cout lower function " << endl;
    cout << "In this program we will count the number of lower case letters\n"
         << "in a name!" << endl << "Let's have some fun! " << endl << endl;
}
