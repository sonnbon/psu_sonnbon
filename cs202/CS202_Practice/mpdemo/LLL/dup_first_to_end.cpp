#include "list.h"

int list::dup_first_to_end_iter()
{
    if (!head) return 0;
    if (!head->next)
        return head->data;

    int sum = 0;

    node * temp = new node;
    temp->data = head->data;
    temp->next = NULL;

    node * current = head->next;

    while (current->next)
        current = current->next;

    current->next = temp;

    sum = current->data + temp->data;

    return sum;
}

int list::dup_first_to_end_recur()
{
    if (!head) return 0;

    if (!head->next)
        return head->data;

    return dup_first_to_end_recur(head->next, head->data);
}

int list::dup_first_to_end_recur(node * & head, int first)
{
    if (!head) return 0;

    int sum = first;

    if (!head->next)
    {
        node * temp = new node;
        temp->data = first;
        temp->next = NULL;

        head->next = temp;
        sum += head->data;
        return sum;
    }
    return dup_first_to_end_recur(head->next, first);
}

