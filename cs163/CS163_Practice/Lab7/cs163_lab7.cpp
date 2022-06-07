#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    table BnewT;
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    int count = BST.count();
    cout << "The number of nodes in the BST is: " << count << endl << endl;

    int sum = BST.sum();
    cout << "The sum of the nodes is: " << sum << endl << endl;

    int height = BST.height();
    cout << "The height of the BST is: " << height << endl << endl;

    int copy_num = BnewT.copy(BST);

    cout << "We copied this many nodes: " << copy_num << endl << endl;

    BnewT.display();

//    int removed = BST.remove_all();

//    if(!BST.display())
//        cerr << "The list is empty!\n\n";

//    cout << "This many nodes were deleted: " << removed << endl << endl;

    return 0;
}
