#include "CS162_movie.h"

//Connor Williams
//CS162 pre-recorded lecture on Multiple files, modular abstraction, classes,
//etc.
//This code is managing working with the external data file

//Save the movies read in to an external data file
void save(movie library[], int num_to_save)
{
    ofstream file_out;
    //file_out.open("movie.txt", ios::app);
    file_out.open("movie.txt");
    if (file_out)
    {
        for (int i = 0; i < num_to_save; ++i)
        {
            file_out << library[i].title << '~'
                     << library[i].info << '~'
                     << library[i].stars << endl;
        }
        file_out.close();
    }
}


//Read information from the file
int load(movie library[]) //return the number of movies read in
{
    ifstream file_in; //be used to read from a file (to load)
    int i = 0;

    //Load any movies stored in an external data file. "movie.txt"
    file_in.open("movie.txt");
    if (file_in) //we connected by not being false
    {
        file_in.get(library[0].title, TITLE, '~');
        file_in.ignore(100, '~');

        while (!file_in.eof() && i < MOVIES)
        {
            file_in.get(library[i].info, INFO, '~');
            file_in.ignore(100, '~');
            file_in >> library[i].stars;
            file_in.ignore(100, '\n');
            ++i;
            file_in.get(library[i].title, TITLE, '~');
            file_in.ignore(100, '~');
        }
        file_in.close();
    }
    return i;
}

