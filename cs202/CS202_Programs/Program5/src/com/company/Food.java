package com.company;

import java.lang.Cloneable;
import java.text.DecimalFormat;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Food.java
// *****************************************************************************
// This file manages the 'Food' abstract base class, which manages general food
// information that would be used on a restaurant's menu. It manages the food
// cart name (String), the food's name (String), the price (double), the
// quantity (integer), and the size (String). It allows the user to input,
// display, compare (carts and names), and change the cost of an item
// (passing in a quantity and size argument or a price). As an abstract base
// class, it also acts as a hub for derived classes to allow users to add
// something extra, choose a specific taste, and choose a specific diet
// restriction.
// *****************************************************************************
abstract class Food extends User_Response implements Cloneable{
    protected String cart;  //Name of cart/restaurant
    protected String name;  //Name of food
    protected double price; //Cost of food
    protected int quantity; //Number of food items (affects price)
    protected char size;    //Size of food (affects price)



    //This default constructor sets the class's fields to their initial values.
    //It would not typically be necessary but the quantity and size need to be
    //set to default values. It takes no arguments and has no return type.
    public Food(){
        this.cart = "None";
        this.name = "None";
        this.price = 0;
        this.quantity = 1; //Quantity should never be less than one
        this.size = 'M'; //Default size should be medium
    }



    //This constructor sets the class's fields to their initial values, but with
    //the use of arguments. It takes two Strings (the cart and food name), and a
    //double (the price), as arguments and has no return type.
    public Food(String cart, String name, double price){
        //Capitalize the first letter of the passed in cart name
        char [] array = cart.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        cart = new String(array);
        this.cart = cart;

        //Capitalize the first letter of the passed in food name
        array = name.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        name = new String(array);
        this.name = name;

        //Check that the passed in price is greater than zero.
        if (price > 0) {
            this.price = price;
        }
        this.quantity = 1; //Default value
        this.size = 'M';   //Default value
    }



    //This public method overrides the Object cloning method to create a deep
    //copy of this class's object. It takes no arguments and returns an
    //'Object'.
    public Object clone() throws CloneNotSupportedException{
        return super.clone();
    }



    //This public method prompts and reads in the users input. It takes no
    //arguments and has a void return type.
    public void input(){
        //Get the cart name.
        System.out.print("What is the name of the restaurant: ");
        this.cart = input.nextLine();

        //Capitalize the first letter of the word
        char [] array = this.cart.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.cart = new String(array);

        //Get the food name.
        System.out.print("What is the name of the food: ");
        this.name = input.nextLine();

        //Capitalize the first letter of the word
        array = this.name.toCharArray();
        array[0] = Character.toUpperCase(array[0]);
        this.name = new String(array);

        //Get the cost.
        do {
            System.out.print("How much does it cost: ");
            this.price = input.nextDouble();

            if (this.price <= 0){
                System.out.println("Invalid entry. Try again.");
            }

            input.nextLine();

        } while (this.price <= 0);
    }



    //This public method outputs all the contents of the class. It takes no
    //arguments and has a void return type.
    public void display(){
        //Variable definitions
        final DecimalFormat form = new DecimalFormat("0.00"); //Rounds decimals
        System.out.println("_________________________________________________");
        System.out.println("Restaurant: " + this.cart);
        System.out.println("Food: " + this.name);
        System.out.println("Price: $" + form.format(this.price));
        System.out.println("Quantity: " + this.quantity);
        System.out.print("Size: ");

        //Display the correct size.
        if (this.size == 'S'){
            System.out.println("Small");
        }
        else if (this.size == 'M'){
            System.out.println("Medium");
        }
        else{
            System.out.println("Large");
        }
    }



    //This public method compares cart names for a match. It takes a 'Food'
    //object as an argument and returns an integer, to be the comparison
    //result (<0: Less than, 0: Match, >0:Greater than).
    public int findCart (Food compare){
        return findCart(compare.cart); //Returns comparison result
    }



    //This public method compares food names for a match. it takes a 'Food'
    //object as an argument and returns an integer, to be the comparison
    //result (<0: Less than, 0: Match, >0:Greater than).
    public int findFood (Food compare) {
        return findFood(compare.name); //Returns comparison result
    }



    //This public method compares cart names for a match. It takes a String
    //as an argument and returns an integer, to be the comparison result
    //(<0: Less than, 0: Match, >0:Greater than).
    public int findCart (String cart){
        //Throws an error if the field or passed in data is null.
        if (this.cart == null || cart == null){
            throw new NullPointerException();
        }

        //Returns less than 0 if the class's data is less than the passed in
        //data, greater than 0 if it is greater than, and 0 if it is a match.
        return this.cart.compareToIgnoreCase(cart);
    }



    //This public method compares food names for a match. It takes a String as
    //an argument and returns an integer, to be the comparison result
    //(<0: Less than, 0: Match, >0:Greater than).
    public int findFood (String name){
        //Throws an error if the field or passed in data is null.
        if (this.name == null || name == null){
            throw new NullPointerException();
        }

        //Returns less than 0 if the class's data is less than the passed in
        //data, greater than 0 if it is greater than, and 0 if it is a match.
        return this.name.compareToIgnoreCase(name);
    }



    //This method changes the cost of the food item based on the quantity and
    //size of the meal. It takes an integer, to be the quantity, and a String,
    //to be the size, as arguments and returns a double, to be the amount
    //changed.
    public double changeCost(int quantity, char size){
        //Variable definitions
        double change = 0; //Amount price changes

        //Returns a failure of the operation if true.
        if (quantity < 1 || (size != 'S' && size != 'M' && size != 'L')){
            return 0;
        }

        //Check if the passed in data is equal to the default data.
        if (quantity == 1 && size == 'M'){
            return change;
        }

        //Get quantity and multiply price by it.
        this.quantity = quantity;

        //Only multiply if quantity is greater than 1.
        if (this.quantity > 1){
            change = (this.quantity * this.price) - this.price; //Amount changed
            this.price *= this.quantity;
        }

        //Assign passed in size to this class's size.
        this.size = size;
        this.size = Character.toUpperCase(this.size); //Capitalize char

        //Add to or subtract from price depending on meal size. If the size is
        //a medium, do nothing.
        if (this.size == 'S'){
            change -= .5;
            this.price -= .5;
        }
        else if (this.size == 'L'){
            change += 1.5;
            this.price += 1.5;
        }

        return change;
    }



    //This public method adds a passed in value to the price of this class's
    //object. It takes a double as an argument and returns a double, to be the
    //amount changed.
    public double changeCost(double update){
        //Set price to 0 if the passed in value results in a negative sum.
        if (this.price + update < 0){
            update = -1 * this.price; //Make update the opposite of price
            this.price = 0;
        }
        else{
            this.price += update;
        }
        return update;
    }



    //This public method gets the cost of the current object's food. It takes no
    //arguments and returns a double.
    public double getPrice(){
        return this.price;
    }



    //This abstract method acts as a hub for derived class's to choose a type of
    //taste, flavor, or style for their food. It takes no arguments and returns
    //a double.
    public abstract double chooseTaste();

    //This abstract method acts as a hub for derived class's to enhance the
    //food, whether it be through decreasing or increasing the intensity of
    // items. It takes no arguments and returns a double.
    public abstract double enhance();

    //This abstract method acts as a hub for derived class's to add or relieve
    //restrictions on a food item. It takes no arguments and returns a double.
    public abstract double restrict();
}

