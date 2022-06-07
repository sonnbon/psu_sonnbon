#include "list.h"

int list::display_unique_iter()
{
    if (!head) return 0;
    if (!head->next)
    {
        cout << head->data << endl;
        return 1;
    }
    node * current = head;
    node * overall = head;
    int match_data = head->data;
    int count = 0;
    int displayed = 0;

    while (overall->next) 
    {
        while (current->next)
        {
            if (match_data == current->next->data)
                ++count;
            current = current->next;
        }
        if (count == 0)
        {
            cout << match_data << " ";
            ++displayed;
        }
        overall = overall->next;
        current = overall;
        match_data = overall->data;
        count = 0;
    }

    cout << overall->data << endl;
    ++displayed;

    return displayed;
}

int list::display_unique_recur()
{
    if (!head) return 0;
    if (!head->next)
    {
        cout << head->data << endl;
        return 1;
    }

    return display_unique_recur(head);
}

int list::display_unique_recur(node * head)
{
    if (!head) return 0;
    int displayed = 0;

    if (!head->next)
    {
        cout << head->data << endl;
        ++displayed;
        return displayed;
    }

    int matches = display_unique_recur(head->next, head->data);

    if (matches == 0)
    {
        cout << head->data << " ";
        ++displayed;
    }
    return displayed += display_unique_recur(head->next);
}

int list::display_unique_recur(node * head, int match)
{
    if (!head) return 0;

    int count = 0;

    if (match == head->data)
        ++count;
    return count += display_unique_recur(head->next, match);
}

