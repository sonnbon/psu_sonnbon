#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// May 24, 2021
// *****************************************************************************
// This header file contains all the necessary constants, prototypes,
// structures, and classes to allow a user to add and display new songs of their 
// choosing, display songs only by a particular genre, and edit particular 
// songs. Each song includes an artist name, title name, type of music, when the 
// user likes to listen to that song, and the link url to access that song. 
// These items are organized in the structure, 'song'. The prototypes contain 
// functions that do not need to share direct information from the class 
// 'playlist' or that work directly with the structure alone. The class 
// 'playlist' contains all other necessary member functions, which can read all 
// the songs in, display all the songs to the user, display songs by a 
// particular genre, and edit particular songs, by sharing the data members 
// (music array, size_of_music integer, and num_of_songs integer) information. 
// The class also allows the user to dynamically allocate memory, letting them 
// choose the size of the playlist.
// *****************************************************************************

//Constants
const int INFO = 31;    //Max size of song structure members, not including link
const int LINK = 101;   //Max size of link url access information

//Structures
//Holds all information to be associated with a song.
struct song
{
    char artist[INFO];  //To be the name of an artist
    char title[INFO];   //To be the title of a song
    char genre[INFO];   //To be the type of music
    char listen[INFO];  //To be when the user likes to listen to a song
    char link[LINK];    //To be the link url to access the song
};

//Function Prototypes
void welcome();                    //Welcomes the user
void read_song(song & a_song);     //Reads in one new song
void display_song(song & a_song);  //Displays one added song
void exit();                       //Displays exiting message
bool add_more();                   //Checks if user wants to add song
int menu();                        //User chooses what they want to do

//Classes
//Holds all information to be associated with a playlist
class playlist
{
    public:
      playlist();          //Constructor, initialize the data members
      ~playlist();         //Destructor, deallocate any dynamic member
      void choose_size();  //For user to dynamically allocate memory
      void read_all();     //Read all the added songs in
      void display_all();  //Display all the added songs out
      void by_genre();     //Searches for and displays particular genre

    private:
      song * music;       //Array can point to one song or the first of many
      int size_of_music;  //To be size of dynamically allocated playlist size
      int num_of_songs;   //To be number of songs
};















