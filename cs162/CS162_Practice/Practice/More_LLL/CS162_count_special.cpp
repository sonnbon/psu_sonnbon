#include "list.h"

//Connor Williams
//CS162 - prerecorded lecture on LLL and adding number of values
//Count the number of even valued data items in a LLL and return that count

int count_even(node * head)
{
    //Empty list situation
    if (NULL == head)  //if (!head)
        return 0;

    //Traverse all the way through, counting as I go
    int counter = 0;
    node * current = head;
    while (NULL != current) //include the last node in my count
    {
        if (current->data % 2 == 0) //even value
            ++counter;
        current = current->next;
    }
    return counter;
}
