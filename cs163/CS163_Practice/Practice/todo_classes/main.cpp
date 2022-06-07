#include "todo_list.h"
using namespace std;

int main()
{
    char name[100], desc[100];
    int priority;

    todo_item test_object;

    cout << "Please enter the name, description, and priority: ";
    cin.get(name, 100);
    cin.ignore(100, '\n');
    cin.get(desc, 100);
    cin.ignore(100, '\n');
    cin >> priority;
    cin.ignore(100, '\n');

    test_object.set(name, desc, priority);
    test_object.display();

    return 0;
}
