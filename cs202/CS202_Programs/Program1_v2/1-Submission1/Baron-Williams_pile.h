#include "Baron-Williams_node.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 21, 2022
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
// empty or full and display the number of cards as well as how many cards are
// left.
class pile
{
  public:
    pile();                     //Default constructor
    pile(int size);             //Constructor with integer argument
    bool is_full() const;       //Check if pile is full
    bool is_empty() const;      //Check if pile is empty
    void cards_left() const;    //Display number of cards left
    void display_count() const; //Display number of cards

  protected:
    int max_size;     //Max number of cards allowed in pile
    int num_of_cards; //Number of cards in pile
};



// - - - - - D E C K S - - - - -
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
    ~a_deck();                          //Destructor
    int insert(const action & from);    //Inserts the passed in action object
    bool retrieve(const action & from)  //Retrieves the passed in action object
                  const;                
    bool copy(action & copy_to);        //Copies to the passed in action object
    bool remove();                      //Removes one card from deck
    bool remove_all();                  //Removes all cards from deck
    void display() const;               //Displays one card from deck
    void display_all() const;           //Displays all cards from deck

  private:
    a_node * rear; //Rear pointer to the action node
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
    ~s_deck();                          //Destructor
    int insert(const spell & from);     //Inserts the passed in spell object
    bool retrieve(const spell & from)   //Retrieves the passed in spell object
                  const;                
    bool copy(spell & copy_to);         //Copies to the passed in spell object
    bool remove();                      //Removes one card from deck
    bool remove_all();                  //Removes all cards from deck
    void display() const;               //Displays one card from deck
    void display_all() const;           //Displays all cards from deck

  private:
    s_node * rear; //Rear pointer to the spell node
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
    ~d_deck();                          //Destructor
    int insert(const defend & from);    //Inserts the passed in defend object
    bool retrieve(const defend & from)  //Retrieves the passed in defend object
                  const;                
    bool copy(defend & copy_to);        //Copies to the passed in defend object
    bool remove();                      //Removes one card from deck
    bool remove_all();                  //Removes all cards from deck
    void display() const;               //Displays one card from deck
    void display_all() const;           //Displays all cards from deck

  private:
    d_node * rear; //Rear pointer to the defend node
};

// -----------------------------------------------------------------------------
//
// - - - - - H A N D S - - - - -
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
    a_hand(int hands = 5);                   //Default constructor
    a_hand(int size, int hands);             //Constructor with arguments
    a_hand(const a_hand & from);             //Copy constructor
    ~a_hand();                               //Destructor
    int insert(const action & from);         //Inserts an action object
    bool retrieve(const action & from,       //Retrieves card matching criteria
                  int player_num,
                  const std::string & 
                  hand_type) const;                     
    bool copy(action & copy_to);             //Copies to action object
    bool remove();                           //Removes one card from hand
    bool remove_discarded();                 //Removes discarded cards from hand
    bool remove_all();                       //Removes all cards from hand
    void display() const;                    //Displays one card from hand
    void display_all(int player_num,         //Displays all cards from a hand
                     const std::string & 
                     hand_type) const;       

  private:
    a_node ** action_hand; //Array of pointers to the action node
    int num_of_hands; //Number of hands allowed
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
    s_hand(int hands = 5);                   //Default constructor
    s_hand(int size, int hands);             //Constructor with arguments
    s_hand(const s_hand & from);             //Copy constructor
    ~s_hand();                               //Destructor
    int insert(const spell & from);          //Inserts an spell object
    bool retrieve(const spell & from,        //Retrieves card matching criteria
                  int player_num,
                  const std::string & 
                  hand_type) const;                     
    bool copy(spell & copy_to);              //Copies to spell object
    bool remove();                           //Removes one card from hand
    bool remove_discarded();                 //Removes discarded cards from hand
    bool remove_all();                       //Removes all cards from hand
    void display() const;                    //Displays one card from hand
    void display_all(int player_num,         //Displays all cards from a hand
                     const std::string & 
                     hand_type) const;       

  private:
    s_node ** spell_hand; //Array of pointers to the spell node
    int num_of_hands; //Number of hands allowed
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
    d_hand(int hands = 5);                   //Default constructor
    d_hand(int size, int hands);             //Constructor with arguments
    d_hand(const d_hand & from);             //Copy constructor
    ~d_hand();                               //Destructor
    int insert(const defend & from);         //Inserts an defend object
    bool retrieve(const defend & from,       //Retrieves card matching criteria
                  int player_num,
                  const std::string & 
                  hand_type) const;                     
    bool copy(defend & copy_to);             //Copies to defend object
    bool remove();                           //Removes one card from hand
    bool remove_discarded();                 //Removes discarded cards from hand
    bool remove_all();                       //Removes all cards from hand
    void display() const;                    //Displays one card from hand
    void display_all(int player_num,         //Displays all cards from a hand
                     const std::string & 
                     hand_type) const;       

  private:
    d_node ** defend_hand; //Rear pointer to the defend node
    int num_of_hands; //Number of hands allowed
};

// -----------------------------------------------------------------------------
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





