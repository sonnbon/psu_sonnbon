#include "table.h"

//display data that only exists once
//return count

int table::display_once()
{
    if (!root) return 0;

    return display_once(root);
}


int table::display_once(node * root)
{
    int count {0};

    if (!root) return 0;

    if (root->right && find_IOS(root->right) != root->data)
    {
        ++count;
        cout << root->data << ' ';
    }

    count += display_once(root->left);
    count += display_once(root->right);

    return count;
}
