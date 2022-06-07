#include "dlist.h"

//Copy the data structure
//and return the number of items that are even
//
//
//
//If this was a LLL - how would I copy it?
//One public member function
int list::copy_list(list & source)
{
    int count {0};

    if (!head)
        return 0;

    count = copy_list(head, source.head, source.tail);

    source.head->previous = nullptr;

    return count;
}


//One private member function
int list::copy_list(node * head, node * & dest, node * & d_tail)
{
    int count {0};

    if (!head)
    {
        dest = nullptr;
        return 0;
    }

    dest = new node;
    dest->data = head->data;
    ++count;

    count += copy_list(head->next, dest->next, d_tail);

    if (!dest->next)
        d_tail = dest;
    if (dest->next)
        dest->next->previous = dest;

    return count;
}
