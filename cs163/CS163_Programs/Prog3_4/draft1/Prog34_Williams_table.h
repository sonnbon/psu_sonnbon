#include "Prog34_Williams_animal.h"
#include <fstream>

// *****************************************************************************
// Author: Connor Williams
// Date: July 27, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_table.h
// *****************************************************************************
// This file contains two node structures, external file specific prototype 
// functions, and a class Abstract Data Type (ADT), named "table". This ADT is 
// used to work with Table ADT's, specifically the Hash Table and Binary Search 
// Tree (BST) data structures. These data structures hold the same object 
// contents of the "animal" class data type. All member functions (not 
// including the constructor or destructor) within the ADT return an integer 
// value to represent success or failure of an operation to the client. 
// Arguments that will be passed in member functions include an object of the 
// "animal" class data type for inserting and retrieving purposes and arrays of 
// characters for displaying, retrieving, and removing purposes. The external
// file specific prototype functions allow for loading and saving of all animal
// information. The two node structures "h_node" and "t_node" hold the
// information needed for a Hash Table and BST, respectively.
// *****************************************************************************



// - - - - - S T R U C T U R E S - - - - -
//
// This node structure holds an object "new_animal" of the "animal" class data 
// type and a next pointer to the node structure.
struct h_node
{
  animal new_animal; //Object holds all animal information
  h_node * next;     //Next pointer to the h_node
};



// This node structure holds an object "new_animal" of the "animal" class data 
// type and a left and right pointer to the node structure.
struct t_node
{
  animal new_animal; //Object holds all animal information
  t_node * left;     //Left pointer to the t_node
  t_node * right;    //Right pointer to the t_node
};
// -----------------------------------------------------------------------------



// - - - - - P R O T O T Y P E S - - - - -
//
//int load(table & animal_list);       //Loads from a file and copies to the
                                     //passed in object
//int save(const table & animal_list); //Saves the passed in object to an external
                                     //file
// -----------------------------------------------------------------------------



// - - - - - C L A S S E S - - - - -
//
// This class manages a Hash Table and Binary Search Tree (BST) data structure, 
// which each hold an object of the "animal" class data type. It allows for
// insertion of an object into a unique location of a Hash Table and into a
// BST, sorted by breed and name. It also allows for displaying an animal of a
// particular type and breed, retrieving an animal of a particular name and
// breed, and removing of an animal of a particular name. Lastly, this class
// allows for the displaying of all animals, sorted by breed and name, for 
// debugging purposes.
class table
{
  public:
    table(int size);                       //Constructor, initializes data 
                                           //members to NULL or 0.
    ~table();                              //Destructor, deallocates dynamic
                                           //data members and resets all data
				                           //members to NULL or 0.
    int hash_function(char key_value1[],   //Takes two arrays of characters and
                      char key_value2[]);  //creates an index value.
    int insert(const animal & new_animal); //Insert a new animal
  
    int display_match(char type[],         //Display all matches of a particular
                      char breed[]);       //type and breed
    int retrieve(char name[], char breed[],//Find a particuluar animal based on
                 animal & to_find);        //their breed and name
    int display_all() const;               //Display all animals
    int remove_animal(char name[]);        //Remove an animal search for by name

  private:
    int BST_insert(t_node * & root,             //Insert a new animal to the BST
                   const animal & new_animal);
    int hash_insert(h_node ** & hash_table,     //Insert a new animal to the
                    const animal & new_animal); //hash table
    int BST_remove(t_node * & root,             //Remove an animal from the BST
                   char name[]);
    int hash_remove(h_node ** & hash_table,     //Remove an animal from the hash
                    char name[]);               //table
    int BST_remove_all(t_node * & root);        //Removes all BST data

    h_node ** hash_table; //Array of head pointers to the 
                          //hash table node
    t_node * root;        //Root pointer to the tree node
    int hash_table_size;  //Size of the hash table
};
// -----------------------------------------------------------------------------




