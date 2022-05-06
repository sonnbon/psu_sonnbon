#include "Prog4_playlist.h"
using namespace std;

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// jcwill@pdx.edu
// Program 4
// May 27, 2021
// *****************************************************************************
// This file implements all the functions and class member functions prototyped
// and interfaced from the 'Prog4_playlist.h' header file. The functions welcome
// and exit the program, and allow the user to read in a song, display a song,
// and make decisions, in terms of adding more songs, editing songs and their 
// information, and menu options. The 'playlist' class member functions allow 
// the user to dynamically allocate memory, letting them choose the size of the 
// playlist, to read all the desired songs in, to display all the added songs, 
// to display songs by  particular genres, and to edit particular songs. Any 
// dynamically allocated memory will be accordingly deallocated by the class as 
// well.
// *****************************************************************************

//Playlist constructor function initializes all of the data members in the
//playlist class. This function takes no arguments and returns nothing.
playlist::playlist()
{
    music = NULL;       //Music array initialized to NULL.
    size_of_music = 0;  //Size of music playlist initialized to 0.
    num_of_songs = 0;   //Number of songs added initialized to 0.
}

//Playlist deconstructor function deallocates the dynamic memory and resets all
//other data members to zero. This function takes no arguments and returns
//nothing.
playlist::~playlist()
{
    if (NULL != music)
      delete [] music;  //Deallocate the dynamic memory.
    music = NULL;       //Reset the music array to NULL.
    size_of_music = 0;  //Size of music playlist reset to 0.
    num_of_songs = 0;   //Number of songs reset to 0.
}

//Function prompts user to enter how many songs they would like to add,
//creating the dynamically allocated size of the playlist. This function takes
//no arguments and returns nothing.
void playlist::choose_size()
{
    cout << "How many songs would you like your playlist to hold?" << endl;
    do
    {
      cout << "Enter a whole number: ";
      cin >> size_of_music;
      cin.ignore(100, '\n');
      
      if (size_of_music < 1)
      {
        cout << "\nYour playlist won't be able to hold any songs! Please try\n"
	     << "again!" << endl << endl;
      }
    } while (size_of_music < 1);
      
    music = new song[size_of_music];  //Dynamically allocate memory of user
                                      //chosen size.

    cout << "\nYour playlist can now hold " << size_of_music << " song(s)!!!"
	 << endl << endl;
}

//Function holds a collection of called functions, which allows the user to
//ultimately edit particular information about a particular song. The user 
//chooses which song and what part of that song they wish to edit. The edit is
//copied to the original information about the song. This function takes no 
//arguments and returns nothing.
void playlist::edit()
{
    //Variable definitions
    int song_choice = 0;  //Will be user's song choice. Set to 0.
    int type_choice = 0;  //Will be user's song information to edit choice.
                          //Set to 0.
    char update[INFO];    //To be updated edit information about a song.
    
    if (num_of_songs != 0)
    {
      display_all();

      song_choice = edit_choice(num_of_songs);  //Get song choice number.

      cout << song_choice + 1 << ". ";  //Display what number song it is in the
                                        //playlist. 
      display_song(music[song_choice]);
    
      type_choice = edit_options();  //Get information to edit choice number.

      cout << "Enter your edit or update to the song's information: ";
      cin.get(update, INFO, '\n');
      cin.ignore(100, '\n');
      cout << endl;

      copy_update(music[song_choice], update, type_choice);

      cout << song_choice + 1 << ". ";  //Display what number song it is in the
                                        //playlist.
      display_song(music[song_choice]);
    }
    else
      display_all();  //Will tell user that there are no songs in the playlist.
}

//Function copies an array to a particular member of the 'song' structure
//depending on what number choice the user makes. This function takes the 
//'song' structure data type, passing the variable 'a_song' by reference, an
//array of characters, and an integer, passed by value, as arguments and returns
//nothing.
void copy_update(song & a_song, char update[], int choice)
{
    switch (choice)
    {
      case 1:
        strcpy(a_song.artist, update);
	break;
      case 2:
	strcpy(a_song.title, update);
	break;
      case 3:
	strcpy(a_song.genre, update);
	break;
      case 4:
	strcpy(a_song.listen, update);
	break;
      case 5:
	strcpy(a_song.link, update);
	break;
      default:
        cout << "Your choice is invalid. Please try again!" << endl << endl;
    }
}

//Function displays a numbered list of options for the user to choose which
//part of a song they would like to edit. The user's response is read in as a
//whole number. This function takes no arguments and returns an integer.
int edit_options()
{
    //Variable definitions
    int choice = 0;  //Will be user's song information choice. Set to 0.

    cout << "What information would you like to edit about this song?\n\n"
	 << "\t1 - Artist\n"
	 << "\t2 - Song Title\n"
	 << "\t3 - Genre\n"
	 << "\t4 - When you like to listen\n"
	 << "\t5 - Link URL\n"
	 << endl;
    do
    {
      cout << "Enter a whole number from the list: ";
      cin >> choice;
      cin.ignore(100, '\n');
      cout << endl;

      if (choice < 1 || choice > 5)
        cout << "Your choice is invalid. Please try again!" << endl << endl;
    } while (choice < 1 || choice > 5);

    return choice;
}

//Function reads in user's choice of which song they would like to edit. This 
//function takes and integer, 'num', passed by value, as an arguemnt and returns
//an integer.
int edit_choice(int num)
{
    //Variable definitions
    int choice = 0;  //Will be user's song choice. Set to 0.
    
    cout << "Which song would you like to edit?" << endl << endl;

    do
    {
      cout << "Enter a whole number from the list: ";
      cin >> choice;
      cin.ignore(100, '\n');

      cout << endl;

      if (choice < 1 || choice > num)
        cout << "Your choice is invalid. Please try again!" << endl << endl;
    } while (choice < 1 || choice > num);
    
    --choice;  //Subtract one to be the real index of the playlist.

    return choice;
}

//Function searches for and displays all matches of a song genre chosen by the
//user. This function takes no arguments and returns nothing.
void playlist::by_genre()
{
    //Variable definitions
    bool match = false;  //To check for song matches. Set to false.
    char genre[INFO];    //To be genre to search for.

    if (num_of_songs == 0)
    {
      cout << "There are no songs to display! Add some songs first!"
	   << endl << endl;
    }
    else
    {
      cout << "REMEMBER to enter your search parameter exactly how the song's\n"
	   << "genre was entered before!" << endl << endl;

      cout << "What genre of songs would you like to display? ";
      cin.get(genre, INFO, '\n');
      cin.ignore(100, '\n');
      cout << endl;

      for (int i = 0; i < num_of_songs; ++i)
      {
        if (!strcmp(music[i].genre, genre))
        {
          cout << i + 1 << ". ";  //Displays what number the song is in the
	                          //playlist.
          display_song(music[i]);
	  match = true;
        }
      }
      if (!match)
      {
        cout << "Sorry, no matches were found in the current playlist."
	     << endl << endl;
      }
    }
}

//Function prompts user to make a choice on how they would like to use the
//program. This function takes no arguments and returns an integer.
int menu()
{
    //Variable definitions
    int choice = 0;  //Will be users number choice response.
    
    cout << "Please choose what you would like to do. Enter the number item\n"
	 << "corresponding to your choice (1, 2, 3, 4, or 5):\n\n"
	 << "\t1 - Add new song\n"
	 << "\t2 - Display all songs\n"
	 << "\t3 - Display songs of a particular genre\n"
	 << "\t4 - Edit a particular song\n"
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
      {
        cout << i + 1 << ". ";  //Displays what number the song is in the
	                        //playlist.
        display_song(music[i]);
      }
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

      response = toupper(response);  //Capitalize response character.

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
          more = add_more();  //Check if user wants to add more songs.
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
    cout << "Artist: " << a_song.artist << "\n   "
	 << "Song Title: " << a_song.title << "\n   "
	 << "Genre: " << a_song.genre << "\n   " 
         << "When you like to listen: " << a_song.listen << "\n   "
	 << "Link URL: " << a_song.link << endl << endl;
}

//Function prompts the user to enter an artist, to enter the title of the song, 
//to enter the type of music, to enter when they like to listen to that song, 
//and to enter the link url to access the song. This function takes the 'song' 
//data type, passing the variable 'a_song' by reference, as an argument and 
//returns nothing.
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
	 << "display songs from a playlist, search for songs by genre, and\n"
	 << "edit songs of your choosing.\n"
	 << "Songs you add will have the following information:\n\n"
	 << "\t- Name of artist\n"
	 << "\t- Name of song\n"
	 << "\t- Type of music\n"
	 << "\t- When you like to listen to it\n"
	 << "\t- The link to access it (https://...)"
	 << endl << endl;

    cout << "When searching for songs by genre, make sure to enter in your\n"
	 << "search parameter exactly how the song's genre was previously\n" 
	 << "entered in the playlist!"
	 << endl << endl;

    cout << "You can add as many songs as you want, you just need to choose\n"
	 << "the size of your playlist. Make sure it's greater than zero!"
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
