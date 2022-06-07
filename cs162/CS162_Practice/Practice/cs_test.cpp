#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    cin >> number;

    if (number > 0)
        cout << "You entered: " << number << endl << endl;
    else if (number < 0)
        cerr << "Oopsies!!!" << endl << endl;

    return 0;
}
