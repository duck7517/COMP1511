// COMP1511 Week $ Laboratory Exercise: TITLE
// This program will ask fore a number
// Then display a message accordingly.
//
// This program was written by Lisa (z5312476) 
// on 22/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int userInput;
    
    //Print invitation to enter integer
    printf("Please enter an integer: ");
    scanf("%d", &userInput);
    
    //If the number is between 1 and 5, display the number as a word
    if (userInput == 1) {
        printf("You entered one.\n");
    }
    if (userInput == 2) {
        printf("You entered two.\n");
    }
    if (userInput == 3) {
        printf("You entered three.\n");
    }
    if (userInput == 4) {
        printf("You entered four.\n");
    }
    if (userInput == 5) {
        printf("You entered five.\n");
    }
    
    //If the number is less than 1, 
    //display the less than one message
    
    if (userInput < 1) {
        printf("You entered a number less than one.\n");
    } 
    if (userInput > 5) {
        printf("You entered a number greater than five.\n");
    }





    return 0;
    
}
