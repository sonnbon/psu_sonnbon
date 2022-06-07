#include "CS162_movie.h"

//Connor Williams
//CS162 pre-recorded lecture on Multiple files, modular abstraction, classes,
//etc.
//This code manages the main which delegates what work needs to get done


int main()
{
    //Variables
    movie library[MOVIES];
    int num_of_movies = 0;
    
    //num_of_movies = load(library);

    read_movies(library, num_of_movies);
    cout << "num_of_movies is: " << num_of_movies << endl;

    display_movies(library, num_of_movies);
    //movie scifi;  //test out just one variable of type struct
    //read_a_movie(scifi);
    //display_a_movie(scifi);

    //save(library, num_of_movies);

    return 0;
}

