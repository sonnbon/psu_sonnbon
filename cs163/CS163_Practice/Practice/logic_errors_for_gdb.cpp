#include <iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};

int main ()
{
    node * head = NULL;

    cout << head->data << endl;

    delete head;
    delete head;
    delete head;


    return 0;
}
