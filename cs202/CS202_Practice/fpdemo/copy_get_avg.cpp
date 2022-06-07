#include "table.h"

//Copy all and get average of even items
//return average of even items
double table::copy_get_avg(table & new_list)
{
    int count {0};

    if (!root)
    {
        new_list.root = nullptr;
        return 0;
    }

    return copy_get_avg(new_list.root, root, count);
}


double table::copy_get_avg(node * & dest, node * src, int & count)
{
    double avg {0};
    int sum {0};

    if (!src)
    {
        dest = nullptr;
        return 0;
    }

    dest = new node;
    dest->data = src->data;

    if (src->data % 2 == 0)
    {
        ++count;
        sum = src->data;
    }

    sum += copy_get_avg(dest->left, src->left, count);
    sum += copy_get_avg(dest->right, src->right, count);

    if (src == this->root)
        avg = sum / count;
    else
        avg = sum;

    return avg;
}
        

