#include <iostream>
#include <cctype>
#include <cstring>

//Connor Williams - Lecture 3
//This file manages the code for a SINGLE todo item

class todo_item
{
    public:
        todo_item();
       ~todo_item();
       int set(char * name, char * desc, int priority);
       int set(const todo_item & to_add);
       bool is_matching_priority(int to_check) const;
       int display() const;

    private:
        char * name;
        char * description;
        int priority;
};
