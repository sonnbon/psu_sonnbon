package com.company;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 5
// Date: March 17, 2022
// Filename: RB_Node.java
// *****************************************************************************
// This file manages the 'RB_Node' class, which manages a left, right, and
// parent reference of the RB_Node class as well as a boolean color value to
// flag whether the node is black or red (true or false, respectively). The
// purpose of the node is to be a container that will ultimately be used in a
// Red Black Tree data structure. It allows the user to get and set the left,
// right, and parent node, as well as the color of the flag. The use of this
// node does not require a default constructor.
// *****************************************************************************
public class RB_Node extends Node{
    private RB_Node left;   //Left reference of the node
    private RB_Node right;  //Right reference of the node
    private RB_Node parent; //Parent reference of the node
    private boolean color;  //Color flag (black = true, red = false)



    //This constructor with arguments calls its parent class to copy a Food item
    //to the node. It takes a Food object as an argument and has no return type.
    public RB_Node(Food item) throws CloneNotSupportedException {
        super(item);
        this.left = null;
        this.right = null;
        this.parent = null;
        this.color = false; //False represents a red flag
    }



    //This public method gets the node that the left field is referencing.
    //It takes no arguments and returns the left reference.
    public RB_Node getLeft(){
        return left;
    }



    //This public method sets the node that the left field will be
    //referencing. It takes a RB_Node object as an argument and has a void return
    //type.
    public void setLeft(RB_Node src){
        this.left = src;
    }



    //This public method gets the node that the right field is referencing.
    //It takes no arguments and returns the right reference.
    public RB_Node getRight(){
        return right;
    }



    //This public method sets the node that the right field will be
    //referencing. It takes a RB_Node object as an argument and has a void return
    //type.
    public void setRight(RB_Node src){
        this.right = src;
    }



    //This public method gets the node that the parent field is referencing.
    //It takes no arguments and returns the parent reference.
    public RB_Node getParent(){
        return parent;
    }



    //This public method sets the node that the parent field will be
    //referencing. It takes a RB_Node object as an argument and has a void return
    //type.
    public void setParent(RB_Node src){
        this.parent = src;
    }



    //This public method gets the color flag of the current node. It takes no
    //arguments and returns a boolean value (black = true, red = false).
    public boolean getColor(){
        return this.color;
    }



    //This public method sets the flag color of the current node. It takes a
    //boolean value as an argument and has a void return type (black = true,
    //red = false).
    public void setColor(boolean flag){
        this.color = flag;
    }
}
