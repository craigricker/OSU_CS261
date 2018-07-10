/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE 11

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int * temp = a;
    a = b;
    b = temp;
    
    /*Decrement the value of integer variable c*/
    c--;
    /*Return c*/
    return (c);
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z, returnVal;
   /* Seed srand using time */
   srand((unsigned int) time(NULL));
   
    x = rand() % RANDOM_RANGE;
    y = rand() % RANDOM_RANGE;
    z = rand() % RANDOM_RANGE;

    
    /*Print the values of x, y and z*/
    printf("x: %d\ty: %d\tz: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    returnVal = foo(&x, &y, z);
    /*Print the values of x, y and z*/
    printf("x: %d\ty: %d\tz: %d\n", x, y, z);
    /*Print the value returned by foo*/
    printf("foo return value: %d\n", returnVal);
 
    
    return 0;
}

/*
    a) Is the return value different than the value of integer z? Why or why not?
         Yes, both the values and addresses of z and return value are different.
         Within foo(), c = z, but you decrement c, and you do not decrement z.
         If the function took a pointer, and the dereferenced pointer was --
         then c and z would be equal to one another
    b) Are the values of integers x and y different before and after calling the 
    function foo(..)? Why or why not?
        No, the values are not changed. Within the scope of foo() a and b swap
        what they are pointed to HOWEVER you are only swapping what these values 
        are actively pointing to, and not dereferencing and THEN swapping values.
*/
    
    


