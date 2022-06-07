#include "CS162_movie.h"

// Connor Williams
// CS162 pre-recorded lecture on classes and multiple files
// This file contains the class interface for a collection of movies

const int MOVIES = 10;

class list
{
    public:
        list(); //constructor, initialize the data members
        void read_all();
        void display_all();

    private:
        movie array[MOVIES];
        int num_of_movies;
};
