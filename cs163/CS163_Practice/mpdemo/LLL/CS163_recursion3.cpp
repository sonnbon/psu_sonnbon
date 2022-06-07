#include "list.h"

//remove all matching items
//return thenumber of removed items

int remove_match(node * & head, int match)
{
    if (!head) return 0;

    int count = 0;
    if (head->data == match)
    {
        ++count;
        node * hold = head->next;
        delete head;
        head = hold;
        count += remove_match(head, match);
    }
    else
      count += remove_match(head->next, match);
    return count;
}


