#include "manager.h"
using namespace std;


//Step 8a - Finish the manager constructor
//
//FINISH THIS FUNCTION.
//HINT - it needs an initialization list to set up the
//managers information
manager::manager( const salaried_employee & managers_information): salaried_employee(managers_information)
 {
    cout <<"\nPlease enter the group name: ";
    group_name.read();
    cout <<"\nHow many group_members? ";
    cin >> num_employees; cin.ignore(100,'\n');

    //COMPLETE THIS FUNCTION - allocating the dynamic array of
    //employees in this group:

    group = new employee * [num_employees];

    for (int i = 0; i < num_employees; ++i)
        group[i] = nullptr;

    
}

//Step 8b - Implement the manager destructor
//
//Deallocate the array of employee pointers
manager::~manager()
{
    if (group)
    {
        for (int i = 0; i < num_employees; ++i)
        {
            if (group[i])
            {
                delete group[i];
                group[i] = NULL;
            }
        }
        delete [] group;
        group = NULL;
    }
    num_employees = 0;
}

// *********** STOP ************* 
// now you will be workiing on experiencing dynamic binding by
// modifying main. Read the lab manual for Step 9

//Step 10 - Experiencing RTTI
//
//THIS FUNCTION REQUIRES RTTI!!!
void manager::add_to_group( const employee & to_add)
{
    int i {0};

    while (group[i] && i < num_employees)
        ++i;

    if (i < num_employees)
    {
        const salaried_employee * ptr = dynamic_cast<const salaried_employee *> (&to_add);
        if (ptr)
            group[i] = new salaried_employee(*ptr);
        else
        {
            const hourly_employee * ptr = dynamic_cast<const hourly_employee *> (&to_add);
            if (ptr)
                group[i] = new hourly_employee(*ptr);
            else
            {
                const full_time * ptr = dynamic_cast<const full_time *> (&to_add);
                if (ptr)
                    group[i] = new full_time(*ptr);
            }
        }
    }
    else
        cout << "No employee added..." << endl << endl;
}

//SAMPLE
void manager::display() const
{
    cout <<"MANAGER ";
    salaried_employee::display();
    cout <<"\nGROUP NAME: ";
    group_name.display();
    for (int i = 0; i < num_employees; ++i)
    {
      if (group[i]) 
          group[i]->display();
    }
}   
