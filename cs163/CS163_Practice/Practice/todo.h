#include <iostream>
#include <cctype>
#include <cstring>

//Connor Williams, CS163, to make a todo list ADT
//This file manages the structs and classes for a todo list abstract data type

struct todo_item
{
    char * name;
    char * description;
    int priority;
};

struct node
{
    todo_item data;
    node * next;
};

//Abstract data type - to manage a collection of the data
class todo_list
{
    public:  //This is what the interface to the ADT includes
        todo_list();   //constructor
        ~todo_list();  //destructor
        int insert_todo(const todo_item & to_add);
        int display_list() const; //constant member function because we're not
                                  //modifying anything
        int display_priority(int matching_priority) const; //display only 
                                                           //matching priority
                                                           //items
        int remove_match(char * name_to_remove);
    private:
        node * head; //head pointer to node structure
};
