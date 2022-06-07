#include "table.h"

//Connor Williams
//CS163

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    int data = 34;
    //int length_of_travel = add_bst(root, data);

    //cout << "The length travelled to insert 34 is: " << length_of_travel << endl << endl;

    //int count = display_inorder(root);
    //cout << endl;
    //cout << "OUR COUNT IS: " << count << endl << endl;

    remove_after_isempty(root, data);

    display(root);
    destroy_all(root);

    return 0;
}
