#include "dlist.h"


int main()
{
    list object;
    list new_list;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = object.copy_DLL(new_list);
    cout << "Excluding the first and last node, " << count << " nodes were copied to the new list." << endl << endl;
    new_list.display();

    object.display();
    
    return 0;
}
