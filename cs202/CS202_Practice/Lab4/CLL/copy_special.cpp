#include "clist.h"

//Make a complete and duplicate copy of a CLL, excluding any multiples of 2
//Return the number of items copied
//
//Wrapper
int list::copy_special(list & new_list)
{
    int count {0};
    if (!rear) return 0;
    if (!new_list.rear)
        count = copy_special(new_list.rear, rear);
    return count;
}

//Recursive
int list::copy_special(node * & new_copy, node * original)
{
    int count {0};

    if (!new_copy)
    {
        if (original->data % 2 != 0)
        {
            new_copy = new node;
            new_copy->data = original->data;
            new_copy->next = new_copy;
            ++count;
            return count += copy_special(new_copy, original->next);
        }
        return count = copy_special(new_copy, original->next);
    }

    if (original == this->rear)
        return 0;

    if (original->data % 2 != 0)
    {
        node * temp = new node;
        temp->data = original->data;
        temp->next = new_copy->next;
        new_copy->next = temp;
        ++count;
        count += copy_special(new_copy->next, original->next);
    }
    else
        count = copy_special(new_copy, original->next);

    return count;
}
