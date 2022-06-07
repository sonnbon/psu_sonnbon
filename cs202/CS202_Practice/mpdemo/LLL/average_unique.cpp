#include "list.h"

float list::average_unique_iter()
{
    if (!head) return 0;
    if (!head->next)
    {
        return head->data;
    }
    node * current = head;
    node * overall = head;
    int match_data = head->data;
    int count = 0;
    int sum = 0;
    int displayed = 0;
    float average = 0.0;

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
            ++displayed;
            sum += match_data;
        }
        overall = overall->next;
        current = overall;
        match_data = overall->data;
        count = 0;
    }

    ++displayed;
    sum += overall->data;

    average = sum / displayed;

    return average;
}

int list::count_unique_recur()
{
    if (!head) return 0;
    if (!head->next)
        return 1;

    return count_unique_recur(head);
}

int list::count_unique_recur(node * head)
{
    if (!head) return 0;
    int displayed = 0;

    if (!head->next)
    {
        ++displayed;
        return displayed;
    }

    int matches = count_unique_recur(head->next, head->data);

    if (matches == 0)
        ++displayed;

    return displayed += count_unique_recur(head->next);
}

int list::count_unique_recur(node * head, int match)
{
    if (!head) return 0;

    int count = 0;

    if (match == head->data)
        ++count;
    return count += display_unique_recur(head->next, match);
}

int list::sum_unique_recur()
{
    if (!head) return 0;
    if (!head->next) return head->data;

    return sum_unique_recur(head);
}

int list::sum_unique_recur(node * head)
{
    if (!head) return 0;

    int sum = 0;

    if (!head->next)
    {
        sum = head->data;
        return sum;
    }

    int matches = count_unique_recur(head->next, head->data);

    if (matches == 0)
        sum = head->data;
    return sum += sum_unique_recur(head->next);
}

float list::average_unique_recur()
{
    if (!head) return 0;
    if (!head->next) return head->data;
    float average = 0.0;

    int count = count_unique_recur();
    int sum = sum_unique_recur();

    average = sum / count;

    return average;
}

