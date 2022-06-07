#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    list list_copy;
    my_list.build();
    my_list.display_all();

    //PLACE YOUR FUNCTION CALL HERE!
    //int sum = my_list.sum_total();
    //cout << "The sum of all the data is " << sum << endl;

    //bool result = my_list.find_item(41);
    //if (result)
    //    cout << "There's a match!" << endl;
    //else
    //    cout << "no matches" << endl;
    
    list_copy.copy(my_list);
    list_copy.display_all();

    //my_list.remove_last();
    //my_list.display_all();

    //my_list.remove_all();
    //my_list.display_all();
    return 0;    
}
