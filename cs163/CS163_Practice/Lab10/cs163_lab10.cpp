#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees;
    table tree_copy;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    trees.display_largest();
    int root_duplicate = trees.count_root();
    cout << "The root's data showed up " << root_duplicate << " time(s)" << endl << endl;

    tree_copy.copy(trees);
    tree_copy.display();


    return 0;
}
