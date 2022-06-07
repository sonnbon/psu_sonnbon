#include "list.h"

//Place your name here in comments:
//Connor Williams
//CS162 - prerecorded lecture on LLL
//
int main()
{
    //DO NOT DELETE ANY CODE! Comment it out if you change your mind
    node * head = NULL;
    build(head);
    //display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    /*cout << "HERE IS OUR FUNCTION: Are you ready?";
    char response;
    cin >> response;
    display_every_item(head);  */

    display_just_last(head);


    display_all(head);
    destroy(head);    

    return 0;
}
