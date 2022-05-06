#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 21, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_card.h
// *****************************************************************************
// This file contains the classes 'card', 'action', 'spell', and 'defend', all
// with the job of managing a card for a card game. The 'card' class contains 
// and manages default card infomation that the latter three classes all have in
// common. The latter three classes contain and manage information unique to
// their respective classes. The purpose of this configuration is to manage
// three different card types using a single inheritance hierarchy. The 'card'
// class is the base class of the four classes. The 'action', 'spell', and 
// 'defend' classes all derive from the 'card' class, inheritting its
// information. The 'action', 'spell', and 'defend' class specifically manage a
// cards attack power (taking life from a player's lifeline), magical
// enhancement (manipulating and attack or defend power by a factor), and defend
// strength (adding life to a player's lifeline), respectively. The 'card'
// manages a card's unique number as well as its "environment" type, which will
// include Forest, Fire, Water, and Desert. Dynamic memory will only be 
// allocated for char types in the 'card' and 'action' class.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ C O N S T A N T S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
const int SIZE = 10; //To be size of temporary arrays
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// ~~~~~~~~~~~~~~~~~~~~~~~ T E S T _ P R O T O T Y P E ~~~~~~~~~~~~~~~~~~~~~~~~~
//
int test_program_objects(); //To keep main clean and for testing purposes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'card' class manages the default information for one card in a card game.
// The default information, or the data members contained, is a unique card 
// number, stored as an integer type, and an "environment" type (Forest, Water,
// Fire, Desert), stored as a pointer to a char type. This class is considered a
// base class in a single inheritance hierarchy with three other card type
// classes. It will be able to add, change, copy, find, display, and remove card 
// information. The two find member functions, find_type and find_card, allow 
// the user to look for a card matching a type, passing in a pointer to a char 
// type, and for a card with an exact match, passing in a card object. The 
// change_card function passes in both data member types in order to change 
// information, whereas the copy function takes a 'card' object passed in to 
// copy information.
class card
{
  public:
    card();                                  //Default constructor
    card(int num, const char * type);        //Constructor with arguments
    card(const card & from);                 //Copy constructor
    ~card();                                 //Destructor
    int change(int num, const char * type);  //Change card, passing in info
    int copy(const card & from);             //Copy card, passing in card object
    bool find_type(const char * type) const; //Find card by type
    bool find_card(const card & from) const; //Find unique card by object
    void read();                             //Read in card information
    void display() const;                    //Display card information
    bool remove();                           //Remove card

  protected:
    int card_num;  //Number assigned to card
    char * a_type; //Card type (e.g. Forest, Water, Fire, Desert)
};



// The 'action' class manages a card type derived from the 'card' class in a
// single inheritance hierarchy. This card specifically manages an action card,
// or a card that deals damage to a player in a card game. The data members
// contained include damage points (always a negative number to subtract life),
// stored as an integer, and a weapon type, stored as a pointer to a char type.
// Similar to its base class, but with its additional 'action' information, 
// this card will be able to add or read, copy, compare, display, and
// remove 'action' card information. Additionally, it will be able to "attack"
// in three different styles returning an integer of data member's affected 
// damage points. The compare member function allows the user to look for a card 
// with an exact match, passing in an 'action' object. The add member function 
// will allow a user to pass in integers and pointers to char types in order 
// to add a card, whereas the read function will prompt the user to enter a card 
// in. The copy function passes in an 'action' object to copy information.
class action: public card
{
  public:
    action();                                 //Default constructor
    action(int card_num, const 
           char * card_type, int damage,
           const char * weapon);              //Constructor with arguments
    action(const action & from);              //Copy constructor
    ~action();                                //Destructor
    int add(int num, const char * type,       //Add action card information
            int damage, const char * weapon);
    bool compare(const action & from) const;  //Find card by action card type
    int copy(const action & from);            //Copy card, passing in object
    int attack() const;                       //Returns the damage points
    int double_attack() const;                //Returns damage points doubled
    int throw_weapon() const;                 //Throws weapon for half damage
    int power() const;                        //Returns damage points
    void read();                              //Read in action card information
    void display() const;                     //Display all information
    bool remove();                            //Remove action card

  protected:
    int damage_points; //Damage points dealt by weapon (Always negative)
    char * a_weapon;   //Type of action card weapon
};



// The 'defend' class manages a card type derived from the 'card' class in a
// single inheritance hierarchy. This card specifically manages a defend card,
// or a card that adds life to a player in a card game. The data members
// contained include strength points (always a positive number to add life),
// stored as an integer, and a shield type, stored as a string type. Similar to 
// its base class, but with its additional 'defend' information, this card will 
// be able to add or read, copy, compare, display, and remove 'defend' 
// card information. Additionally, it will be able to "block", "hide", and 
// "push back" returning an integer of the affected data member's strength 
// points. The compare member function allows the user to look for a card with 
// an exact match, passing in a 'defend' object. The add member function will 
// allow a user to pass in an integer and string type in order to add a card, 
// whereas the read function will prompt the user to enter a card in. The copy 
// function passes in a 'defend' object to copy information.
class defend: public card
{
  public:
    defend();                                //Default constructor
    defend(int num, const char * type,       //Constructor with arguments
           int strength, const 
           std::string & shield);      
    int add(int num, const char * type,      //Add defend card information
            int strength, const
            std::string & shield);           
    bool compare(const defend & from) const; //Find card by defend card type
    int copy(const defend & from);           //Copy card, passing in object
    int block() const;                       //Blocks with normal strength
    int hide() const;                        //Hides with double strength
    int push_back() const;                   //Pushes back dealing small damage
    int power() const;                       //Returns strength points
    void read();                             //Read in defend card information
    void display() const;                    //Display all information
    bool remove();                           //Remove defend card

  protected:
    int strength_points;  //Strength points added to lifeline (always positive)
    std::string a_shield; //Type of defend card shield
};



// The 'spell' class manages a card type derived from the 'card' class in a
// single inheritance hierarchy. This card specifically manages a spell card,
// or a card that affects an 'action' or 'defend' cards power. The data members
// contained include an enhancement factor (changes 'action' or 'defend' cards
// power by a factor), stored as a float, and a magic type, stored as a string
// type. Similar to its base class, but with its additional 'spell' information,
// this card will be able to add or read, copy, compare, display, and
// remove 'spell' card information. Additionally, it will be able to 
// "enhance", "diminish", and "redirect" 'action' and 'defend' objects, 
// returning a float of affected data member's enhancement factor. The 
// compare member function allows the user to look for a card with an exact 
// match, passing in a 'spell' object. The add member function will allow a user 
// to pass in a float and a string type in order to add a card, whereas the read
// function will prompt the user to enter a card in. The copy function passes 
// in a 'spell' object to copy information.
class spell: public card
{
  public:
    spell();                                //Default constructor
    spell(int num, const char * type,       //Constructure with arguments
          float factor, const 
          std::string & magic_type);
    int add(int num, const char * type,     //Add spell card information
              float factor, const
              std::string & magic_type);
    bool compare(const spell & from) const; //Find card by spell card type
    int copy(const spell & from);           //Copy card, passing in object
    float enhance(const defend & from)      //Enhances defend object's strength
                  const;
    float diminish(const action & from)     //Diminishes action object's damage
                   const;
    float redirect(const action & from)     //Redirects action object's attack
                   const;
    void read();                            //Read in spell card information
    void display() const;                   //Display all information
    bool remove();                          //Remove spell card

  protected:
    float enhancement_factor; //Increase or decrease action or defend by factor
    std::string magic;        //Type of spell call (Ex: Wingardium Leviosa!")
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
