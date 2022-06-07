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
    append_at_end(head, 99);


    display_all(head);
    destroy(head);    

    return 0;
}
