#include "dlist.h"

//Copy a DLL excluding the first and last item
//Return the number of nodes in the new list
//
//Wrapper
int list::copy_DLL(list & new_list)
{
    int count {0};

    if (!head) return 0;
    if (!head->next) return 0; //Only one!
    if (!head->next->next) return 0; //Only a first and last exist!

    if (!new_list.head)
        count = copy_DLL(new_list.head, head->next);
    
    if (new_list.head)
        new_list.head->previous = NULL;

    return count;
}

//Recursive call
int list::copy_DLL(node * & new_copy, node * original)
{
    int count {0};

    if(!original->next)
    {
        new_copy = NULL;
        return 0;
    }

    new_copy = new node;
    new_copy->data = original->data;
    ++count;

    count += copy_DLL(new_copy->next, original->next);

    if (new_copy->next)
        new_copy->next->previous = new_copy;

    return count;

}
