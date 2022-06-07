#include "clist.h"

bool list::remove_last()
{
    if (!rear)
        return false;
    if (rear == rear->next)
    {
        delete rear;
        rear = nullptr;
        return true;
    }
    return remove_last(rear->next, rear->next);
}

bool list::remove_last(node * & rear, node * front)
{
    bool removed {false};

    if (rear->next == this->rear)
    {
        node * hold = front;
        delete rear->next;
        rear->next = hold;
        this->rear = rear;
        removed = true;
        return removed;
    }

    removed = remove_last(rear->next, front);
    return removed;
}

