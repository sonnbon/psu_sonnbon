#include "Baron-Williams_pile.h"
#include <vector>
using namespace std;

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 31, 2022
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
  //Variable definitions
  //Decks, Hands, and Cards
  a_deck action_deck;  //Object holds the action deck
  d_deck defend_deck;  //Object holds the defend deck
  s_deck spell_deck;   //Object holds the spell deck
  a_hand action_hands; //Object holds the players action cards and discard pile
  d_hand defend_hands; //Object holds the players defend cards and discard pile
  s_hand spell_hands;  //Object holds the players spell cards and discard pile
  action action_card;  //Object holds one action card
  defend defend_card;  //Object holds one defend card
  spell spell_card;    //Object holds one spell card

  //Action, Defend, and Spell boards (cards at play) and lifelines
  vector<action> action_board(2); //Vector holds two players' action cards
  vector<defend> defend_board(2); //Vector holds two players' defend cards
  vector<spell> spell_board(2);   //Vector holds two players' spell cards
  vector<int> attack(2);          //Vector holds two players' attacks
  vector<int> defense(2);         //Vector holds two players' defenses
  vector<float> magic(2);         //Vector holds two players' magic
  vector<float> lifelines(2);     //Vector holds both players' lifelines


  //Miscellaneous
  char response = 'N'; //To be users changing response throughout the game
  int option = 0;      //To be users changing menu option choice
  int a_count = 0;     //To make sure players play one action card per turn
  int d_count = 0;     //To make sure players play one defend card per turn
  int s_count = 0;     //To make sure players play one spell card per turn
  int hand_p1 = 0;     //Index for player 1's hand
  int played_p1 = 1;   //Index for player 1's played cards
  int hand_p2 = 2;     //Index for player 2's hand
  int played_p2 = 3;   //Index for player 2's played cards
  int d_pile = 4;      //Index for discard pile

  //External files to read from
  string action_list = "Baron-Williams_actionlist.txt"; //External Action cards
  string defend_list = "Baron-Williams_defendlist.txt"; //External Defend cards
  string spell_list = "Baron-Williams_spelllist.txt";   //External Spell cards

  do
  {
    //Set or reset player 1 and player 2's lifelines. ([0] - P1, [1] - P2)
    lifelines[0] = 100;
    lifelines[1] = 100;

    //Build the card decks
    action_deck.build(action_list);
    defend_deck.build(defend_list);
    spell_deck.build(spell_list);

    //Welcome the user
    cout << "Welcome to a Very Mediocre Card Game!\n"
         << "In this card game, each player's hand will be randomly generated\n"
         << "from the provided card decks. There are three decks, an action deck,"
         << "\nan defend deck, and a spell deck. Action cards from the action\n"
         << "deck can be used to attack the other player. Defend cards from the\n"
         << "defend deck can be used to add life to one's lifeline. Spell cards\n"
         << "from the spell deck can be used to enhance action and defend cards\n"
         << "in many different ways.\n\n"
         << "Players can only play one card at a time from each hand and it\n" 
         << "must be the first card in their hand. NO CHEATING!\n" << endl;

    cout << "The decks have already been built. Would you like to see them or\n"
         << "would you like to begin by building each player's hand?\n" << endl;

    do
    {
      cout << "Enter here (Y - see decks, N - start game): ";

      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);

      if ('Y' == response)
      {
        cout << "-----ACTION DECK-----" << endl;
        action_deck.display_all();
        cout << "_____________________" << endl << endl;

        cout << "-----DEFEND DECK-----" << endl;
        defend_deck.display_all();
        cout << "_____________________" << endl << endl;

        cout << "-----SPELL DECK-----" << endl;
        spell_deck.display_all();
        cout << "____________________" << endl << endl;
      }
      else if ('N' != response)
        cout << "Oops, try responding again..." << endl << endl;

    } while ('N' != response && 'Y' != response);

    //Start game
    cout << "Great! Let's get started!" << endl << endl;
    cout << "Building both players' hands now...\n...\n..." << endl << endl;

    //Build players' action hands taking all cards from each deck randomly until
    //they are empty.
    while (!action_deck.is_empty())
    {
      //Draw and add to player 1's hand.
      action_deck.remove(action_card);
      action_hands.insert(action_card, hand_p1);

      //Draw and add to player 2's hand.
      action_deck.remove(action_card);
      action_hands.insert(action_card, hand_p2);
    }

    //Build players' defend hands taking all cards from each deck randomly until
    //they are empty.
    while (!defend_deck.is_empty())
    {
      //Draw and add to player 1's hand.
      defend_deck.remove(defend_card);
      defend_hands.insert(defend_card, hand_p1);

      //Draw and add to player 2's hand.
      defend_deck.remove(defend_card);
      defend_hands.insert(defend_card, hand_p2);
    }

    //Build players' spell hands taking all cards from each deck randomly until
    //they are empty.
    while (!spell_deck.is_empty())
    {
      //Draw and add to player 1's hand.
      spell_deck.remove(spell_card);
      spell_hands.insert(spell_card, hand_p1);

      //Draw and add to player 2's hand.
      spell_deck.remove(spell_card);
      spell_hands.insert(spell_card, hand_p2);
    }

    //The decks and hands are built, ready for gameplay.
    cout << "Everything is ready to go!\n" << endl;
    cout << "Player 1 will get to go first. Each player must choose one\n"
         << "action card and one defend card before moving on to choose\n"
         << "one spell card each. When a spell card is chosen, it will\n"
         << "affect a card how you choose and deal damage or add health\n"
         << "to a player's lifeline.\n\n"
         << "Have a mediocre time!" << endl << endl;

    do
    {
      cout << "Player 1's lifeline: " << lifelines[0]
           << "\nPlayer 2's lifeline: " << lifelines[1]
           << endl << endl;
      do
      {
        cout << "Player 1: What would you like to do?\n\n"
             << "1 - View action hand\n"
             << "2 - View action cards played\n"
             << "3 - View defend hand\n"
             << "4 - View defend cards played\n"
             << "5 - Attack!\n"
             << "6 - Double Attack!!\n"
             << "7 - Throw weapon...\n"
             << "8 - Block!\n"
             << "9 - Hide...\n"
             << "10 - PUSH BACK\n"
             << "\nEnter whole number here: ";

        cin >> option;
        cin.ignore(100, '\n');

        switch (option)
        {
          case 1:
            action_hands.display_all(hand_p1);   //Display action hand
            break;
          case 2:
            action_hands.display_all(played_p1); //Display played action cards
            break;
          case 3:
            defend_hands.display_all(hand_p1);   //Display defend hand
            break;
          case 4:
            defend_hands.display_all(played_p1); //Display played defend cards
            break;
          case 5:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p1);  //Remove from hand
              action_board[0].copy(action_card);          //Copy it to the board
              attack[0] = action_board[0].attack();       //Holds the attack power
              action_hands.insert(action_card, played_p1);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 6:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p1);  //Remove from hand
              action_board[0].copy(action_card);          //Copy it to the board
              attack[0] = action_board[0].double_attack();//Holds the attack power
              action_hands.insert(action_card, played_p1);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 7:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p1);  //Remove from hand
              action_board[0].copy(action_card);          //Copy it to the board
              attack[0] = action_board[0].throw_weapon(); //Holds the attack power
              action_hands.insert(action_card, played_p1);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 8:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p1);  //Remove from hand
              defend_board[0].copy(defend_card);          //Copy it to the board
              defense[0] = defend_board[0].block();       //Holds the strength
              defend_hands.insert(defend_card, played_p1);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played a defend card." << endl << endl;
            break;
          case 9:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p1);  //Remove from hand
              defend_board[0].copy(defend_card);          //Copy it to the board
              defense[0] = defend_board[0].hide();        //Holds the strength
              defend_hands.insert(defend_card, played_p1);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played a defend card." << endl << endl;
            break;
          case 10:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p1);  //Remove from hand
              defend_board[0].copy(defend_card);          //Copy it to the board
              defense[0] = defend_board[0].push_back();   //Holds the damage
              defend_hands.insert(defend_card, played_p1);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played a defend card." << endl << endl;
            break;
          default:
            cout << "That's not a valid choice. Try again..." << endl << endl;
            break;
        }

      } while (a_count == 0 || d_count == 0); 

      a_count = 0; //Reset action card played count for Player 2
      d_count = 0; //Reset defend card played count for Player 2

      //Now it is player two's turn to choose what to do.
      do
      {
        cout << "\nPlayer 2: What would you like to do?\n\n"
             << "1 - View action hand\n"
             << "2 - View action cards played\n"
             << "3 - View defend hand\n"
             << "4 - View defend cards played\n"
             << "5 - Attack!\n"
             << "6 - Double Attack!!\n"
             << "7 - Throw weapon...\n"
             << "8 - Block!\n"
             << "9 - Hide...\n"
             << "10 - PUSH BACK\n"
             << "\nEnter whole number here: ";
  
        cin >> option;
        cin.ignore(100, '\n');

        switch (option)
        {
          case 1:
            action_hands.display_all(hand_p2);   //Display action hand
            break;
          case 2:
            action_hands.display_all(played_p2); //Display played action cards
            break;
          case 3:
            defend_hands.display_all(hand_p2);   //Display defend hand
            break;
          case 4:
            defend_hands.display_all(played_p2); //Display played defend cards
            break;
          case 5:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p2);  //Remove from hand
              action_board[1].copy(action_card);          //Copy it to the board
              attack[1] = action_board[1].attack();       //Holds the attack power
              action_hands.insert(action_card, played_p2);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 6:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p2);  //Remove from hand
              action_board[1].copy(action_card);          //Copy it to the board
              attack[1] = action_board[1].double_attack();//Holds the attack power
              action_hands.insert(action_card, played_p2);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 7:
            if (!a_count)
            {
              action_hands.remove(action_card, hand_p2);  //Remove from hand
              action_board[1].copy(action_card);          //Copy it to the board
              attack[1] = action_board[1].throw_weapon(); //Holds the attack power
              action_hands.insert(action_card, played_p2);//Place in played hand
              action_hands.insert(action_card, d_pile);   //Place in discard pile
              ++a_count;
            }
            else
              cout << "You've already played an action card." << endl << endl;
            break;
          case 8:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p2);  //Remove from hand
              defend_board[1].copy(defend_card);          //Copy it to the board
              defense[1] = defend_board[1].block();       //Holds the strength
              defend_hands.insert(defend_card, played_p2);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played an defend card." << endl << endl;
            break;
          case 9:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p2);  //Remove from hand
              defend_board[1].copy(defend_card);          //Copy it to the board
              defense[1] = defend_board[1].hide();        //Holds the strength
              defend_hands.insert(defend_card, played_p2);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played an defend card." << endl << endl;
            break;
          case 10:
            if (!d_count)
            {
              defend_hands.remove(defend_card, hand_p2);  //Remove from hand
              defend_board[1].copy(defend_card);          //Copy it to the board
              defense[1] = defend_board[1].push_back();   //Holds the damage
              defend_hands.insert(defend_card, played_p2);//Place in played hand
              defend_hands.insert(defend_card, d_pile);   //Place in discard pile
              ++d_count;
            }
            else
              cout << "You've already played an defend card." << endl << endl;
            break;
          default:
            cout << "That's not a valid choice. Try again..." << endl << endl;
            break;
        }

      } while (a_count == 0 || d_count == 0);

      a_count = 0; //Reset action card played count for Player 2
      d_count = 0; //Reset defend card played count for Player 2

      //Now that attack or defend cards have been played, each player must choose
      //a spell card from their hand and how to use it.
      cout << "Now each player gets to choose a spell to use and how to use it!"
           << endl << endl;
      do
      {
        cout << "Player 1: How would you like to use your spell?\n\n"
             << "1 - View spell hand\n"
             << "2 - View spell cards played\n"
             << "3 - Enhance my defenses\n"
             << "4 - Diminish opponents attack\n"
             << "5 - Redirect opponents attack\n"
             << "\nEnter whole number here: ";

        cin >> option;
        cin.ignore(100, '\n');

        switch (option)
        {
          case 1:
            spell_hands.display_all(hand_p1);    //Display spell hand
            break;
          case 2:
            spell_hands.display_all(played_p1);  //Display played spell cards
            break;
          case 3:
            if (!s_count)
            {
              spell_hands.remove(spell_card, hand_p1);  //Remove from hand
              spell_board[0].copy(spell_card);          //Copy it to the board
              magic[0] = spell_board[0].enhance(defend_board[0]);//Enhance defense
  
              //Use you turn and play the cards.
              //Defense is negative it has become an attack. Otherwise, add it
              //to your lifeline.
              if (magic[0] < 0)
                lifelines[1] += magic[0];
              else
                lifelines[0] += magic[0];

              //Use your attack card.
              lifelines[1] += attack[0];

              spell_hands.insert(spell_card, played_p1);//Place in played hand
              spell_hands.insert(spell_card, d_pile);   //Place in discard pile
              ++s_count;
            }
            else
              cout << "You've already played a spell card." << endl << endl;
            break;
          case 4:
            if (!s_count)
            {
              spell_hands.remove(spell_card, hand_p1);  //Remove from hand
              spell_board[0].copy(spell_card);          //Copy it to the board
              magic[0] = spell_board[0].diminish(action_board[1]);//Diminish attack

              //Use your turn and play the cards.
              //Opponents attack is weaker (negative number).
              lifelines[0] += magic[0];

              //Use both of your attack and defense cards.
              lifelines[1] += attack[0];
              lifelines[0] += defense[0];

              spell_hands.insert(spell_card, played_p1);//Place in played hand
              spell_hands.insert(spell_card, d_pile);   //Place in discard pile
              ++s_count;
            }
            else
              cout << "You've already played a spell card." << endl << endl;
            break;
          case 5:
            if (!s_count)
            {
              spell_hands.remove(spell_card, hand_p1);  //Remove from hand
              spell_board[0].copy(spell_card);          //Copy it to the board
              magic[0] = spell_board[0].redirect(action_board[1]);//Redirect attack

              //Use your turn and play the cards.
              //You redirected their attack
              lifelines[1] += magic[0];

              //Use both of your attack and defense cards now.
              lifelines[1] += attack[0];
              lifelines[0] += defense[0];

              spell_hands.insert(spell_card, played_p1);//Place in played hand
              spell_hands.insert(spell_card, d_pile);   //Place in discard pile
              ++s_count;
            }
            else
              cout << "You've already played a spell card." << endl << endl;
            break;
          default:
            cout << "That's not a valid choice. Try again..." << endl << endl;
            break;
        }

      } while (s_count == 0);

      s_count = 0; //Reset for Player 2's turn

      //Check if anyone has lost before letting Player 2 have a chance.
      if (lifelines[0] > 0 && lifelines[1] > 0)
      {
        do
        {
          cout << "Player 2: How would you like to use your spell?\n\n"
               << "1 - View spell hand\n"
               << "2 - View spell cards played\n"
               << "3 - Enhance my defenses\n"
               << "4 - Diminish opponents attack\n"
               << "5 - Redirect opponents attack\n"
               << "\nEnter whole number here: ";

          cin >> option;
          cin.ignore(100, '\n');

          switch (option)
          {
            case 1:
              spell_hands.display_all(hand_p2);    //Display spell hand
              break;
            case 2:
              spell_hands.display_all(played_p2);  //Display played spell cards
              break;
            case 3:
              if (!s_count)
              {
                spell_hands.remove(spell_card, hand_p2);  //Remove from hand
                spell_board[0].copy(spell_card);          //Copy it to the board
                magic[1] = spell_board[1].enhance(defend_board[1]);//Enhance defense

                //Use you turn and play the cards.
                //Defense is negative it has become an attack. Otherwise, add it
                //to your lifeline.
                if (magic[1] < 0)
                  lifelines[0] += magic[1];
                else
                  lifelines[1] += magic[1];

                //Use your attack card.
                lifelines[0] += attack[1];

                spell_hands.insert(spell_card, played_p2);//Place in played hand
                spell_hands.insert(spell_card, d_pile);   //Place in discard pile
                ++s_count;
              }
              else
                cout << "You've already played a spell card." << endl << endl;
              break;
            case 4:
              if (!s_count)
              {
                spell_hands.remove(spell_card, hand_p2);  //Remove from hand
                spell_board[1].copy(spell_card);          //Copy it to the board
                magic[1] = spell_board[1].diminish(action_board[0]);//Diminish attack

                //Use your turn and play the cards.
                //Opponents attack is weaker (negative number).
                lifelines[1] += magic[1];

                //Use both of your attack and defense cards.
                lifelines[0] += attack[1];
                lifelines[1] += defense[1];

                spell_hands.insert(spell_card, played_p2);//Place in played hand
                spell_hands.insert(spell_card, d_pile);   //Place in discard pile
                ++s_count;
              }
              else
                cout << "You've already played a spell card." << endl << endl;
              break;
            case 5:
              if (!s_count)
              {
                spell_hands.remove(spell_card, hand_p2);  //Remove from hand
                spell_board[1].copy(spell_card);          //Copy it to the board
                magic[1] = spell_board[1].redirect(action_board[0]);//Redirect attack

                //Use your turn and play the cards.
                //You redirected their attack
                lifelines[0] += magic[1];

                //Use both of your attack and defense cards now.
                lifelines[0] += attack[1];
                lifelines[1] += defense[1];

                spell_hands.insert(spell_card, played_p2);//Place in played hand
                spell_hands.insert(spell_card, d_pile);   //Place in discard pile
                ++s_count;
              }
              else
                cout << "You've already played a spell card." << endl << endl;
              break;
            default:
              cout << "That's not a valid choice. Try again..." << endl << endl;
              break;
          }

        } while (s_count == 0);

      }

      s_count = 0; //Reset spell card played count for Player 1.

    } while (lifelines[0] > 0 && lifelines[1] > 0);

    //Check if anyone has lost after a round of play.
    if (lifelines[0] < 0 && lifelines[1] < 0)
       cout << "Looks like you both lose!!!" << endl << endl;
    else if (lifelines[0] < 0)
      cout << "Player 2 Wins!!!" << endl << endl;
    else if (lifelines[1] < 0)
      cout << "Player 1 Wins!!!" << endl << endl;


    do
    {
      cout << "Want to play again? (Y or N): ";
      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);

      if ('N' == response)
        cout << "Exiting game... Goodbye" << endl << endl;
      else if ('Y' != response)
        cout << "Try responding again..." << endl << endl;

    } while ('N' != response && 'Y' !=response);


  } while ('Y' == response);

  return 0;
}



