#include "clist.h"

//Add node last unless the data already exists in the list
//REturns a success or failure
int list::add_node_last(int num)
{
    if (!rear)
    {
        rear = new node;
        rear->data = num;
        rear->next = rear;
        return 1;
    }

    return add_node_last(rear->next, num);
}

int list::add_node_last(node * & rear, int num)
{
    if (rear->data == num)
        return 0;

    if (rear == this->rear)
    {
        node * temp = new node;
        temp->data = num;
        temp->next = rear->next;
        rear->next = temp;
        this->rear = temp;
        return 1;
    }

    return add_node_last(rear->next, num);
}

