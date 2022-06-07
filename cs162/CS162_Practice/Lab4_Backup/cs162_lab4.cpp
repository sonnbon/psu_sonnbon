//Connor Williams
//CS162 - Intro to Computer Science
//The purpose of this lab is to get information from a student using functions


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//Constants
const int NAME = 21;  //max for name lengths

// ***************************************** 
//Place your prototypes here:
void get_name(char first[], char last[]);
void get_course(int & crn, char design[], int & section);
bool again();
void capitalize(char word[]);


int main()
{
     //Variable definitions
     char first_name[NAME];  //array for first name
     char last_name[NAME];   //array for last name
     int course_num;         //to be CRN
     char course_desig[NAME]; //to be course designation
     int section_num;        //to be section number
     bool start_over;        //checks if users wants to start again
     
     do
     {
       //Make sure to call the function(s) that you write from main!
       get_name(first_name, last_name);
       get_course(course_num, course_desig, section_num);
       capitalize(first_name);
       capitalize(last_name);

       cout << first_name << " " << last_name << endl << endl;
       start_over = again();

     } while (start_over);

     return 0;
}

//Now implement the functions here:
//Function prompts user for first and last name and echoes it back. Function
//returns nothing and takes two arrays as arguments.
void get_name(char first[], char last[])
{
    cout << "Please enter your first and last name." << endl << endl;

    cout << "First name: ";
    cin.get(first, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "Last name: ";
    cin.get(last, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "Awesome! Your name is " << first << " " << last << "!"
         << endl << endl;
}

//Function prompts and reads in the course information. Returns nothing and
//takes two integers and an array as arguments.
void get_course(int & crn, char design[], int & section)
{
    cout << "Please enter your CRN: ";
    cin >> crn;
    cin.ignore(100, '\n');

    cout << "Please enter your Course Designator: ";
    cin.get(design, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter your Section Number: ";
    cin >> section;
    cin.ignore(100, '\n');

    cout << "Awesome! So your CRN is " << crn << " and your Course\n"
         << "Designator is " << design << ", Section " << section << "."
         << endl << endl;
}

//Function checks whether user wants to continue or quit. Function takes no
//arguments and returns true or false
bool again()
{
    //variables
    char response = 'Y';   //set to yes for loops
    bool again = true;     //set to true for loops
    cout << "Do you want to continue? (Y/N): ";
    cin >> response;
    cin.ignore(100, '\n');

    if (response != 'Y')
      again = false;

    return again;
}

//Function capitalizes the first character of each word
void capitalize(char word[])
{
    //variables
    int len = 0;    //length set to zero for finding length of array

    word[0] = toupper(word[0]);

    len = strlen(word);    //get length of strings characters

    for (int i = 0; i < len; ++i)
    {
      if (word[i] == ' ' && (i + 1) < len)
        word[i + 1] = toupper(word[i + 1]);
    }
}
