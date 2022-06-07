#include "clist.h"

//Remove any node that has the same data as the last node, not including the last node
//REturn whether nodes were deleted
bool list::remove_same_last()
{
    if (!rear)
        return false;
    if (rear == rear->next)
        return false;
    return remove_same_last(rear->next, rear->data);
}

bool list::remove_same_last(node * & rear, int last)
{
    bool removed {false};

    if (rear == this->rear)
        return false;
    if (rear->data == last)
    {
        node * hold = rear->next;
        delete rear;
        rear = hold;
        removed = true;
        removed += remove_same_last(rear, last);
    }
    else
        removed += remove_same_last(rear->next, last);

    return removed;
}


