#include "cs162_list.h"

//These are the functions you will be writing
//Everything else has already been written for you!

//Constructor
list::list()
{
     //Step 3 - Implement the constructor here
     head = NULL;
}


//Display all items in a linear linked list
void list::display_all()
{
     //Step 5 - Implement the display_all function here
     node * current = head;
     if (!head)
         cout << "You're empty!" << endl;
     else
     {
       while (current->next != NULL)
       {
           cout << current->data << ' ';
           current = current->next;
       }
       cout << current->data << endl;
     }
}


//Count the number of times the first node's data appears
//in the list, and return that count.
int list::count_first()
{
     //Step 6 - Implement the count_first here
     //(remember to return the count!
     int count = 0;

     node * current = head;
     if (!head)
         cout << "You're empty!" << endl;
     else
     {
         while (current->next != NULL)
         {
             if (current->data == head->data)
                 ++count;
             current = current->next;
         }
         if (current->data == head->data)
             ++count;
     }
     return count;
}

//Display the LAST node's data
void list::display_last()
{
    //Step 7 - Place your code here
    node * current = head;
    if (!head)
        cout << "You're empty!" << endl;
    else
    {
        while (current->next)
            current = current->next;
        cout << "The last node's data is " << current->data 
             << endl << endl;
    }
}

//Return true if the last node's data appears
//in the list more than once.
bool list::find_last()
{
    //Step 8 - Place your code here
    bool more_than_once = false;
    int count = 0;
    node * current = head;
    node * last = head;

    if (!head)
        cout << "You're empty!" << endl;
    else
    {
        while (last->next)
            last = last->next;
        while (current->next)
        {
            if (current->data == last->data)
              ++count;
            current = current->next;
        }
        if (count > 0)
        {
          more_than_once = true;
        }
    }
    return more_than_once;
}
