#include "list.h"

//Removing the first and the last
//Return the sum of the first and last
int remove_first_last(node * & head)
{
    //Wrapper function doing NON repetitive work
    int hold = 0;
    if (!head) return 0;
    hold = head->data; //I will need to sum this together later on
    node * to_delete = head;
    head = head->next; //head now points to second node
    delete to_delete;  //the first node is now deleted
    hold += remove_last(head);
    return hold;
}

//Recursive function to remove the last node
int remove_last(node * & head)
{
    if (!head) return 0;
    if (!head->next) //I'm at the last node
    {
        int hold = head->data;
        delete head;
        head = NULL;
        return hold;
    }
    return remove_last(head->next);
}
