package com.company;

import java.util.Scanner;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: Utility.java
// *****************************************************************************
// This file manages a 'Utility' class that initializes and creates a new
// Scanner object field, to be used for all input stream purposes. Only a
// constructor is used in this class.
// *****************************************************************************
public class Utility {
    protected Scanner input; //For inputting data in the input stream

    //This constructor creates a new Scanner object that allows for an input
    //stream. It takes no arguments and has no return type.
    public Utility() {
        input = new Scanner(System.in);
    }
}
