package com.company;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4
// Date: March 17, 2022
// Filename: LLL_Node.java
// *****************************************************************************
// This file manages the 'LLL_Node' class, which manages a next reference of the
// LLL_Node class. The purpose of the node is to be a container that will
// ultimately be used in a Linear Linked List data structure. It allows
// the user to get and set the next node. The use of this node does not require
// a default constructor.
// *****************************************************************************
public class LLL_Node extends Node{
    private LLL_Node next; //Next reference of the Node



    //This constructor with arguments calls its parent class to copy a Food item
    //to the node. It takes a Food object as an argument and has no return type.
    public LLL_Node(Food item) throws CloneNotSupportedException {
        super(item);
        this.next = null;
    }



    //This public method gets the next Node that the next field is referencing.
    //It takes no arguments and returns the next reference.
    public LLL_Node getNext(){
        return next;
    }



    //This public method sets the next Node that the next field will be
    //referencing. It takes a LLL_Node object as an argument and has a void return
    //type.
    public void setNext(LLL_Node src){
        this.next = src;
    }
}
