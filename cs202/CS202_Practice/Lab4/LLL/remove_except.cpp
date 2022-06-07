#include "list.h"

//Remove all but the last two items in a LLL
//Return the number of items removed
//
//Wrapper
int list::remove_except()
{
    if (!head) return 0;
    if (!head->next)
        return 0; //There is only one node
    if (!head->next->next)
        return 0; //There are only two nodes

    return remove_except(head);
}

int list::remove_except(node * & head)
{
    if (!head->next->next)
        return 0;

    node * hold {head->next};
    delete head;
    head = hold;

    return 1 + remove_except(head); //Already traversed up to delete
}
