package com.company;

import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.io.File;
import java.util.Scanner;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4
// Date: March 17, 2022
// Filename: Menu.java
// *****************************************************************************
// This file manages the 'Menu' class, which manages an ArrayList of food items
// (using the Food class) that a user can browse through to order from. It
// allows the user to input, display, edit, and retrieve items from the "menu".
// It also allows the user to read in from an external file, so menu items do
// not need to be manually entered.
// *****************************************************************************
public class Menu extends User_Response{
    protected ArrayList<Food> options;



    //This constructor sets a new ArrayList of Food objects. It takes no
    //arguments and has no return type.
    public Menu() {
        options = new ArrayList<Food>();
    }



    //This public method inserts a food item of the user's choice into the
    //ArrayList. It takes no arguments and has a void return type.
    public void insert() {
        //Variable definitions
        Food item = null;    //Food item to be added to list

        //Get users food ordering type choice.
        System.out.println("""
                Which type of food would you like to add?
                B - Barbeque
                C - Custom (Build your own)
                D - Dietary Restrictions""");

        //Get user's response.
        switch (item_choice()){
            case 'B':
                //New BBQ object.
                item = new BBQ();
                break;
            case 'C':
                //New Custom object.
                item = new Custom();
                break;
            case 'D':
                //New Dietary object.
                item = new Dietary();
                break;
            default:
                System.out.println("This should not get called.");
                break;
        }

        assert item != null;    //Assert whether item got a new object created.
        item.input();           //Input item contents
        this.options.add(item); //Add item to list
    }



    //This public method displays all the contents of the ArrayList. It takes no
    //arguments and returns an integer, to be the number of items displayed.
    public int display(){
        //Variable definitions
        int count = 0; //Number of items displayed

        //Loop through list and display each item.
        for (int i = 0; i < this.options.size(); ++i){
            this.options.get(i).display();
            ++count;
        }

        return count;
    }



    //This public method retrieves an item from the list, lets the user choose
    //ordering options, and then returns it. It takes two String arguments, the
    //restaurant name and the food item, and returns a 'Food' object.
    public Food orderItem(String cart, String name) throws CloneNotSupportedException {
        //Variable definitions
        final DecimalFormat form = new DecimalFormat("0.00"); //Rounds decimals
        Food item = null;      //Temporary food item to be ordered
        Food copy = null;      //Copy of item listed in menu
        boolean found = false; //Check whether item is found.
        double change = 0;     //Price change, if any
        int quantity = 0;      //Quantity of the ordered item
        int range = 100;       //Max number a quantity of a single food item can be
        char size = 'M';       //Size of the ordered item

        //Search for food item.
        for (int i = 0; i < this.options.size(); ++i){
            if (this.options.get(i).findCart(cart) == 0 &&
                this.options.get(i).findFood(name) == 0){
                copy = this.options.get(i); //Get reference to food item
                found = true;
            }
        }

        //If item was found, give user food ordering options for that item and
        //get the total change in cost as a result.
        if (found){
            item = (Food)copy.clone();
            change = item.chooseTaste(); //Taste selection
            change += item.enhance();     //Food enhancement
            change += item.restrict();    //Food restrictions

            //Prompt user for quantity.
            System.out.println("How many orders of this item (up to 100!)?");

            quantity = choice(range); //Get user's response

            //Prompt user for size.
            System.out.println("What size? Small (S), Medium (M), or Large (L)?");

            size = size_choice(); //Get user's response

            change += item.changeCost(quantity, size); //Update price change

            System.out.println("\nItem ordered!");

            //Check if the price change is negative or positive.
            if (change < 0){
                System.out.println("And with a price deduction of $" + form.format(change));
            }
            else if (change > 0){
                System.out.println("But with a price increase of $" + form.format(change));
            }
        }

        return item;
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It takes no arguments and returns an integer, to
    //be the number of items updated.
    public int editDiet(){
        //Variable definitions
        int count = 0;       //Number of items updated
        String choice = "";  //User inputted edit choice
        Dietary item = null; //Temporary Dietary object

        //Prompt if user wants to change all dietary food's diets (vegan, etc.).
        System.out.println("""
                           Do you want to change the diet type of all foods with
                           dietary restrictions?""");

        //Get user's response
        if (agree()) {
            System.out.println("What diet would you like for all foods?");
            System.out.print("(vegan, vegetarian, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update dietary foods, overloading generic food class.
            for (int i = 0; i < this.options.size(); ++i) {

                //Check if the food is an instance of the Dietary class.
                if (this.options.get(i) instanceof Dietary) {
                    item = (Dietary)this.options.get(i); //Cast to a temporary
                    item.chooseTaste(choice); //Overload parent class method
                    this.options.set(i, item); //Reset the data
                    ++count;
                }
            }
        }
        return count;
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It takes no arguments and returns an integer, to
    //be the number of items updated.
    public int editProtein(){
        //Variable definitions
        int count = 0;       //Number of items updated
        String choice = "";  //User inputted edit choice
        Custom item = null;  //Temporary Custom object

        //Prompt if user wants to change all customizable food's proteins.
        System.out.println("""
                           Do you want to change the protein of all customizable
                           foods?""");

        //Get user's response.
        if (agree()) {
            System.out.println("What protein would you like for all foods?");
            System.out.print("(chicken, tofu, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update custom foods, overloading generic food class.
            for (int i = 0; i < this.options.size(); ++i) {

                //Check if the food is an instance of the Custom class.
                if (this.options.get(i) instanceof Custom) {
                    item = (Custom)this.options.get(i); //Cast to a temporary
                    item.chooseTaste(choice); //Overload parent class method
                    this.options.set(i, item); //Reset the data
                    ++count;
                }
            }
        }
        return count;
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It takes no arguments and returns an integer, to
    //be the number of items updated.
    public int editSauce(){
        //Variable definitions
        int count = 0;       //Number of items updated
        String choice = "";  //User inputted edit choice
        BBQ item = null;     //Temporary BBQ object

        //Prompt if user wants to change all BBQ food's sauce.
        System.out.println("""
                           Do you want to change the sauce of all BBQ type
                           foods?""");

        //Get user's response.
        if (agree()) {
            System.out.println("What sauce would you like for all foods?");
            System.out.print("(House Sauce, BBQ Sauce, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update BBQ foods, overloading generic food class.
            for (int i = 0; i < this.options.size(); ++i) {

                //Check if the food is an instance of the BBQ class.
                if (this.options.get(i) instanceof BBQ) {
                    item = (BBQ)this.options.get(i); //Cast to a temporary
                    item.chooseTaste(choice); //Overload parent class method
                    this.options.set(i, item); //Reset the data
                    ++count;
                }
            }
        }
        return count;
    }



    //This public method reads in an external text file and adds food items to
    //the ArrayList. It takes a String object, to be the filename, as an
    //argument and returns an integer, to be the number of items loaded.
    public int load(String filename) throws FileNotFoundException {
        //Variable definitions
        Food item = null;       //Temporary food item to be added to list
        int count = 0;          //Number of items loaded
        boolean success = true; //Checks for read success
        char type = 'B';        //Food item type read in


        //Create another Scanner object to read in the passed in file name,
        //which is passed into a new File object.
        Scanner read = new Scanner(new File(filename));
        read.useDelimiter(","); //Delimiter to split text in external file

        //Read in each option of each line until the end of the file is reached.
        while (read.hasNext()) {
            type = read.next().charAt(0);

            //Check if the type is BBQ and create a new BBQ object, reading each
            //variable into its constructor.
            if (type == 'B'){
                item = new BBQ(read.next(), read.next(), read.nextDouble(),
                               read.next());
                read.nextLine();
            }

            //Check if the type is Custom and create a new Custom object,
            //reading in each variable into its constructor.
            else if (type == 'C'){
                item = new Custom(read.next(), read.next(), read.nextDouble(),
                                  read.next());
                read.nextLine();
            }

            //Check if the type is Dietary and create a new Dietary object,
            //reading in each variable into its constructor.
            else if (type == 'D'){
                item = new Dietary(read.next(), read.next(), read.nextDouble());
                read.nextLine();
            }

            //Otherwise, something is wrong and success gets flagged false.
            else{
                success = false; //There should only be three possible responses
            }

            this.options.add(item); //Add new item to ArrayList
            ++count;
        }

        //Check that data was read in.
        if (count == 0 || !success){
            return 0;
        }

        return count;
    }



    //This public method removes all the contents of the list. It takes no
    //arguments and has a void return type.
    public void removeAll(){
        options.clear(); //Clears the list
    }
}
