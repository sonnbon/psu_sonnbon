package com.company;

import java.lang.Cloneable;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Dietary.java
// *****************************************************************************
// This file manages the 'Dietary' class, which manages food that can edit
// dietary needs including whether an item has gluten (boolean), what kind of
// diet it is (vegan, pescaterian, etc. - String), and what condiments to hold
// from the food (String). It allows the user to input the menu item, display,
// choose a taste (edit diet), enhance (make glutenous), and restrict (an item
// to hold) a food item.
// *****************************************************************************
public class Dietary extends Food implements Cloneable{
    protected boolean gluten;  //It is gluten free or not
    protected String restrict; //What item to hold from the food
    protected String diet;     //Is it vegan, vegetarian, pescatarian, etc.?



    //This default constructor sets the class's fields to their initial values.
    //It takes no arguments and has no return type.
    public Dietary(){
        this.gluten = true;     //Default is set to glutenous
        this.restrict = "None"; //Default is set to None
        this.diet = "Regular";  //Default is set to Regular
    }



    //This constructor with arguments sets the class's fields as well as its
    //parent's fields to their initial values. It takes two Strings, to be the
    //restaurant and food name, and a double, to be the price, as arguments and
    //has no return type.
    public Dietary(String cart, String name, double price){
        //Call the parent's constructor
        super(cart, name, price);

        this.gluten = true;     //Default is set to glutenous
        this.restrict = "None"; //Default is set to None
        this.diet = "Regular";  //Default is set to Regular
    }



    //This public method overrides the Object cloning method to create a deep
    //copy of this class's object. It takes no arguments and returns an
    //'Object'.
    public Object clone() throws CloneNotSupportedException{
        return (Dietary) super.clone();
    }



    //This public method prompts and reads in the users input. It takes no
    //arguments and has a void return type.
    public void input(){
        //Call the base class' input method.
        super.input();

        //Get diet choice.
        System.out.print("What kind of diet (vegan, vegetarian, etc.): ");
        this.diet = input.nextLine();

        //Capitalize the first letter of the word
        char [] array = this.diet.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.diet = new String(array);
    }



    //This public method displays the menu item's contents. It takes no
    //arguments and returns nothing.
    public void display(){
        //Call the base class first.
        super.display();

        System.out.println("Diet choice: " + this.diet);
        System.out.println("Items to hold: " + this.restrict);
        System.out.print("Gluten free? ");

        //Check if it is gluten free
        if (this.gluten){
            System.out.println("No");
        }
        else{
            System.out.println("Yes");
        }
        System.out.println("_________________________________________________");
    }



    //This public method lets a user choose a type of diet for their dietary
    //food. It takes no arguments and returns a double, to be the price change.
    public double chooseTaste(){
        //Variable definitions
        double change = 0; //Price change, if any

        System.out.print("What kind of diet? (vegan, vegetarian, regular, etc.): ");
        this.diet = input.nextLine();

        //Check if input data is valid.
        if (this.diet == null){
            return 0;
        }

        //Capitalize the first letter of the word
        char [] array = this.diet.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.diet = new String(array);

        //If the input data is not equal to "Regular" then add 75 cents to
        //the price.
        if (this.diet.compareTo("Regular") != 0){
            change = changeCost(.75);
        }

        return change; //Returns price change
    }



    //This public method updates a user's preference for their diet, overloading
    //this and its parent class's method. It takes a String object as an
    //argument and has a void return type.
    public void chooseTaste(String diet){
        //Check if passed in data is valid.
        if (diet == null){
            throw new NullPointerException();
        }

        this.diet = diet;

        //Capitalize the first letter of the word
        char [] array = this.diet.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.diet = new String(array);
    }



    //This public method allows the user to enhance the food by choosing
    //whether they want to make it glutenous. It takes no arguments and
    //returns a double, to be the price change.
    public double enhance(){
        //Variable definitions
        double change = 0;   //Price change, if any

        //Check what the field is currently set to and prompt the user
        //accordingly.
        if (this.gluten){
            System.out.println("Do you want to make this gluten free?");

            //Make user updates to field. Adds a dollar to the price if gluten
            //free.
            if (agree()){
                this.gluten = false;
                change = changeCost(1);
            }
        }

        //Otherwise, it is already gluten free.
        else{
            System.out.println("Do you want to add gluten?");

            //Make user updates to field. Makes no change to the price.
            if (agree()){
                this.gluten = true;
            }
        }
        return change; //Returns price change
    }



    //This public method allows the user to change food restrictions, choosing
    //what items to hold. It takes no arguments and returns a double, to be the
    //price change.
    public double restrict() {
        //Variable definitions
        double change = 0; //Price change, if any

        //Check what the field is current set to and prompt the user
        //accordingly.
        System.out.println("What do you want to hold from the food? " +
                           "Enter 'None' if you want everything.");
        System.out.print("(no tomatoes, no onions, etc.: ");
        this.restrict = input.nextLine();

        //If the user wants to hold items, 50 cents will get added to the price.
        if (this.restrict.compareTo("None") != 0){
            change = changeCost(.50);
        }

        return change; //Returns the price change
   }
}
