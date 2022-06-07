#include "CS162_movie.h"

//Connor Williams
//CS162 pre-recorded lecture on Multiple files, modular abstraction, classes,
//etc.
//The code in this file manages reading and writing movies

//READ ALL of the movies in that the user wants
//Make sure not to go outside the array bounds
void read_movies(movie library[], int & num_of_movies)
{
    int i = num_of_movies;
    char response = 'n'; //allow the user to decide when to be done

    cout << "Do you want to read in a new movie: ";
    cin >> response;
    cin.ignore(100, '\n');

    //Read in the movies if the user wants to
    while ('Y' == toupper(response) && i < MOVIES)
    {
        read_a_movie(library[i]);
        cout << "Another? ";
        cin >> response;
        cin.ignore(100, '\n');
        ++i;
    }

    //Update the number of movies
    num_of_movies = i;
}

//Display all of the movies
void display_movies(movie library[], int num_of_movies)
{
    for (int i = 0; i < num_of_movies; ++i)
    {
        cout << library[i].title << endl;
        cout << library[i].info << endl;
        cout << "The number of stars is: " << library[i].stars << endl;
    }
}

//Read in a movie and store it in the argument that is passed by reference
void read_a_movie(movie & a_movie)
{
    //Prompt and read in the title, information, and # of stars
    cout << "Please enter the movie title: ";
    cin.get(a_movie.title, TITLE, '\n');
    cin.ignore(100, '\n');

    cout << "Enter information about the movie: ";
    cin.get(a_movie.info, INFO, '\n');
    cin.ignore(100, '\n');

    cout << "How many stars (1-5): ";
    cin >> a_movie.stars;
    cin.ignore(100, '\n');
}

//Display the contents of a movie
void display_a_movie(movie & one_movie)
{
    cout << one_movie.title << endl
         << one_movie.info << endl
         << "The number of stars is: " << one_movie.stars << endl;
}






