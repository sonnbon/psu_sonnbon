#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int displayed = object.display_unique_iter();
    cout << displayed << " unique items displayed" << endl << endl;

    displayed = object.display_unique_recur();
    cout << displayed << " unique items displayed" << endl << endl;

    displayed = object.display_last_not_first();
    if (!displayed)
        cout << "The last is the same as the first item. Not displayed!" << endl << endl;
    else
        cout << "The last is different than the first and is: " << displayed << endl << endl;
    
    displayed = object.display_last_not_recur();
    if (!displayed)
        cout << "The last is the same as the first item. Not displayed!" << endl << endl;
    else
        cout << "The last is different than the first and is: " << displayed << endl << endl;

    float average = object.average_unique_iter();
    if (!average)
        cout << "No average to display." << endl << endl;
    else
        cout << "The average of the unique items is: " << average << endl << endl;

    average = object.average_unique_recur();
    if (!average)
        cout << "No average to display." << endl << endl;
    else
        cout << "The average of the unique items is: " << average << endl << endl;

    int sum = object.move_first_to_end_iter();
    cout << "The sum of the data (iteratively) is: " << sum << endl << endl;
    object.display_all();

    sum = object.move_first_to_end_recur();
    cout << "The sum of the data (recursively) is: " << sum << endl << endl;
    object.display_all();

    sum = object.dup_first_to_end_iter();
    cout << "Sum of last two (iteratively) is: " << sum << endl << endl;
    object.display_all();

    sum = object.dup_first_to_end_recur();
    cout << "Sum of last two (recursively) is: " << sum << endl << endl;
    object.display_all();

    int removed = object.remove_duplicate_iter();
    cout << removed << " number of duplicate nodes were removed (iteratively)" << endl << endl;
    object.display_all();

    removed = object.remove_last_largest();
    object.display_all();

    object.display();  //displays the LLL again!
   
    
    return 0;
}
