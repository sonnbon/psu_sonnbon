#include "dlist.h"

//Remove every other node in the list
//Return the number of item removed
int list::remove_every_other()
{
    int count {0};

    if (!head)
        return 0;
    if (!head->next)
        return 0;
    count = remove_every_other(head->next);

    if (head->next)
        head->next->previous = head;

    return count;
}

int list::remove_every_other(node * & head)
{
    int count {0};

    if (!head)
        return 0;
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return 1;
    }
        
    node * hold {head->next};
    delete head;
    head = hold;
    head->previous = nullptr;
    ++count;

    count += remove_every_other(head->next);

    if (!head->next)
        tail = head;
    if (head->next)
        head->next->previous = head;
    return count;
}

