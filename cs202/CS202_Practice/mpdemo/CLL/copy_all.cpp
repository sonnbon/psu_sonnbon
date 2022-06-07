#include "clist.h"

//Copy all
//REturn number copied
int list::copy_all(const list & from)
{
    if (!from.rear)
        rear = nullptr;
    rear = new node;
    rear->data = from.rear->data;
    rear->next = rear;

    return 1 + copy_all(rear, from.rear, from.rear->next);
}

int list::copy_all(node * & dest, node * src_rear, node * src_current)
{
    if (src_current == src_rear)
        return 0;

    node * temp = new node;
    temp->data = src_current->data;
    temp->next = dest->next;
    dest->next = temp;
    
    return 1 + copy_all(dest->next, src_rear, src_current->next);
}

int list::copy_to(list & new_list)
{
    if (!rear)
        new_list.rear = nullptr;

    new_list.rear = new node;
    new_list.rear->data = rear->data;
    new_list.rear->next = new_list.rear;

    return 1 + copy_to(rear->next, new_list.rear);
}

int list::copy_to(node * rear, node * & dest)
{
    if (rear == this->rear)
        return 0;

    node * temp = new node;
    temp->data = rear->data;
    temp->next = dest->next;
    dest->next = temp;

    return 1 + copy_to(rear->next, dest->next);
}
