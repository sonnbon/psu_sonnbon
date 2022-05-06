#include "Baron-Williams_pile.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 19, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_game.h
// *****************************************************************************
// This file contains the classes 'a_node', 's_node', and 'd_node', all with the
// job of managing a node of the classes they are respectively derived from
// ('action', 'spell', and 'defend'). These three nodes inherit their respective
// classes information for the purpose of being used in varying data structures
// that will provide the ability to play a card game. The sole purpose of each
// node, however, is to be a container that can be connected to other nodes by
// pointing to itself.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'a_node' class manages a "container" of the 'action' class that it is 
// derived from in a single inheritance hierarchy. This "container" has a data
// member, a pointer to an 'a_node', that allows it to be used to connect to 
// other nodes of this same class type. This class can go to the next node, by
// returning the pointer to the next node, and can check if the next node is
// NULL, returning a bool value.
class game:
{
  public:
    game();                    //Default constructor


  private:
   
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

