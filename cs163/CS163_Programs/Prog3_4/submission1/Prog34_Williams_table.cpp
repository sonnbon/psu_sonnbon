#include "Prog34_Williams_table.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 30, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_table.cpp
// *****************************************************************************
// This file contains the member functions of the "table" class, which allows
// for an Array of Linear Linked Lists (LLL) of "animal" objects. From the 
// client, a user can insert objects into both a Hash Table and a Binary Search
// Tree (BST), display all matches of a particular animal type and breed from 
// the Hash Table, retrieve paricular animal's based on their breed and name
// from the BST, display all animals in sorted order by their breed and name
// from the BST, and remove an animal of a particular name from both the Hash
// Table and BST. This class is working with a Hash Table and BST  data structure 
// and is doing so with three data members, an array of head pointers
// ("hash_table") to a Hash Table node ("h_node"), a root pointer to a tree node
// ("t_node"), and an integer of the Hash Table's array size. The Hash Table 
// uses a "hash_function", which determines where data gets added into the table
// by passing in two arrays of characters. The "insert" function passes in three
// arrays of characters and an object of the "animal" class data type in order
// to add data to both tables. The "display_match" function passes in two arrays
// of characters to find and display specific table matches. The "load" and 
// "save" member functions pass in an objet of the "table" class data type in
// order to accomplish loading a list of animals from and saving to an external
// file. All member functions return an integer data type to the client to 
// represent success or failure of the operation.
// *****************************************************************************


    
// The constructor initializes the data members to NULL or 0. This constructor 
// takes no arguments and returns nothing.
table::table(int size)
{
  //Initialize BST.
  root = NULL;

  //Initialize Hash Table.
  hash_table = new h_node * [size]; //Allocate hash table node of input size

  //Iterate through new hash table and set each element to NULL.
  for (int i = 0; i < size; ++i)
    hash_table[i] = NULL;

  hash_table_size = size; //Set hash table's size to input size
}




// The destructor deallocates any dynamically allocated memory and resets it to
// NULL. This destructor takes no arguments and returns nothing.
table::~table()
{
  BST_remove_all(root);        //Removes all data from the BST

  hash_remove_all(hash_table); //Removes all data from the Hash Table
}



// This member function creates and returns an index to be used to add data to
// a hash table's Array of Linear Linked Lists. This member function takes two
// arrays of characters as arguments and returns an interger to represent the 
// index to be used when adding the data to the hash table.
int table::hash_function(char key_value1[], char key_value2[])
{
  //Variable definitions
  int index = 0;     //Will be returned index
  int length1 = 0;   //Will be length of inputted key_value1 array of characters
  int length2 = 0;   //Will be length of inputted key_value2 array of characters
  int sum = 0;       //Will be sum of all the characters in the inputted arrays

  length1 = strlen(key_value1);
  length2 = strlen(key_value2);

  //Iterate through key_value1 and add each character ASCII value
  for (int i = 0; i < length1; ++i)
    sum += key_value1[i];

  //Iterate through key_value2 and add each character ASCII value
  for (int i = 0; i < length2; ++i)
    sum += key_value2[i];

  index = sum % hash_table_size; //Get index to be position of hash table

  return index; //Returns the index result
}



// This member function inserts client inputted data into a Hash Table and a
// Binary Search Tree. This member function takes two arrays of characters and a
// an object of the constant "animal" class type as arguments and returns an
// integer to represent the success or failure of the operation.
int table::insert(char type[], char breed[], char name[], 
                  const animal & add_animal)
{
  hash_insert(type, breed, add_animal); //Inserts client data into Hash Table

  BST_insert(root, breed, name, add_animal); //Inserts client data into BST

  return 1;
}



// This member function displays all matches of a particular type and breed of
// animal within the Hash Table. This member function takes two arrays of 
// characters as arguments and returns an integer to represent the success or
// failure of the operation.
int table::display_match(char type[], char breed[])
{
  //Variable definitions
  int index = 0; //Will be index for position in Hash Table

  index = hash_function(type, breed); //Index catches result of function call

  //Checks if this tables element is empty.
  if (!hash_table[index])
    return 0; //Returns a failure of the operation

  h_node * current = hash_table[index]; //Current pointer gets the value of the
                                        //table's index node
  //Traverse while current is not NULL.
  while (current)
  {
    //Check if current node has matching data to the search parameters.
    if (current->new_animal.ismatch(type, breed))
      current->new_animal.display(); //Current displays it's new_animal data

    current = current->next;
  }

  return 1; //Returns a success of the operation
}



// This member function finds a particular animal searched for by the client.
// This member function takes two arrays of characters and an object of the
// "animal" class data type as arguments and returns and integer to represent
// a success or failure of the operation.
int table::retrieve(char name[], char breed[], animal & to_find)
{
  //Check if the table is empty.
  if (!root)
    return 0; //Returns a failure of the operation

  //Traverse the table recursively
  return BST_retrieve(root, name, breed, to_find);
}



// This member function displays all added animals in the Binary Search Tree
// sorted by their breed and name. This member function takes no arguments and
// returns an integer to represent a success or failure of the operation.
int table::display_all() const
{
  //Check if table is empty.
  if (!root)
    return 0; //Returns a failure of the operation

  //Traverse the table recursively.
  return BST_display_all(root); 
}



// This member function removes a particular animal searched for by name from 
// both table data structures. This member function takes an array of characters
// as an argument and returns an integer to represent a success or failure of
// the operation.
int table::remove_animal(char name[])
{

  return 0;
}



// This private member function removes a particular animal searched for by name
// from the Hash Table. This member function takes an array of characters and an
// array of "hash_table" pointers to the Hash Table node "h_node" structure data
// type as arguments and returns an integer to represent a success or failure of
// the operation.
int table::hash_remove(h_node ** & hash_table, char name[])
{

  return 0;
}



// This private member function removes a particular animal searched for by name
// from the Binary Search Tree (BST). This member function takes an array of 
// characters and a root pointer to the BST's node "t_node" structure data type
// as arguments and returns an integer to represent a success or failure of the
// operation.
int table::BST_remove(t_node * & root, char name[])
{

  return 0;
}



// This member function inserts client inputted data into a Hash Table by a
// key value. This member function takes two arrays of characters and an
// object of the constant "animal" class data type as arguments and returns
// an integer to represent a success or failure of the operation.
int table::hash_insert(char type[], char breed[], const animal & add_animal)
{
  if (add_animal.isempty())
    return 0; //Returns a failure of the operation

  //Gets index to use for adding data to the hash table.
  int index = hash_function(type, breed);
  
  h_node * temp = hash_table[index]; //Temp pointer gets the value of the Hash
                                     //Table's element
  hash_table[index] = new h_node;    //Allocate a new node for the Hash Table's
                                     //element

  //Add the client inputted object to the Hash Table's element's pointer to a
  //new animal.
  hash_table[index]->new_animal.copy(add_animal);
  hash_table[index]->next = temp;   //Hash Table's element's next pointer gets
                                    //the value of temp

  return 1; //Returns a success of the operation
}



// This private member function inserts client inputted data into a Binary
// Search Tree (BST), sorted by animal breed and name. This member function
// takes a root pointer to the BST's node "t_node" and an object of the
// constant "animal" class data type, passed by reference, as arguments and
// returns an integer to represent a success or failure of the operation.
int table::BST_insert(t_node * & root, char breed[], char name[], 
                      const animal & add_animal)
{ 
  //Check if data to add is empty.
  if (add_animal.isempty())
    return 0; //Returns a failure of the operation

  //Check if BST is empty.
  if (!root)
  {
    root = new t_node;                 //Allocate a new tree node to the root
    root->new_animal.copy(add_animal); //Add user inputted data to root's object
    root->left = NULL;
    root->right = NULL;

    return 1; //Returns a success of the operation
  }

  //Check if inputted data is less than the object's data, alphabetically.
  if (root->new_animal.get_sorted(breed, name) == 1)
    return BST_insert(root->left, breed, name, add_animal);

  //The inputted data is greater than the object's data, alphabetically.
  return BST_insert(root->right, breed, name, add_animal);
}



// This private member function finds a particular animal searched for by the 
// client. This member function takes a root pointer to the tree node "t_node"
// structure data type, two arrays of characters and an object of the "animal"
// class data type as arguments and returns and integer to represent a success
// or failure of the operation.
int table::BST_retrieve(t_node * root, char breed[], char name[], 
                        animal & to_find)
{
  //Check if at the end of the table
  if (!root)
    return 0; //Returns a failure of the operation

  //Check if the inputted data matches the object's data
  if (root->new_animal.retrieve(breed, name))
  {
    to_find.copy(root->new_animal); //Copy data to passed in object
    return 1; //Returns a success of the operation
  }

  //Check if inputted data is less than the object's data, alphabetically.
  if (root->new_animal.get_sorted(breed, name) == 1)
    return BST_retrieve(root->left, breed, name, to_find);

  //The inputted data is greater than the object's data, alphabetically.
  return BST_retrieve(root->right, breed, name, to_find);
}



// This private member function displays all added animals in the Binary Search 
// Tree sorted by their breed and name. This member function takes a root 
// pointer to the tree node "t_node" structure data type as an argument and 
// returns an integer to represent a success or failure of the operation.
int table::BST_display_all(t_node * root) const
{
  //Check if at the end of the table
  if (!root)
    return 0; //Returns a failure of the oepration

  //Traverse left recursively.
  BST_display_all(root->left);

  root->new_animal.display();

  //Traverse right recursively.
  BST_display_all(root->right);

  return 1; //Returns a success of the operation
}



// This private member function deletes all the data in a Binary Search Tree.
// This member function takes a root pointer to the tree's node structure 
// data type, passed by reference, as an argument and returns an integer to 
// represent success or failure of the operation.
int table::BST_remove_all(t_node * & root)
{
  //Check if table is empty
  if (!root)
    return 0; //Returns failure of the operation

  BST_remove_all(root->left);  //Traverse the list left
  BST_remove_all(root->right); //Traverse the list right

  delete root;
  root = NULL;

  return 1; //Returns success of the operation
}



// This private member function deletes all the data in a Hash Table. This
// member function takes an array of hash_table pointers to the h_node
// structure data type, passed by reference, as an argument and returns an
// integer to represent success or failure of the operation.
int table::hash_remove_all(h_node ** & hash_table)
{
  //Check if the table is empty.
  if (!hash_table)
    return 0; //Returns a failure of the operation

  //Iterate through each Hash Table element.
  for (int i = 0; i < hash_table_size; ++i)
  {
    h_node * temp = hash_table[i]; //Temp pointer gets the value of Hash Table's
                                   //element

    //Traverse temp while it is not NULL.
    while (temp)
    {
      temp = temp->next;
      delete hash_table[i];
      hash_table[i] = temp; //Set Hash Table's element to temp
    }
  }

  delete [] hash_table;
  hash_table = NULL;

  return 1; //Returns a success of the operation
}



// This member function loads data from an external file and copies it to a 
// client input table object. This member function takes an object of the
// "table" class data type, passed by reference, as an argument and returns
// an integer to represent a failure or a success and the number of items
// loaded.
int table::load(table & animal_list)
{

  return 0;
}



// This member function saves the current list of animals to an external file.
// This member function takes an object of the constant "table" class, passed
// by reference, and an integer, passed by value, as arguments and returns an
// integer to represent a success or failure of the operation.
int table::save(const table & animal_list, int num)
{

  return 0;
}
