#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 100;
const int SIES = 100;

int main()
{
    char array1[SIZE];
    char new_array[SIZE];
    char array2[SIES];

    cout << "Enter: ";
    cin.get(array1, SIZE, '\n');
    cin.ignore(100, '\n');
    
    strcpy(array2, array1);
    int length = strlen(array2);

    for (int i = 0; i < length; ++i)
    {
        if (array2[i] == ' ' || array2[i] == '.' && (i + 1) != length)
        {
          array2[i] = array2[i + 1];
          array2[i + 1] = '.';
        }
    }        
        cout << array2 << endl;
          

    return 0;
}
