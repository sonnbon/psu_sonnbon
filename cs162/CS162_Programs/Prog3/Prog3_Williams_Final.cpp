#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// May 12, 2021
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
// user, called by the function 'menu', letting them choose from six options:
// 1 - Add new song, 2 - Display all songs, 3 - Save all songs to an external 
// data file, 4 - Load songs from an external data file, 5 - Search for and 
// display particular songs, and 6 - Exit the program. The user will get brought 
// back to this menu whenever they finish with which ever choice they make, 
// except for exiting the program, which will call the function, 'exit', and 
// display an exiting message. If the user types anything other than 1 through 
// 6, an error message will display and prompt them to try again. If the user 
// chooses option 1, the function, 'read_all', will get called. This function 
// then calls the function, 'read_song', allowing the user to add a song with 
// all of the members from the 'song' structure (artist, title, genre, listen, 
// and link). The number of songs is then incremented by one. If the number of 
// songs is still less than 10, then the function, 'add_more', gets called, 
// asking the user if they would like to add a new song. If their response is 
// neither yes nor no, an error message will prompt them to try again. 
// Otherwise, if their response is yes, the function will return true and, 
// within the 'read_all' function, will loop back to calling the 'read_song' 
// function again. This will loop until the user's response is no or if the 
// number of songs reaches 10. If their response is no, the user will be brought
// back to the main menu. In the main menu, if the user chooses option 2, the 
// function, 'display_all', will get called. This function first checks if there 
// are songs in the playlist. If not, a message will get displayed to the user 
// letting them know, and then take them back to the main menu. If there are 
// songs in the playlist, then, on a loop iterating through the number of songs, 
// the function, 'display_song', gets called. This function displays each 
// individual song with its collective information separated by a '|', line by 
// line. The user is then taken back to the main menu. If the user chooses
// option 3, the function, 'save', will get called. The function will warn
// the user that they will save over anything that may already be saved in the 
// file, by calling the function, 'overwrite'. If the user chooses to continue,
// then 'overwrite' returns true and then the 'save' function continues. This
// function connects to an external data file and saves each added song to it. 
// Once the function has iterated through every song, the program displays the
// number of songs saved to the external data file and returns to the main menu. 
// If the user decides to not overwrite the file (a 'no' response), the program 
// will return to the main menu. If the user chooses option 4, the function, 
// 'load', will get called. The function will warn the user that they will load 
// over any songs that they have already entered in their current session unless 
// they go back to the menu and save first, by calling the function, 
// 'load_over'. If the user chooses to continue, then 'load_over' returns true 
// and then the 'load' function continues. This function connects to an external 
// data file and reads every song in from it (up to 10). Once the function has 
// iterated through every previously saved song, it displays and stores the 
// number of songs loaded. If the user decides to not load over any songs (a 
// 'no' response), the program will return to the main menu. In the main menu,
// if the user chooses option 5, the function, 'search', gets called. If there
// are no songs added, a message will display to the user letting them know they
// need to add songs first. Otherwise, the function, 'search_type', gets called,
// which asks the user how they would like to search for songs. The user can
// search by artist, title, genre, or when they like listening to a song by
// entering 1, 2, 3, or 4, respectively. The 'search_type' function returns the
// user's integer choice. If the user entered none of the four numbers, an error
// message will display and 'search_type' will get called again. Otherwise,
// the functions, 'find_artist', 'find_title', 'find_genre', or 'find_listen',
// will get called depending on the users respective choice of 1, 2, 3, or 4.
// These four functions prompt the user for the song information according to
// the function name ('find_artist' will search by artist). The function reads
// in the users input and then string compares it to the entire playlist by 
// iterating through the 'song' structures respective member. If there is a
// match, the song will display. If there is at least one match, the function
// will return true. Otherwise, there are no matches and the respective
// function returns false. If there are no matches, the 'search' function then
// displays to the user that no matches were found. After matching songs are
// displayed or if the user gets no matches, the program returns to the main
// menu. In the main menu, if the user chooses option 6, the function, 'exit',
// gets called and displays an exiting message.
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

//Function Prototypes
void welcome();                              //Welcomes the user
void read_song(song & a_song);               //Reads in one new song
void display_song(song & a_song);            //Displays one added song
void read_all(song playlist[], int & num);   //Read all the added songs in
void display_all(song playlist[], int num);  //Display all the added songs out
void save(song playlist[], int num);         //Saves playlist to external file
void search(song playlist[], int num);       //Searches for particular songs
void exit();                                 //Displays exiting message
bool add_more();                             //Checks if user wants to add song
bool overwrite();                            //Warn user they might clear file
bool load_over();                            //Warn user they might clear songs
bool find_artist(song playlist[], int num);  //Displays artist matches
bool find_title(song playlist[], int num);   //Displays title matches
bool find_genre(song playlist[], int num);   //Displays genre matches
bool find_listen(song playlist[], int num);  //Displays listen matches
int menu();                                  //User chooses what they want to do
int load(song playlist[], int num);          //Loads playlist from external file
int search_type();                           //Gets user search type preference

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

      //Main menu
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
	  save(playlist, num_of_songs);
	  break;
	case 4:
	  //Load new songs from a file previously stored
          num_of_songs = load(playlist, num_of_songs);
	  break;
	case 5:
	  //Display all songs that match a particular choice
	  search(playlist, num_of_songs);
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

//Function searches for and displays all matches of a song type chosen by the
//user. This function takes the 'song' data type, passing the array variable 
//'playlist', and an integer, 'num', passed by value, as arguments and returns 
//nothing.
void search(song playlist[], int num)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    int choice = 0;      //To be users search type choice. Set to 0.

    if (num == 0)
    {
      cout << "There are no songs to search for! Add some songs first!"
	   << endl << endl;
    }
    else
    {
      do
      {
        choice = search_type();  //Get users search type choice
      
        switch (choice)
        {
          case 1:
	    match = find_artist(playlist, num);  //Find and display artist match
	    break;
          case 2:
	    match = find_title(playlist, num);   //Find and display title match
	    break;
          case 3:
	    match = find_genre(playlist, num);   //Find and display genre match
	    break;
          case 4:
	    match = find_listen(playlist, num);  //Find and display listen match
	    break;
          default:
	    cout << "Your choice is invalid. Please try again" << endl << endl;
        }
      } while (choice < 1 || choice > 4);

      cout << endl;

      if (!match)
      {
        cout << "Sorry, no matches were found in the current playlist."
	     << endl << endl;
      }
    }
}

//Function checks for and displays songs that match a particular preference on
//when the user likes to listen to a song. This function takes the 'song' data 
//type, passing the array variable 'playlist', and an integer, 'num', passed by 
//value, as arguments and returns true for matches or false for no matches.
bool find_listen(song playlist[], int num)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char listen[INFO];   //To be when user likes to listening to song

    cout << "Search by when you like to listen to a song: ";
    cin.get(listen, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num; ++i)
    {
      if (!strcmp(playlist[i].listen, listen))
      {
        display_song(playlist[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular genre. This
//function takes the 'song' data type, passing the array variable 'playlist', 
//and an integer, 'num', passed by value, as arguments and returns true for 
//matches or false for no matches.
bool find_genre(song playlist[], int num)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char genre[INFO];    //To be genre to search by

    cout << "What genre would you like to search by? ";
    cin.get(genre, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num; ++i)
    {
      if (!strcmp(playlist[i].genre, genre))
      {
        display_song(playlist[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular title. This 
//function takes the 'song' data type, passing the array variable 'playlist', 
//and an integer, 'num', passed by value, as arguments and returns true for 
//matches or false for no matches.
bool find_title(song playlist[], int num)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char title[INFO];    //To be title to search by

    cout << "What song title would you like to search by? ";
    cin.get(title, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num; ++i)
    {
      if (!strcmp(playlist[i].title, title))
      {
        display_song(playlist[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular artist. This 
//function takes the 'song' data type, passing the array variable 'playlist', 
//and an integer, 'num', passed by value, as arguments and returns true for 
//matches or false for no matches.
bool find_artist(song playlist[], int num)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char artist[INFO];   //To be artist to search by

    cout << "What artist would you like to search by? ";
    cin.get(artist, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num; ++i)
    {
      if (!strcmp(playlist[i].artist, artist))
      {
        display_song(playlist[i]);
	match = true;
      }
    }
    return match;
}

//Function prompts and reads in how the user would like to search for particular
//songs, whether it be by artist, song title, genre, or when they like to listen 
//to a song (will not search by link, as a link will always output a unique song 
//rather than a list of songs matching the same search parameter). This function 
//takes no arguments and returns an integer.
int search_type()
{
    //Variable definitions
    int choice = 0;  //To be users search type choice. Set to 0.
    
    cout << "How would you like to search for songs? Enter the number\n"
	 << "item corresponding to your choice (1, 2, 3, or 4):\n\n"
	 << "\t1 - by Artist\n"
	 << "\t2 - by Title\n"
	 << "\t3 - by Genre\n"
	 << "\t4 - by When you like to listen\n"
	 << endl;
    cout << "Enter number choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    cout << endl;

    if (choice >= 1 && choice <= 4)
    {
      cout << "REMEMBER to enter your search parameter exactly how the song's\n"
	   << "information was entered before!" << endl << endl;
    }
    return choice;
}

//Function reads in the songs from an external data file. If user chooses to
//proceed, knowing they may load over songs, then the function will read in each 
//songs member from the 'playlist' array while the end of file is not flagged 
//and the number of songs is less than 10. This function takes the 'song' data 
//type, passing the array variable 'playlist', and an integer, 'num', passed by 
//value, as arguments and returns an integer.
int load(song playlist[], int num)
{
    //Variable definitions
    int i = 0;           //To be number of songs read in. Set to 0.
    bool clear = false;  //To check if user decides to continue with loading.
                         //Set to false.
    ifstream song_in;    //To connect and input songs from external file

    clear = load_over();  //Checks if user decides to continue with loading

    if (clear)
    {
      //Connect to file
      song_in.open("song.txt");

      //Check that connection is good and load the previously stored list of 
      //songs from the external file
      if (song_in)
      {
        song_in.get(playlist[0].artist, INFO, '|');
        song_in.ignore(100, '|');
        while (!song_in.eof() && i < SONGS)
        {
          song_in.get(playlist[i].title, INFO, '|');
          song_in.ignore(100, '|');

          song_in.get(playlist[i].genre, INFO, '|');
          song_in.ignore(100, '|');

          song_in.get(playlist[i].listen, INFO, '|');
          song_in.ignore(100, '|');

          song_in >> playlist[i].link;
          song_in.ignore(100, '\n');
          ++i;

          song_in.get(playlist[i].artist, INFO, '|');
          song_in.ignore(100, '|');
        }
        song_in.close();  //Close file

        cout << "+++++++++++++++++++++++ " << i 
	     << " SONG(S) LOADED +++++++++++++++++++++++" 
	     << endl << endl;
      }
      else
      {
        cout << "No file to load from. Try saving some songs first!"
	     << endl << endl;
      }
    }
    else
      i = num;  //To prevent loss of songs entered in current session
    return i;   //To track how many songs are in the playlist
}

//Function prompts user whether they would like to continue and possibly clear 
//all of the currently inputted songs or go back to the main menu and save them 
//first. This function takes no arguments and returns true or false.
bool load_over()
{
    //Variable definitions
    char response = 'N';  //Users 'Y' or 'N' (yes/no) response. Set to 'N'.
    bool clear = false;   //To check if user decides to continue with loading.
                          //Set to false.

    cout << "Loading will load over any songs that you have already entered.\n"
	 << "Please make sure to first save any songs you might have entered\n"
	 << "during this session!"
	 << endl << endl;
    do
    {
      cout << "Are you sure you want to continue? (Y/N): ";
      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);  //Capitalize response character

      cout << endl;

      if ('Y' != response && 'N' != response)
      {
	cout << "That is an invalid response. Please try again!"
	     << endl << endl;
      }
    } while ('Y' != response && 'N' != response);
      
    if ('Y' == response)
      clear = true;
    return clear;
}

//Function prompts user whether they would like to continue and possibly clear 
//the entire file or go back to the main menu and try loading from the file 
//first. This function takes no arguments and returns true or false.
bool overwrite()
{
    //Variable definitions
    char response = 'N';  //Users 'Y' or 'N' (yes/no) response. Set to 'N'.
    bool clear = false;   //To check if user decides to continue with saving.
                          //Set to false.

    cout << "Saving will overwrite anything that is currently saved in your\n"
	 << "file. Please make sure to first load any songs you might have\n" 
	 << "saved in a previous session!"
	 << endl << endl;
    do
    {
      cout << "Are you sure you want to continue? (Y/N): ";
      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);  //Capitalize response character

      cout << endl;

      if ('Y' != response && 'N' != response)
      {
	cout << "That is an invalid response. Please try again!"
	     << endl << endl;
      }
    } while ('Y' != response && 'N' != response);
      
    if ('Y' == response)
      clear = true;
    return clear;
}

//Function saves the songs that have been inputted by the user and read in to 
//an external data file. If the user chooses to proceed, knowing that they may
//save over any previously saved songs, then each member of the 'playlist' array 
//will be outputted to the text file. This function takes the 'song' data type, 
//passing the array variable 'playlist', and an integer variable 'num', passed 
//by value, as arguments and returns nothing.
void save(song playlist[], int num)
{
    //Variable defintions
    bool clear = false;   //To check if user decides to continue with saving.
                          //Set to false.
    ofstream song_out;    //To connect and output songs to external file

    clear = overwrite();  //Checks if user decides to continue with saving

    if (clear)
    {
      //Connect to file
      song_out.open("song.txt");
    
      //Check that connection is good and save the current list of songs to the
      //external file
      if (song_out)
      {
        for (int i = 0; i < num; ++i)
        {
          song_out << playlist[i].artist << '|' << playlist[i].title << '|'
		   << playlist[i].genre << '|' << playlist[i].listen << '|'
		   << playlist[i].link << endl;
        }
        song_out.close();  //Close file

        cout << "======================= " << num
             << " SONG(S) SAVED =======================" 
	     << endl << endl;
      }
    }
}

//Function prompts user to make a choice on how they would like to use the
//program. This function takes no arguments and returns an integer.
int menu()
{
    //Variable definitions
    int choice = 0;  //Will be users number choice response
    
    cout << "Please choose what you would like to do. Enter the number item\n"
	 << "corresponding to your choice (1, 2, 3, 4, 5, or 6):\n\n"
	 << "\t1 - Add new song\n"
	 << "\t2 - Display all songs\n"
	 << "\t3 - Save songs to external file\n"
	 << "\t4 - Load songs from external file\n"
	 << "\t5 - Search for particular songs\n"
	 << "\t6 - Exit Program\n"
	 << endl;

    cout << "Enter number choice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    
    cout << endl;

    return choice;
}

//Function displays everything that is read in from the function, 'read_all', 
//back to the user, song by song, by looping through the function,
//'display_song'. This function takes the 'song' data type, passing the array 
//variable 'playlist', and an integer variable 'num', passed by value, as
//arguments and returns nothing.
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
      cout << endl;
    }
}

//Function checks if user would like to add a new song and checks for a valid or
//invalid response to a yes or no question. This function takes no arguments and 
//returns true or false.
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

      cout << endl;

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
//This function takes the 'song' data type, passing the array variable 
//'playlist', and an integer variable 'num', passed by reference, as arguments 
//and returns nothing.
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
          more = add_more();  //Check if user wants to add more songs
        else
          cout << "You've added 10 songs!" << endl << endl;
      } while (more && num < SONGS);
    }
    else
      cout << "You've added 10 songs!" << endl << endl;
}

//Function displays the song that is read in from the function, 'read_song', 
//back to the user. This function takes the 'song' data type, passing the 
//variable 'a_song' by reference, as an argument and returns nothing.
void display_song(song & a_song)
{
    cout << "Artist: " << a_song.artist << '\n' 
	 << "Song Title: " << a_song.title << '\n' 
	 << "Genre: " << a_song.genre << '\n'
	 << "When you like to listen: " << a_song.listen << '\n' 
	 << "Link: " << a_song.link << endl << endl;
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
//properly. Function takes no arguments and returns nothing.
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
	 << "you like to listen to it). When looking for songs, make sure to\n"
	 << "enter in your search parameter exactly how the song's\n"
	 << "information was previously entered in the playlist!"
	 << endl << endl;

    cout << "You will not be able to add, display, save, or load more than 10\n"
	 << "songs at a time to a playlist, so make sure to choose your\n"
	 << "favorite songs!"
	 << endl << endl;

    cout << "When using this program, be careful and make sure you are ready\n"
	 << "to continue or you might end up saving over a file or loading\n"
	 << "over songs you just entered!"
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
