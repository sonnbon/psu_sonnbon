package com.company;

import java.lang.Cloneable;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: BBQ.java
// *****************************************************************************
// This file manages the 'BBQ' class, which manages barbeque type foods. It
// manages the type of sauce (String), the spice level (integer), and whether
// the item is fried (boolean). It allows the user to input the menu item,
// display, choose a taste (edit sauce), enhance (make fried), and restrict
// (change the spice level - up to level 5).
// *****************************************************************************
public class BBQ extends Food implements Cloneable{
    protected String sauce;  //BBQ sauce flavor
    protected int spice;     //Spice level
    protected boolean fried; //Is if fried or not?



    //This default constructor sets the class's fields to their initial values.
    //It takes no arguments and has no return type.
    public BBQ(){
        this.sauce = "None";      //Default is set to None
        this.spice = 1;           //Default is set to 1
        this.fried = false;       //Default is set not fried
    }



    //This constructor with arguments sets the class's fields as well as its
    //parent's fields to their initial values. It takes two Strings, to be the
    //restaurant and food name, and a double, to be the price, as arguments and
    //has no return type.
    public BBQ(String cart, String name, double price, String sauce){
        //Call the parent's constructor
        super(cart, name, price);

        this.sauce = sauce;
        this.spice = 1;     //Default is set to 1
        this.fried = false; //Default is set not fried
    }



    //This public method overrides the Object cloning method to create a deep
    //copy of this class's object. It takes no arguments and returns an
    //'Object'.
    public Object clone() throws CloneNotSupportedException{
        return (BBQ) super.clone();
    }



    //This public method prompts and reads in the users input. It takes no
    //arguments and has a void return type.
    public void input(){
        //Variable definitions
        int range = 5; //Spice level range

        //Call the base class' input method.
        super.input();

        //Get sauce choice.
        System.out.print("What kind of BBQ sauce do you want: ");
        this.sauce = input.nextLine();

        //Capitalize the first letter of the word
        char [] array = this.sauce.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.sauce = new String(array);

        //Get the spice level.
        System.out.println("From 1 to 5, what spice level do you want?");

        this.spice = choice(range); //Gets user's choice
    }



    //This public method displays the menu item's contents. It takes no
    //arguments and returns nothing.
    public void display(){
        //Call the base class first.
        super.display();

        System.out.println("BBQ sauce: " + this.sauce);
        System.out.println("Spice level: " + this.spice);
        System.out.print("Is it fried? ");

        //Check if it is fried.
        if (this.fried){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
        System.out.println("_________________________________________________");
    }



    //This public method lets a user choose a type of BBQ sauce for their
    //food. It takes no arguments and returns a double, to be the price change.
    public double chooseTaste(){
        //Variable definitions
        double change = 0; //Price change if any

        System.out.print("What kind of BBQ sauce do you want? ");
        this.sauce = input.nextLine();

        //Check if input is valid.
        if (this.sauce == null){
            return 0;
        }

        //Capitalize the first letter of the word
        char [] array = this.sauce.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.sauce = new String(array);

        //For every letter entered, add one cent to the price.
        for (int i = 0; i < this.sauce.length(); ++i){
            change = changeCost(.01);
        }

        return change; //Returns the price change
    }



    //This public method updates a user's preference for their sauce,
    //overloading this and its parent class's method. It takes a String object
    //as an argument and has a void return type.
    public void chooseTaste(String sauce){
        //Check if passed in data is valid.
        if (sauce == null){
            throw new NullPointerException();
        }

        this.sauce = sauce;

        //Capitalize the first letter of the word
        char [] array = this.sauce.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.sauce = new String(array);
    }



    //This public method allows the user to enhance the food by choosing
    //whether it should be fried. It takes no arguments and returns a double, to
    //be the price change.
    public double enhance(){
        //Variable definitions
        double change = 0;      //Price change, if any
        boolean agreed = false; //Holds agree method result

        //Prompt and check user's response if they want fried food.
        System.out.println("Do you want your food fried?");
        agreed = agree();

        //Check if the user said yes and that the fried food is not already
        //fried. Add 50 cents if it is to be fried.
        if (agreed && !this.fried){
            this.fried = true;
            change = changeCost(.50);
        }

        //Otherwise, if the response is no and the food is fried, subtract 50
        //cents from the price and update the field.
        else if (!agreed && this.fried){
            this.fried = false;
            change = changeCost(-.50);
        }

        //Otherwise, the field stays the same and is unchanged.
        return change; //Returns the price change
    }



    //This public method allows the user to restrict the food by choosing
    //the spice level from 1 to 5 (5 being the hottest). It takes no arguments
    //and returns a double, to be the price change.
    public double restrict() {
        //Variable definitions
        int level = 0;     //Spice level input by user
        int range = 5;     //Spice level range
        double change = 0; //Price change, if any

        System.out.println("What spice level do you want between 1 and 5: ");
        level = choice(range); //Get user's choice

        //Check the input difference and add or subtract 25 cents from the cost
        //accordingly.
        if (level < this.spice){
            change = changeCost(-.25); //Subtracts 25 cents
        }
        else if (level > this.spice){
            change = changeCost(.25); //Add 25 cents to price
        }

        this.spice = level;

        return change; //Returns price change
    }
}
