/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE 11;        /* Acceptable high end of range */

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
     printf("%d", (* iptr));
     /*Increment the value of the integer pointed to by iptr by 5*/
     (* iptr) += 5;
     /*Print the address of iptr itself*/
     printf("%d", iptr);
     
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
     printf("Value: %d, address: %d", (*jptr), jptr);
     /*Decrement jptr by 1*/
     jptr--;
     /*Print the address of jptr itself*/
     printf("Address: %d", jptr);
}


int main(){
    /* Seed srand using time */
    srand(time(NULL));
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    int x = rand() % RANDOM_RANGE;

    
    /*Print the value and address of x*/
    printf("X is : %d, with an address of %d", x, &x);

        
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("%d", x);
    
    /*Call fooB() with the address of x*/
    fooB(&x);
    
    /*Print the value and address of x*/
    printf("%d", x);
    
    
    /* Answer the following question in a comment right after printing the 
    value and address of x:
    Are the value and address of x different than the value and address 
    that were printed before the call to fooB(..)? Why or why not?
    
    The value and address of x are not different before and after the fooB
    call. In fooB, a pointer to x is passed into the function. No alterations
    are done when dereferencing the pointer. While there is a modification
    to the value jptr is pointing to within fooB, it does not change the
    physical location of where x resides - a pointer is just reassigned 
    within the scope of fooB. The variable x within main has no knowledge
    of what happens to a pointer within the scope of fooB()
    */
    return 0;
}


