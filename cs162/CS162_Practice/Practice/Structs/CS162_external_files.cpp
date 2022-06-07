#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
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

int load(movie library[]); //return the number of movies read in
void save(movie library[], int num_to_save);

int main()
{
    //Variables
    movie library[MOVIES];
    int num_of_movies = 0;
    
    num_of_movies = load(library);

    read_movies(library, num_of_movies);
    cout << "num_of_movies is: " << num_of_movies << endl;

    display_movies(library, num_of_movies);
    //movie scifi;  //test out just one variable of type struct
    //read_a_movie(scifi);
    //display_a_movie(scifi);

    save(library, num_of_movies);

    return 0;
}

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






