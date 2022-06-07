#include "table.h"

//Connor Williams
//CS163

int main()
{
    node * root = NULL;
    //node * copy = NULL;
    //node * copy2 = NULL;

    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    //int data = 34;
    //int length_of_travel = add_bst(root, data);

    //cout << "The length travelled to insert 34 is: " << length_of_travel << endl << endl;

    //int count = display_inorder(root);
    //cout << endl;
    //cout << "OUR COUNT IS: " << count << endl << endl;

    //remove_after_isempty(root, data);

    //float average = display_largest_and_smallest(root);
    //cout << "The average of height between the largest and smallest is: " << average << endl << endl;
/*    int count = count_all(root);
    cout << "There are " << count << " number of nodes" << endl << endl;

    count = count_even(root);
    cout << "There are " << count << " even number of nodes" << endl << endl;

    count = count_largest_left(root);
    cout << "There are " << count << " number of nodes in the largest left subtree" << endl << endl;

    int sum = sum_root_largest(root);
    cout << "The sum of the root and the largest node is: " << sum << endl << endl;
    
    count = display_sorted(root);
    cout << endl << count << " items." << endl << endl;

    count = count_larger(root);
    cout << "There are " << count << " items larger than the root." << endl << endl;

    if (!display_largest_smallest(root))
        cerr << "The list is empty...\n\n";

    if (largest_equal_root(root))
        cout << "They match" << endl << endl;
    else
        cout << "Not a match" << endl << endl;

    if (!goto_root_IOS(root))
        cerr << "No IOS in tree...\n\n";

    count = count_match(root, 32);
    cout << "There are " << count << " items equal to 32." << endl << endl;

    //count = remove_leaves(root);
    //cout << count << " leaves were removed" << endl << endl;

    //if (!remove_largest(root))
    //    cerr << "List is empty...\n\n";
    
    //if (!remove_smallest_and_largest(root))
    //    cerr << "Smallest and largest were not removed...\n\n";

    float average = average_all(root);
    cout << "The average of all the data is: " << average << endl << endl;

    average = average_even(root);
    cout << "The average of all the even data is: " << average << endl << endl;

    if (!copy_tree(copy, root))
        cerr << "Copy failed...\n\n";

//    remove_all(copy);
    if (!insert_unique(copy, 32))
        cerr << "32 is already in the tree, NOT ADDED...\n\n";

    count = count_leaves(copy);
    cout << "There are " << count << " leaves." << endl << endl;

    count = get_height(copy);
    cout << "The height it: " << count << endl << endl;

    display(copy);

    //if (!copy_even(copy2, root))
    //    cerr << "Copy failed...\n\n";

    //display(copy2);

    insert_num(root, 99);
*/
    if (!display_largest_two(root))
        cerr << "Empty list...\n\n";

    return 0;
}
