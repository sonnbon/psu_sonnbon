#include "clist.h"


int main()
{
    list object;
    list new_list;
    object.build();		//builds a circular LL
    object.display();	//displays the list


    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = object.copy_special(new_list);
    cout << count << " nodes were copied to the new list." << endl << endl;
    new_list.display();


    object.display(); //resulting list after your function call!
    
    return 0;
}
