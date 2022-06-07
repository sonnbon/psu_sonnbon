#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//Connor Williams
//CS162 pre-recorded lecture on Multiple files, modular abstraction, classes
//etc.
//Header file
//We will be implementing the code for the data flow diagram from the topic #2
//power point slides to manage a movie. We will read in a movie and display a
//movie, working ultimately with an array of movies

//Constants
const int TITLE = 31;
const int INFO = 131;
const int MOVIES = 10;

//Structure
struct movie
{
    char title[TITLE];
    char info[INFO];  //description or information I want to keep about a movie
    int stars;        //how much did I like the movie (5 stars is great)
};

//Prototypes
void read_movies(movie library[], int & num_of_movies);
void display_movies(movie library[], int num_of_movies);
void read_a_movie(movie & a_movie);  //read in only one movie
void display_a_movie(movie & one_movie); //just displays one

int load(movie library[]); //return the number of movies read in
void save(movie library[], int num_to_save);

