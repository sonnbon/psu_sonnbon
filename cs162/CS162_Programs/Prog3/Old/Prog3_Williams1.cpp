#include <iostream>
#include <cctype>
#include <cstring>
//#include <fstream>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// May 6, 2021
// *****************************************************************************
// This program allows a user to add and display new songs of their choosing, as
// well as save and load a song playlist to and from an external data file, 
// "song.txt". Each song includes an artist name, title name, type of music, 
// when the user likes to listen to that song, and the link url to access that
// song. These items are organized in the structure, 'song'. A user can also 
// search for and display all songs matching a word or phrase that they input.
//
// The user is first welcomed by the 'welcome' function, which explains what
// this program does and how to properly use it. A menu is then displayed to the
// user, called by the function 'menu', letting them choose from six options
// (ONLY TWO OPTIONS AVAILABLE RIGHT NOW, NOT INCLUDING THE EXIT FUNCTION, WHICH 
// ACHIEVE TASK 1 AND TASK 2): 1 - Add new song, 2 - Display all songs, 3 - Save
// all songs to an external data file, 4 - Load songs from an external data 
// file, 5 - Search for and display particular songs, and 6 - Exit the program.
// The user will get brought back to this menu whenever they finish with which
// ever choice they make, except for exiting the program, which will call the
// function, 'exit', and display an exiting message. If the user types anything
// other than 1 through 6, an error message will display and prompt them to try
// again. If the user chooses option 1, the function, 'read_all', will get
// called. This function then calls the function, 'read_song', allowing the user
// to add a song with all of the members from the 'song' structure (artist,
// title, genre, listen, and link). The number of songs is then incremented by
// one. If the number of songs is still less than 10, then the function, 
// 'add_more', gets called, asking the user if they would like to add a new
// song. If their response if neither yes nor no, an error message will prompt
// them to try again. Otherwise, if their response is yes, the function will 
// return true and, within the 'read_all' function, will loop back to calling
// the 'read_song' function again. This will loop until the user's response is
// no or if the number of songs reach 10. If their response is no, the user will 
// be brought back to the main menu. In the main menu, if the user chooses
// option 2, the function, 'display_all', will get called. This function first
// checks if there are songs in the playlist. If not, a message will get 
// displayed to the user letting them know, and then take them back to the main
// menu. If there are songs in the playlist, then, on a loop iterating through
// the number of songs, the function, 'display_song', gets called. This function
// displays each individual song with its collective information separated by a
// '|', line by line. The user is then taken back to the main menu.
// (TASK 1 and TASK 2)
// *****************************************************************************

//Constants
const int INFO = 31;    //Max size of artist, title, genre, and when user likes
                        //to listen
const int LINK = 101;   //Max size of link url access information
const int SONGS = 10;   //Max number of songs allowed to be added

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

//Prototypes
void welcome();                              //Welcomes the user
int menu();                                  //User chooses what they want to do
void read_song(song & a_song);               //Reads in one new song
void display_song(song & a_song);            //Displays one added song
void read_all(song playlist[], int & num);   //Read all the added songs in
void display_all(song playlist[], int num);  //Display all the added songs out
bool add_more();                             //Checks if user wants to add song
void exit();                                 //Displays exiting message

/*
void save(song playlist[], int num);         //Saves playlist to external file
int load(song playlist[]);                   //Loads playlist from external file
bool is_search();                            //Checks if user wants to search 
                                             //for any particular songs
char search_type();                          //Checks what song type user wants 
                                             //to search by
bool is_match(song playlist[], char type);   //Check and display all song 
                                             //matches
bool bad_input(char choice);                 //Checks for invalid search choice
*/

int main()
{
    //Variable definitions
    song one_song;           //Will be one added song
    song playlist[SONGS];    //Will be the playlist of added songs (up to 10)
    int num_of_songs = 0;    //Will be the number of songs added (up to 10)
    int menu_option = 0;     //Will determine what user wants to do

    //Welcome the user
    welcome();
    do
    {
      menu_option = menu();  //Get users menu option choice

      switch (menu_option)
      {
        case 1:
          //Read all new songs
          read_all(playlist, num_of_songs);
	  break;
        case 2:
	  //Display all read in songs
          display_all(playlist, num_of_songs);
	  break;
	case 3:
	  //Save current list of songs to external data file
	  cout << "Coming Soon..." << endl << endl;
	  break;
	case 4:
	  //Load new songs from a file previously stored
	  cout << "Coming Soon..." << endl << endl;
	  break;
	case 5:
	  //Display all songs that match a particular choice
	  cout << "Coming Soon..." << endl << endl;
	  break;
	case 6:
	  //Exiting message
	  exit();
	  break;
        default:
	  cout << "Your choice is invalid. Please try again!" << endl << endl;
      }
    } while (menu_option != 6);


    return 0;
}

//Function prompts user to make a choice on how they would like to use the
//program. The user's choice is read in as a whole number integer. This
//Function takes no arguments and returns an integer.
int menu()
{
    //Variable definitions
    int choice = 0;  //Will be users number choice response
    
    cout << "\nPlease choose what you would like to do. Enter the number item\n"
	 << "(1, 2, 3, 4, 5, or 6) corresponding to your choice:\n\n"
	 << "\t1 - Add new song\n"
	 << "\t2 - Display all songs\n"
	 << "\t3 - Save songs to 'Song.txt' (TEMPORARILY UNAVAILABLE)\n"
	 << "\t4 - Load songs from 'Song.txt' (TEMPORARILY UNAVAILABLE)\n"
	 << "\t5 - Search for particular song (TEMPORARILY UNAVAILABLE)\n"
	 << "\t6 - Exit Program"
	 << endl << endl;
    cout << "Enter number choice here: ";
    cin >> choice;
    cin.ignore(100, '\n');
      
    return choice;
}


//Function displays everything that is read in from the function, 'read_all', 
//back to the user, song by song. The function, 'display_song', will get called 
//and repeat again, taking the 'playlist' array's index as its argument, 
//incrementing by one index until the number of songs has been reached. However,
//if there are no songs in the playlist, a message will be displayed to the user
//informing them of this. This function takes the 'song' data type, passing the 
//array variable 'playlist', and an integer variable 'num_of_songs', passed by 
//value, as arguments and returns nothing.
void display_all(song playlist[], int num)
{
    if(num == 0)
    {
      cout << "There are no songs in your playlist! Please add new songs!"
	   << endl << endl;
    }
    else
    {
      for (int i = 0; i < num; ++i)
        display_song(playlist[i]);
    }
}

//Function checks if user would like to add a new song and checks for a valid or
//invalid response to a yes or no question. It will display an error message to 
//the user if their response is neither yes nor no and prompt them to try again. 
//Otherwise, the response is valid and the function will return true for yes or
//false for no. This function takes no arguments and returns true or false.
bool add_more()
{
    //Variable definitions
    char response = 'N';  //Users 'Y' or 'N' (yes/no) response. Set to 'N'.
    bool more = false;    //True or false for yes or no response. Set to false.

    do
    {
      cout << "Would you like to add a new song? (Y/N): ";
      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);  //Capitalize response character

      if ('Y' != response && 'N' != response)
        cout << "Your response is invalid. Please try again!" << endl << endl;
    } while ('Y' != response && 'N' != response);

    if ('Y' == response)
      more = true;
    return more;
}


//Function allows the user to enter up to 10 songs or less, which ever they 
//prefer. If the number of songs in the playlist is less than 10, then the
//function 'read_song' gets called, which allows the user to add one song.
//The user will keep getting prompted if they would like to add a new song 
//by the function, 'add_more', until their response is no or the number of 
//songs reaches 10. If the user's response is no, the prompts will stop and the 
//number of songs will be stored. If the user's response is neither yes nor no,
//an error message will get displayed and prompt the user to try again. If 10
//songs have been added, a message will inform the user. This function takes the 
//'song' data type, passing the array variable 'playlist', and an integer 
//variable 'num', passed by reference, as arguments and returns nothing.
void read_all(song playlist[], int & num)
{
    //Variable definitions
    bool more = false;  //True or false for yes or no response. Set to false. 
    
    if (num < SONGS)
    {
      do
      {
        read_song(playlist[num]);
        ++num;
        cout << endl;
      
        if (num < SONGS)
          more = add_more();  //Check for yes or no response, whether users wants
                              //to add more songs.
        else
          cout << "You've added 10 songs!" << endl << endl;
      } while (more && num < SONGS);
    }
    else
      cout << "You've added 10 songs!" << endl << endl;
}

//Function displays the song that is read in from the function, 'read_song', 
//back to the user. In a printed out statement, the function will display the 
//user's inputted song artist, title, genre, when they like to listen to it, 
//and the link url to access the song, all on separate lines. This function 
//takes the 'song' data type, passing the variable 'a_song' by reference, as an 
//argument and returns nothing.
void display_song(song & a_song)
{
    cout << a_song.artist << '|' << a_song.title << '|' << a_song.genre << '|'
         << a_song.listen << '|' << a_song.link << endl;
}

//Function prompts the user to enter an artist, to enter the title of the song, 
//to enter the type of music, to enter when they like to listen to that song, 
//and to enter the link url to access the song. The user's inputs are read in 
//separately after each prompt and stored accordingly to the 'song' structure's 
//respective members. This function takes the 'song' data type, passing the 
//variable 'a_song' by reference, as an argument and returns nothing.
void read_song(song & a_song)
{
    cout << "Please enter the name of the artist: ";
    cin.get(a_song.artist, INFO, '\n');
    cin.ignore(100, '\n');
    
    cout << "Please enter the title of the song: ";
    cin.get(a_song.title, INFO, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter the genre of the song: ";
    cin.get(a_song.genre, INFO, '\n');
    cin.ignore(100, '\n');
    
    cout << "When do you like to listen to the song? ";
    cin.get(a_song.listen, INFO, '\n');
    cin.ignore(100, '\n');
    
    cout << "What is the link to access this song (https://...)? ";
    cin.get(a_song.link, LINK, '\n');
    cin.ignore(100, '\n');

}

//Function welcomes the user, explaining what the program is and how to use it
//properly. Functions takes no arguments and returns nothing.
void welcome()
{
    cout << "****************************************************************\n"
         << "---------Welcome to the Song Playlist Building Program!---------\n"
	 << "****************************************************************"
	 << endl << endl;
    
    cout << "This program gives you the option to add songs to a playlist,\n"
	 << "display songs from a playlist, search for songs in a playlist,\n"
	 << "and save songs to or load songs from an external data file.\n"
	 << "Songs you add will have the following information:\n\n"
	 << "\t- Name of artist\n"
	 << "\t- Name of song\n"
	 << "\t- Type of music\n"
	 << "\t- When you like to listen to it\n"
	 << "\t- The link to access it (https://...)"
	 << endl << endl;

    cout << "If you are looking for particular songs in your playlist, you\n"
	 << "will be able to search by type (artist, title, genre, or when\n"
	 << "you like to listen to it)."
	 << endl << endl;

    cout << "You will not be able to add, display, save, or load more than 10\n"
	 << "songs to a playlist, so make sure to choose your favorite songs!"
	 << endl << endl;

    cout << "Follow the directions carefully and have fun!\n\n"
	 << "****************************************************************"
	 << endl << endl;
}

//Function displays an exiting message to the user. This function takes no
//arguments and returns nothing.
void exit()
{
    cout << "****************************************************************\n"
         << "-------------Exiting Song Playlist Building Program-------------\n"
	 << "****************************************************************"
	 << endl << endl;
}

/*The function, 'save', will save the songs that have been inputted by the user
and read in to an external data file named, "song.txt". First, a connection for
output must be made with the text file. If the connection is good, then the 
indexed element of the 'playlist' array's associated artist, title, genre, when
the user listens to the song, and link url to access the song, will be outputted
to the text file. After each element output, the index will increment by one, 
until the number of songs inputted by the user and read in is reached. While 
each song is outputted to the text file, each member will be separated by a 
pipe, '|'. Once the total number of songs is outputted to the text file, the 
function then closes the file. This function takes the 'song' data type, passing
the array variable 'playlist', and an integer variable 'num_to_save', passed 
by value, as arguments and returns nothing.

The function, 'load', will read in the songs from an external data file named,
"song.txt". First, a connection for input must be made with the text file. If
the connection is good, then the function will read in the first element of the
'playlist' array's associated artist, making sure to use the pipe, '|', as its
delimiter. Then, while the array's index is less than the total allowed number
of songs (up to 10) and there is not an end of file flag, read in the indexed
element of the 'playlist' array's associated title, genre, when the user likes
to listen to the song, and the link url to access the song, all individually 
making sure to use the pipe, '|', as their delimiter. After reading in the link 
url, increment the index by one, then read in the indexed element of the 
'playlist' array's associated artist, making sure to use the pipe, '|', as its 
delimiter. This will then repeat from reading in the next title element until 
the index number is no longer less than the total allowed number of songs (up to 
10) or there is nothing else to read in. When this is done looping, the function 
will close the file. The function then returns the index number. This function 
takes the 'song' data type, passing the array variable 'playlist' as an argument 
and returns an integer to keep track of the number of songs read in from the 
file.

The function, 'is_search', will prompt and read in whether the user would like
to search for a particular list of songs. If the response is neither yes nor no, 
an error message will get displayed to the user and they will be prompted the 
yes or no question again. If the user's response is yes, the function will store 
the result as true. Otherwise, the function will return false. This function 
takes no arguments and returns true or false.

The function, 'search_type', will prompt and read in whether the user wants to
search by artist, song title, genre, or when they like to listen to a song (will
not search by link, as a link will always output a unique song rather than a
list of songs matching the same search parameter). If the user's response is
'artist', the function will store the character 'a'. If the user's response is
'title', the function will store the character 't'. If the user's response is
'genre', the function will store the character 'g'. If the user's response is
'listen', the function will store the character 'l'. Otherwise, an error message
will get displayed to the user and they will be prompted the question again.
This function takes no arguments and returns a character 'a', 't', 'g', or 'l'.

The function, 'is_match', will prompt the user to input the artist, title,
genre, or when they like to listen based on the returned character from the
function, 'search_type'. Iterating through a loop, if the returned character is 
'a', the user will be prompted to enter in the artist they are searching for. 
The user's input will then be string compared to the 'playlist' array's indexed
element associated artist. If there is a match, store the result as true. If the
returned character is 't', the user will be prompted to enter in the title they 
are looking for. The user's input will then be string compared to the 'playlist'
array's indexed element associated title. If there is a match, store the result
as true. If the returned character is 'g', the user will be prompted to enter in
the genre they are looking for. The user's input will then be string compared to
the 'playlist' array's indexed element associated genre. If there is a match,
store the result as true. If the returned character is 'l', the user will be 
prompted to enter in when they like to listen to a song. The user's input will
then be string compared to the 'playlist' array's indexed element associated
'listen'. If there is a match, store the result as true. Otherwise, store the
result as false. If there was a match for any of the user's inputs, the
function, 'display_song', will be called, taking the 'playlist' array's indexed
element as its argument. The index will then increment by one and the loop will
start over checking for the same match in the next 'playlist' element for each
member. This will loop until the number of songs entered has been iterated
through. If no matches are ever found, no songs will be displayed to the user.
Instead, a message letting the user know that no matches were found will be
displayed. This function takes the 'song' data type, passing the array
variable, 'playlist', and the user's character input, passed by value, as
arguments and returns true or false.


The function, 'bad_input', will be used in place whenever a user inputs an
invalid value having to do with how the user wants to search ('a', 't', 'g', or 
'l' not entered when prompted by the 'search_type' function). It will check that
the user's response was neither 'a', 't', 'g', nor 'l' and store the result as
true. It will then display the error message, telling the user to try again. 
Otherwise, the response is valid and the function will return false. This 
function takes the user's character response as an argument and returns true or 
false.*/
