#include <iostream>
#include <cctype>
#include <cstring>

// *****************************************************************************
// Author: Connor Williams
// Date: August 10, 2021
// Course: CS163 Data Structures
// Assignment: Program 5
// Filename: Prog5_Williams_graph.h
// *****************************************************************************
// This file contains the structures and classes need to hold, insert, display,
// and destroy an list or graph of trailheads or path intersections that are
// adjacent to each other. This is a achieved by using an array of Linear Linked
// Lists (LLL). A "vertex" structure is used to hold the information of each
// trailhead or path intersection, pointing to an adjacent trailhead. The "node"
// structure is used to hold an array of those "vertex" objects, pointing to the
// next node within the "node" structure. The "graph" class is used to insert,
// display, and destroy this data, using an array of "vertex" objects to keep 
// track of a list of adjacent trailheads and the size of the list. Arguments
// passed in are arrays of characters (not including the constructor, which
// takes a default integer list size) and all return types are of an integer
// data type to represent success or failure of an operation.
// *****************************************************************************



// - - - - - - - S T R U C T U R E S - - - - - - -
// This "vertex" structure holds the name of a trailhead or path intersection
// and a head pointer to the "node" structure data type.
struct vertex
{
  char * name;        //Name of the trailhead or path intersection
  struct node * head; //Head pointer to the "node" structure data type
};



// This "node" structure holds an array of "vertex" objects, called "adjacent",
// and a next pointer to the "node" structure itself.
struct node
{
  vertex * adjacent; //Array of "vertex" objects
  node * next;       //Next pointer to the "node" structure itself
};
// -----------------------------------------------------------------------------



// - - - - - - - C L A S S E S - - - - - - -
// This "graph" class holds the information needed to add, display, and destroy
// a graph or table of path intersections, specifically by using an array of
// "vertex" objects, where each object holds the name of the trailhead or path
// and a head pointer that points to a trailhead adjacent to it. A "list_size"
// integer variable is also used to keep track of the size of the array that is
// used to hold all the trailhead information. All arguments passed in are
// arrays of characters (not including the constructor which takes a default
// integer list size) and all return types are of an integer data type.
class graph
{
  public:
    graph(int size = 7); //Constructor initializes data to NULL
    ~graph();            //Destructor deallocates all data members
    int insert(char * add_name) const;     //Inserts a trailhead into the graph
    int display_choice(char * to_go) const;//Display where a user can go next
    int destroy();                         //Deallocates all data in the graph

  private:
    vertex * adjacency_list; //Array of "vertex" objects
    int list_size;           //To be list size of "adjacency_list"
};
// -----------------------------------------------------------------------------
