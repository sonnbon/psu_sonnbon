package com.company;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Main.java
// *****************************************************************************
// This file manages the 'Main' application, which allows a user to choose
// between using Programming Assignment #4 and #5's applications, ultimately
// allowing a user to add food items or load food items to a menu, which can
// then be ordered. Programming Assignment #4's application uses an ArrayList
// to manage a menu of Food items and a Linear Linked List to manage a list of
// ordered Food items. Programming Assignment #5's application executes almost
// exactly the same way as Program #4's, except it uses a Red Black Balancing
// Tree to manage a menu of Food items instead. Program #5's application
// includes one additional option, which allows a user to look up specific food
// names in the Red Black Tree menu.
// *****************************************************************************
public class Main {

    public static void main(String[] args) {
        //Variable definitions -------------------------------------------------
        //Program 4 application using an ArrayList as a menu and a Linear Linked
        //List as a list of ordered items.
        //Food_App_LLL program4_app = new Food_App_LLL();

        //Program 5 application using a Red Black Tree as a menu and a Linear
        //Linked List as a list of ordered items.
        //Food_App_RBT program5_app = new Food_App_RBT();

        //For Main functionality
        User_Response answer = new User_Response(); //User inputted responses
        int mm_size = 2;  //Size of main menu (set to 2)
        // ---------------------------------------------------------------------

        //Welcome user.
        System.out.println("""
                           \nWelcome! Choose which food and ordering 
                           application you would like to use. The capabilities
                           of both options are very similar, but what's going on
                           in the background is much different!\n""");

        //User list of options
        do {
            System.out.println("""
                    What would you like to do?
                    1 - Use Program #5's App (Red Black Tree menu)?
                    2 - Use Program #4's App""");

            //Get user's response
            switch (answer.choice(mm_size)) {
                case 1:
                    //Use Programming Assignment #5's application, which uses a
                    //Red Black Tree for its menu and a Linear Linked List for
                    //its list of ordered items.
                    Food_App_RBT.main();
                    break;
                case 2:
                    //Use Programming Assignment #4's application, which uses an
                    //ArrayList for its menu and a Linear Linked List for its
                    //list of ordered items.
                    Food_App_LLL.main();
                    break;
                default:
                    System.out.println("This should not get called...");
                    break;
            }

            System.out.println("Start over and try another application?");

        } while (answer.agree());

        System.out.println("Exiting program... Goodbye.");
    }
}
