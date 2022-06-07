//Connor Williams
//CS162 - Introduction to Computer Science
//This program will calculate an employee's pay

// This program will allow the use to enter an employee's initials, the number of hours worked,
// and their wage. This program will also ask if a cost of living increase to the users wage
// is appropriate at this time.

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
     //Variable definitions
     char f_initial;             //the users first initial
     char m_initial;             //the users middle initial
     char l_initial;             //the users last initial
     float wage = 0.0;           //to be the users wage
     int hours = 0;              //to be the users hours worked
     float income = 0.0;         //to be the income based on wage and hours
     char response;              //to be the users response
     float living_cost = 0.0;    //to be the cost of living increase
     float new_wage = 0.0;       //to be wage based on cost of living increase
     float new_income = 0.0;     //to be income based on new wage

     do
     {
       //Prompt and read in the users initials
       cout << "Please enter your initials (e.g, JCW): ";
       cin >> f_initial >> m_initial >> l_initial;

       if (!(isalpha(f_initial) && isalpha(m_initial) && isalpha(l_initial)))
       {
         cout << "Oops! You did not enter an alphabetic value. Please try again!"
              << endl << endl;
       }
       else
       {
           f_initial = toupper(f_initial);    //Capitalize first initial
           m_initial = toupper(m_initial);    //Capitalize middle initial
           l_initial = toupper(l_initial);    //Capitalize last initial
           cout << "You entered that your initials are " << f_initial
                << m_initial << l_initial
                << "." << endl << endl;
         do
         {
           //Prompt and receive the hourly wage and number of hours worked
           cout << "Please enter your hourly wage: ";
           cin >> wage;
     
           if (wage < 0)
             cout << "The value you entered is negative. Please try again." << endl << endl;
           else
           {
             do
             {
               cout << "Please enter how many total hours you worked: ";
               cin >> hours; 
               if (hours < 0)
                 cout << "The value you entered is negative. Please try again." << endl << endl;
               else
               {
                 cout << "It looks like you get paid $" << wage << " an hour,"
                      << " and you worked a total of " << hours << " hours."
                      << endl;
              
                 //Compute the resulting pay and display the results
                 income = wage * hours;
                 cout << "Based on this information, " << f_initial << m_initial << l_initial
                      << "'s income is $" << income << "." << endl << endl;
                 
                 do
                 {
                   //Add possible cost of living increase
                   cout << "Does a cost of living increase need to be applied (Y/N)? ";
                   cin >> response;
                   response = toupper(response);
                   if (response == 'Y')
                   {  
                     cout << "What percentage increase is expected? ";
                     cin >> living_cost;
                     if (living_cost == 0)
                     {
                       cout << "Your wage and income will remain unchanged." << endl
                            << "Wage: $" << wage << " an hour" << endl
                            << "Income: $" << income << endl << endl;
                     }
                     else
                     {
                       living_cost /= 100;    //decimal form for being used as a percentage
                       new_wage = wage + (wage * living_cost);
                       new_income = hours * new_wage;
             
                       cout << "Based on this information, your new wage would be $"
                            << new_wage << " an hour, making your new income $"
                            << new_income << "." << endl << endl;
                     }
                   }
                   else if (response == 'N')
                   {
                     cout << "Your wage and income will remain unchanged." << endl
                          << "Wage: $" << wage << " an hour" << endl
                          << "Income: $" << income << endl << endl;
                   }
                   else
                     cout << "That is not a valid response. Try again." << endl << endl;
                 } while (response != 'Y' && response != 'N');

               }

             } while (hours < 0);
             
           }

         } while (wage < 0);

       }

     } while (!(isalpha(f_initial) && isalpha(m_initial) && isalpha(l_initial)));

     return 0;
}
