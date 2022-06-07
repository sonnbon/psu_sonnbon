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
    cout << "Our count was: " << count_special(head) << endl;

    int largest = 0;
    cin >> largest;
    int count = find_largest(head, largest);
    cout << "Largest found: " << count << " times." << endl;

    display_all(head);
    destroy(head);    

    return 0;
}
