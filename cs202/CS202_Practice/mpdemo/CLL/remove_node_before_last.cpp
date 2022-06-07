#include "clist.h"

//Remove the node before the last node
//Return the removed data
//Wrapper function
int list::remove_node_before_last()
{
    if (!rear) return 0;
    if (rear->next == rear) //one item list
        return 0;
    return remove_node_before_last(rear->next); //start at the front
}

//Recursive version
int list::remove_node_before_last(node * & rear)
{
    //Base case
    if (rear->next == this->rear)
    {
        int hold = rear->data;
        delete rear;
        rear = this->rear;
        return hold;
    }
    return remove_node_before_last(rear->next);
}
