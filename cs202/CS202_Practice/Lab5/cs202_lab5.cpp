#include "store.h"
using namespace std;

//Implement each of these using exception handeling
//For each function consider if you should have the try block
//in the function or if you should have the try block in the
//calling routine. If you throw an exception without a
//try block, then add an exception specification list


//Step 5a - throw an exception if there is an invalid response
bool again()
{
    char response = 'N';

    cin >> response;
    cin.ignore(100, '\n');
    response = toupper(response);

      if (response == 'Y')
        return true;
      if (response == 'N')
          return false;
    throw response;
}

//Step 5b - implement the address constructor and throw an
//exception if ther eis a null string being copied:

address::address(char * new_street, char * new_zip)
{
    NULL_STRING badstr;

    if (!new_street)
    {
        badstr.street = new_street;
        throw badstr.street;
    }
    if (!new_zip)
    {
        badstr.zip = new_zip;
        throw badstr.zip;
    }

    street = new char[strlen(new_street) + 1];
    strcpy(street, new_street);

    zip = new char[strlen(new_zip) + 1];
    strcpy(zip, new_zip);
}

//Step 5c - implement the set pay function and throw an
//exception if a zzero or negative pay is requested

void hourly_employee::set_pay_rate(float rate) throw(INVALID_PAY)
{
    INVALID_PAY badpay;
    if (rate <= 0)
    {
        badpay.pay_rate = rate;
        throw badpay.pay_rate;
    }
    pay_rate = rate;
}

// *************************** Now move to main.cpp and work there


//Step 7 - implement the two compare functions. The first
//compares the employees name. Throw an exception if there is no match
bool employee::compare(const name & match)
{
    if (!find_by_name(match))
        throw false;

    return true;
}

//Now travere the binary search tree of reviews and
//throw an exception if there is no match
bool employee::compare(char * match)
{
    if (!root->compare(match))
        throw false;
    return true;
}

