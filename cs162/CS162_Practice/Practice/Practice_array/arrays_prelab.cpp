#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 21;

int main()
{
    char hello[SIZE];

    while (strcmp(hello, "hi") != 0)
    {
        cout << "Enter: ";
        cin.width(SIZE);
        cin >> hello;
        cin.ignore(100, '\n');
    }

    return 0;
}
