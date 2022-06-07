#include "cs162_list.h"


//These are the functions to implement for this lab
//Notice that they are not in a class this time!
//This means we need to pass in head as an argument
//since there is no "data member" shared


//Check to see if the desired item is in the list
//Return true if it is found
bool find(node * head, int match) 
{
    //Step 3 - Place your code here
    if (!head)
        return false;
    if (head->data == match)
        return true;
    return find(head->next, match);
}

//Remove all nodes in the list
int remove_all(node * & head) 
{
    int count = 0;

    //Step 4 - Place your code here
    if (!head)
        return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    node * local = head;
    delete head;
    head = local->next;
    count += remove_all(head) + 1;
    return count;
}

//Remove all nodes in the list after the recursive call
int remove_all_2nd(node *& head)
{
     //Step 5 - Place your code here


}

//Display every other item starting with the first
int display_every_other(node * head) 
{
      //Step 6 - Place your code here
   /* if (!head)
        return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    node * local = head->next;
    delete head;
    head = local;
    return remove_all(head->next) + 1;*/
}

