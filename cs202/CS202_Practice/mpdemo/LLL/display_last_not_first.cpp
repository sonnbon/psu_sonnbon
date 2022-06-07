#include "list.h"

int list::display_last_not_first()
{
    if (!head) return 0;

    if (!head->next) return 0; //if one item, then last is the same as first

    node * current = head->next;

    while (current->next)
        current = current->next;

    if (head->data != current->data)
        return current->data;
    return 0;
}

int list::display_last_not_recur()
{
    if (!head) return 0;
    if (!head->next) return 0; //if one item, then last is the same as first

    return display_last_not_recur(head->next, head->data);
}

int list::display_last_not_recur(node * head, int to_match)
{
    if (!head) return 0;
    if (!head->next)
    {
        if (head->data != to_match)
            return head->data;
        return 0;
    }
    return display_last_not_recur(head->next, to_match);
}
