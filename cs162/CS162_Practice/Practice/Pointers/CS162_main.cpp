#include "CS162_list.h"

// Connor Williams
// CS162- pre-recorded lecture on classes and multiple files
// This will be the main manager

int main()
{
    /* Testing the single movie class:
    char matching [31];

    movie scifi;
    cout << "Let's work with scifi: " << endl;
    scifi.read();  //object.member
    scifi.display();

    cout << "What movie would you like to look for? ";
    cin.get(matching, 31, '\n');
    cin.ignore(100, '\n');

    if (scifi.is_match(matching))
        cout << "YES, it is a match " << endl;
    else
        cout << "No match today" << endl;

    movie drama;
    movie kids; */

    //Testing the list class (a collection of movies)
    list scifi_library; //implicitly call the list class constructor
    scifi_library.read_all();
    scifi_library.display_all();


    return 0;
}
