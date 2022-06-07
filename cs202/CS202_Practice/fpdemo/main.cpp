#include "table.h"

int main()
{
    table object;
    table new_list;
    //l_node * head = nullptr;

    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    if (object.find_root())
        cout << "Yes the root has duplicates." << endl;

    cout << object.duplicate_largest() << " is the largest item in the tree." << endl;

    //double avg = object.copy_get_avg(new_list);
    //cout << "Average of the even nodes is: " << avg << endl << endl;

    //int count = object.copy_to_LLL(head);
    //cout << count << " items copied to LLL." << endl << endl;

    int height = object.get_height();
    cout << "The height of the tree is " << height << endl << endl;

    if (object.add_if_new(23))
        cout << "New item added." << endl << endl;
    else
        cout << "New item not added." << endl << endl;

    cout << object.remove_largest() << " is the largest item and was removed." << endl << endl;

    cout << object.find_IOS() << " is the IOS of the tree, if not 0." << endl << endl;

    int display = object.display_once();
    cout << endl;
    cout << display << " unique items displayed." << endl << endl;

    int new_count = object.copy_leaves(new_list);
    cout << new_count << " leaves copied." << endl << endl;

    new_count = object.delete_leaves();
    cout << new_count << " leaves deleted." << endl << endl;


    object.display();	//displays again after!

    cout << "NEW LIST" << endl;
    new_list.display();

    return 0;
}
