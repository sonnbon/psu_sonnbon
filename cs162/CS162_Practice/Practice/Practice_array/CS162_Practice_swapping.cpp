#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Connor Williams
// Topic 1 Arrays swapping lecture example
// We want to demonstrate how to swap two elements of an array
// With this example we will use an array of characters

const int SIZE = 10;
int main()
{
    char word[SIZE];    //array we are working with to swap
    char hold;          //temporarily holds onto an element's data as part
                        //of the swap
    int i = 0;
    int j = 1;

    //read in a word
    cout << "Please enter a word: ";
    cin.width(SIZE);  //enforce that we will only read in SIZE-1 characters
    cin >> word;      //assuming no whitespace in the word
    cin.ignore(100, '\n');

    //Let's swap the first and the second elements
    hold = word[i];   //gets the first element's value
    word[i] = word[j];
    cout << "first and second should be the same: " << word << endl;
    word[j] = hold;

    cout << "Our resulting word with the first two characters swapped is: "
         << word << endl;

    //Let's swap the first and last characters
    i = 0; //first
    j = strlen(word) - 1;

    hold = word[i];
    word[i] = word[j];
    word[j] = hold;

    cout << "Our result of the first and last being swapped: " << word << endl;


    return 0;
}
