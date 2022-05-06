#include "Baron-Williams_card.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 21, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_node.h
// *****************************************************************************
// This file contains the classes 'a_node', 's_node', and 'd_node', all with the
// job of managing a node of the classes they are respectively derived from
// ('action', 'spell', and 'defend'). These three nodes inherit their respective
// classes information for the purpose of being used in varying data structures
// that will provide the ability to play a card game. The sole purpose of each
// node, however, is to be a container that can be connected to other nodes by
// pointing to itself.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'a_node' class manages a "container" of the 'action' class that it is 
// derived from in a single inheritance hierarchy. This "container" has a data
// member, a pointer to an 'a_node', that allows it to be used to connect to 
// other nodes of this same class type. This class can go to the next node, by
// returning the pointer to the next node, and can check if the next node is
// NULL, returning a bool value.
class a_node: public action
{
  public:
    a_node();                    //Default constructor
    a_node(const action & from); //Constructor with action object argument
    a_node(const a_node & from); //Copy constructor
    a_node * & go_next();        //Returns the pointer to the next node
    bool if_next() const;        //Checks if next pointer is pointing to NULL

  private:
    a_node * next; //Next pointer to the node
};



// The 's_node' class manages a "container" of the 'spell' class that it is 
// derived from in a single inheritance hierarchy. This "container" has a data
// member, a pointer to an 's_node', that allows it to be used to connect to 
// other nodes of this same class type. This class can go to the next node, by
// returning the pointer to the next node, and can check if the next node is
// NULL, returning a bool value.
class s_node: public spell
{
  public:
    s_node();                    //Default constructor
    s_node(const spell & from);  //Constructor with spell object argument
    s_node(const s_node & from); //Copy constructor
    s_node * & go_next();        //Returns the pointer to the next node
    bool if_next() const;        //Checks if next pointer is pointing to NULL

  private:
    s_node * next; //Next pointer to the node
};



// The 'd_node' class manages a "container" of the 'defend' class that it is 
// derived from in a single inheritance hierarchy. This "container" has a data
// member, a pointer to an 'd_node', that allows it to be used to connect to 
// other nodes of this same class type. This class can go to the next node, by
// returning the pointer to the next node, and can check if the next node is
// NULL, returning a bool value.
class d_node: public defend
{
  public:
    d_node();                    //Default constructor
    d_node(const defend & from); //Constructor with defend object argument
    d_node(const d_node & from); //Copy constructor
    d_node * & go_next();        //Returns the pointer to the next node
    bool if_next() const;        //Checks if next pointer is pointing to NULL

  private:
    d_node * next; //Next pointer to the node
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
