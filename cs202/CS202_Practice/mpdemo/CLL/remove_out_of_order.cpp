#include "clist.h"

int list::remove_out_of_order()
{
    if (!rear)
        return 0;
    if (rear == rear->next)
        return 0;
    return remove_out_of_order(rear->next);
}

int list::remove_out_of_order(node * & rear)
{
    int last_num {0};
    int count{0};
    int removed {0};

    if (rear == this->rear)
    {
        last_num = rear->data;
        return last_num;
    }

    last_num = remove_out_of_order(rear->next);

    if (last_num < rear->data)
    {
      if (rear->next == this->rear)
      {
        node * hold = this->rear->next;
        this->rear = rear;
        delete rear->next;
        rear->next = hold;
      }
      else
      {
        node * hold = rear->next;
        hold = hold->next;
        delete rear->next;
        rear->next = hold;
      }
      
      ++removed;
    }

    last_num = rear->data;

    count += removed;

    return last_num;
}


