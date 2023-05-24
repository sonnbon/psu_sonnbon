#include "Baron-Williams_athlete.h"

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_BST.h
// *****************************************************************************
// This file contains the classes 'node' and 'BST', both with the job of 
// managing a containment of and a Binary Search Tree (BST) of figure skaters. 
// The 'node' class contains two pointers to the 'node' class, for the purpose 
// of being used in the 'BST' class data structure. Its job is to be a 
// container of a figure skating athlete competing in the Winter Olympics. The 
// 'BST' class contains a pointer to the 'node' class as well for the purpose of 
// creating a BST of figure skating athletes. The BST allows a user to insert, 
// remove, remove all, display, display all, retrieve, and copy all athletes.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'node' class manages a "container" that derives from and inherits all 
// data from the 'figure_skate' class, for the purpose of being able to get
// figure skater's statistical and biographical information. This class' data 
// members include two pointers to a 'node' ('left' and 'right'), which allow it 
// to be used to connect "left" and "right" to other "children" nodes of this 
// same class type. This class can go to the left or right 'node' by returning
// the pointer to the left or right 'node' and set both the left and right 
// 'nodes'. Operator overloaders included are = for assignment of a
// 'figure_skate' object, <, <=, >, and >= to see how a passed in name compares
// to a 'nodes' name for sorting purposes, and == and != to see if a node's name 
// is equal to or not equal to a passed in name for searching and displaying 
// purposes. Operators overloaded also include << for output of an object.
class node: public figure_skate
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    node();                     //Default constructor
    node * & go_left();         //Returns the pointer to the left node
    node * & go_right();        //Returns the pointer to the right node
    void set_left(node * src);  //Sets the left node to passed in pointer
    void set_right(node * src); //Sets the right node to passed in pointer

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Assignment of a figure skater
    node & operator=(const figure_skate & game);

    //Output an object
    friend std::ostream & operator<<(std::ostream & out, const node & from);

    //Compare if 'nodes' name is less than passed in name
    bool operator<(const char * name) const;
    bool operator<(const figure_skate & game) const;

    //Compare if 'nodes' name is less than or equal to passed in name
    bool operator<=(const char * name) const;
    bool operator<=(const figure_skate & game) const;

    //Compare if 'nodes' name is greater than passed in name
    bool operator>(const char * name) const;
    bool operator>(const figure_skate & game) const;

    //Compare if 'nodes' name is greater than or equal to passed in name
    bool operator>=(const char * name) const;
    bool operator>=(const figure_skate & game) const;

    //Compare if 'nodes' name is equal to or not equal to passed in name
    bool operator==(const char * name) const;
    bool operator!=(const char * name) const;


  private:
    node * left;  //Left pointer to the node
    node * right; //Right pointer to the node
};



// The 'BST' class manages a Binary Search Tree (BST) data structure with a 
// containing relationship with the 'node' class. The purpose of this data
// structure is to hold a list of figure skaters, sorted by name, competing in 
// the Winter Olympics. Being a containing relationship, this class has a data 
// member that is a pointer to the 'node' class type. This data structure allows 
// the user to insert, retrieve, copy, remove, remove all, display, and display 
// all athletes in the list. This class has a copy constructor and a destructor 
// because it is working with dynamic memory. Operator overloaders included are 
// = for assigning a BST object to another, +, +=, -, and -=, for adding and 
// removing athletes, and == and != to check if a name is equal to or not equal
// to another. Operators overloaded also include << for outputting an object.
class BST
{
  public:
    // - - - - - - - - - - - - - - - M E T H O D S - - - - - - - - - - - - - - -
    BST();                                     //Default constructor
    BST(const BST & from);                     //Copy Constructor
    void copy_all(const BST & from);           //Copies all athletes
    ~BST();                                    //Destructor
    int remove_all();                          //Removes all athletes
    bool remove(const char * name);            //Removes an athlete by name
    void insert(const figure_skate & from);    //Inserts an athlete
    bool retrieve(const char * name) const;    //Retrieves an athlete
    int display_all(std::ostream & out) const; //Displays all atheltes

    // - - - - - - - - - O P E R A T O R _ O V E R L O A D E R S - - - - - - - -
    //Assignment of an object
    BST & operator=(const BST & old_tree);

    //Output of an object
    friend std::ostream & operator<<(std::ostream & out, const BST & tree);

    //Add an athlete
    friend BST operator+(const BST & list, const figure_skate & game);
    friend BST operator+(const figure_skate & game, const BST & list);
    BST & operator+=(const figure_skate & game);

    //Remove an athlete
    friend BST operator-(const BST & list, const char * name);
    friend BST operator-(const char * name, const BST & list);
    BST & operator-=(const char * name);

    //Compare if a name in the list is equal to or not equal to the passed in 
    //name.
    bool operator==(const char * name) const;
    bool operator!=(const char * name) const;


  private:
    node * root; //Root pointer to a 'node'

    // - - - - - - - - - - - P R I V A T E _ M E T H O D S - - - - - - - - - - -
    void copy_all(node * & root, node * src);               //Copy all athletes
    int remove_all(node * & root);                          //Remove all
    bool remove(node * & root, const char * name);          //Removes an athlete
    void insert(node * & root, const figure_skate & from);  //Inserts an athlete
    bool retrieve(node * head, const char * name) const;    //Retrieve athlete
    int display_all(std::ostream & out, node * head) const; //Display all
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


