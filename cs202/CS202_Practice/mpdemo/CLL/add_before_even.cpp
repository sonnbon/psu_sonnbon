#include "clist.h"

//Add node before even nodes
//REturn number of added nodes

int list::add_before_even()
{
    if (!rear)
        return 0;
    return add_before_even(rear->next);
}

int list::add_before_even(node * & rear)
{
    int count {0};

    if (rear == this->rear)
        return 0;

    if (rear->next->data % 2 == 0)
    {
        node * temp = new node;
        temp->data = 99;
        temp->next = rear->next;
        rear->next = temp;
        ++count;
        count += add_before_even(rear->next->next);
    }
    else
      count += add_before_even(rear->next);

    return count;
}
