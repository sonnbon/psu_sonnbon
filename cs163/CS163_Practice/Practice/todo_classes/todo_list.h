#include "todo_item.h"

//Connor Williams, CS163, to make a todo list ADT
//This file manages the collection of items in a list for our ADT
//called a todo_list

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
        //Call set function in the todo_item class with all three arguments
        int insert_todo(char * name, char * description, int priority);

        //Call set function with one todo_item as an argument
        int insert_todo(const todo_item & to_add);

        //Call display function for each node's todo_item
        int display_list() const; //constant member function because we're not
                                  //modifying anything

        //Call compare_priority? is_it match passing in a priority number as an
        //argument
        int display_priority(int matching_priority) const; //display only 
                                                           //matching priority
                                                           //items
        //Call the compare_priority or is_it_match from the todo_item class
        int remove_match(char * name_to_remove);
    private:
        node * head; //head pointer to node structure
};
