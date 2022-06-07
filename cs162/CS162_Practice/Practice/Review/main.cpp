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
    int fifth = display_except(head);
    cout << "This is the 5th data item in the list " << fifth << endl << endl;

    display_all(head);
    destroy(head);    

    return 0;
}
