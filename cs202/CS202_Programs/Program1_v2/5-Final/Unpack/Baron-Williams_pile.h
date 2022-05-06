#include "Baron-Williams_node.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 31, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_pile.h
// *****************************************************************************
// This file contains classes 'pile', 'a_deck', 's_deck', 'd_deck', 'a_hand',
// 's_hand', and 'd_hand', all with the job of managing different types of 
// collections of the node classes that are derived from each card type
// ('action', 'spell', and 'defend', respectively) in order to create decks and
// hands of cards to play a card game. In this file, the 'pile' class acts as a
// base class to the other six classes, focusing on the size and how full a pile
// of cards is (two integer data members). The 'a_deck', 's_deck', and 'd_deck',
// which are derived from 'pile', inherit all of the base class' information and
// additionally manage Circular Linked Lists of each respective card type
// ('action', 'spell', and 'defend') through a containing relationship with the 
// card type class' derived nodes ('a_node', 's_node', and 'd_node', 
// respectively). The purpose of this data structure is to create three separate 
// card decks, each of their own card type. The 'a_hand', 's_hand', and 'd_hand', 
// which are also derived from 'pile', inherit all of the base class' 
// information and additionally manage an Array of Linear Linked Lists of each 
// respective card type through a containing relationship with the card type 
// class' derived nodes. The purpose of this data structure is to create three 
// separate lists that contain both players hands of cards, both players used 
// cards, and all the discarded cards in general. This way what cards a player 
// has and has played can be tracked, and when the deck is empty, the discarded 
// cards can be used to refill it.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'pile' class manages the basics of a pile of cards. These basics include
// the two integer type data members, managing the set maximum number of cards
// allowed in a pile of cards and the number of cards that are currently present
// in the pile. With this, the class will be able to check whether the pile is
// empty or full and display how many cards are left.
class pile
{
  public:
    pile();                     //Default constructor
    pile(int size);             //Constructor with integer argument
    bool is_full() const;       //Check if pile is full
    bool is_empty() const;      //Check if pile is empty
    void cards_left() const;    //Display number of cards left

  protected:
    int max_size;     //Max number of cards allowed in pile
    int num_of_cards; //Number of cards in pile
};



// - - - - - - - - - - - - - - - - D E C K S - - - - - - - - - - - - - - - - - -
//
// The 'a_deck' class, derived from the 'pile' class,  manages a Circular 
// Linked List data structure with a containing relationship of the 'a_node'
// class. The purpose of this data structure is to hold a list of action cards
// in an action deck. Being a containing relationship, this class' data member
// is a pointer to the 'a_node' class type. This data structure allows the user
// to insert, retrieve, copy to, remove, remove all, display, and display all
// action cards in the list.
class a_deck: public pile
{
  public:
    a_deck();                           //Default constructor
    a_deck(int size);                   //Constructor with integer argument
    a_deck(const a_deck & from);        //Copy constructor
    int copy_all(const a_deck & from);  //Copies from a deck object
    ~a_deck();                          //Destructor
    void remove_all();                  //Removes all cards from deck
    int insert(const action & from);    //Inserts the passed in action object
    bool retrieve(const action & from)  //Retrieves the passed in action object
                  const;                
    bool remove(action & copy);         //Removes and copies one card from deck
    void display() const;               //Displays one card from deck
    int display_all() const;            //Displays all cards from deck
    int build(const std::string &       //Build an action deck
              filename);

  private:
    //Data members
    a_node * rear; //Rear pointer to the action node

    //Recursive functions
    int copy_all(a_node * hold,
                 a_node * & rear,       //Recursively copies all nodes from deck
                 a_node * src_rear, 
                 a_node * src_front);
    void remove_all(a_node * & rear);   //Recursively remove all nodes from deck
    bool retrieve(a_node * rear,        //Recursively look for a card match
                  const action & from) 
                  const;
    bool remove_rand(a_node * & rear,   //Recursively copy and remove card
                     action & copy, 
                     int rand_num, 
                     int & moves);
    int display_all(a_node * rear)      //Recursively displays all cards in deck
                    const;
};



// The 'd_deck' class, derived from the 'pile' class,  manages a Circular 
// Linked List data structure with a containing relationship of the 'd_node'
// class. The purpose of this data structure is to hold a list of defend cards
// in a defend deck. Being a containing relationship, this class' data member
// is a pointer to the 'd_node' class type. This data structure allows the user
// to insert, retrieve, copy to, remove, remove all, display, and display all
// defend cards in the list.
class d_deck: public pile
{
  public:
    d_deck();                           //Default constructor
    d_deck(int size);                   //Constructor with integer argument
    d_deck(const d_deck & from);        //Copy constructor
    int copy_all(const d_deck & from);  //Copies from a deck object
    ~d_deck();                          //Destructor
    void remove_all();                  //Removes all cards from deck
    int insert(const defend & from);    //Inserts the passed in defend object
    bool retrieve(const defend & from)  //Retrieves the passed in defend object
                  const;                
    bool remove(defend & copy);         //Removes and copies one card from deck
    void display() const;               //Displays one card from deck
    int display_all() const;            //Displays all cards from deck
    int build(const std::string &       //Build an defend deck
              filename);

  private:
    //Data members
    d_node * rear; //Rear pointer to the defend node

    //Recursive functions
    int copy_all(d_node * hold,
                 d_node * & rear,       //Recursively copies all nodes from deck
                 d_node * src_rear, 
                 d_node * src_front);
    void remove_all(d_node * & rear);   //Recursively remove all nodes from deck
    bool retrieve(d_node * rear,        //Recursively look for a card match
                  const defend & from) 
                  const;
    bool remove_rand(d_node * & rear,   //Recursively copy and remove card
                     defend & copy, 
                     int rand_num, 
                     int & moves);
    int display_all(d_node * rear)      //Recursively displays all cards in deck
                    const;
};



// The 's_deck' class, derived from the 'pile' class,  manages a Circular 
// Linked List data structure with a containing relationship of the 's_node'
// class. The purpose of this data structure is to hold a list of spell cards
// in a spell deck. Being a containing relationship, this class' data member
// is a pointer to the 's_node' class type. This data structure allows the user
// to insert, retrieve, copy to, remove, remove all, display, and display all
// spell cards in the list.
class s_deck: public pile
{
  public:
    s_deck();                           //Default constructor
    s_deck(int size);                   //Constructor with integer argument
    s_deck(const s_deck & from);        //Copy constructor
    int copy_all(const s_deck & from);  //Copies from a deck object
    ~s_deck();                          //Destructor
    void remove_all();                  //Removes all cards from deck
    int insert(const spell & from);     //Inserts the passed in spell object
    bool retrieve(const spell & from)   //Retrieves the passed in spell object
                  const;                
    bool remove(spell & copy);          //Removes and copies one card from deck
    void display() const;               //Displays one card from deck
    int display_all() const;            //Displays all cards from deck
    int build(const std::string &       //Build an spell deck
              filename);

  private:
    //Data members
    s_node * rear; //Rear pointer to the spell node

    //Recursive functions
    int copy_all(s_node * hold,
                 s_node * & rear,       //Recursively copies all nodes from deck
                 s_node * src_rear, 
                 s_node * src_front);
    void remove_all(s_node * & rear);   //Recursively remove all nodes from deck
    bool retrieve(s_node * rear,        //Recursively look for a card match
                  const spell & from) 
                  const;
    bool remove_rand(s_node * & rear,   //Recursively copy and remove card
                     spell & copy, 
                     int rand_num, 
                     int & moves);
    int display_all(s_node * rear)      //Recursively displays all cards in deck
                    const;
};



// - - - - - - - - - - - - - - - - H A N D S - - - - - - - - - - - - - - - - - -
//
// The 'a_hand' class, derived from the 'pile' class, manages an Array of Linear
// Linked Lists data structure with a containing relationship of the 'a_node'
// class. The purpose of this data structure is to hold a list of action cards,
// indexed by the first player's hand of cards, their cards played, the second
// player's hand of cards, their cards played, and all the discarded cards in
// total. Being a containing relationship, this class has a data member that is 
// a pointer, pointing to the 'a_node' class type. There is also a data member
// integer for storing the size of the Array, which will be set to 5 as a
// default. This data structure allows the user to insert, retrieve (from a 
// specific hand), copy to, remove, remove all, display, and display all (from 
// a specific hand) action cards in the list. Additionally, a user can remove 
// just the discarded cards from the list.
class a_hand: public pile
{
  public:
    a_hand(int size = 5);              //Default constructor
    void create_arr();                 //Creates an empty ARR
    a_hand(const a_hand & from);       //Copy constructor
    int copy_all(const a_hand & from); //Copies from a hand object
    ~a_hand();                         //Destructor
    void remove_all();                 //Removes all cards from hand
    bool remove_discarded(a_deck &     //Remove discarded cards and adds to deck
                          add_to);
    int insert(const action & from,    //Inserts an action object
               int hand_num);
    bool retrieve(const action & from, //Retrieves card matching criteria
                  int hand_num) const;
    bool remove(action & copy,         //Removes and copies one card from hand
                int hand_num);
    void display(int hand_num) const;  //Displays one card from hand
    int display_all(int hand_num)      //Displays all cards from a hand
                    const;       

  private:
    //Data members
    a_node ** head;   //Array of pointers to the action node
    int num_of_hands; //Size of array

    //Recursive functions
    void create_arr(int & index);      //Recursively creates an empty ARR
    int copy_all(a_node ** src,        //Recursively copies an array
                 int & index);
    int copy_list(a_node * & dest,     //Recursively copies a LLL
                  a_node * src);
    void remove_all(int & index);      //Recursively removes indexed information
    bool remove_discarded(a_node * &   //Recursively removes and copies to deck
                          head, a_deck 
                          & add_to);
    void remove_list(a_node * & head); //Recursively removes LLL
    bool retrieve_list(a_node * head,  //Recursively retrieve in indexed list
                       const action & 
                       from) const;
    int display_list(a_node * head)    //Recursively display indexed list
                     const;
};



// The 'd_hand' class, derived from the 'pile' class, manages an Array of Linear
// Linked Lists data structure with a containing relationship of the 'd_node'
// class. The purpose of this data structure is to hold a list of defend cards,
// indexed by the first player's hand of cards, their cards played, the second
// player's hand of cards, their cards played, and all the discarded cards in
// total. Being a containing relationship, this class has a data member that is 
// a pointer, pointing to the 'd_node' class type. There is also a data member
// integer for storing the size of the Array, which will be set to 5 as a
// default. This data structure allows the user to insert, retrieve (from a 
// specific hand), copy to, remove, remove all, display, and display all (from 
// a specific hand) defend cards in the list. Additionally, a user can remove 
// just the discarded cards from the list.
class d_hand: public pile
{
  public:
    d_hand(int size = 5);              //Default constructor
    void create_arr();                 //Creates an empty ARR
    d_hand(const d_hand & from);       //Copy constructor
    int copy_all(const d_hand & from); //Copies from a hand object
    ~d_hand();                         //Destructor
    void remove_all();                 //Removes all cards from hand
    bool remove_discarded(d_deck &     //Remove discarded cards and adds to deck
                          add_to);
    int insert(const defend & from,    //Inserts a defend object
               int hand_num);
    bool retrieve(const defend & from, //Retrieves card matching criteria
                  int hand_num) const;
    bool remove(defend & copy,         //Removes and copies one card from hand
                int hand_num);
    void display(int hand_num) const;  //Displays one card from hand
    int display_all(int hand_num)      //Displays all cards from a hand
                    const;       

  private:
    //Data members
    d_node ** head;   //Array of pointers to the defend node
    int num_of_hands; //Size of array

    //Recursive functions
    void create_arr(int & index);      //Recursively creates an empty ARR
    int copy_all(d_node ** src,        //Recursively copies an array
                 int & index);
    int copy_list(d_node * & dest,     //Recursively copies a LLL
                  d_node * src);
    void remove_all(int & index);      //Recursively removes indexed information
    bool remove_discarded(d_node * &   //Recursively removes and copies to deck
                          head, d_deck 
                          & add_to);
    void remove_list(d_node * & head); //Recursively removes LLL
    bool retrieve_list(d_node * head,  //Recursively retrieve in indexed list
                       const defend & 
                       from) const;
    int display_list(d_node * head)    //Recursively display indexed list
                     const;
};



// The 's_hand' class, derived from the 'pile' class, manages an Array of Linear
// Linked Lists data structure with a containing relationship of the 's_node'
// class. The purpose of this data structure is to hold a list of spell cards,
// indexed by the first player's hand of cards, their cards played, the second
// player's hand of cards, their cards played, and all the discarded cards in
// total. Being a containing relationship, this class has a data member that is 
// a pointer, pointing to the 's_node' class type. There is also a data member
// integer for storing the size of the Array, which will be set to 5 as a
// default. This data structure allows the user to insert, retrieve (from a 
// specific hand), copy to, remove, remove all, display, and display all (from 
// a specific hand) spell cards in the list. Additionally, a user can remove 
// just the discarded cards from the list.
class s_hand: public pile
{
  public:
    s_hand(int size = 5);              //Default constructor
    void create_arr();                 //Creates an empty ARR
    s_hand(const s_hand & from);       //Copy constructor
    int copy_all(const s_hand & from); //Copies from a hand object
    ~s_hand();                         //Destructor
    void remove_all();                 //Removes all cards from hand
    bool remove_discarded(s_deck &     //Remove discarded cards and adds to deck
                          add_to);
    int insert(const spell & from,     //Inserts a spell object
               int hand_num);
    bool retrieve(const spell & from,  //Retrieves card matching criteria
                  int hand_num) const;
    bool remove(spell & copy,          //Removes and copies one card from hand
                int hand_num);
    void display(int hand_num) const;  //Displays one card from hand
    int display_all(int hand_num)      //Displays all cards from a hand
                    const;       

  private:
    //Data members
    s_node ** head;   //Array of pointers to the defend node
    int num_of_hands; //Size of array

    //Recursive functions
    void create_arr(int & index);      //Recursively creates an empty ARR
    int copy_all(s_node ** src,        //Recursively copies an array
                 int & index);
    int copy_list(s_node * & dest,     //Recursively copies a LLL
                  s_node * src);
    void remove_all(int & index);      //Recursively removes indexed information
    bool remove_discarded(s_node * &   //Recursively removes and copies to deck
                          head, s_deck 
                          & add_to);
    void remove_list(s_node * & head); //Recursively removes LLL
    bool retrieve_list(s_node * head,  //Recursively retrieve in indexed list
                       const spell & 
                       from) const;
    int display_list(s_node * head)    //Recursively display indexed list
                     const;
};

// -----------------------------------------------------------------------------
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





