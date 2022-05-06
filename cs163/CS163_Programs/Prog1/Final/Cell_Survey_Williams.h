#include <iostream>
#include <cctype>
#include <cstring>

// ****************************************************************************
// Author: Connor Williams
// Date: July 9, 2021
// Course: CS163 Data Structures
// Assignment: Program 1
// Filename: Cell_Survey_Williams.h
// ****************************************************************************
// This file contains four structure data types, two of which are nodes for 
// two Linear Linked Lists, and one class data type. The two node structures,
// "app_node" and "use_node" allow for a Linear Linked List of cellphone
// applications, in which each application has a Linear Linked List of user's
// usage characteristics, respectively. This data type is used to specifically
// work with the Linear Linked List data structure. The other two structures, 
// "cell_app" and "cell_usage", hold all the necessary information for a 
// cellphone application and its usage characteristics, respectively. This data
// type is used to easily be passed by reference as an argument in certain
// class member functions. The class "cell_survey" is the Abstract Data Type to
// be used to allow a user to add, remove and display cellphone application
// information. It will also allow for inserting user usage characteristics for
// each application. All member functions (not including the constructor or
// destructor) within the Abstract Data Type return an integer value to 
// represent success or failure of an operation to the client. Arguments that
// will be passed in member functions include both the "cell_app" and 
// "cell_usage" structure data types, and variables of character data types for
// searching purposes.
// ****************************************************************************



// - - - C O N S T A N T S - - -
//
const int SIZE = 101;  //Temporary size for any array before dynamic allocation
// ----------------------------------------------------------------------------



// - - - S T R U C T U R E S - - -
//
// This structure holds three pointer members to the character data type,
// "name", "type", and "description". This will hold information about a 
// cellphone application.
struct cell_app
{
    char * name;         //Pointer to a char for an application name
    char * type;         //Pointer to a char for an application type
    char * description;  //Pointer to a char for an application description
};



// This structure holds two pointer members to the character data type, 
// "user_name" and "use_reason", and a "frequency" variable of data type float.
// This will hold information about user cellphone application usage
// characteristics, such as why a user uses and application and for how long.
struct cell_usage
{
    char * user_name;  //Pointer to a char for a user's name who is being
                       //surveyed 
    char * use_reason; //Pointer to a char for a user's reason why they use a
                       //specific application
    float frequency;   //Float variable to be hours of usage per user per day
};



// This node structure holds the object "use_data" of the "cell_usage"
// structure data type and a next pointer to the "use_node" (itself) structure
// data type. This will hold a user's usage characteristics in a node and point
// to the next node.
struct use_node
{
    cell_usage use_data; //Cellphone usage structure data type object to hold
                         //information on one user's usage survey
    use_node * next_use; //Next pointer to the usage node's (itself) Linear 
                         //Linked List
};



// This node structure holds the object "app_data" of the "cell_app" structure
// data type, a head pointer to the "use_node" structure data type, and a next
// pointer to the "app_node" (itself) structure data type. This will hold a
// cellphone application's information in a node, point to the next node, and
// point to the beginng of a Linear Linked List hold information about user
// usage characteristics.
struct app_node
{
    cell_app app_data;   //Cellphone application structure data type object to
                         //hold information on one application
    use_node * use_head; //Head pointer to the beginning of an application's
                         //Linear Linked List of multiple user's usage
			 //information
    app_node * next_app; //Next pointer to the application node's (itself) 
                         //Linear Linked List
};
// ----------------------------------------------------------------------------



// - - - P R O T O T Y P E S - - -
//
bool again(char response); //Checks is user wants to do something again
// ----------------------------------------------------------------------------



// - - - C L A S S E S - - -
//
// This class holds member functions that will allow the client to manipulate
// a Linear Linked List of cellphone applications that also points to a Linear
// Linked List of user usage characteristics. These manipulations include 
// adding a new cellphone application, displaying all cellphone applications, 
// inserting a user's usage characteristics for a specific cellphone
// application, displaying usage characteristics of all cellphone applications
// of a particular type, and removing a cellphone application from the list.
// All member functions (not including the constructor and destructor) return
// an integer to the client to represent success or failure of an operation.
// This class has one data member, which is a head pointer to the "app_node"
// structure data type.
class cell_survey
{
    public:
      cell_survey();                            //Constructor initializes data
      ~cell_survey();                           //Destructor deallocates or
                                                //resets data to NULL or 0.
      int set_app(char name[], char type[],     //Allocates memory for one
		  char description[],           //application
		  cell_app & an_app);
      int add_new(const cell_app & app);        //Add new cellphone application
      int display_all() const;                  //Display all applications
      int set_use(char user_name[],             //Allocated memory for one
		  char use_reason[],            //usage survey
		  float frequency,
		  cell_usage & use);
      int insert_usage(char name_match[],       //Insert usage information for
		       const cell_usage & use); //an application
      int display_usage(char type_match[]) const; //Displays Linear Linked List
                                                  //of frequency usage
						  //information for each
						  //application of a particular
						  //type
      int remove_app(char name_match[]);        //Remove application searched
                                                //by name
      int remove_all();                         //Removes everything from the
                                                //list
    private:
      int add_new(app_node * & app_head,        //Add new cellphone application
		  const cell_app & app);        //recursively
      int insert_usage(app_node * & app_head,   //Insert usage information for
		       char name_match[],       //an application recursively
		       const cell_usage & use);
      int remove_app(app_node * & app_head,     //Remove application searched
		     char name_match[]);        //by name recursively
      app_node * app_head;                      //Head pointer to Linear Linked
                                                //List of applications
};
// ----------------------------------------------------------------------------

