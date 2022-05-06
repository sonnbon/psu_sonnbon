#include "Program1_Williams_vehicle.h"



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_node.h
// *****************************************************************************
// This file contains two classes of a larger hierarchy, which strongly focus
// on locational and nodal aspects of an object (stall and node). The purpose of 
// the stall class, being a class derived from address, is to manage more 
// specific location information (block face identification and stall number) as 
// well as behavioral information (whether it is empty and what type of stall it 
// is) while also inheritting address information. The purpose of this specific 
// management is to have a stall ultimately be occupied or unoccupied by a 
// vehicle of a certain type. If a stall is occupied or a vehicle's type does 
// not match a stall's parking type, then it cannot park there. The user will be 
// able to add, change, remove, find, occupy, exit, and display a stall object. 
//
// The purpose of the node class, being derived from stall, is to manage stall
// information and all of its inheritted data in order to contain it all within
// a data structure. The node class makes possible a data structure that can
// then be added to, removed from, traversed, and displayed. The user will be
// able to gain a better picture of where everything is and what is in it, data
// wise, with the help of the node class.
// *****************************************************************************



// - - - - - - - - - - C L A S S E S - - - - - - - - - -

//This stall class is derived from an address. It keeps track of an individual 
//parking stall for the purpose of being empty or occupied by a vehicle. It
//manages a block face identification number (block_id - a specific side of a
//city block with a given ID), a stall number (where the stall is on that block
//face), whether it is empty, what type of parking stall it is (2 Hour, 30 
//Minute, Loading Zone, etc.), and a vehicle object. It allows for the creation 
//of a parking stall as well as its manipulation, which includes changing the 
//stall type with a new stall type, removing a stall with the block ID and stall 
//number passed in (integer return type), and occupying (with a vehicle object) 
//or exiting a stall (integer return types). It allows for the user to find a 
//parking stall by street and type or by city and type, as well as to check if a 
//stall is empty (bool return types). All other member functions have a void 
//return type. This stall class also allows the user to display the stall 
//object's information.
class stall: public address
{
    public:
        stall();                                    //Default constructor
        stall(const stall & source);                //Copy constructor
        ~stall();                                   //Destructor
        void change_type(const char * stall_type);  //Change parking stall type
        int remove(int block_id, int stall_num);    //Remove specific stall
        bool find_by_street(char * street,          //Is it available on street
                            char * stall_type) 
                            const;
        bool find_by_city(char * city,              //Is it available in city
                          char * stall_type) 
                          const;
        bool is_empty() const;                      //Is object empty or full
        int occupy(const vehicle & to_occupy);      //Occupies parking stall
        int exit(const vehicle & to_exit);         //Free's a parking stall
        void input();                               //Adds stall to object
        void display() const;                       //Displays object's stall

    protected:
        int block_id;      //Block face ID number (location on a parking block)
        int stall_num;     //Stall number (location on a block face)
        bool empty;        //To be empty or occupied
        char * stall_type; //Stall type (2 Hour, 30 Minute, Loading Zone, etc.)
        vehicle my_vehicle; //Vehicle to occupy parking stall
};


 
//The node class is derived from the stall class. It keeps track of an 
//individual next pointer to the node class and contains all the data it
//inherits from the stall class and further hierarchical ancestors. It allows
//for the creation and manipulation of a node container, which will be used to
//add, remove, connect, traverse, and display in a data structure.
class node
{
    public:
        node();                                     //Default constructor
        node(const node & source);                  //Copy constructor
        node *& go_next();                          //Traverses to next node
        bool connect_next(node * connection);       //Connects next node
        bool remove();
        int display_block(int block_num);
        int display();


    protected:
        node * next; //Next pointer to node class
};
