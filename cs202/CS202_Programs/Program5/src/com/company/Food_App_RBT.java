package com.company;

import java.text.DecimalFormat;
import java.util.Scanner;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 5
// Date: March 17, 2022
// Filename: Food_App_RBT.java
// *****************************************************************************
// This file manages the 'Food_App_RBT' application, which allows a user to add
// food items or load food items to a menu, which can then be ordered. Food
// items ordered are copied and manipulated to the users preferences (quantity,
// size, etc.) to a list of ordered food items. There are three different types
// of ordering processes that can take place for any restaurant's food items:
// Customization, where a user can choose protein, whether it's toasted, and if
// they want extra protein; Barbeque, where a user can choose a BBQ sauce, its
// spice level, and whether it is fried; Dietary Restrictions, where a user can
// choose whether it is gluten free, whether it is vegan, vegetarian etc., and
// if they want any items held (no tomatoes, etc.). The Food menu (Red Black
// Tree) shows all food items from every restaurant, sorted by restaurant and
// food name. The Ordered list (Linear Linked List) shows all food items
// ordered, sorted by restaurant and food name.
// (This application is specific to Programming Assignment 5)
// *****************************************************************************
public class Food_App_RBT {
    public static void main() {
        //Variable definitions -------------------------------------------------
        //Input stream
        Scanner input = new Scanner(System.in); //Input stream for Main

        //For program functionality
        Menu_RBT menu = new Menu_RBT();               //Hold food items to order
        Ordered_Items my_order = new Ordered_Items(); //List of items ordered
        String filename = "MenuOptions.txt";          //Name of file to be used

        //For Main functionality
        final DecimalFormat form = new DecimalFormat("0.00"); //Rounds decimals
        User_Response answer = new User_Response(); //User inputted responses
        int mm_size = 8;  //Size of main menu (set to 8)
        int count = 0;    //Number of items
        double total = 0; //Total cost of food items
        String cart = ""; //Restaurant name to look up
        String name = ""; //Food name to look up
        // ---------------------------------------------------------------------

        //Welcome user
        System.out.println("""
                            \nWelcome to your food menu and ordering app!
                            \nIn this program, you can view a menu of food from
                            different restaurants that you can order from. You
                            can load a menu from a pre-made external file or add
                            food items to the menu yourself! When ordering food,
                            you will be prompted through specific menu options
                            so you can get the food properties and flavors you
                            truly want! You will be able to also search through
                            your ordered list, remove from your ordered list, or
                            remove everything from your ordered list.
                            \nLet's get started!\n""");

        try{
            do{
                //Load items from external file?
                System.out.println("Would you like to load a menu of food options?");

                //Get user's response.
                if (answer.agree()){
                    count = menu.load(filename); //Load from file
                    System.out.println(count + " items loaded.");
                }

                //Insert items manually?
                System.out.println("Would you like to load food items manually?");

                //Get user's response
                if (answer.agree()){
                    do{
                        //Manually insert item and prompt user to insert again.
                        menu.input();
                        System.out.println("Enter another food item?");

                    } while (answer.agree());
                }

                //User list of options
                do {
                    System.out.println("""
                            What would you like to do?
                            1 - Display Food Menu
                            2 - Display specific food in Food Menu
                            3 - Edit menu items in bulk
                            4 - Order Food
                            5 - Display Food Ordered
                            6 - Find Food in your Ordered List
                            7 - Remove Food from your Ordered List
                            8 - Remove all Food from your Ordered List""");

                    //Get users main menu inputted answer.
                    switch (answer.choice(mm_size)) {
                        case 1:
                            //Display the food menu
                            count = menu.display();
                            System.out.println(count + " item(s) displayed.");
                            break;
                        case 2:
                            //Display specific food from menu
                            System.out.print("Which food? ");
                            name = input.nextLine();
                            count = menu.findFood(name);

                            //Check if retrieval and display was successful.
                            if (count == 0) {
                                System.out.println("Item not in menu...");
                            } else {
                                System.out.println(count + " items displayed.");
                            }
                            break;
                        case 3:
                            //Edit menu
                            count = menu.editDiet();     //Edit diet
                            count += menu.editProtein(); //Edit protein
                            count += menu.editSauce();   //Edit sauce

                            System.out.println(count + " item(s) updated.");
                            break;
                        case 4:
                            //Order food item.
                            System.out.print("Which restaurant? ");
                            cart = input.nextLine();

                            System.out.print("Which food? ");
                            name = input.nextLine();

                            //Add order to ordered list.
                            total = my_order.insert(menu.orderItem(cart, name));

                            //Check if insertion succeeded.
                            if (total == 0) {
                                System.out.println("Item not in menu...");
                            } else {
                                System.out.println("Your total cost is $" + form.format(total));
                            }
                            break;
                        case 5:
                            //Display ordered list.
                            count = my_order.display();
                            System.out.println("Number of items ordered: " + count);
                            break;
                        case 6:
                            //Find food item
                            System.out.print("Which restaurant? ");
                            cart = input.nextLine();

                            System.out.print("Which food? ");
                            name = input.nextLine();

                            //Search the list.
                            if (!my_order.retrieve(cart, name)) {
                                System.out.println("Food item not found...");
                            }
                            break;
                        case 7:
                            //Remove food item
                            System.out.print("Which restaurant? ");
                            cart = input.nextLine();

                            System.out.print("Which food? ");
                            name = input.nextLine();

                            //Search and remove from the list.
                            if (my_order.remove(cart, name)) {
                                System.out.println("Food item removed.");
                            } else {
                                System.out.println("Food item not found...");
                            }
                            break;
                        case 8:
                            //Remove all from ordered list.
                            my_order.removeAll();
                            break;
                        default:
                            System.out.println("This should not be called.\n");
                    }

                    //Prompt user to see main menu again.
                    System.out.println("See main menu again?");

                } while (answer.agree());

                //Prompt user to start over.
                System.out.println("Start over from the beginning?");

                menu.removeAll(); //Remove the menu list whether yes or no

            } while (answer.agree());
        }

        //Catch any errors that have been thrown.
        catch (Exception error){
            System.out.println("Invalid data has been used...");
        }

        System.out.println("Exiting application... Goodbye");
    }
}
