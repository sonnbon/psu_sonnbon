#include "CS162_pet_hotel.h"

using namespace std;

//Connor Williams
//This code will test out the classes that we are writing

//constants
const int SIZE = 5;

int main()
{
    pet_hotel rescue;  //for all of my rescue dogs
    pet_hotel personal_pets; //for all my personal pets

    pet all_pets[SIZE];

    char response = 'n';
    bool finished = false;

    do
    {
        finished = rescue.input();  //object DOT member function
        cout << "Again? ";
        cin >> response;
        cin.ignore(100, '\n');

    } while (!finished && toupper(response) == 'Y');

    rescue.display_all();
    rescue.save_all();

    return 0;
}
