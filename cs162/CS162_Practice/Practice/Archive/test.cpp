#include <iostream>
#include <cctype>
using namespace std;

// Connor Williams
// Just testing!

int main()
{
        char grade;

        cout << "Please enter: ";
        cin >> grade;

        while (grade < 'A' || grade > 'F' || 'E' == toupper(grade))
        {
            cout << "WRONG. again: ";
            cin >> grade;
        }
        return 0;
}
