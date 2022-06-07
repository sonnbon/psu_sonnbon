//Partial program - practice with pointers

int array[10];
int num1, num2;
int *ptr1;
int *ptr2;

num1 = 10;
num2 = 20;

//legal? illegal? What's the value of the variable (if legal)?
ptr1 = &num1;    //address of operator - it will give me the address of where
                 //num1 is located

cout << *ptr1;   //dereferences operator - GO THERE to where we are pointing
num2 = num1 - *ptr1;    //This would work and equal 0.
num2 - *(num1 - ptr1);   //ILLEGAL!! We can't dereference num1 because it is an
                         //integer

ptr2 = &array[9];
cout << *(ptr2 - num1);  //accesses garbage but does work. If num1 was smaller
                         //it would have output an element in the array.


void function(int & arg);  //here the & is the reference operator
