#include "list.h"

int list::remove_last_largest()
{
    if (!head) return 0;

    int largest = head->data;

    if (!head->next)
    {
        delete head;
        head = NULL;
        return largest;
    }

    if (!remove_last_largest(head, largest))
        return 0;
    return largest;
}

bool list::remove_last_largest(node * & head, int & largest)
{
    if (!head) return false;

    //Find the largest item
    if (head->data > largest)
        largest = head->data;
    bool removed = remove_last_largest(head->next, largest);

    if (!removed && head->data == largest) //AT the last largest value
    {
        node * hold = head->next;
        delete head;
        head = hold;
        if (!head->next)
            tail = head;
        return true;
    }
    return removed;
}
