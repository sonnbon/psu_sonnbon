#include "table.h"
using namespace std;

int main()
{
    table BST;	
    table BST2;
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    int count = BST.count();
    cout << count << " nodes not equal to root." << endl << endl;

    count = BST.count_right_subtree();
    cout << count << " nodes in smallest items right subtree." << endl << endl;

    int largest = BST.remove_largest();
    cout << "Largest node removed: " << largest << endl << endl;

    int avg = BST.sum();
    cout << "Average of nodes that are multiples of 3 or 5: " << avg << endl << endl;

    count = BST.copy(BST2);
    cout << count << " nodes copied to new tree." << endl << endl;


    BST.display(0);
    BST2.display(0);

    return 0;
}
