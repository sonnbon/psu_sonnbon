#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Connor Williams
//CS162 pre-recorded lecture on Structures
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

int main()
{
    //Variables
    movie library[MOVIES];
    int num_of_movies = 0;

    read_movies(library, num_of_movies);
    cout << "num_of_movies is: " << num_of_movies << endl;

    display_movies(library, num_of_movies);
    //movie scifi;  //test out just one variable of type struct
    //read_a_movie(scifi);
    //display_a_movie(scifi);


    return 0;
}

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
        display_a_movie(library[i]);
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






