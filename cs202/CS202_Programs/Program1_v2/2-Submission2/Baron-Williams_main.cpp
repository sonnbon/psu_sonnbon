#include "Baron-Williams_pile.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 26, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_main.cpp
// *****************************************************************************
// This file contains the application in which a two player card game can be
// played. In this file, the flow of the game can be controlled through a text
// based menu options. There will be three separate card deck objects
// containing 'action' cards, 'defend' cards, and 'spell' cards. There will also
// be three hand objects containing a separate list of 'action', 'defend', and
// 'spell' cards, holding both players hands of cards, cards played, and total
// discarded cards. The deck objects will read in cards from external files
// when the user is ready to play the card game. The hands will be able to draw
// cards from each deck, placing cards in the correct respective hand. This will
// remove the cards from the decks. When a player plays a card, it will remove
// from their cards hand and move to their respective played hand and the
// discarded pile. Cards can be used to take away a player's lifeline or give
// life to their own. This file manages and rebuilds deck object's from the
// respective discard piles when they are empty, each card, played one at a
// time, and when a player's lifeline reaches zero, resulting in a game over.
// *****************************************************************************



int main()
{

  //Test out a number of objects and functions.
  test_program_objects();

  return 0;
}



