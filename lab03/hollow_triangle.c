// COMP1511 Week 3 Laboratory Exercise: Draw a Hollow Triangle
// This program reads and integer n and prints a pattern
// of stars forming a hollow triangle.
// It is assumed that n is greather than 3.
//
// This program was written by Lisa (z5312476) 
// on /09/2020 for tue17a


#include <stdio.h>

int main(void) {
    //declare variables
    int size;
     
     
    //ask user for input
    printf("Enter size: ");
    scanf("%d", &size);
     
    //make sure n is > 3
    if (size <= 3) {
        printf("Please enter a number greater than 3.\n");
        return 1;
    }
     
    //declare variables required for looping
    int i = 0;
    int row = 0;
    
    //create loop to print triangle
    //when number of rows is less than or equal to size
    //print rows of stars and spaces
    while (row < size - 1) {
        while (i <= row) {
            if (i == 0 || i == row) {
                printf("*");
            }
            else {
                printf(" ");
            }
            i++;
        }
        printf("\n");
        row++;
        i = 0;
        
        while (row == size - 1) {
            while (i < row + 1) {
                printf("*");
                i++;
            }
            printf("\n");
            row++;
        } 
    }   
    
    return 0;
}
