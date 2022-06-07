#include "CS162_movie.h"

//Connor Williams
//CS162 - pre-recorded lecture on classes and multiple files
//The purpose of this file is to implement the member functions provided in
//the movie class
//
//The data members are:
/*
      char title[TITLE];
      char info[INFO];
      int stars;
*/

// :: scope resolution operator
// This is the movie constructor and it should initialize all of the data
// members in the movie class
movie::movie()
{
    title = NULL;
    info[0] = '\0';
    stars = 0;
    //cout << "We just executed the movie constructor" << endl;
}

//Write the code to deallocate the dynamic memory in a destructor
movie::~movie()
{
    if (NULL != title)
        delete [] title;
    title = NULL;
}

//This function will read in a title, info and stars after prompting the
//user
void movie::read()
{
    char temp[TITLE];
    cout << "Please enter a movie title: ";
    cin.get(temp, TITLE, '\n'); //reads in a title
    cin.ignore(100, '\n');

    //size the title just right
    title = new char[strlen(temp) + 1];
    strcpy(title, temp);

    //read in the rest of the members as before
    cout << "Please enter information about the movie: ";
    cin.get(info, INFO, '\n');
    cin.ignore(100, '\n');

    cout << "How many stars (1-5): ";
    cin >> stars;
    cin.ignore(100, '\n');
}

//This function will display the contents of the movie object which includes
//the title, info and stars
void movie::display()
{
    if (NULL == title) return; //nothing is in the title array
    cout << title << '\t' << info << endl << "# of stars: " << stars
         << endl;
}

//Compare the movie passed in as an argument with the title in the class
bool movie::is_match(char matching_title[])
{
    if (NULL == title) return false; //nothing to compare
    if(strcmp(matching_title, title) == 0)
        return true;
    return false;
}





