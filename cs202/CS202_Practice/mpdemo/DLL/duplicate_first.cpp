#include "dlist.h"

//Copy first and add to end. Return sum of first and last.
int list::duplicate_first()
{
    int first {0};

    if (!head)
        return 0;

    first = head->data;

    if (!head->next)
    {
        node * temp = new node;
        temp->data = first;
        temp->next = nullptr;
        temp->previous = head;
        head->next = temp;
        return head->data + temp->data;
    }

    return first + duplicate_first(head->next, first);
}


//Recursive
int list::duplicate_first(node * & head, int first)
{
    int sum {0};

    if (!head)
    {
        node * temp = new node;
        temp->data = first;
        temp->next = nullptr;
        head = tail = temp;
        return first;
    }

    sum += duplicate_first(head->next, first);

    if (!head->next->next)
        head->next->previous = head;

    return sum;
}

    
