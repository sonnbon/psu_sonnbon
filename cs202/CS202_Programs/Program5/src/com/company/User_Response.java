package com.company;

import java.util.InputMismatchException;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 4/5
// Date: March 17, 2022
// Filename: User_Response.java
// *****************************************************************************
// This file manages the 'User_Response' class, which prompts a user to respond
// different prompts. This class has no fields and its public methods prompt a
// user to respond yes or no, and prompt a user to respond with an integer value
// between 0 and a passed in value or a specific char.
// *****************************************************************************
public class User_Response extends Utility {

    //This public method prompts a user to input Y or N, to represent yes or no.
    //It takes no arguments and returns a boolean value.
    public boolean agree(){
        //Variable definitions
        char response = 'N'; //User inputted response

        do {
            //Get yes or no response from user.
            System.out.print("Yes (Y) or No (N): ");
            response = input.next().charAt(0);
            response = Character.toUpperCase(response);
            input.nextLine();

            if (response != 'Y' && response != 'N') {
                System.out.println("Invalid input... Try again.");
            }

        } while (response != 'N' && response != 'Y');

        return response == 'Y'; //Returns true if user inputted Y
    }



    //This public method prompts a user to input a number between 0 and a passed
    //in number. It takes an integer as an argument and returns an integer, to
    //be the users response.
    public int choice(int size){
        //Variable definitions
        int choice = 0; //User inputted choice

        do{
            //Get valid input.
            try{
                //Get number response from list of main menu options.
                System.out.print("Enter a whole number: ");
                choice = input.nextInt();

                if (choice <= 0 || choice > size){
                    throw new InputMismatchException();
                }
            }

            //Catch any thrown errors.
            catch (InputMismatchException error){
                System.out.println("Invalid input... Try again.");
                choice = 0;
            }

            input.nextLine();


        } while (choice <= 0 || choice > size);

        return choice;
    }



    //This public method prompts a user to input a character, to represent the
    //food item choice. It takes no arguments and returns a char.
    public char item_choice(){
        //Variable definitions
        char response = 'B'; //User inputted choice

        do {
            //Get valid response from user.
            System.out.print("Enter character response: ");
            response = input.next().charAt(0);
            response = Character.toUpperCase(response);
            input.nextLine();

            if (response != 'B' && response != 'C' && response != 'D') {
                System.out.println("Invalid input... Try again.");
            }

        } while (response != 'B' && response != 'C' && response != 'D');

        return response;
    }



    //This public method prompts a user to input a character, to represent the
    //size of a food item. It takes no arguments and returns a char.
    public char size_choice(){
        //Variable definitions
        char response = 'M'; //User inputted choice

        do {
            //Get valid response from user.
            System.out.print("Enter character response: ");
            response = input.next().charAt(0);
            response = Character.toUpperCase(response);
            input.nextLine();

            if (response != 'S' && response != 'M' && response != 'L') {
                System.out.println("Invalid input... Try again.");
            }

        } while (response != 'S' && response != 'M' && response != 'L');

        return response;
    }
}

