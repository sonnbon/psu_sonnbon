#include "clist.h"

//Display all but the last node.
//Return the sum of the displayed.
//
int list::display_all_but_last()
{
    int sum {0};

    if (!rear)
        return 0;
    sum = display_all_but_last(rear->next);

    cout << endl << endl;

    return sum;
}

int list::display_all_but_last(node * rear)
{
    int sum {0};

    if (rear == this->rear)
        return 0;

    cout << rear->data << " <--> ";
    sum = rear->data;

    sum += display_all_but_last(rear->next);
    return sum;
}
