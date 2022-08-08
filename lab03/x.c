// COMP1511 Week 3 Laboratory Exercise: Draw an X
// This program reads an integer n from standard input, 
// and prints an nxn pattern of asterisks and dashes 
// in the shape of an "X".
// It is assumed that n is odd and >= 5
//
// This program was written by Lisa (z5312476) 
// on 30/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int size;
    
    //ask user for input
    printf("Enter size: ");
    scanf("%d", &size);
    
    //make sure input is odd and >=5
    if (size % 2 == 0 || size < 5) {
        printf(
        "Number is invalid. Please enter an odd number greater than"
        " or equal to 5.\n"
        );
        return 1;
    }
    
    //print the x to the requested size
    
    int row = 0;
    while (row < size) {
        int i = 0;    
        while (i < size) {            
            
            if (i == row || i == size - 1 - row) {
                printf("*");
            }
            else {
                printf("-");
            }
            i++;
        }
        printf("\n");
        row++;
    }

    
    
    return 0;
}
