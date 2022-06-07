#include "list.h"

//Connor Williams
//CS162 - prerecorded lecture on creating LLL and summing numbers
//Sum the values of the first and the last node in the LLL and return
//the sum
//
//Special cases:
//  - empty (nothing to do)
//  - 1 item (just return the first items's data)
//  - many items (traverse until current->next is NULL and then sum the first
//    and last)

int sum_first_last(node * head)
{
    //Empty list
    if (NULL == head)   //if (!head)
        return 0;
    if (NULL == head->next)  //1 item only
        return head->data;
    //Traverse to the end
    node * current = head;
    while (current->next != NULL)
        current = current->next;
    return head->data + current->data;
}

