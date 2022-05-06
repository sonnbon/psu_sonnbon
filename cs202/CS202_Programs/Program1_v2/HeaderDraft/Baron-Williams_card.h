#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 19, 2022
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



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'card' class manages the default information for one card in a card game.
// The default information, or the data members contained, is a unique card 
// number, stored as an integer type, and an "environment" type (Forest, Water,
// Fire, Desert), stored as a pointer to a char type. This class is considered a
// base class in a single inheritance hierarchy with three other card type
// classes. It will be able to add or read, change, copy, find, display, and 
// remove card information. The two find member functions, find_type and
// find_card, allow the user to look for a card matching a type, passing in a
// pointer to a char type, and for a card with an exact match, passing in a card
// object. The add member function will allow a user to pass in an integer and
// pointer to a char type in order to add a card, whereas the read function will
// prompt the user to enter a card in. The change_card function passes in both
// data member types in order to change information, whereas the copy function
// takes a 'card' object passed in to copy information.
class card
{
  public:
    card();                                  //Default constructor
    card(int num, const char * type);        //Constructor with arguments
    card(const card & from);                 //Copy constructor
    ~card();                                 //Destructor
    int add(int num, const char * type);     //Add card, passing in info
    void change_card(int num, const
                     char * type);           //Change card, passing in info
    void copy(const card & from);            //Copy card, passing in card object
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
// this card will be able to add or read, change, copy, compare, display, and
// remove 'action' card information. Additionally, it will be able to display
// the attack power of the 'action' class' weapon and it will be able to 
// "attack" returning an integer of data member's damage points. The compare 
// member function allows the user to look for a card with an exact match, 
// passing in an 'action' object. The add member function will allow a user to 
// pass in an integer and pointer to a char type in order to add a card, whereas 
// the read function will prompt the user to enter a card in. The two change 
// functions, change_damage and change_weapon, allow the user to change the 
// damage points, passing an integer type, and to change the weapon type, 
// passing in a pointer to a char type. The compare and copy functions, pass in 
// an 'action' object to compare and copy information.
class action: public card
{
  public:
    action();                                 //Default constructor
    action(int card_num, const 
           char * card_type, int damage,
           const char * weapon);              //Constructor with arguments
    action(const action & from);              //Copy constructor
    ~action();                                //Destructor
    int add(int damage, const char * weapon); //Add action card information
    int change_damage(int damage);            //Change damage points
    bool change_weapon(const char * weapon);  //Change weapon type
    bool compare(const action & from) const;  //Find card by action card type
    void copy(const action & from);           //Copy card, passing in object
    int attack() const;                       //Return attack power
    void read();                              //Read in action card information
    void attack_power() const;                //Display damage point power
    void display() const;                     //Display all information
    bool remove();                            //Remove action card

  protected:
    int damage_points; //Damage points dealt by weapon (Always negative)
    char * a_weapon;   //Type of action card weapon
};



// The 'spell' class manages a card type derived from the 'card' class in a
// single inheritance hierarchy. This card specifically manages a spell card,
// or a card that affects an 'action' or 'defend' cards power. The data members
// contained include an enhancement factor (changes 'action' or 'defend' cards
// power by a factor), stored as a float, and a magic type, stored as a string
// type. Similar to its base class, but with its additional 'spell' information,
// this card will be able to add or read, change, copy, compare, display, and
// remove 'spell' card information. Additionally, it will be able to display
// the spell type of the 'spell' class' magic and it will be able to 
// "cast a spell" returning a float of data member's enhancement factor. The 
// compare member function allows the user to look for a card with an exact 
// match, passing in a 'spell' object. The add member function will allow a user 
// to pass in a float and a string type in order to add a card, whereas the read
// function will prompt the user to enter a card in. The two change functions, 
// change_factor and change_spell, allow the user to change the enhancement 
// factor, passing a float type, and to change the spell type, passing in a
// string type. The compare and copy functions, pass in a 'spell' object to 
// compare and copy information.
class spell: public card
{
  public:
    spell();                                //Default constructor
    spell(int card_num, const 
           char * card_type, float factor,
           const std::string & magic_type); //Constructor with arguments
    float add(float factor, const
              std::string & magic_type);    //Add spell card information
    float change_factor(float factor);      //Change enhancement factor
    bool change_spell(const std::string & 
                      magic_type);          //Change magic type
    bool compare(const spell & from) const; //Find card by spell card type
    void copy(const spell & from);          //Copy card, passing in object
    float cast_spell() const;               //Return spell power
    void read();                            //Read in spell card information
    void display_spell() const;             //Display spell enhancement factor
    void display() const;                   //Display all information
    bool remove();                          //Remove spell card

  protected:
    float enhancement_factor; //Increase or decrease action or defend by number
    std::string magic;        //Type of action card weapon
};



// The 'defend' class manages a card type derived from the 'card' class in a
// single inheritance hierarchy. This card specifically manages a defend card,
// or a card that adds life to a player in a card game. The data members
// contained include strength points (always a positive number to add life),
// stored as an integer, and a shield type, stored as a string type. Similar to 
// its base class, but with its additional 'defend' information, this card will 
// be able to add or read, change, copy, compare, display, and remove 'defend' 
// card information. Additionally, it will be able to display the shield type of 
// the 'defend' class' shield and it will be able to "block" returning an integer 
// of the data member's strength points. The compare member function allows the 
// user to look for a card with an exact match, passing in a 'defend' object. 
// The add member function will allow a user to pass in an integer and string 
// type in order to add a card, whereas the read function will prompt the user 
// to enter a card in. The two change functions, change_strength and 
// change_shield, allow the user to change the strength points, passing an 
// integer type, and to change the shield type, passing in a string type.
class defend: public card
{
  public:
    defend();                                //Default constructor
    defend(int card_num, const 
           char * card_type, int strength,
           const std::string & shield);      //Constructor with arguments
    int add(int strength, const
            std::string & shield);           //Add defend card information
    int change_strength(int strength);       //Change strength points number
    bool change_shield(const std::string & 
                      shield);               //Change shield type
    bool compare(const defend & from) const; //Find card by defend card type
    void copy(const defend & from);          //Copy card, passing in object
    int block() const;                       //Return strength points power
    void read();                             //Read in defend card information
    void shield_type() const;                //Display shield type
    void display() const;                    //Display all information
    bool remove();                           //Remove defend card

  protected:
    int strength_points;  //Strength points added to lifeline (always positive)
    std::string a_shield; //Type of action card weapon
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
