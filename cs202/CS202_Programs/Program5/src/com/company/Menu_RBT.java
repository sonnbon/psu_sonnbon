package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.Scanner;

// *****************************************************************************
// Author: Connor Baron-Williams
// Class: CS202 - Programming Systems
// Assignment: Program 5
// Date: March 17, 2022
// Filename: Menu_RBT.java
// *****************************************************************************
// This file manages the 'Menu_RBT' class, which manages a Red Black Balanced
// Tree (RBT) of food items (using the Food class) that a user can browse
// through to order from. It allows the user to input, display, edit, and
// retrieve items from the "menu", both to order and to look up specific foods.
// It also allows the user to read in from an external file, so menu items do
// not need to be manually entered. This class specifically manages a root
// reference to an RB_Node class as well as boolean rotation flags meant to help
// other methods determine whether the RBT needs to rotate right or left to keep
// the tree balanced.
// *****************************************************************************
public class Menu_RBT extends User_Response{
    private RB_Node root;         //Root reference of a node
    private boolean left_rotate;  //Determines if tree needs left rotation
    private boolean right_rotate; //Determines if tree needs right rotation
    private boolean left_right;   //Determines if tree needs left then right
                                  //rotation
    private boolean right_left;   //Determines if tree needs right then left
                                  //rotation


    //This default constructor sets all the fields to their zero equivalent or
    //default values. It takes no arguments and has no return type.
    public Menu_RBT(){
        this.root = null;
        this.left_rotate = false;  //True when left rotation needed
        this.right_rotate = false; //True when right rotation needed
        this.left_right = false; //True when both rotations needed, left first
        this.right_left = false; //True when both rotations needed, right first
    }



    //This public method allows the user to input a specific type of food item
    //for insertion into the RBT. It takes no arguments and has a void return
    //type.
    public void input() throws CloneNotSupportedException {
        //Variable definitions
        Food item = null;    //Food item to be added to list

        //Get users food ordering type choice.
        System.out.println("""
                Which type of food would you like to add?
                B - Barbeque
                C - Custom (Build your own)
                D - Dietary Restrictions""");

        //Get user's response.
        switch (item_choice()){
            case 'B':
                //New BBQ object.
                item = new BBQ();
                break;
            case 'C':
                //New Custom object.
                item = new Custom();
                break;
            case 'D':
                //New Dietary object.
                item = new Dietary();
                break;
            default:
                System.out.println("This should not get called.");
                break;
        }

        assert item != null; //Assert whether item got a new object created.
        item.input();        //Input item contents
        insert(item);        //Insert the item into the tree
    }



    //This public method acts as a wrapper to insert a Food item into the RBT,
    //sorted by restaurant and food name. It takes a Food object as an
    //argument and has a void return type.
    public void insert(Food item) throws CloneNotSupportedException {
        //Check if the tree is empty.
        if (this.root == null){

            //Create new node with Food item passed in, the root's parent
            //and left and right children set to null, and the color flag set
            //to false (Red).
            this.root = new RB_Node(item);
            this.root.setColor(true); //Sets a black flag
            return;
        }

        //Otherwise, traverse to the end of the tree to insert item.
        this.root = insert(this.root, item);
    }



    //This private method inserts a new Food item into the tree. It takes a
    //RB_Node and Food object as arguments and returns a RB_Node.
    private RB_Node insert(RB_Node root, Food item) throws
                           CloneNotSupportedException {
        //Variable definitions
        boolean rr_conflict = false; //Checks for Red Red conflict (true)
        int traversal = 0;           //Traversal direction (<0=left, >0=right)

        //Check if at end of tree.
        if (root == null){
            //Create new node with Food item passed in, the root's parent
            //and left and right children set to null, and the color flag set
            //to false (Red).
            root = new RB_Node(item);
            return root;
        }

        traversal = traverse(root, item); //Get traversal direction

        //If the passed in item is less than the root's restaurant name, go
        //left.
        if (traversal < 0){
            root.setLeft(insert(root.getLeft(), item)); //Traverse and set left
            root.getLeft().setParent(root); //Set root's left's parent to root.

            //Check that root is not referencing the true root of the tree.
            if (root != this.root){

                //Check if the root's and its left's color flag are red (false).
                if (!root.getColor() && !root.getLeft().getColor()){
                    rr_conflict = true; //There is a Red Red conflict
                }
            }
        }

        //Otherwise, traverse right.
        else{
            root.setRight(insert(root.getRight(), item)); //Traverse/set right
            root.getRight().setParent(root); //Set root's right's parent to root

            //Check that root is not referencing the true root of the tree.
            if (root != this.root){

                //Check if the root's and its right's color flag are red
                //(false).
                if (!root.getColor() && !root.getRight().getColor()){
                    rr_conflict = true; //There is a Red Red conflict
                }
            }
        }

        //Determine rotation and/or rotation pattern for tree and reset rotation
        //field flags to false when done.
        //Check if left rotation needed.
        if (this.left_rotate){
            root = rotateLeft(root);        //Rotate root left
            root.setColor(true);            //Set root's color to black
            root.getLeft().setColor(false); //Set root's left's color to red
            this.left_rotate = false;       //Reset rotate flag to false
        }

        //Check if right rotation is needed.
        else if (this.right_rotate){
            root = rotateRight(root);        //Rotate root right
            root.setColor(true);             //Set root's color to black
            root.getRight().setColor(false); //Set root's right's color to red
            this.right_rotate = false;       //Reset rotate flag to false
        }

        //Check if right and left rotation is needed, with right rotation first.
        else if (this.right_left){
            //Rotate root's right child to the right, setting it to root's right
            //child.
            root.setRight(rotateRight(root.getRight()));
            root.getRight().setParent(root); //Set root's right's parent to root
            root = rotateLeft(root);         //Rotate root left
            root.setColor(true);             //Set root's color to black
            root.getLeft().setColor(false);  //Set root's left's color to red
            this.right_left = false;         //Reset rotate flag to false
        }

        //Check if left and right rotation is needed, with left rotation first.
        else if (this.left_right){
            //Rotate root's left child to the left, setting it to root's left
            //child
            root.setLeft(rotateLeft(root.getLeft()));
            root.getLeft().setParent(root);  //Set root's left's parent to root
            root = rotateRight(root);        //Rotate root right
            root.setColor(true);             //Set root's color to black
            root.getRight().setColor(false); //Set root's right's color to red
            this.left_right = false;         //Reset rotate flag to false
        }

        //Check if there are any Red Red conflicts to deal with.
        if (rr_conflict){

            //Check if the root's parent's right child is referencing the
            //current root.
            if (root.getParent().getRight() == root){

                //Check if the root's parent's left child is null or if it is
                //black (true).
                if (root.getParent().getLeft() == null ||
                    root.getParent().getLeft().getColor()){

                    //Check that the root's left child is not null and that its
                    //left child is red (false).
                    if (root.getLeft() != null && !root.getLeft().getColor()){
                        //Set right, then left rotation flag to true.
                        this.right_left = true;
                    }

                    //Otherwise, check that root's right child is not null and
                    //that its right child is red (false).
                    else if (root.getRight() != null &&
                             !root.getRight().getColor()){
                        //Set left rotation flag to true.
                        this.left_rotate = true;
                    }
                }

                //Otherwise, the root's parent's left child is not null and it
                //is red. Set root's and its parent's left child to black
                //(true).
                else{
                    root.getParent().getLeft().setColor(true);
                    root.setColor(true);

                    //Check that root's parent is not referencing the true root
                    //of the tree and set it to red.
                    if (root.getParent() != this.root){
                        root.getParent().setColor(false);
                    }
                }
            }

            //Otherwise, root's parent's right child is not referencing the
            //current root.
            else{

                //Check if root's parent's right child is null or if its color
                //is black (true).
                if (root.getParent().getRight() == null ||
                    root.getParent().getRight().getColor()){

                    //Check that root's left child is not null and that its
                    //color is red (false).
                    if (root.getLeft() != null && !root.getLeft().getColor()){
                        //Set right rotation flag to true.
                        this.right_rotate = true;
                    }

                    //Otherwise, check that root's right child is not null and
                    //that its color is red.
                    else if (root.getRight() != null &&
                             !root.getRight().getColor()){
                        //Set left, then right rotation flag to true.
                        this.left_right = true;
                    }
                }

                //Otherwise, root's parent's right child is not null and its
                //color is red. Set root's and its parent's right child to black
                //(true).
                else{
                    root.getParent().getRight().setColor(true);
                    root.setColor(true);

                    //Check that the root's parent is not referencing the true
                    //root of the tree and set its color to red (false).
                    if (root.getParent() != this.root){
                        root.getParent().setColor(false);
                    }
                }
            }
        }
        return root;
    }



    //This private method determines, which way to traverse a tree based on the
    //two significant details of a food item, the restaurant name and the food
    //name. It takes a RB_Node and a Food object as arguments and returns an
    //integer to be the traversal result (less than 0 = go left, greater than
    //0 = go right).
    private int traverse(RB_Node root, Food item){
        //Variable definitions
        int result = 0; //Comparison result

        if (root == null || item == null){
            throw new NullPointerException();
        }

        //Check if the passed in item is less than the root's restaurant name.
        if (root.findCart(item) > 0){
            result = -1;
        }

        //Check if the passed in item is greater than the root's restaurant
        //name.
        else if (root.findCart(item) < 0){
            result = 1;
        }

        //If the restaurant names are the same, then check if the item is less
        //than the root's food name.
        else if (root.findFood(item) > 0){
            result = -1;
        }

        //Otherwise the restaurant names are the same and the item's food name
        //greater than or equal to the root's food name.
        else{
            result = 1;
        }

        return result;
    }



    //This private method determines which way to traverse a tree based on the
    //two significant details of a food item, the restaurant name and the food
    //name. It takes a RB_Node and two String objects as arguments and returns
    //an integer to be the traversal result (less than 0 = go left, greater
    //than 0 = go right).
    private int traverse(RB_Node root, String cart, String name){
        //Variable definitions
        int result = 0; //Comparison result

        if (root == null || cart == null || name == null){
            throw new NullPointerException();
        }

        //Check if the passed in item is less than the root's restaurant name.
        if (root.findCart(cart) > 0){
            result = -1;
        }

        //Check if the passed in item is greater than the root's restaurant
        //name.
        else if (root.findCart(cart) < 0){
            result = 1;
        }

        //If the restaurant names are the same, then check if the item is less
        //than the root's food name.
        else if (root.findFood(name) > 0){
            result = -1;
        }

        //Otherwise the restaurant names are the same and the item's food name
        //greater than or equal to the root's food name.
        else{
            result = 1;
        }

        return result;
    }



    //This private method rotates the RBT to the right, shifting the current
    //root to the right, making its left child the new root. It takes a RB_Node
    //object as an argument and returns a RB_Node.
    private RB_Node rotateRight(RB_Node root){
        //Variable definitions
        RB_Node h_parent = root.getLeft();    //To be parent, holds root's left
        RB_Node h_left = h_parent.getRight(); //To be left child, holds
                                              //h_parent's right.

        h_parent.setRight(root); //Set future parent's right child to root

        root.setLeft(h_left); //Set root's left to future left child

        root.setParent(h_parent); //Set root's parent to future parent

        //Check that the future left child is not null and set its parent to the
        //current root.
        if (h_left != null){
            h_left.setParent(root);
        }

        return h_parent; //Returns future parent (new root)
    }



    //This private method rotates the RBT to the left, shifting the current
    //root to the left, making its right child the new root. It takes a RB_Node
    //object as an argument and returns a RB_Node.
    private RB_Node rotateLeft(RB_Node root){
        //Variable definitions
        RB_Node h_parent = root.getRight();   //To be parent, holds root's right
        RB_Node h_right = h_parent.getLeft(); //To be right child, holds
                                              //h_parent's left.

        h_parent.setLeft(root); //Set future parent's left child to root

        root.setRight(h_right); //Set root's right to future right child

        root.setParent(h_parent); //Set root's parent to future parent

        //Check that the future right child is not null and set its parent to
        //the current root.
        if (h_right != null){
            h_right.setParent(root);
        }

        return h_parent; //Returns future parent (new root)
    }



    //This public method acts as a wrapper to display all the items in a tree.
    //It takes no arguments and returns an integer, to be the number of items
    //displayed.
    public int display() {
        //Check if the tree is empty.
        if (this.root == null){
            return 0;
        }

        return display(root); //Traverse and display the tree.
    }



    //This private static method displays all the items in a tree. It takes a
    //RB_Node object as an argument and returns an integer, to be the number of
    //items displayed.
    private static int display(RB_Node root){
        //Variable definitions
        int count = 0; //Number of items displayed

        //Check if at the end of the tree.
        if (root == null){
            return 0;
        }

        count = display(root.getLeft());

        root.display(); //Display root's contents
        ++count;

        count += display(root.getRight());

        return count;
    }



    //This public method acts as a wrapper to find and display all food's of a
    //specific name. It takes a String as an argument and returns an integer, to
    //be the number of items displayed.
    public int findFood(String name){
        //Check if the tree is empty.
        if (this.root == null){
            return 0;
        }

        return findFood(this.root, name); //Traverse and search the tree.
    }



    //This private static method finds and displays all food items that match
    //the passed in name. It takes a RB_Node and String object as arguments and
    //returns an integer, to be the number of items displayed.
    private static int findFood(RB_Node root, String name){
        //Variable definitions
        int count = 0; //Number of items displayed

        //Check if at the end of the tree.
        if (root == null){
            return 0;
        }

        count = findFood(root.getLeft(), name);

        //Check for a match.
        if (root.findFood(name) == 0){
            root.display();
            ++count;
        }

        count += findFood(root.getRight(), name);

        return count;
    }



    //This public method acts as a wrapper to retrieve an item from the tree,
    //let the user choose ordering options, and then return it. It takes two
    //String arguments, the restaurant name and the food item, and returns a
    //'Food' object.
    public Food orderItem(String cart, String name) {
        //Variable definitions
        Food item = null; //Temporary food item to be ordered

        //Check if the tree is empty.
        if (this.root == null) {
            return null;
        }

        return orderItem(this.root, cart, name, item);
    }



    //This private method retrieves an item from the tree, lets the user choose
    //ordering options, and then returns it. It takes a RB_Node object and two
    //Strings, the restaurant name and the food item, as arguments and returns a
    //'Food' object.
    private Food orderItem(RB_Node root, String cart, String name,
                                  Food item) {
        //Variable definitions
        final DecimalFormat form = new DecimalFormat("0.00"); //Rounds decimals
        double change = 0;     //Price change, if any
        int quantity = 0;      //Quantity of the ordered item
        int range = 100;       //Max number a quantity of a single food item can be
        int traversal = 0;     //Traversal direction (<0 = go left, >0 = go right)
        char size = 'M';       //Size of the ordered item

        //Check if the tree is empty.
        if (root == null){
            return item;
        }

        //Check if a match is found and let user personalize food order.
        if (root.findCart(cart) == 0 && root.findFood(name) == 0){
            item = root.getItem();       //Copy the root's data over
            change = item.chooseTaste(); //Taste selection
            change += item.enhance();    //Food enhancement
            change += item.restrict();   //Food restrictions

            //Prompt user for quantity.
            System.out.println("How many orders of this item (up to 100!)?");

            quantity = choice(range); //Get user's response

            //Prompt user for size.
            System.out.println("What size? Small (S), Medium (M), or Large (L)?");

            size = size_choice(); //Get user's response

            change += item.changeCost(quantity, size); //Update price change

            System.out.println("\nItem ordered!");

            //Check if the price change is negative or positive.
            if (change < 0){
                System.out.println("And with a price deduction of $" +
                                   form.format(change));
            }
            else if (change > 0){
                System.out.println("But with a price increase of $" +
                                    form.format(change));
            }
            return item;
        }

        traversal = traverse(root, cart, name); //Get traversal direction

        //If traversal is less than 0, go left.
        if (traversal < 0){
            return orderItem(root.getLeft(), cart, name, item);
        }

        //Otherwise, go right.
        return orderItem(root.getRight(), cart, name, item);
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It acts as a wrapper to traverse the tree and
    //update correct Food items. It takes no arguments and returns an integer,
    //to be the number of items updated.
    public int editDiet() throws CloneNotSupportedException {
        //Variable definitions
        String choice = ""; //User inputted edit choice

        //Check if the tree is empty.
        if (this.root == null) {
            return 0;
        }

        //Prompt if user wants to change all dietary food's diets (vegan, etc.).
        System.out.println("""
                Do you want to change the diet type of all foods with
                dietary restrictions?""");

        //Get user's response
        if (agree()) {
            System.out.println("What diet would you like for all foods?");
            System.out.print("(vegan, vegetarian, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update dietary foods, overloading generic food class.
            return editDiet(this.root, choice);
        }
        return 0;
    }



    //This private static method bulk updates any Food item's diet in the tree
    //that is an instance of the Dietary class. It takes a RB_Node and String
    //object as arguments and returns an integer, to be the number of items
    //updated.
    private static int editDiet(RB_Node root, String choice)
                                throws CloneNotSupportedException {
        //Variable definitions
        int count = 0;       //Number of items updated
        Dietary item = null; //Temporary Dietary object

        //Check if tree has been traversed.
        if (root == null) {
            return 0;
        }

        count = editDiet(root.getLeft(), choice);

        //Check if the current item is an instance of the Dietary class before
        //updating it.
        if (root.getItem() instanceof Dietary) {
            item = (Dietary)root.getItem();
            item.chooseTaste(choice);
            root.setItem(item);
            ++count;
        }

        count += editDiet(root.getRight(), choice);
        return count;
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It acts as a wrapper to traverse the tree and
    //update correct Food items. It takes no arguments and returns an integer,
    //to be the number of items updated.
    public int editProtein() throws CloneNotSupportedException {
        //Variable definitions
        String choice = ""; //User inputted edit choice

        //Check if the tree is empty.
        if (this.root == null) {
            return 0;
        }

        //Prompt if user wants to change all customizable food's proteins.
        System.out.println("""
                           Do you want to change the protein of all customizable
                           foods?""");

        //Get user's response.
        if (agree()) {
            System.out.println("What protein would you like for all foods?");
            System.out.print("(chicken, tofu, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update Custom foods, overloading generic food class.
            return editProtein(this.root, choice);
        }
        return 0;
    }



    //This private static method bulk updates any Food item's protein in the
    //tree that is an instance of the Custom class. It takes a RB_Node and
    //String object as arguments and returns an integer, to be the number of
    //items updated.
    private static int editProtein(RB_Node root, String choice)
                                   throws CloneNotSupportedException {
        //Variable definitions
        int count = 0;      //Number of items updated
        Custom item = null; //Temporary Custom object

        //Check if tree has been traversed.
        if (root == null) {
            return 0;
        }

        count = editProtein(root.getLeft(), choice);

        //Check if the current item is an instance of the Dietary class before
        //updating it.
        if (root.getItem() instanceof Custom) {
            item = (Custom)root.getItem();
            item.chooseTaste(choice);
            root.setItem(item);
            ++count;
        }

        count += editProtein(root.getRight(), choice);
        return count;
    }



    //This public method prompts the user to enter whether they want to bulk
    //update items in the menu. It acts as a wrapper to traverse the tree and
    //update correct Food items. It takes no arguments and returns an integer,
    //to be the number of items updated.
    public int editSauce() throws CloneNotSupportedException {
        //Variable definitions
        String choice = ""; //User inputted edit choice

        //Check if the tree is empty.
        if (this.root == null) {
            return 0;
        }

        //Prompt if user wants to change all BBQ food's sauce.
        System.out.println("""
                           Do you want to change the sauce of all BBQ type
                           foods?""");

        //Get user's response.
        if (agree()) {
            System.out.println("What sauce would you like for all foods?");
            System.out.print("(House Sauce, BBQ Sauce, etc.): ");
            choice = input.next();
            input.nextLine();

            //Capitalize the first letter of the passed in food name
            char [] array = choice.toCharArray();
            array[0] = Character.toUpperCase(array[0]);
            choice = new String(array);

            //Search and update BBQ foods, overloading generic food class.
            return editSauce(this.root, choice);
        }
        return 0;
    }



    //This private static method bulk updates any Food item's sauce in the tree
    //that is an instance of the BBQ class. It takes a RB_Node and String
    //object as arguments and returns an integer, to be the number of items
    //updated.
    private static int editSauce(RB_Node root, String choice)
                                 throws CloneNotSupportedException {
        //Variable definitions
        int count = 0;   //Number of items updated
        BBQ item = null; //Temporary BBQ object

        //Check if tree has been traversed.
        if (root == null) {
            return 0;
        }

        count = editSauce(root.getLeft(), choice);

        //Check if the current item is an instance of the Dietary class before
        //updating it.
        if (root.getItem() instanceof BBQ) {
            item = (BBQ)root.getItem();
            item.chooseTaste(choice);
            root.setItem(item);
            ++count;
        }

        count += editSauce(root.getRight(), choice);
        return count;
    }



    //This public method reads in an external text file and adds food items to
    //the RBT. It takes a String object, to be the filename, as an
    //argument and returns an integer, to be the number of items loaded.
    public int load(String filename) throws FileNotFoundException,
                                            CloneNotSupportedException {
        //Variable definitions
        Food item = null;       //Temporary food item to be added to list
        int count = 0;          //Number of items loaded
        boolean success = true; //Checks for read success
        char type = 'B';        //Food item type read in


        //Create another Scanner object to read in the passed in file name,
        //which is passed into a new File object.
        Scanner read = new Scanner(new File(filename));
        read.useDelimiter(","); //Delimiter to split text in external file

        //Read in each option of each line until the end of the file is reached.
        while (read.hasNext()) {
            type = read.next().charAt(0);

            //Check if the type is BBQ and create a new BBQ object, reading each
            //variable into its constructor.
            if (type == 'B'){
                item = new BBQ(read.next(), read.next(), read.nextDouble(),
                        read.next());
                read.nextLine();
            }

            //Check if the type is Custom and create a new Custom object,
            //reading in each variable into its constructor.
            else if (type == 'C'){
                item = new Custom(read.next(), read.next(), read.nextDouble(),
                        read.next());
                read.nextLine();
            }

            //Check if the type is Dietary and create a new Dietary object,
            //reading in each variable into its constructor.
            else if (type == 'D'){
                item = new Dietary(read.next(), read.next(), read.nextDouble());
                read.nextLine();
            }

            //Otherwise, something is wrong and success gets flagged false.
            else{
                success = false; //There should only be three possible responses
            }

            insert(item); //Add new item to RBT
            ++count;
        }

        //Check that data was read in.
        if (count == 0 || !success){
            return 0;
        }

        return count;
    }



    //This public method acts as a wrapper to remove all items from the RBT. It
    //takes no arguments and has a void return type.
    public void removeAll(){
        //Check if the tree is empty.
        if (this.root == null){
            return;
        }
        this.root = removeAll(this.root); //Traverse and remove all
    }



    //This private static method removes all of the items from the RBT. It takes
    //a RB_Node object as an argument and returns an RB_Node node.
    private static RB_Node removeAll(RB_Node root) {
        //Check if at the end of the list.
        if (root == null){
            return null;
        }

        root.setLeft(removeAll(root.getLeft()));
        root.setRight(removeAll(root.getRight()));

        root = null;
        return root;
    }
}
