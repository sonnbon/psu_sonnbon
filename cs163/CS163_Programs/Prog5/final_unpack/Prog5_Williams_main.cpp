#include "Prog5_Williams_graph.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: August 13, 2021
// Course: CS163 Data Structures
// Assignment: Program 5
// Filename: Prog5_Williams_main.cpp
// *****************************************************************************
// This file contains a menu of options to test inserting and displaying data
// into a hiking route to see what trailheads are adjacent to each other. The 
// client can insert all trailheads of a specific area into a list, constructing
// the an adjacency list. The client can then connect these trailheads to other 
// trailheads in the list, representing which trailheads are adjacent to each 
// other and which are not, constructing an edge list. The client can then 
// display which trailheads are adjacent to a specific trailhead within the 
// list. Step by step, as the client enters each following adjacent trailhead, 
// they can eventually come to a dead end (no more connections).
// *****************************************************************************



int main()
{
  //Variable definitions
  graph hiking_route;  //To be object holding a list of trailhead names
  char trailhead[31];  //To be trailhead name
  char path[31];       //To be trailhead name on a path from another trailhead
  int menu_option = 0; //To be client inputted menu choice

  cout << "This program allows a user to create an adjacency list of\n"
       << "trailheads, to which they can then insert trailheads from the list\n"
       << "that are adjacent to other trailheads in the adjacency list.\n"
       << "First, you will want to create your list of trailheads. Then, you\n"
       << "will want to add trailheads that are adjacent to each other. Last,\n"
       << "you can then display which trailheads are adjacent to each other,\n"
       << "or in other words, you will be able to see where you can go next.\n"
       << "\nPlease choose from the menu below."
       << endl << endl;

  do
  {
    cout << "\t1) Insert a trailhead into the list\n"
         << "\t2) Insert a trailhead adjacent to another trailhead\n"
         << "\t3) Display where you can go to based on your chosen position\n"
         << "\t4) Exit program"
         << endl << endl;

    cout << "Please enter a number from the menu above: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    switch (menu_option)
    {
      //Construct the adjancency list of trailheads.
      case 1:
        cout << "Please enter the name of the trailhead: ";
        cin.get(trailhead, 31, '\n');
        cin.ignore(100, '\n');

        if (!hiking_route.insert_trailhead(trailhead))
          cerr << "The list of trailheads is full...\n\n";
        else
          cout << trailhead << " added to the list." << endl << endl;
        break;

      //Insert adjacent trailheads to the trailheads in the adjacency list.
      case 2:
        cout << "Please enter the name of the trailhead you wish to create a\n"
             << "path from: ";
        cin.get(trailhead, 31, '\n');
        cin.ignore(100, '\n');

        cout << "Please enter the name of the adjacent trailhead: ";
        cin.get(path, 31, '\n');
        cin.ignore(100, '\n');

        if (!hiking_route.insert_path(trailhead, path))
        {
          cerr << "There's no trailhead with that name or the trailhead you\n"
               << "are trying to connect to does not exist...\n\n";
        }
        else
          cout << "Path to adjacent trailhead added." << endl << endl;
        break;

      //Display trailheads that are adjacent to the inputted trailhead from the
      //adjacency list.
      case 3:
        cout << "Please enter your where you want to travel from: ";
        cin.get(trailhead, 31, '\n');
        cin.ignore(100, '\n');

        cout << "From " << trailhead << ", you can travel to:\n\n"
             << "Trailheads:" << endl;

        if (!hiking_route.display_choices(trailhead))
          cerr << "No where to go...\n\n";
        break;

      case 4:
        cout << "Exiting program..." << endl << endl;
        break;
      
      default:
        cout << "That's not a valid menu option... Try again." << endl << endl;
        break;
    }

  } while (menu_option != 4);

  return 0;
}
   
