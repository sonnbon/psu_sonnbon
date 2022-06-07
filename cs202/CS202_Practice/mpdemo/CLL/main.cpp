#include "clist.h"


int main()
{
    list object;
    list new_list1;
    list new_list2;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned
/*    int sum {object.display_all_but_last()};
    cout << "The sum of all but the last node: " << sum << endl << endl;

    if (object.remove_last())
        cout << "The last has been removed." << endl << endl;

    int count {new_list1.copy_all(object)};
    cout << "NEW LIST 1: " << count << " copied." << endl;

    new_list1.display();

    count = new_list1.copy_to(new_list2);
    cout << "NEW LIST 2: " << count << " copied." << endl;

    new_list2.display();

    if (object.add_node_last(count))
        cout << "Successfully added to end!!!" << endl << endl;


    object.display(); //resulting list after your function call!

    count = object.add_before_even();
    cout << count << " nodes were added to the list." << endl << endl;

    object.display();

    if (object.remove_same_last())
    {
        cout << "Nodes were removed." << endl << endl;
        object.display();
    }
*/ 
    int new_count = object.remove_out_of_order();
    cout << new_count << " nodes were removed." << endl << endl;

    //object.display();
    
    return 0;
}
