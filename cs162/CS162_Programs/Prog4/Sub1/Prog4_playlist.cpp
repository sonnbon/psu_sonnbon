#include "Prog4_playlist.h"

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// May 20, 2021
// *****************************************************************************
// This file implements all the functions and class member functions prototyped
// and interfaced from the 'Prog4_playlist.h' header file. The functions welcome
// and exit the program, and allow the user to read in a song, display a song,
// and make decisions, in terms of adding more songs, menu options, and 
// searching by type. The 'playlist' class member functions allow the user to
// dynamically allocate memory, letting them choose the size of the playlist, to
// read all the desired songs in, to display all the added songs, to search for
// and to edit particular songs. Any dynamically allocated memory will be 
// accordingly deallocated by the class as well.
// *****************************************************************************

//Playlist constructor function initializes all of the data members in the
//playlist class. This function takes no arguments and returns nothing.
playlist::playlist()
{
    music = NULL;       //Music array initialized to NULL
    size_of_music = 0;  //Size of music playlist initialized to 0
    num_of_songs = 0;   //Number of songs added initialized to 0
}

//Playlist deconstructor function deallocates the dynamic memory and resets all
//other data members to zero. This function takes no arguments and returns
//nothing.
playlist::~playlist()
{
    if (NULL != music)
      delete [] music;  //Deallocate the dynamic memory
    music = NULL;       //Reset the music array to NULL
    size_of_music = 0;  //Size of music playlist reset to 0
    num_of_songs = 0;   //Number of songs reset to 0.
}

//Function prompts user to enter how many songs they would like to add,
//creating the dynamically allocated size of the playlist. This function takes
//no arguments and returns nothing.
void playlist::choose_size()
{
    cout << "How many songs would you like your playlist to hold?\n"
	 << "Enter a whole number: ";
    cin >> size_of_music;
    cin.ignore(100, '\n');

    music = new song[size_of_music];

    cout << "\nYour playlist can now hold " << size_of_music << " song(s)!!!"
	 << endl << endl;
}

//Function searches for and displays all matches of a song type chosen by the
//user. This function takes no arguments and returns nothing.
void playlist::search(songs)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    int choice = 0;      //To be users search type choice. Set to 0.

    if (num_of_songs == 0)
    {
      cout << "There are no songs to search for! Add some songs first!"
	   << endl << endl;
    }
    else
    {
      do
      {
        choice = search_type();     //Get users search type choice
      
        switch (choice)
        {
          case 1:
	    match = find_artist(music);  //Find and display artist match
	    break;
          case 2:
	    match = find_title(music);   //Find and display title match
	    break;
          case 3:
	    match = find_genre(music);   //Find and display genre match
	    break;
          case 4:
	    match = find_listen(music);  //Find and display listen match
	    break;
	  case 5:
	    match = find_link(music);    //Find and display link match
	    break;
          default:
	    cout << "Your choice is invalid. Please try again" << endl << endl;
        }
      } while (choice < 1 || choice > 5);

      cout << endl;

      if (!match)
      {
        cout << "Sorry, no matches were found in the current playlist."
	     << endl << endl;
      }
    }
}

//Function checks for and displays songs that match a particular link. This
//function takes no arguments and returns true for matches or false for no 
//matches.
bool find_link(playlist music)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char link[LINK];     //To be link to search by

    cout << "What link would you like to search by? ";
    cin.get(link, LINK, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num_of_songs; ++i)
    {
      if (!strcmp(music[i].link, link))
      {
        display_song(music[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular preference on
//when the user likes to listen to a song. This function takes no arguments and 
//returns true for matches or false for no matches.
bool find_listen(playlist music)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char listen[INFO];   //To be when user likes to listening to song

    cout << "Search by when you like to listen to a song: ";
    cin.get(listen, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num_of_songs; ++i)
    {
      if (!strcmp(music[i].listen, listen))
      {
        display_song(music[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular genre. This
//function takes no arguments and returns true for matches or false for no 
//matches.
bool find_genre(playlist music)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char genre[INFO];    //To be genre to search by

    cout << "What genre would you like to search by? ";
    cin.get(genre, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num_of_songs; ++i)
    {
      if (!strcmp(music[i].genre, genre))
      {
        display_song(music[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular title. This 
//function takes no arguments and returns true for matches or false for no 
//matches.
bool find_title(playlist music)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char title[INFO];    //To be title to search by

    cout << "What song title would you like to search by? ";
    cin.get(title, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num_of_songs; ++i)
    {
      if (!strcmp(music[i].title, title))
      {
        display_song(music[i]);
	match = true;
      }
    }
    return match;
}

//Function checks for and displays songs that match a particular artist. This 
//function takes no arguments and returns true for matches or false for no 
//matches.
bool find_artist(playlist music)
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char artist[INFO];   //To be artist to search by

    cout << "What artist would you like to search by? ";
    cin.get(artist, INFO, '\n');
    cin.ignore(100, '\n');

    cout << endl;

    for (int i = 0; i < num_of_songs; ++i)
    {
      if (!strcmp(music[i].artist, artist))
      {
        display_song(music[i]);
	match = true;
      }
    }
    return match;
}

//Function prompts and reads in how the user would like to search for particular
//songs, whether it be by artist, song title, genre, or when they like to listen 
//to a song. This function takes no arguments and returns an integer.
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
	 << "\t5 - by Link\n"
	 << endl;
    cout << "Enter number choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    cout << endl;

    if (choice >= 1 && choice <= 5)
    {
      cout << "REMEMBER to enter your search parameter exactly how the song's\n"
	   << "information was entered before!" << endl << endl;
    }
    return choice;
}

//Function prompts user to make a choice on how they would like to use the
//program. This function takes no arguments and returns an integer.
int menu()
{
    //Variable definitions
    int choice = 0;  //Will be users number choice response
    
    cout << "Please choose what you would like to do. Enter the number item\n"
	 << "corresponding to your choice (1, 2, 3, 4, or 5):\n\n"
	 << "\t1 - Add new song\n"
	 << "\t2 - Display all songs\n"
	 << "\t3 - Search for particular songs\n"
	 << "\t4 - Edit a particular song (OUT OF ORDER)\n"
	 << "\t5 - Exit Program\n"
	 << endl;

    cout << "Enter number choice: ";
    cin >> choice;
    cin.ignore(100, '\n');
    
    cout << endl;

    return choice;
}

//Function displays everything that is read in from the function, 'read_all', 
//back to the user, song by song, by looping through the function,
//'display_song'. This function takes no arguments and returns nothing.
void playlist::display_all()
{
    if(num_of_songs == 0)
    {
      cout << "There are no songs in your playlist! Please add new songs!"
	   << endl << endl;
    }
    else
    {
      for (int i = 0; i < num_of_songs; ++i)
        display_song(music[i]);
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

//Function allows the user to enter as many songs as they want, within the 
//bounds of the user allocated playlist size. If the number of songs in the 
//playlist is less than the dynamically allocated max size, then the
//function 'read_song' gets called, which allows the user to add one song.
//This function takes no arguments and returns nothing.
void playlist::read_all()
{
    //Variable definitions
    bool more = false;  //True or false for yes or no response. Set to false. 
    
    if (num_of_songs < size_of_music)
    {
      do
      {
        read_song(music[num_of_songs]);
        ++num_of_songs;
        cout << endl;
      
        if (num_of_songs < size_of_music)
          more = add_more();  //Check if user wants to add more songs
        else
          cout << "You've added " << size_of_music << " songs!" << endl << endl;
      } while (more && num_of_songs < size_of_music);
    }
    else
      cout << "You've added " << size_of_music << " songs!" << endl << endl;
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
	 << "Link URL: " << a_song.link << endl << endl;
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
	 << "and edit songs of your choosing.\n"
	 << "Songs you add will have the following information:\n\n"
	 << "\t- Name of artist\n"
	 << "\t- Name of song\n"
	 << "\t- Type of music\n"
	 << "\t- When you like to listen to it\n"
	 << "\t- The link to access it (https://...)"
	 << endl << endl;

    cout << "If you are looking for particular songs in your playlist, you\n"
	 << "will be able to search by type (artist, title, genre, or when\n"
	 << "you like to listen to it, or link URL). When looking for songs,\n"
	 << "make sure to enter in your search parameter exactly how the\n"
	 << "song's information was previously entered in the playlist!"
	 << endl << endl;

    cout << "You can add as many songs as you want, you just need to choose\n"
	 << "the size of your playlist!"
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
