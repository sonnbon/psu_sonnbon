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
    //int sum = sum_first_last(head);
    //cout << "Our sum was the following: " << sum << endl << endl;

    int count = count_even(head);
    cout << "The number of even valued data items is: " << count <<endl <<endl;

    display_all(head);
    destroy(head);    

    return 0;
}
