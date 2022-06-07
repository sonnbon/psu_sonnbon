#include "CS162_list.h"

// Connor Williams
// CS162 pre-recorded lecture on classes and multiple files
// This file will contain the implemntation of the list class
// member functions

//The data members for the class:
/*
        movie array[MOVIES];
        int num_of_movies;
*/

//This is the list class constructor. It should initialize the data
//members to the zero equivalent value. 
//
// --movie array does not need to be
//   initialized because it is an array of movie objects. Implicitly calls
//   the constructor of the movie for each element of the array. Sets the title,
//   info, stars for each element to '\0' element 0, stars to zero.--
list::list()
{
    cout << "How many movies would you like: ";
    cin >> size_of_array;
    cin.ignore(100, '\n');

    array = new movie[size_of_array];
    num_of_movies = 0;

 /* alternative:
  
    array = NULL;
    size_of_array = 0;
    num_of_movies = 0;
 */
}

//Destructor will deallocate the dynamic memory
list::~list()
{
    if (NULL != array)
        delete [] array;
    array = 0;
    size_of_array = 0;
    num_of_movies = 0;
}

//Read in movie until the user wants to stop or we run out of space
void list::read_all()
{
    char response = 'y'; //does the user want to do this again
    while (tolower(response) == 'y' && num_of_movies < size_of_array)
    {
        array[num_of_movies].read();
        ++num_of_movies;

        cout << "Again? ";
        cin >> response;
        cin.ignore(100, '\n');
    }
}

//Display all movies
void list::display_all()
{
    for (int i = 0; i < num_of_movies; ++i)
        array[i].display();
}
