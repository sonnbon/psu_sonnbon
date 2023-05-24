package com.company;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Node.java
// *****************************************************************************
// This file manages the 'Node' class, which manages a container holding a Food
// object. The purpose of the Node is to be a container that will ultimately be
// a base class to different types of nodes for different types of data
// structures. It has wrapper functions that will allow a user to add and
// compare Node's through its Food field. The use of this Node does not require
// a default constructor.
// *****************************************************************************
public class Node {
    private Food item; //Food item to be contained



    //This constructor with arguments sets its Food field to the passed in data.
    //It takes a Food object as an argument and has no return type.
    public Node(Food item) throws CloneNotSupportedException {
        //Check if the passed in item is null.
        if (item == null){
            throw new NullPointerException();
        }

        this.item = (Food)item.clone(); //Clone the passed in data
    }



    //This public method acts as a getter to get the node's Food item data. It
    //takes no arguments and returns a Food object.
    public Food getItem(){
        return this.item;
    }



    //This public method acts as a setter to set the node's Food item data. It
    //takes a Food object as an argument and has a void return type.
    public void setItem(Food item) throws CloneNotSupportedException {
        this.item = (Food)item.clone();
    }



    //This public method acts as a wrapper to compare a Food object's restaurant
    //name (cart). It takes a Food object as an argument and returns and
    //integer, to be the comparison result.
    //(<0: Less than, 0: Match, >0:Greater than)
    public int findCart (Food compare){
        //Check if the field is null.
        if (this.item == null){
            throw new NullPointerException();
        }
        return this.item.findCart(compare); //Returns comparison result
    }



    //This public method acts as a wrapper to compare a Food object's food name.
    //It takes a Food object as an argument and returns an integer, to be the
    //comparison result.
    //(<0: Less than, 0: Match, >0:Greater than)
    public int findFood (Food compare) {
        //Check if the field is null.
        if (this.item == null){
            throw new NullPointerException();
        }
        return this.item.findFood(compare); //Returns comparison result
    }



    //This public method acts as a wrapper to compare restaurant (cart) names.
    //It takes a String object as an argument and returns and integer, to be the
    //comparison result.
    //(<0: Less than, 0: Match, >0:Greater than)
    public int findCart (String cart){
        //Check if the field is null.
        if (this.item == null){
            throw new NullPointerException();
        }
        return this.item.findCart(cart); //Returns comparison result
    }



    //This public method acts as a wrapper to compare food names. It takes a
    //String object as an argument and returns an integer, to be the comparison
    //result.
    //(<0: Less than, 0: Match, >0:Greater than)
    public int findFood (String name){
        //Check if the field is null.
        if (this.item == null){
            throw new NullPointerException();
        }
        return this.item.findFood(name); //Returns comparison result
    }



    //This public method acts as a wrapper to display the contents of the Food
    //field. It takes no arguments and has a void return type.
    public void display(){
        if (this.item == null){
            throw new NullPointerException();
        }

        this.item.display(); //Display item's contents
    }



    //This public method acts as a wrapper to get the current price of the
    //Food field's cost. It takes no arguments and returns a double.
    public double getPrice(){
        //Check if the field is null.
        if (this.item == null){
            throw new NullPointerException();
        }

        return this.item.getPrice();
    }
}
