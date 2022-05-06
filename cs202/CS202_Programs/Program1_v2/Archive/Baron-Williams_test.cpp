#include "Baron-Williams_card.h"
using namespace std;

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 21, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_test.h
// *****************************************************************************
// PROGRESS SUBMISSION 1 - IN PROGRESS TESTING
// THIS IS FOR TEST PURPOSES AND TO KEEP MAIN CLEAN. DISREGARD OTHERWISE:
// - valgrind shows no leaks
// - gdb steps through with no errors
// *****************************************************************************

//Test function makes objects of all the cards, default and specific, and tests
//most member functions for functionality and to find any memory leaks/step
//through and test out GDB. Exit out of menus to skip and disregard this
//function.
int test_program_objects()
{
  //Initialization of all card type objects through default, arguments passed
  //in, and copy constructors.
  //Default cards
  card test1;
  card test2(4, "Forest");
  card test3;
  card test4(test3);
  card test5(-1, "Forest");
  card test6(3, "Garbage");

  //Action cards
  action a_test1;
  action a_test2(94, "Fire", -10, "Sword");
  action a_test3;
  action a_test4(a_test3);
  action a_test5(10, "Desert", -10, "Needle");
  action a_test6(-10, "Fire", -10, "Weapon");

  //Defend cards
  defend d_test1;
  defend d_test2(94, "Fire", -10, "Sword");
  defend d_test3;
  defend d_test4(d_test3);
  defend d_test5(10, "Desert", 10, "Needle");
  defend d_test6(-10, "Fire", -10, "Weapon");

  //Spell cards
  spell s_test1;
  spell s_test2(94, "Fire", -10, "Sword");
  spell s_test3;
  spell s_test4(s_test3);
  spell s_test5(10, "Desert", 4.2, "whoooooosh");
  spell s_test6(-10, "Fire", 0, "Weeeee");

  //Other variables
  int test_damage = 0;   //For checking damage cost output
  int test_strength = 0; //For checking strength gain output
  float test_factor = 0; //For checking factored strength or damage output

  int menu_option = 0;   //To be menu choice

  //Test default cards
  do
  {
    cout << "Choose an option:\n"
         << "1 - Read card in\n"
         << "2 - Display card\n"
         << "3 - Change card\n"
         << "4 - Copy card\n"
         << "5 - Find by type\n"
         << "6 - Find exact card\n"
         << "7 - Remove card\n"
         << endl;

    cout << "Enter choice here: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    switch (menu_option)
    {
      case 1:
        test1.read();
        test4.read();
        break;
      case 2:
        test1.display();
        test2.display();
        test3.display();
        test4.display();
        test5.display();
        test6.display();
        break;
      case 3:
        test6.change(-9, "Window");
        test6.change(6, "Desert");
        break;
      case 4:
        test1.copy(test5);
        break;
      case 5:
        cout << "This works, don't waste space" << endl;
        break;
      case 6:
        cout << "This works, don't waste space" << endl;
        break;
      case 7:
        test3.remove();
        test4.remove();
        test2.remove();
        break;
      default:
        cout << "\nWrong choice. Bye." << endl << endl;
        break;
    }
  } while (menu_option > 0 && menu_option < 8);

  //Test action cards
  do
  {
    cout << "Choose an option:\n"
         << "1 - Read action card in\n"
         << "2 - Display action card\n"
         << "3 - Change action card\n"
         << "4 - Copy action card\n"
         << "5 - Compare action card\n"
         << "6 - Attack types\n"
         << "7 - Remove action card\n"
         << endl;

    cout << "Enter choice here: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    switch (menu_option)
    {
      case 1:
        a_test1.read();
        a_test3.read();
        a_test4.read();
        break;
      case 2:
        a_test1.display();
        a_test2.display();
        a_test3.display();
        a_test4.display();
        a_test5.display();
        a_test6.display();
        break;
      case 3:
        a_test6.add(300, "Forest", -9, "Glass Shard");
        a_test6.add(1, "Water", 6, "Nothing");
        break;
      case 4:
        a_test1.copy(a_test5);
        break;
      case 5:
        if(!a_test1.compare(a_test5))
          cout << "NO MATCH" << endl;
        if(!a_test2.compare(a_test1))
          cout << "NO MATCH" << endl;
        break;
      case 6:
        test_damage = a_test1.attack();
        cout << test_damage << endl << endl;

        test_damage = a_test2.double_attack();
        cout << test_damage << endl << endl;

        test_damage = a_test3.throw_weapon();
        cout << test_damage << endl << endl;

        test_damage = a_test4.attack();
        cout << test_damage << endl << endl;

        test_damage = a_test5.double_attack();
        cout << test_damage << endl << endl;

        test_damage = a_test6.throw_weapon();
        cout << test_damage << endl << endl;
        break;
      case 7:
        a_test3.remove();
        a_test4.remove();
        a_test2.remove();
        break;
      default:
        cout << "\nWrong choice. Bye." << endl << endl;
        break;
    }
  } while (menu_option > 0 && menu_option < 8);

  //Test defend cards
  do
  {
    cout << "Choose an option:\n"
         << "1 - Read defend card in\n"
         << "2 - Display defend card\n"
         << "3 - Change defend card\n"
         << "4 - Copy defend card\n"
         << "5 - Compare defend card\n"
         << "6 - Defend types\n"
         << "7 - Remove defend card\n"
         << endl;

    cout << "Enter choice here: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    switch (menu_option)
    {
      case 1:
        d_test1.read();
        d_test3.read();
        d_test4.read();
        break;
      case 2:
        d_test1.display();
        d_test2.display();
        d_test3.display();
        d_test4.display();
        d_test5.display();
        d_test6.display();
        break;
      case 3:
        d_test6.add(300, "Forest", -9, "Shard");
        d_test6.add(1, "Water", 6, "Metal Shield");
        break;
      case 4:
        d_test1.copy(d_test5);
        break;
      case 5:
        if(!d_test1.compare(d_test5))
          cout << "NO MATCH" << endl;
        if(!d_test2.compare(d_test1))
          cout << "NO MATCH" << endl;
        break;
      case 6:
        test_strength = d_test1.block();
        cout << test_strength << endl << endl;

        test_strength = d_test2.hide();
        cout << test_strength << endl << endl;

        test_strength = d_test3.push_back();
        cout << test_strength << endl << endl;

        test_strength = d_test4.block();
        cout << test_strength << endl << endl;

        test_strength = d_test5.hide();
        cout << test_strength << endl << endl;

        test_strength = d_test6.push_back();
        cout << test_strength << endl << endl;
        break;
      case 7:
        d_test3.remove();
        d_test4.remove();
        d_test2.remove();
        break;
      default:
        cout << "\nWrong choice. Bye." << endl << endl;
        break;
    }
  } while (menu_option > 0 && menu_option < 8);

  //Test spell cards
  do
  {
    cout << "Choose an option:\n"
         << "1 - Read spell card in\n"
         << "2 - Display spell card\n"
         << "3 - Change spell card\n"
         << "4 - Copy spell card\n"
         << "5 - Compare spell card\n"
         << "6 - Spell types\n"
         << "7 - Remove spell card\n"
         << endl;

    cout << "Enter choice here: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    switch (menu_option)
    {
      case 1:
        s_test1.read();
        s_test3.read();
        s_test4.read();
        break;
      case 2:
        s_test1.display();
        s_test2.display();
        s_test3.display();
        s_test4.display();
        s_test5.display();
        s_test6.display();
        break;
      case 3:
        s_test6.add(300, "Forest", -9, "Shard");
        s_test6.add(1, "Water", 3.2, "Latinum Vibrosium");
        break;
      case 4:
        s_test1.copy(s_test5);
        break;
      case 5:
        if(!s_test1.compare(s_test5))
          cout << "NO MATCH" << endl;
        if(!s_test2.compare(s_test1))
          cout << "NO MATCH" << endl;
        break;
      case 6:
        test_factor = s_test1.enhance(d_test1);
        cout << test_factor << endl << endl;

        test_factor = s_test2.diminish(a_test2);
        cout << test_factor << endl << endl;

        test_factor = s_test3.redirect(a_test3);
        cout << test_factor << endl << endl;

        test_factor = s_test4.enhance(d_test4);
        cout << test_factor << endl << endl;

        test_factor = s_test5.diminish(a_test5);
        cout << test_factor << endl << endl;

        test_factor = s_test6.redirect(a_test6);
        cout << test_factor << endl << endl;
        break;
      case 7:
        s_test3.remove();
        s_test4.remove();
        s_test2.remove();
        break;
      default:
        cout << "\nWrong choice. Bye." << endl << endl;
        break;
    }
  } while (menu_option > 0 && menu_option < 8);

  return 0;
}


