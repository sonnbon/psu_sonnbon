#include "dlist.h"


int main()
{
    list object;
    //list obj2;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    /*int count = object.remove_every_other();
    cout << count << " nodes removed from list." << endl << endl;

    count = object.copy_list(obj2);
    cout << count << " nodes copied." << endl << endl;

    cout << "\nCOpied list:" << endl;
    obj2.display();
   */ 

    if (object.insert_data(19))
        cout << "Data added." << endl;
    else
        cout << "Data not added." << endl;

    int sum = object.duplicate_first();
    cout << sum << ": Sum of first and new last" << endl;

    object.display();

    return 0;
}
