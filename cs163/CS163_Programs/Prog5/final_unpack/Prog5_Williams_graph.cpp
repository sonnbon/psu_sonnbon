#include "Prog5_Williams_graph.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: August 13, 2021
// Course: CS163 Data Structures
// Assignment: Program 5
// Filename: Prog5_Williams_graph.cpp
// *****************************************************************************
// This file contains the member functions needed to insert, display, and
// destroy data in a graph table Abstract Data Type (ADT). The constructor
// initializes an array of Linear Linked List's data structure to NULL with a 
// default integer size passed in as an argument. The destructor calls the
// "destroy" member function to deallocate and reinitialize all data to NULL.
// All other member functions that pass in arguments, take arrays of characters,
// passed by pointers, to achieve the operation. There are two insertion
// functions, "insert_trailhead" and "insert_path", which insert a trailhead
// into the array of Linear Linked List's array elements (constructing the 
// adjacency list) and a trailhead into the array of Linear Linked List's nodes 
// (representing adjacent trailhead's to the trailheads in the array's indexed 
// element, or the edge list), respectively. There is also a private member 
// function for "insert_path" that takes a head pointer to the node, in order to 
// be called recursively. The "display_choices" member function displays all 
// adjacent trailheads to the trailhead at a specific indexed element in the 
// array (or all data in the specified edge list). There are also additional 
// "ismatch" and "isempty" member functions that check for matches in the array 
// list and whether the list itself is empty, respectively. All functions return 
// an integer to represent a success or failure of their operations.
// *****************************************************************************



//This constructor member function allocates memory to an array of vertices and
//sets the information in each index to NULL. It also sets the list size of the
//list to the passed in integer argument.
graph::graph(int size)
{
  adjacency_list = new vertex[size]; //Allocate new array of vertices

  //Set all names and head pointers in the adjacency list to NULL.
  for (int i = 0; i < size; ++i)
  {
    adjacency_list[i].name = NULL;
    adjacency_list[i].head = NULL;
  }

  list_size = size;
}



//This destructor member function calls the "destroy" function, deallocating all 
//memory in an array of vertices and sets the information in each index to NULL. 
//It also sets the list size to zero.
graph::~graph()
{
  destroy();
}



//This member function inserts a trailhead into the adjacency list. This member
//function takes an array of characters, passed by pointer, as an argument and
//returns an integer to represent a success or failure of the operation.
int graph::insert_trailhead(char * add_name) const
{
  //Variable definitions
  int i = 0; //To be the index of the adjacency list

  //Checks for the next available index in the adjacency list.
  while (i < list_size && adjacency_list[i].name)
    ++i;

  //Checks if the adjacency list is already full. If not, a new trailhead can
  //be added.
  if (i != list_size)
  {
    adjacency_list[i].name = new char[strlen(add_name) + 1];
    strcpy(adjacency_list[i].name, add_name);

    return 1; //Returns a success of the operation
  }

  return 0; //Returns a failure of the operation
}



//This member function inserts an adjacent trailhead to a trailhead that is
//already in the adjacency list. This member function takes two arrays of
//characters, passed by pointers, as arguments and returns an integer to 
//represent a success or failure of the operation.
int graph::insert_path(char * trailhead, char * to_attach) const
{
  //Variable definitions
  int index = 0;   //To be the index of the adjacency list
  int is_real = 0; //To check whether trailhead to connect to exists

  //Check if the adjacency list is empty.
  if (isempty())
    return 0; //Returns a failure of the operation

  index = ismatch(trailhead);  //Get the index of where the client input matches
  is_real = ismatch(to_attach);//Checks whether trailhead to connect to exists


  //Check if index is the same as the list size, meaning a match was not found,
  //or if the trailhead to connect to exists in the adjacency list.
  if (index == list_size || is_real == list_size)
    return 0; //Returns a failure of the operation

  //Call function to insert recursively, passing the list's indexed head pointer
  //along with the array of characters to attach. Returns a success or failure
  //of the operation.
  return insert_path(adjacency_list[index].head, to_attach);
}



//This private member function inserts an adjacent trailhead to a trailhead that 
//is already in the adjacency list, recursively. This member function takes one 
//array of characters, passed by pointer, and a head pointer to the "node" 
//structure data type, passed by reference, as arguments and returns an integer 
//to represent a success or failure of the operation.
int graph::insert_path(node * & head, char * to_attach) const
{
  //Check if inputted data is NULL.
  if (!to_attach)
    return 0; //Returns a failure of the operation

  //Check if the list is empty and copy data to attach, allocating memory for a
  //new node, vertex, and array of characters.
  if (!head)
  {
    head = new node;
    head->adjacent = new vertex;
    head->adjacent->name = new char[strlen(to_attach) + 1];
    strcpy(head->adjacent->name, to_attach);
    head->next = NULL;

    return 1; //Returns a success of the operation
  }

  //Call function recursively, passing in head's next pointer, and return a
  //success or failure of the operation.
  return insert_path(head->next, to_attach);
}



//This member function checks whether a client inputted array of characters
//matches a trailhead in the adjacency list. This member function takes an
//array of characters, passed by pointer, as an argument and returns an 
//integer representing the index position of the match in the list and a 
//success of the operation or the list size and a failure of the operation.
int graph::ismatch(char * trailhead) const
{
  //Variable definitions
  bool match = false;  //To check whether a match occurs
  int index = 0; //To be index of matching position

  //Loops through list, checks for and finds matching position.
  for (int i = 0; i < list_size; ++i)
  {
    //Check if the indexed name is not NULL and that there is a match.
    if (adjacency_list[i].name && !strcmp(adjacency_list[i].name, trailhead))
    {
      match = true;
      index = i;
    }
  }

  //Checks if a match was found.
  if (match)
    return index; //Returns a success and the indexed position

  return list_size; //Returns a failure and the list size (out of bounds)
}



//This member function checks whether the adjacency list is empty. This member
//function takes no arguments and returns an integer to represent true (1) or
//false (0).
int graph::isempty() const
{
  //Variable definitions
  int count = 0; //Counts number of NULL elements in list

  //Loops through list and checks if every element is NULL.
  for (int i = 0; i < list_size; ++i)
  {
    if (!adjacency_list[i].name)
      ++count;
  }

  //Checks if every element is NULL
  if (count == list_size)
    return 1; //Returns true to the client

  return 0; //Returns false to the client
}



//This member function displays all the adjacent trailheads to a client inputted
//trailhead. This member function takes an array of characters, passed by
//pointer, as an argument and returns an integer to represent a success or 
//failure of the operation. 
int graph::display_choices(char * to_go) const
{
  //Variable definitions
  int index = 0; //To be the index of the adjacency list

  //Checks if the adjacency list is empty.
  if (isempty())
    return 0; //Returns a failure of the operation

  index = ismatch(to_go); //Get the index where the client input matches

  //Checks if the index is equal to the list size, meaning no match was found.
  if (index == list_size)
    return 0; //Returns a failure of the operation

  node * current = adjacency_list[index].head; //Hold indexed head pointer
 
  //Check if the indexed head pointer is NULL.
  if (!current)
    return 0; //Returns a failure of the operation

  //Traverse the entire edge list, displaying all the nodes.
  while (current)
  {
    cout << current->adjacent->name << endl;
    current = current->next;
  }

  cout << endl;
  
  return 1; //Returns a success of the operation
}



//This member function deallocates all data members memory and sets it to NULL.
//It also sets the list size to zero. This member function takes no arguments
//and returns an integer to represent a success or failure of the operation.
int graph::destroy()
{
  if (!adjacency_list)
    return 0; //Returns a failure of the operation

  //Check and deallocate all memory from every index and node in the list.
  for (int i = 0; i < list_size; ++i)
  {
    if (adjacency_list[i].name)
    {
      delete [] adjacency_list[i].name;
      adjacency_list[i].name = NULL;
    }
    
    node * current = adjacency_list[i].head; //Hold indexed head pointer

    //Traverse through every node at the indexed element and deallocate all.
    while (current)
    {
      node * temp = current->next; //Hold current's next pointer
      
      //Check that the current node's name in the edge list is not NULL and 
      //deallocate all memory.
      if (current->adjacent->name)
      {
        delete [] current->adjacent->name;
        current->adjacent->name = NULL;
      }

      //Check that the current node's vertex in the edge list is not NULL and 
      //deallocate all memory.
      if (current->adjacent)
      {
        delete current->adjacent;
        current->adjacent = NULL;
      }

      delete current;
      current = temp;
    }
  }

  delete [] adjacency_list;
  adjacency_list = NULL;

  list_size = 0;

  return 1; //Returns a success of the operation
}





