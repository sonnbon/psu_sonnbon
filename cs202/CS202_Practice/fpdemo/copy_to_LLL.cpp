#include "table.h"

//Copy inorder to a LLL
//return number of items copied
int table::copy_to_LLL(l_node * & head)
{
    if (!root)
    {
        head = nullptr;
        return 0;
    }

    return copy_to_LLL(head, root);
}


int table::copy_to_LLL(l_node * & head, node * root)
{
    int count{0};

    if (!root)
        return 0;

    count += copy_to_LLL(head, root->right);

    l_node * hold = head;
    head = new l_node;
    head->data = root->data;
    head->next = hold;
    ++count;

    count += copy_to_LLL(head, root->left);

    return count;
}
