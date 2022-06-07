//Include your name, course, and information about the code
//implemented in this file.

#include "cs162_course.h"

//Implement the body of these functions for Lab #6

//Constructor - initialize all data members to their zero equivalent value
course::course()
{
	//Place the code for the constructor here
    first_name[0] = '\0';
    last_name[0] = '\0';
    crs_num = 0;
    crs_desc[0] = '\0';
    section[0] = '\0';

}


//Read in the CRN, Course Description and Section
//Store these into the private data members of the class
void course::read_course()
{
    //Implement this function
    cout << "Please enter the CRN: ";
    cin >> crs_num;
    cin.ignore(100, '\n');
    cout << endl;

    cout << "Please enter the Course Descriptor: ";
    cin.get(crs_desc, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << endl;

    cout << "Please enter the section number: ";
    cin.get(section, SIZE, '\n');
    cin.ignore(100, '\n');
    cout << endl;
}


//Display the name and course information
void course::display()
{
    //Implement this function
    display_name();
    cout << "CRN: " << crs_num << "\tCourse Designation: " << crs_desc 
         << "\tSection Number: " << section << endl << endl; 
}

//Take the argument and compare it to the student's name
//If it is the same, return a true - otherwise return false
bool course::is_match(char a_first_name[], char a_last_name[])
{
    //Implement this function
    bool match = false;

    if(!strcmp(a_first_name, first_name) &&
       !strcmp(a_last_name, last_name))
      match = true;
    return match;
}


//Reset the course information for a student if they
//want to drop, given the CRN. Only drop the course if the CRN
//matches. Return true if the operation was successful and false
//if the CRN doesn't match
bool course::drop(int CRN)
{
    //Implement this function 
    bool drop = false;

    if (CRN == crs_num)
    {
      crs_num = 0;
      crs_desc[0] = '\0';
      drop = true;
    }
    return drop;
}


