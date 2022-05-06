#include "Prog34_Williams_table.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: August 6, 2021
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
// from the BST, and remove an animal of a particular type, breed, and name 
// (virtually unique) from both the Hash Table and BST. This class is working 
// with a Hash Table and BST data structure and is doing so with three data 
// members, an array of head pointers ("hash_table") to a Hash Table node 
// ("h_node"), a root pointer to a tree node ("t_node"), and an integer of the 
// Hash Table's array size. The Hash Table uses a "hash_function", which 
// determines where data gets added into the table by passing in two arrays of 
// characters. The "insert" function passes in three arrays of characters and an 
// object of the "animal" class data type in order to add data to both tables. 
// The "display_match" function passes in two arrays of characters to find and 
// display specific table matches. The "retrieve" member function passes in two
// arrays of characters and an object of the "animal" class data type to copy to
// when an item is found. The "load" member function passes in six arrays of 
// characters, a float, and object of the "animal" class data type in order to 
// accomplish loading a list of animals from an external file. All member 
// functions return an integer data type to the client to represent success or 
// failure of the operation.
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
  BST_remove_all(root); //Removes all data from the BST

  hash_remove_all();    //Removes all data from the Hash Table
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
  //Checks and inserts client data into Hash Table and BST
  if (hash_insert(type, breed, add_animal) && 
      BST_insert(root, breed, name, add_animal))
    return 1; //Returns a success of the operation

  return 0; //Returns a failure of the operation
}



// This member function displays all matches of a particular type and breed of
// animal within the Hash Table. This member function takes two arrays of 
// characters as arguments and returns an integer to represent the success and
// number of nodes displayed or failure of the operation.
int table::display_match(char type[], char breed[])
{
  //Variable definitions
  int count = 0; //Gets number of nodes displayed

  int index = hash_function(type, breed); //Index catches hash function result

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
    {
      current->new_animal.display(); //Current displays it's animal data
      ++count;
    }

    current = current->next;
  }

  return count; //Returns a success and number of nodes or failure if 0
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



// This member function removes a particular animal from both table data 
// structures. This member function takes three arrays of characters as
// arguments and returns an integer to represent a success or failure of the
// operation.
int table::remove_animal(char type[], char breed[], char name[])
{
  int index = hash_function(type, breed);

  //Checks and removes a matching item from the Hash Table and BST
  if (hash_remove(hash_table[index], type, breed, name) &&
     BST_remove(root, type, breed, name))
    return 1; //Returns a success of the operation

  return 0; //Returns a failure of the operation
}



// This private member function removes a particular animal from the Hash Table. 
// This member function takes three arrays of characters and a head pointer to 
// the Hash Table node "h_node" structure data type, passed by reference, as 
// arguments and returns an integer to represent a success or failure of the 
// operation.
int table::hash_remove(h_node * & head, char type[], char breed[], char name[])
{

  //Check if the list in the table is empty.
  if (!head)
    return 0; //Returns a failure of the operation

  //Check for a match with the passed in data.
  if (head->new_animal.find_unique(type, breed, name))
  {
    h_node * hold = head->next; //Hold onto head's next pointer
    delete head;
    head = hold;
    
    return 1; //Returns a success of the operation
  }

  //Returns a success or failure, calling the function recursively.
  return hash_remove(head->next, type, breed, name);
}



// This private member function removes a particular animal from the Binary 
// Search Tree (BST). This member function takes three arrays of characters and 
// a root pointer to the BST's node "t_node" structure data type as arguments 
// and returns an integer to represent a success or failure of the operation.
int table::BST_remove(t_node * & root, char type[], char breed[], char name[])
{
  //Variable definitions
  int count = 0; //Counts the deleted node

  //Check if the table is empty or we are at the end.
  if (!root)
    return 0; //Returns a failure of the operation

  //Check whether there is a match with the passed in data.
  if (root->new_animal.find_unique(type, breed, name))
  {
    //If the node has no children.
    if (!root->left && !root->right)
    {
      delete root;
      root = NULL;
    }
    
    //Else if the node has a left child but no right child.
    else if (!root->right)
    {
      t_node * hold = root->left; //Hold gets the value of root's left pointer
      delete root;
      root = hold;
    }

    //Else if the node has a right child but no left child.
    else if (!root->left)
    {
      t_node * hold = root->right; //Hold gets the value of root's right pointer
      delete root;
      root = hold;
    }

    //Otherwise the node has two children.
    else
    {
      t_node * right_hold = root->right; //Hold onto root's right pointer

      //Check if root's right pointer is the inorder successor.
      if (!right_hold->left)
      {
        //Copy root's right pointer data to itself and connect to the right
        //pointer's right pointer.
        root->new_animal.copy(right_hold->new_animal);
        root->right = right_hold->right;
        delete right_hold;
      }

      //Otherwise root's right pointer is not the inorder successor.
      else
      {
        t_node * previous = right_hold; //Previous gets right pointer's value

        //Traverse from root's right pointer to the left most node.
        while (right_hold->left)
        {
          previous = right_hold;
          right_hold = right_hold->left;
        }

        //Copy inorder successor's data to root and connect to previous' left
        //pointer to the inorder successor's right pointer.
        root->new_animal.copy(right_hold->new_animal);
        previous->left = right_hold->right;
        delete right_hold;
      }
    }
    
    ++count;
    return count; //Returns a success of the operation
  }

  //Recursive call checks next node to the left.
  count = BST_remove(root->left, type, breed, name);

  //Recursive call checks next node to the right.
  count += BST_remove(root->right, type, breed, name);

  return count; //Returns whether a node was removed
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
int table::hash_remove_all()
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
// client input table object. This member function takes six arrays of 
// characters, a float, and an object of the "animal" class data type, passed by 
// reference, as arguments and returns an integer to represent a failure or a 
// success and the number of items loaded.
int table::load(char filename[], char type[], char breed[], char name[],
                char needs[], float age, char notes[], animal & load_animal)
{
  //Variable definitions
  int num = 0;      //To be number of files read in. Set to 0.

  ifstream file_in; //To connect and input files from external file

  //Connect to file
  file_in.open(filename);

  //Check that connection is good and load the previously stored list of 
  //animals from the external file
  if (file_in)
  {
    file_in.get(type, SIZE, '|');
    file_in.ignore(400, '|');

    while (!file_in.eof())
    {
      file_in.get(breed, SIZE, '|');
      file_in.ignore(400, '|');

      file_in.get(name, SIZE, '|');
      file_in.ignore(400, '|');

      file_in.get(needs, SIZE, '|');
      file_in.ignore(400, '|');

      file_in >> age;
      file_in.ignore(400, '|');

      file_in.get(notes, SIZE, '\n');
      file_in.ignore(400, '\n');
      ++num;

      load_animal.set(type, breed, name, needs, age, notes);
      insert(type, breed, name, load_animal);

      file_in.get(type, SIZE, '|');
      file_in.ignore(400, '|');
    }
    file_in.close();  //Close file
  }

  return num; //Returns success and number of animals or failure of operation
}




