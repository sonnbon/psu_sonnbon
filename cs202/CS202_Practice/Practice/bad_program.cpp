#include <iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};

int main()
{
    int data {14};
    node * head {NULL};

    head = new node;


    delete head;
    delete head;
    delete head;

    return 0;
}
