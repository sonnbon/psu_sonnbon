#include "cs162_list.h"

//Start in Step 3 by uncommenting out the code to create 
//a list object and build it!

int main()
{
    //Create an object of class list
    list my_list;

    //Call the build function to create a Linear Linked List
    //(The build member function has already been written)
    my_list.build();


    //Place your code here to call the functions for Lab #7
    my_list.display_all();
    int count = my_list.count_first();
    cout << "The first number repeated " << count << " times!" << endl << endl;

    my_list.display_last();

    bool more_than_once = my_list.find_last();
    if (more_than_once)
        cout << "Yep, last item appeared more than once!" << endl << endl;
    else
        cout << "Nope, last item only appears last." << endl << endl;

    return 0;
}
