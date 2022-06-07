#include <iostream>
#include <cctype>
using namespace std;

// Connor Williams
// CS162 Lab2 - Practice Questions

int main()
{
    //variable def
    char letter_case;
    char other;
    int letter;
    int other_l;
    int difference;
    char f_initial;
    char m_initial;
    char l_initial;
    

    //checking letter value
    cout << "check case: ";
    cin >> letter_case;
    cout << endl;
    cin >> other;


    letter = letter_case;
    other_l = other;
    difference = other - letter_case;
    cout << letter << endl;
    cout << other_l << endl;
    cout << difference << endl;
    ++letter_case;
    cout << letter_case << endl;
    
    //1. if statement
    cout << "Enter initials: ";
    cin >> f_initial >> m_initial >> l_initial;

    if (isdigit(f_initial))
        cout << "YEP!" << endl;

     

    return 0;
}
