#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Connor Williams
//CS162 Example lecture functions
//Demonstrate how functions can make our tasks more useful - we can use a
//function to do the same thing but on different data

//Constants
const int SIZE = 30;

//Prototype
void read_array(char array[], int size);
void swap(char array[], int first_element, int second_element);


int main()
{
    //Local Variables
    char phrase[SIZE];  
    char word[SIZE];
    int start = 0;
    int finish = 28; //we don't wan to swap the '\0'
    
    //Fill up the array from a function
    read_array(phrase, SIZE);
    read_array(word, SIZE);

    //Get which elements to swap
    cout << "Which two elements to swap? 0-28: ";
    cin >> start >> finish;
    cin.ignore(100, '\n');

    swap(phrase, start, finish);
    swap(word, start, finish);

    //Output our results
    cout << "Here is what we got: " << phrase << endl << word << endl;

    return 0;
}

//This function will prompt the user for an array and then read it in.
//The maximum number of characters is being sent in as an argument
void read_array(char array[], int size)
{
    cout << "Please enter some text: ";
    cin.get(array, size, '\n');
    cin.ignore(100, '\n');
}

//Swap function will exchange two elements of an array of characters passed
//in as arguments
void swap(char array[], int start, int finish)
{
    //Error checking
    if (start < 0 || finish < 0)
    {
        cout << "The request index is before the beginning of the array! ";
        return;
    }
    int length = strlen(array); //how many characters there are in the array
    --length;                   //I do not want to swap the '\0'
    
    if (start > length || finish > length)
    {
        cout << "The requested index is after the end of the word or phrase! ";
    }
    else
    {
        //Swap
        char hold = array[start];
        array[start] = array[finish];
        array[finish] = hold;
    }
}

