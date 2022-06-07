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
    cout << "NOW IN REVERSE ORDER" << endl << endl;
    int num = display_reverse(head);

    remove_all_nodes(head);


    display_all(head);
    destroy(head);    

    return 0;
}
