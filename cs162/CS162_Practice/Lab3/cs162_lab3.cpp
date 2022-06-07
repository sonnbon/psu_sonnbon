// Connor Williams
// CS162 - Introduction to Computer Science
// This program allows the user to read in a person's name and major. 

//Every program  

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//Here is an example of a constant; constants should
//be global so that they are accessible by all functions
//and there are no "side effects" unlike with global
//variables (which should be avoided!)
const int NAME = 31;    //max size for name
const int MAJOR = 21;   //max size for major
const int OVERSIZE = 100;  //space for oversized input

int main()
{
    //Variable definitions
    char name[NAME];    //array for full name
    char major[MAJOR];  //array for major
    int name_len = 0;   //to get name length
    int major_len = 0;  //to get major length
    char response = 'N';      //to restart
    
    do
    {
      cout << "Please enter your full name: ";
      cin.get(name, NAME, '\n');
      cin.ignore(100, '\n');
      name[0] = toupper(name[0]);

      name_len = strlen(name);    //get length of strings characters

      for (int i = 0; i < name_len; ++i)
      {
        if (name[i] == ' ' && (i + 1) < name_len)
          name[i + 1] = toupper(name[i + 1]);
      }

      cout << "Your name is " << name << endl << endl;
    
      cout << "Please enter your major: ";
      cin.get(major, OVERSIZE, '\n');
      cin.ignore(100, '\n');
    
      major_len = strlen(major);   //get length of strings characters

      while (major_len > MAJOR)
      {
        cout << "I'm sorry, that's too many characters. Try again..." << endl;
        cin.get(major, OVERSIZE, '\n');
        cin.ignore(100, '\n');

        major_len = strlen(major);
      }
      if (strcmp(major, "Computer Science") == 0)
        cout << "It's Computer Science!" << endl;
      else
        cout << "Your major is " << major << endl;

      cout << "Add another name and major? (Y/N): ";
      cin >> response;
      cin.ignore(100, '\n');

      if (response == 'Y')
          cout << endl;

    } while (response == 'Y');

    return 0;
}
