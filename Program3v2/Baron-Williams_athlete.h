#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <array>
#include <forward_list>
#include "Baron-Williams_error.h"

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_athlete.h
// *****************************************************************************
// This file contains the classes 'athlete', 'figure_skate', 'ski_jump', and 
// 'bobsled', all with the job of managing a type of competition that an athlete
// competes in during the Winter Olympics. The 'athlete' class contains and 
// manages information that the latter three classes all have in common, the 
// athlete's name, the country they represent, their years of competing 
// experience, and the total points scored in the competition. The latter three 
// classes contain and manage information unique to their respective classes. 
// The purpose of this configuration is to manage three different competition 
// types using a single inheritance hierarchy. The 'figure_skate', 'ski_jump', 
// and 'bobsled' classes all derive from the 'athlete' class, inheritting its 
// information. The 'figure_skate' class manages the number of triple axels 
// landed and the song choice for the figure skating competition. The 'ski_jump' 
// class manages the distance traveled, the wind's head or tail wind cost, and 
// the speed traveled at the jump (paired with the wind, a distance is the 
// result). The 'bobsled' class manages the time it took to finish the course, 
// and the position in the bobsled car (front, middle, rear). Dynamic memory 
// will only be allocated for a pointer to a char (athlete's name) in the 
// 'athlete' class.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ C O N S T A N T S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
const int SIZE = 31;    //Size of temporary arrays
const int ARR_SIZE = 3; //Size of STL array container
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// ~~~~~~~~~~~~~~~~~~~~~~~~~~ P R O T O T Y P E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
bool again();                    //Check if user wants to do something again
void STL_forwardlist_function(); //Implements Forward List STL of bobsledders
void STL_array_function();       //Implements Array STL list of ski jumpers
void BST_function();             //Runs functioning list of figure skaters
void test_athlete();             //Tests the athlete class
void test_figure_skater();       //Tests the figure_skate class
void test_ski_jumper();          //Tests the ski_jump class
void test_bobsledder();          //Tests the bobsled class
void test_BST();                 //Tests the BST class
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'athlete' class manages the athlete's name, a pointer to a char, the 
// country they represent, a string object, the number of years they have been
// competing, an integer, and the total points scored, an integer. This class is
// a base class in a single inheritance hierarchy. Dynamic memory is allocated 
// in this class so a copy constructor and destructor are included. Class 
// methods included allow the user to read in, display, compare, and copy data
// members. The compare functions look for an object match or a name match.
// Operators overloaded include +, +=, -, and -= for the purpose of adding and
// subtracting points from the total points scored, <, <=, >, and >= for the
// purpose of comparing two different names, and == and != for the purpose of 
// findng exact matches or completely different objects. Operators overloaded 
// also include the use of assignment for assigning an object, and istream and 
// ostream for input and output.
class athlete
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    athlete();                               //Default constructor
    athlete(const athlete & from);           //Copy Constructor
    ~athlete();                              //Destructor
    void read(std::istream & in);            //Read in data members
    void display(std::ostream & out) const;  //Display data members
    int compare(const athlete & from) const; //Compare two objects
    int compare(const char * name) const;    //Compares athlete names
    void copy(const athlete & from);         //Copy an object

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Assignment of an object
    athlete & operator=(const athlete & player);

    //Input and output an object
    friend std::istream & operator>>(std::istream & in, athlete & player);
    friend std::ostream & operator<<(std::ostream & out, const athlete & player);

    //Add points to the total score
    friend athlete operator+(const athlete & player, int points);
    friend athlete operator+(int points, const athlete & player);
    athlete & operator+=(int points);

    //Subtract points from the total score
    friend athlete operator-(const athlete & player, int points);
    friend athlete operator-(int points, const athlete & player);
    athlete & operator-=(int points);

    //Compare if one name is less than another
    friend bool operator<(const athlete & player1, const athlete & player2);
    friend bool operator<(const athlete & player, const char * name);
    friend bool operator<(const char * name, const athlete & player);

    //Compare if one name is less than or equal to another
    friend bool operator<=(const athlete & player1, const athlete & player2);
    friend bool operator<=(const athlete & player, const char * name);
    friend bool operator<=(const char * name, const athlete & player);

    //Compare if one name is greater than another
    friend bool operator>(const athlete & player1, const athlete & player2);
    friend bool operator>(const athlete & player, const char * name);
    friend bool operator>(const char * name, const athlete & player);

    //Compare if one name is greater than or equal to another
    friend bool operator>=(const athlete & player1, const athlete & player2);
    friend bool operator>=(const athlete & player, const char * name);
    friend bool operator>=(const char * name, const athlete & player);

    //Compare if one name is equal to another
    friend bool operator==(const athlete & player1, const athlete & player2);
    friend bool operator==(const athlete & player, const char * name);
    friend bool operator==(const char * name, const athlete & player);

    //Compare if one name is different than another
    friend bool operator!=(const athlete & player1, const athlete & player2);
    friend bool operator!=(const athlete & player, const char * name);
    friend bool operator!=(const char * name, const athlete & player);

  protected:
    char * name;         //Athlete's name
    std::string country; //The country the athlete represents
    int experience;      //Number of years the athlete has competed
    int score;           //Total points scored
};



// The 'figure_skate' class manages the number of triple axels landed, an 
// integer, and the song choice for the figure skating competition, a string
// object. This class, deriving from the 'athlete' class, inherits the data
// members from its parent class as well. Class methods included allow the user
// to read in, display, compare, and copy objects of the same type. Operators 
// overloaded include +, +=, -, and -= for the purpose of adding and subtracting 
// the number of axels landed, <, <=, >, and >= for the purpose of comparing two 
// different names, and == and != for the purpose of findng exact matches or 
// completely different objects. Operators overloaded also include the use of 
// assignment for assigning only a new song, and istream and ostream for input 
// and output.
class figure_skate: public athlete
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    figure_skate();                         //Default constructor
    void read(std::istream & in);           //Read in data members
    void display(std::ostream & out) const; //Display data members
    void copy(const figure_skate & from);   //Copy an object
    bool is_empty() const;                  //Checks if object is empty

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Input and output an object
    friend std::istream & operator>>(std::istream & in, figure_skate & game);
    friend std::ostream & operator<<(std::ostream & out, const figure_skate & game);

    //Add to the number of triple axels
    friend figure_skate operator+(const figure_skate & game, int axels);
    friend figure_skate operator+(int axels, const figure_skate & game);
    figure_skate & operator+=(int axels);

    //Subtract from the number of axels
    friend figure_skate operator-(const figure_skate & game, int axels);
    friend figure_skate operator-(int axels, const figure_skate & game);
    figure_skate & operator-=(int axels);

    //Compare if one name is less than another
    friend bool operator<(const figure_skate & game1, const figure_skate & game2);
    friend bool operator<(const figure_skate & game, const char * name);
    friend bool operator<(const char * name, const figure_skate & game);

    //Compare if one name is less than or equal to another
    friend bool operator<=(const figure_skate & game1, const figure_skate & game2);
    friend bool operator<=(const figure_skate & game, const char * name);
    friend bool operator<=(const char * name, const figure_skate & game);

    //Compare if one name is greater than another
    friend bool operator>(const figure_skate & game1, const figure_skate & game2);
    friend bool operator>(const figure_skate & game, const char * name);
    friend bool operator>(const char * name, const figure_skate & game);

    //Compare if one name is greater than or equal to another
    friend bool operator>=(const figure_skate & game1, const figure_skate & game2);
    friend bool operator>=(const figure_skate & game, const char * name);
    friend bool operator>=(const char * name, const figure_skate & game);

    //Compare if one name is equal to another
    friend bool operator==(const figure_skate & game1, const figure_skate & game2);
    friend bool operator==(const figure_skate & game, const char * name);
    friend bool operator==(const char * name, const figure_skate & game);

    //Compare if one name is different than another
    friend bool operator!=(const figure_skate & game1, const figure_skate & game2);
    friend bool operator!=(const figure_skate & game, const char * name);
    friend bool operator!=(const char * name, const figure_skate & game);


  protected:
    int triple_axels; //Number of triple axels landed
    std::string song; //Song choice for the figure skating competition
};



// The 'ski_jump' class manages the distance traveled, an integer, the negative 
// or positive cost of the tail or head wind, an integer, and the speed 
// traveled at the moment of the jump, an integer. This class, deriving from the 
// 'athlete' class, inherits the data members from its parent class as well. 
// Class methods included allow the user to read in, display, compare, and copy
// objects of the same type. This class also has a method that allows for
// calculating the distance traveled based on wind and jump speed. Operators 
// overloaded include +, +=, -, and -= for the purpose of adding and subtracting 
// speed traveled, <, <=, >, and >= for the purpose of comparing two different 
// names, and == and != for the purpose of findng exact matches or completely 
// different objects. Operators overloaded also include the use of istream and 
// ostream for input and output.
class ski_jump: public athlete
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    ski_jump();                                  //Default constructor
    void read(std::istream & in);                //Read in data members
    void display(std::ostream & out) const;      //Display data members
    float calc_distance(int gust, int velocity); //Calculates distance traveled
    void copy(const ski_jump & from);            //Copy an object
    bool is_empty() const;                       //Checks if object is empty

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Input and ouput an object
    friend std::istream & operator>>(std::istream & in, ski_jump & game);
    friend std::ostream & operator<<(std::ostream & out, const ski_jump & game);

    //Add points to the total score
    friend ski_jump operator+(const ski_jump & game, int velocity);
    friend ski_jump operator+(int velocity, const ski_jump & game);
    ski_jump & operator+=(int velocity);

    //Subtract points from the total score
    friend ski_jump operator-(const ski_jump & game, int velocity);
    friend ski_jump operator-(int velocity, const ski_jump & game);
    ski_jump & operator-=(int velocity);

    //Compare if one name is less than another
    friend bool operator<(const ski_jump & game1, const ski_jump & game2);
    friend bool operator<(const ski_jump & game, const char * name);
    friend bool operator<(const char * name, const ski_jump & game);

    //Compare if one name is less than or equal to another
    friend bool operator<=(const ski_jump & game1, const ski_jump & game2);
    friend bool operator<=(const ski_jump & game, const char * name);
    friend bool operator<=(const char * name, const ski_jump & game);

    //Compare if one name is greater than another
    friend bool operator>(const ski_jump & game1, const ski_jump & game2);
    friend bool operator>(const ski_jump & game, const char * name);
    friend bool operator>(const char * name, const ski_jump & game);

    //Compare if one name is greater than or equal to another
    friend bool operator>=(const ski_jump & game1, const ski_jump & game2);
    friend bool operator>=(const ski_jump & game, const char * name);
    friend bool operator>=(const char * name, const ski_jump & game);

    //Compare if one name is equal to another
    friend bool operator==(const ski_jump & game1, const ski_jump & game2);
    friend bool operator==(const ski_jump & game, const char * name);
    friend bool operator==(const char * name, const ski_jump & game);

    //Compare if one name is different than another
    friend bool operator!=(const ski_jump & game1, const ski_jump & game2);
    friend bool operator!=(const ski_jump & game, const char * name);
    friend bool operator!=(const char * name, const ski_jump & game);


  protected:
    float distance; //Distance traveled
    int wind;       //Speed of wind (head wind decreases distance)
    int speed;      //Speed traveled at jump
};



// The 'bobsled' class manages the time it took to finish the course, an 
// integer, and the position in the bobsled car (front, middle, rear), a string
// object. This class, deriving from the 'athlete' class, inherits the data 
// members from its parent class as well. Class methods included allow the user 
// to read in, display, compare, copy objects of the same type. Operators 
// overloaded include +, +=, -, and -= for the purpose of adding and subtracting 
// time bobsledded, <, <=, >, and >= for the purpose of comparing two different 
// names, and == and != for the purpose of findng exact matches or completely 
// different objects. Operators overloaded also include the use of istream and 
// ostream for input and output.
class bobsled: public athlete
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    bobsled();                              //Default constructor
    void read(std::istream & in);           //Read in data members
    void display(std::ostream & out) const; //Display data members
    void copy(const bobsled & from);        //Copy an object
    bool is_empty() const;                  //Checks if object is empty

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Input and output an object
    friend std::istream & operator>>(std::istream & in, bobsled & game);
    friend std::ostream & operator<<(std::ostream & out, const bobsled & game);

    //Add points to the total score
    friend bobsled operator+(const bobsled & game, int minutes);
    friend bobsled operator+(int minutes, const bobsled & game);
    bobsled & operator+=(int minutes);

    //Subtract points from the total score
    friend bobsled operator-(const bobsled & game, int minutes);
    friend bobsled operator-(int minutes, const bobsled & game);
    bobsled & operator-=(int minutes);

    //Compare if one name is less than another
    friend bool operator<(const bobsled & game1, const bobsled & game2);
    friend bool operator<(const bobsled & game, const char * name);
    friend bool operator<(const char * name, const bobsled & game);

    //Compare if one name is less than or equal to another
    friend bool operator<=(const bobsled & game1, const bobsled & game2);
    friend bool operator<=(const bobsled & game, const char * name);
    friend bool operator<=(const char * name, const bobsled & game);

    //Compare if one name is greater than another
    friend bool operator>(const bobsled & game1, const bobsled & game2);
    friend bool operator>(const bobsled & game, const char * name);
    friend bool operator>(const char * name, const bobsled & game);

    //Compare if one name is greater than or equal to another
    friend bool operator>=(const bobsled & game1, const bobsled & game2);
    friend bool operator>=(const bobsled & game, const char * name);
    friend bool operator>=(const char * name, const bobsled & game);

    //Compare if one name is equal to another
    friend bool operator==(const bobsled & game1, const bobsled & game2);
    friend bool operator==(const bobsled & game, const char * name);
    friend bool operator==(const char * name, const bobsled & game);

    //Compare if one name is not equal to another
    friend bool operator!=(const bobsled & game1, const bobsled & game2);
    friend bool operator!=(const bobsled & game, const char * name);
    friend bool operator!=(const char * name, const bobsled & game);

  protected:
    int total_time;       //Time it took to complete the course (in minutes)
    std::string position; //Position in bobsled car (e.g. front, middle, rear)
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
