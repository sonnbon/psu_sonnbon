#include "Prog4_playlist.h"
using namespace std;

// *****************************************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// jcwill@pdx.edu
// Program 4
// May 27, 2021
// *****************************************************************************
// This file contains the main function, calling all implemented and prototyped 
// functions and class member functions from 'Prog4_playlist.cpp' and 
// 'Prog4_playlist.h', allowing the user to create a playlist of songs, with the 
// ability to display every song, display only songs by a particular genre, and 
// edit particular songs.
//
// After the user is first welcomed by the 'welcome' function, and the program
// is explained, the user is prompted by the 'choose_size' member function to
// enter how many songs they want their song playlist to hold, dynamically
// allocating the size. A menu is then displayed to the user, called by the 
// function 'menu', letting them choose from five options: 1 - Add new song, 
// 2 - Display all songs, 3 - Display all songs that match a particular genre, 
// 4 - Edit particular songs, and 5 - Exit the program. Calling the member 
// function, 'read_all', allows the user to add as many songs to a playlist as
// they wish, with all of the members from the 'song' structure (artist, title, 
// genre, listen, and link), within the bounds of the user allocated playlist 
// size. Calling the member function, 'display_all', displays each individual 
// added song with its collective information, grouped and separated by
// category. Calling the member function, 'by_genre', allows the user to search
// for and display songs of a particular genre by entering in a genre or type
// as a search parameter. Calling the member function, 'edit', allows the user 
// to choose a specific song from all of the added songs and edit any part of 
// that song (artist, title, genre, when they like to listen, or link). Calling 
// the function, 'exit', displays an exiting message. The program will exit the 
// main menu.
// *****************************************************************************

int main()
{
    //Variable definitions
    playlist music_list;  //Implicitly call the playlist class constructor
    int menu_option = 0;  //Will determine what user wants to do. Set to 0.

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
	  //Display all songs that match a particular genre
	  music_list.by_genre();
	  break;
	case 4:
	  //Edit a particular song
	  music_list.edit();
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

