// COMP1511 Week 2 Laboratory Exercise: Don't Be So Negative
// This program 
//
// This program was written by Lisa (z5312476) 
// on 22/09/2020 for tue17a


#include <stdio.h>

int main(void) {
    int number;
   
    //Creating the user input
    scanf("%d", &number);
   
    //Defining conditions for program output messages
    
    if (number > 0) {
        printf("You have entered a positive number.\n");
    }
    if (number == 0) {
        printf("You have entered zero.\n");
    }
    if (number < 0) {
        printf("Don't be so negative!\n");
    }


    return 0;
}
