package com.company;

import java.lang.Cloneable;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Custom.java
// *****************************************************************************
// This file manages the 'Custom' class, which manages food that can be
// minimally customized. It allows a user to choose a protein (String), whether
// the item is toasted (boolean), and whether they want extra protein (boolean).
// It allows the user to input the menu item, display, choose a taste (edit
// protein), enhance (add extra protein), and restrict (toasted or not) a food
// item.
// *****************************************************************************
public class Custom extends Food implements Cloneable{
    protected String protein;  //Protein choice
    protected boolean toasted; //Is it toasted
    protected boolean extra;   //If user wants extra



    //This default constructor sets the class's fields to their initial values.
    //It takes no arguments and has no return type.
    public Custom(){
        this.protein = "Chicken"; //Default is set to Chicken
        this.toasted = true;      //Default set to toasted
        this.extra = false;       //Default set to no extra
    }



    //This constructor sets the class's fields to their initial values, but with
    //the use of arguments. It takes an integer (the item number), two Strings
    //(the name and protein choice), and a double (the price), as arguments and
    //has no return type.
    public Custom(String cart, String name, double price, String protein){
        //Call parent's constructor
        super(cart, name, price);

        //Capitalize the first letter of the passed in protein
        char [] array = protein.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        protein = new String(array);
        this.protein = protein;

        this.toasted = true;
        this.extra = false;
    }



    //This public method overrides the Object cloning method to create a deep
    //copy of this class's object. It takes no arguments and returns an
    //'Object'.
    public Object clone() throws CloneNotSupportedException{
        return (Custom) super.clone();
    }



    //This public method prompts and reads in the users input. It takes no
    //arguments and has a void return type.
    public void input(){
        //Call the base class' input method.
        super.input();

        //Get protein choice
        System.out.print("What choice of protein: ");
        this.protein = input.nextLine();

        //Capitalize the first letter of the word
        char [] array = this.protein.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.protein = new String(array);
    }



    //This public method displays the menu item's contents. It takes no
    //arguments and returns nothing.
    public void display(){
        //Call the base class first.
        super.display();

        System.out.println("Protein choice: " + this.protein);
        System.out.print("Toasted? ");

        //Check if it is toasted.
        if (this.toasted){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }

        System.out.print("Extra protein? ");

        //Check if extra protein is provided.
        if (this.extra){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
        System.out.println("_________________________________________________");
    }



    //This public method lets a user choose a type of protein for their custom
    //food. It takes no arguments and returns a double, to be the price change.
    public double chooseTaste(){
        //Variable definitions
        double change = 0; //Price change, if any

        System.out.print("What kind of protein would you like? ");
        this.protein = input.nextLine();

        //Check if input data is valid.
        if (this.protein == null){
            return 0;
        }

        //Capitalize the first letter of the word
        char [] array = this.protein.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.protein = new String(array);

        //If the passed in data is greater alphabetically than the default
        //protein type (Chicken), then add 50 cents to the price.
        if (this.protein.compareTo("Chicken") > 0){
            change = changeCost(.50);
        }

        return change; //Returns price change
    }



    //This public method updates a user's preference for their protein,
    //overloading this and its parent class's method. It takes a String object
    //as an argument and has a void return type.
    public void chooseTaste(String protein){
        //Check if passed in data is valid.
        if (protein == null){
            throw new NullPointerException();
        }

        this.protein = protein;

        //Capitalize the first letter of the word
        char [] array = this.protein.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.protein = new String(array);
    }



    //This public method allows the user to enhance the food by choosing
    //whether they want extra protein provided. It takes no arguments and
    //returns a double, to be the price change.
    public double enhance(){
        //Variable definitions
        double change = 0;   //Price change, if any

        //Check what the field is currently set to and prompt the user
        //accordingly.
        if (this.extra){
            System.out.println("Extra protein is already provided. Do you want" +
                               " to keep it this way?");

            //Make user updates to field. Subtract 50 cents from price if no
            //longer extra.
            if (!agree()){
                this.extra = false;
                change = changeCost(-.50);
            }
        }

        //Otherwise, extra is already set to false.
        else{
            System.out.println("Do you want extra protein?");

            //Make user updates to field. Add 50 cents to price if now extra.
            if (agree()){
                this.extra = true;
                change = changeCost(.50);
            }
        }
        return change; //Returns the price change
    }



    //This public method allows the user to change food restrictions, choosing
    //whether the food is toasted. It takes no arguments and returns a double,
    //to be the price changed.
    public double restrict() {
        //Variable definitions
        double change = 0;      //Price change, if any
        boolean agreed = false; //Holds agree method result

        //Check what the field is current set to and prompt the user
        //accordingly.
        System.out.println("Do you want your food toasted?");
        agreed = agree();

        //Make user updates to field. Subtract 25 cents from price if user does
        //not want it toasted.
        if (!agreed && this.toasted) {
            this.toasted = false; //It is not toasted
            change = changeCost(-.25);
        }

        //Otherwise, if the response is yes and it is not already toasted, add
        //25 cents to the price and update the field.
        else if (agreed && !this.toasted){
            this.toasted = true; //It is now toasted
            change = changeCost(.25);
        }

        return change; //Returns price change
    }
}
