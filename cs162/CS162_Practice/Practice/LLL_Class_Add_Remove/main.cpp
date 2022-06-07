#include "list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //DO NOT DELETE ANY CODE! Comment it out if you change your mind
    node * head = NULL;
    node * new_animal;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int num = add_end_LLL(head, 99);
    cout << "The total number of nodes is: " << num << endl;
 
      cout << "enter number here: ";
      cin >> new_animal->data;
      cin.ignore(100, '\n');
      new_animal->next = NULL;

      createlist(head, new_animal);

    display_all(head);
    destroy(head);    

    return 0;
}
