#include "Prog4_playlist.h"

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// May 20, 2021
// *****************************************************************************
// This file contains main, calling all implemented and prototyped functions and
// class member functions from 'Prog4_playlist.cpp' and 'Prog4_playlist.h',
// allowing the user to use this 'Song Playlist Building program.
//
// After the user is first welcomed by the 'welcome' function, and the program
// is explained, the user is prompted by the 'choose_size' member function to
// enter how many songs they want their song playlist to hold, dynamically
// allocating the playlist size. A menu is then displayed to the user, called by 
// the function 'menu', letting them choose from five options: 1 - Add new song, 
// 2 - Display all songs, 3 - Search for and display particular songs, 4 - Edit particular songs, and 5 - Exit the 
// program. If the user types anything other than 1 through 5, an error message 
// will display and prompt them to try again. If the user chooses option 1, the 
// member function, 'read_all', will get called and accessed by the 
// 'music_list' array. This allows the user to add as many songs, with all of the 
// members from the 'song' structure (artist, title, genre, listen, and link), as
// the user wants within the bounds of the user allocated playlist size. If the
// user reaches the max limit of songs added or they chooses to stop adding
// songs, they will be brought back to the main menu. In the main menu, if the 
// user chooses option 2, the member function, 'display_all', will get called and
// accessed by 'music_list'. This function displays each individual added song 
// with its collective information separated by a '|', line by line. In the main
// menu, if the user chooses option 3, the member function, 'search', gets 
// called and accessed by 'music_list'. The user is prompted to enter how they 
// would like to search for songs. The user can search by artist, title, genre, 
// when they like listening to a song, or link URL. All song matches will be
// displayed to the user or, if there are no matches, the user will be notified.
// In the main menu, if the user chooses option 4, the member function, 'edit',
// will get called and accessed by 'music_list'. This function allows the user
// to choose a specific song from all of the added songs and edit any part of 
// that song (artist, title, genre, when they like to listen, or link). In the 
// main menu, if the user chooses option 5, the function, 'exit', gets called 
// and displays an exiting message. The program will exit the main menu.
// *****************************************************************************

int main()
{
    //Variable definitions
    song one_song;        //Will be one added song
    playlist music_list;  //Implicitly call the playlist class constructor
    int menu_option = 0;  //Will determine what user wants to do

    //Welcome the user and dynamically allocate the playlist size
    welcome();
    music_list.choose_size();    
    do
    {
      menu_option = menu();  //Get users menu option choice

      //Main menu
      switch (menu_option)
      {
        case 1:
          //Read all new songs
          music_list.read_all();
	  break;
        case 2:
	  //Display all read in songs
          music_list.display_all();
	  break;
	case 3:
	  //Display all songs that match a particular choice
	  music_list.search();
	  break;
	case 4:
	  //Edit a particular song
	  cout << "Coming soon..." << endl;
	  break;
	case 5:
	  //Exiting message
	  exit();
	  break;
        default:
	  cout << "Your choice is invalid. Please try again!" << endl << endl;
      }
    } while (menu_option != 5);

    return 0;
}

