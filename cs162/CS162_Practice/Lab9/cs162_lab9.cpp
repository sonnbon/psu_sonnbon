#include "cs162_list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
   // int match = 45;
   /* bool is_match = find(head, match);

    if (is_match)
        cout << "It's in there!" << endl << endl;
    else
        cout << "It's not in there!" << endl << endl;*/

    int num = remove_all(head);

    cout << "You removed " << num << " nodes." << endl << endl;


    display_all(head);
    destroy(head);
    
    return 0;
}
