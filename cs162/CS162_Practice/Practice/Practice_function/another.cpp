#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 200;

int main()
{
    char array1[SIZE];
    char array2[SIZE];
    char hold;
    int length = 0;

    cout << "Enter notation: ";
    cin.get(array1, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Enter its word: ";
    cin.get(array2, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "You entered array1 as: " << array1 << endl;
    cout << "and entered array2 as:: " << array2 << endl;

    length = strlen(array2);
    for (int i = 0; i < length; ++i)
    {
        hold = array1[i];
        array1[i] = array2[i];
        array2[i] = hold;
    }
    array1[length] = '\0';

    cout << "Now array1 is: " << array1 << endl;
    cout << "and array2 is: " << array2 << endl;

    return 0;
}
