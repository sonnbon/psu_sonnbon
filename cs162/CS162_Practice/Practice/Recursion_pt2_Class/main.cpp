#include "list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //DO NOT DELETE ANY CODE! Comment it out if you change your mind
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num = add_at_end(head);

    int sum = remove_last_and_sum(head);

    display_all(head);
    cout << "We counted " << num << " nodes." << endl << endl;
    cout << "The sum of all including the deleted last node is " << sum << endl
         << endl;
    destroy(head);    

    return 0;
}
