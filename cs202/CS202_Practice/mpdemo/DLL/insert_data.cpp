#include "dlist.h"

//Wrapper. Insert data if it's greater than previous and less than next, other wise don't add it.
bool list::insert_data(int num)
{
    if (!head)
        return false;
    if (!head->next)
        return false;
    return insert_data(head, num);
}


//Recursive
bool list::insert_data(node * & head, int num)
{
    if (!head)
        return false;
    if (!head->next)
        return false;
    if (head->previous)
    {
        if (num > head->data && num < head->next->data)
        {
            node * temp = new node;
            node * hold = head->next;
            temp->data = num;
            temp->next = hold;
            temp->previous = head;
            hold->previous = temp;
            head->next = temp;
            return true;
        }
    }
    return insert_data(head->next, num);
}


