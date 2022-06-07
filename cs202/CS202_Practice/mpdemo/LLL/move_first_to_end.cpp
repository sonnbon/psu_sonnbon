#include "list.h"

int list::move_first_to_end_iter()
{
    if (!head) return 0;

    int first = head->data;

    if (!head->next)
        return first;
    
    node * temp = new node;
    temp->data = first;
    temp->next = NULL;

    node * hold = head->next;
    delete head;
    head = hold;

    int sum = first;

    node * current = head;

    while (current->next)
    {
        sum += current->data;
        current = current->next;
    }
    
    sum += current->data;

    current->next = temp;


    return sum;
}

int list::move_first_to_end_recur()
{
    if (!head) return 0;

    int first = head->data;

    if (!head->next)
        return first;

    node * temp = head->next;
    delete head;
    head = temp;

    return first += move_first_to_end_recur(head, first);
}

int list::move_first_to_end_recur(node * & head, int first)
{
    if (!head) return 0;

    int sum = 0;

    if (!head->next)
    {
        sum = head->data;

        node * temp = new node;
        temp->data = first;
        temp->next = NULL;
        head->next = temp;

        return sum;
    }

    sum = head->data;

    return sum += move_first_to_end_recur(head->next, first);
}

void list::display_all()
{
    cout << "Below is my display function" << endl;
    if (!head)
        cout << "The list is empty" << endl << endl;
    else if (!head->next)
        cout << head->data;
    else
    {
        node * current = head;
        while (current->next)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << current->data << endl;
    }
}










