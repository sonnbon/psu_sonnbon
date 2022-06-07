#include "list.h"

//Determine if two LLLs contain the same values, only traverse as far as necceary.
//
//Wrapper
bool list::same_contents(list & second_list)
{
    if (!head || !second_list.head)
        return false;

    return same_contents(head, second_list.head);
}

//Recursive call
bool list::same_contents(node * head1, node * head2)
{
    bool is_same = false;

    if (!head1 || !head2)
        return false;

    if (head1->data != head2->data)
        return false; 

    is_same = true;

    return is_same += same_contents(head1->next, head2->next);
}
