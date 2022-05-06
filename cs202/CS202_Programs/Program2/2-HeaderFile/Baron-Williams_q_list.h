#include "Baron-Williams_prep.h"

// *****************************************************************************
// Program 2
// Author: Connor Baron-Williams
// Due Date: February 4, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_q_list.h
// *****************************************************************************
// This file contains the classes 'node' and 'q_list', both with the job of 
// managing a containment of and Array of Doubly Linked Lists of different types
// of test preparation questions. The 'node' class contains a pointer to an 
// Abstract Base Class (ABC), called 'prep' (included from 
// "Baron-Williams_prep.h" file), for the purpose of being used in the 'q_list'
// class data structure. The sole purpose of the node, however, is to be a 
// container of different object types through the use of dynamic binding, 
// connecting to other nodes by pointing to itself and its previous self. The
// 'q_list' class contains a pointer to a pointer to the 'node' class for the 
// purpose of creating an Array of Doubly Linked Lists of different question
// types and question samples. The array is to be used to sort the questions by
// type and the Doubly Linked list is to be used to sort questions by difficulty
// rating.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'node' class manages a "container" that contains a pointer to the
// 'prep' class, for the purpose of being able to get different class objects'
// information, which are derived from 'prep', through dynamic binding. This 
// class' other data members include two pointers to a 'node' ('next' and 
// 'prev'), that allow it to be used to connect "forward" and "backward" to 
// other nodes of this same class type. This class can go to the next node by 
// returning the pointer to the next node, go the previous node by returning the 
// pointer to the previous node, set both the next and previous nodes, and can 
// check if the next node or previous nodes are pointing to NULL (bool return 
// type). This class has a copy constructor and a destructor because it is
// working with dynamic memory.
class node
{
  public:
    node();                    //Default constructor
    node(const prep & from);   //Constructor with prep object argument
    node(const node & from);   //Copy constructor
    ~node();                   //Destructor
    node * & go_next();        //Returns the pointer to the next node
    node * & go_prev();        //Returns the pointer to the previous node
    bool has_next() const;     //Checks if next pointer is pointing to NULL
    bool has_prev() const;     //Checks if previous pointer is pointing to NULL
    void set_next(node * src); //Sets the next node to passed in pointer
    void set_prev(node * src); //Sets the previous node to passed in pointer

  private:
    prep * practice; //Pointer to the 'prep' Abstract Base Class
    node * next;     //Next pointer to the node
    node * prev;     //Previous pointer to the node
};



// The 'q_list' class manages an Array of Doubly Linked Lists data structure 
// with a containing relationship with the 'node' class. The purpose of this 
// data structure is to hold a list of test preparation questions for a written
// exam, a live coding proficiency demo exam, or an unforeseen exam of the
// future with new concepts to study. The array's index will keep the types of
// questions organized separately while the Doubly Linked Lists will keep the 
// questions sorted by difficulty rating. Being a containing relationship, this 
// class has a data member that is a pointer to a pointer to the 'node' class 
// type. There is also a data member integer for storing the size of the array, 
// which will be set to 10 as a default size. This data structure allows the 
// user to insert (with the use of a hash function), retrieve, copy all, remove,
// remove by type, remove all, display, display by type, and display all 
// questions in the list. This class has a copy constructor and a destructor
// because it is working with dynamic memory.
class q_list
{
  public:
    q_list(int size = 10);               //Default constructor
    void set_empty();                    //Creates an empty Array of DLL
    q_list(const q_list & from);         //Copy constructor
    void copy_all(const q_list & from);  //Copies from a q_list object
    ~q_list();                           //Destructor
    void remove_all();                   //Removes all questions
    int hash_function(const std::string  //Hash function for index insertion
                      & type) const;
    int insert(const prep & from);       //Inserts a question to prepare for
    bool retrieve(const prep & from)     //Retrieves a specific question
                  const;
    bool retrieve_type(const std::string //Retrieves a list of questions by type
                       & type) const;
    void remove();                       //Removes a question
    int remove_type(const std::string    //Removes a list of questions by type
                    & type);
    void display() const;                //Displays a question
    int display_type(const std::string   //Displays a list of questions by type
                     & type) const;
    int display_all() const;             //Displays all questions

  private:
    //Data members
    node ** questions; //Dynamic array of node pointers
    int list_size;     //Size of array

    //Recursive functions
    void set_empty(int & index);     //Creates an empty Array of DLL
    void copy_all(node ** src,       //Copies from another Array of DLL
                 int & index);
    void copy_type(node * & dest,    //Copies from another DLL
                   node * src);
    void remove_all(int & index);    //Removes indexed information of an Array
    void remove_type(node * & head); //Removes all from a DLL
    bool retrieve(node * head,       //Retrieves a specific question
                  const prep & from) 
                  const;
    int display_all(int & index);    //Displays all questions by index
    int display_type(node * head)    //Displays a list of questions by type
                     const;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


