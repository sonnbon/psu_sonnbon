#include "list.h"

int list::remove_duplicate_iter()
{
    if (!head) return 0;
    if (!head->next) return 0; //none removed if one item

    int match = head->data;
    int removed = 0;
    int count = 0;




    return removed;
}
