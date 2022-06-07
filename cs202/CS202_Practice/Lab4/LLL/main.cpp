#include "list.h"

int main()
{
    list object;
    list second_list;
    second_list.build();

    object.build();    //builds a LLL
    object.display();  //displays the LLL
    int data {2};

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Number of times " << data << " is found: " << object.num_times(data)
         << endl << endl;

    data = object.display_except();
    cout << "The sum of the first and last node, which were not displayed, is: " << data
         << endl << endl;

    data = object.remove_except();
    cout << data << " nodes have been removed, leaving only two left" << endl << endl;

    if (object.same_contents(object))
        cout << "YES THEY ARE THE SAME!" << endl << endl;
    if (object.same_contents(second_list))
        cout << "YES THEY ARE THE SAME!" << endl << endl;
    else
        cout << "THEY ARE diFFERENT!" << endl << endl;


    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
