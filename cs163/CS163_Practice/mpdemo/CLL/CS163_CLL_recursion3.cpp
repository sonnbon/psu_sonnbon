#include "clist.h"

//CIRCULAR LINKED LIST
//remove all matching items
//return thenumber of removed items

//Wrapper function to handle the empty list situation
int remove_match(node * & rear, int match)
{
    if (!rear) return 0;

    int count = 0;

    //One node that is a match
    if (rear->next == rear && rear->data == match) //one item list
    {
        delete rear;
        ++count;
        rear = NULL;
    }
    else
      count = remove_CLL_match(rear->next, rear, match);
    return count;
}

int remove_CLL_match(node * & head, node * real_rear, int match)
{
    if (head->next == real_rear) //Is head at the end of the list now
    {
        //Todo = 2nd to the last needs to be checked
        if (head->next->data == match)
        {
            node * hold = head->next->next;
            delete head->next;
            real_rear = hold;
            return 1;
        }
    }
    int count = 0;
    if (head->data == match)
    {
        ++count;
        node * hold = head->next;
        delete head;
        head = temp;
        count += remove_match(head, match);
    }
    else
      count += remove_match(head->next, match);
    return count;
}


