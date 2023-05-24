package com.company;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Ordered_Items.java
// *****************************************************************************
// This file manages the 'Ordered_Items' class, which manages a Linear Linked
// List (LLL) of nodes, which contain Food objects. This LLL data structure will
// act as a list of Food items that a user has ordered to be purchased. It
// allows the user to insert, display, retrieve, and remove orders to and from
// the list.
// *****************************************************************************
public class Ordered_Items {
    private LLL_Node head; //Head reference of the LLL_Node class
    private double total;  //Total cost of all the items in the list



    //This constructor sets the field to its zero equivalent value. It takes no
    //arguments and has no return type.
    public Ordered_Items() {
        head = null;
        total = 0;
    }



    //This public method acts as a wrapper to insert a Food item into the list,
    //sorted by restaurant and food name. It takes a Food object as an argument
    //and returns a double, to be the total cost.
    public double insert(Food item) throws CloneNotSupportedException {
        //Check if passed in data is null.
        if (item == null){
            return 0;
        }

        //Check if the list is empty.
        if (this.head == null){
            this.head = new LLL_Node(item);
            this.total = this.head.getPrice(); //Add cost to the total
            return this.total;                 //Returns the updated total
        }

        this.head = insert(this.head, item); //Traverse the list and insert
        this.total += item.getPrice();       //Add cost to the total
        return this.total;                   //Returns the updated total
    }



    //This private static method inserts a Food item into the list, sorted by
    //restaurant and food name. It takes a LLL_Node and Food object as arguments
    //and returns a LLL_Node.
    private static LLL_Node insert(LLL_Node head, Food item)
                                   throws CloneNotSupportedException {
        //Check if the list is at the end.
        if (head == null){
            head = new LLL_Node(item);
            return head;
        }

        //Check if the item's restaurant is less than the head's restaurant,
        //alphabetically, or, if they are equal, if the item's food is less than
        //the head's food.
        if ((head.findCart(item) > 0) ||
           ((head.findCart(item) == 0) && (head.findFood(item) > 0))){
            LLL_Node hold = new LLL_Node(item);
            hold.setNext(head);
            head = hold;
            return head;
        }

        head.setNext(insert(head.getNext(), item));
        return head;
    }



    //This public method acts as a wrapper to display all the items in the list.
    //It takes no arguments and returns an integer, to be the number of items in
    //the list.
    public int display(){
        //Check if the head is null.
        if (this.head == null){
            return 0;
        }

        return display(this.head); //Traverse the list and get number of items
    }



    //This private static method displays all the items in the list. It takes a
    //LLL_Node object as an argument and returns an integer, to be the number of
    //items in the list.
    private static int display(LLL_Node head){
        //Check if the head is null.
        if (head == null){
            return 0;
        }

        head.display(); //Display head's contents

        return 1 + display(head.getNext());
    }



    //This public method acts as a wrapper to retrieve and display a specific
    //Food item in the list. It takes two String objects, to be the restaurant
    //and food names, as arguments and returns a boolean value.
    public boolean retrieve(String cart, String name){
        //Check if the passed in data is null.
        if (cart == null || name == null){
            throw new NullPointerException();
        }

        //Check if the list is empty.
        if (this.head == null){
            return false;
        }

        return retrieve(this.head, cart, name);
    }



    //This private static method retrieves and displays a specific Food item
    //from a specific restaurant in the list. It takes a LLL_Node object and two
    //String objects, to be the restaurant and food names, as arguments and
    //returns a boolean value.
    private static boolean retrieve(LLL_Node head, String cart, String name){
        //Check if the list is at the end.
        if (head == null){
            return false; //The item was not found
        }

        //Check for a match
        if (head.findCart(cart) == 0 && head.findFood(name) == 0){
            head.display();
            return true;
        }

        return retrieve(head.getNext(), cart, name);
    }



    //This public method acts as a wrapper to remove an item from the list.
    //It takes two String objects, to be the restaurant and food names, as
    //arguments and returns a boolean value.
    public boolean remove(String cart, String name){
        //Variable definitions
        double price_hold = 0; //Holds price before any changes

        //Check if the passed in data is null.
        if (cart == null || name == null){
            throw new NullPointerException();
        }

        //Check if the list is empty.
        if (this.head == null){
            return false;
        }

        price_hold = this.total;                   //Hold the total
        this.head = remove(this.head, cart, name); //Traverse and remove

        return price_hold > this.total; //Returns whether a change was made
    }



    //This private method removes an item from a restaurant. It takes a LLL_Node
    //object, and two String objects, to be the restaurant and food names, as
    //arguments and returns a LLL_Node.
    private LLL_Node remove(LLL_Node head, String cart, String name) {
        //Check if the list is at the end.
        if (head == null){
            return null;
        }

        //Check if there is a match.
        if (head.findCart(cart) == 0 && head.findFood(name) == 0){
            LLL_Node hold = head.getNext();
            this.total -= head.getPrice();
            head = hold;
            return head;
        }

        head.setNext(remove(head.getNext(), cart, name));
        return head;
    }



    //This public method acts as a wrapper to remove all items from the list. It
    //takes no arguments and has a void return type.
    public void removeAll(){
        //Check that the list is not empty.
        if (this.head != null){
            this.head = removeAll(this.head);
        }
    }



    //This private static method removes all the items from the list. It takes
    //no arguments and returns a LLL_Node.
    private static LLL_Node removeAll(LLL_Node head) {
        //Check if the list is empty.
        if (head == null){
            return null;
        }

        LLL_Node hold = head.getNext();
        head = hold;

        head = removeAll(head);
        return head;
    }
}
