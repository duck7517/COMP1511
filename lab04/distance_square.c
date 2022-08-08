// COMP1511 Week 4 Weekly Test: Distance Square
// This program reads integer n and prints 
// nxn pattern of integers. Each is the number of steps
// required to reach the centre.
//
// This program was written by Lisa (z5312476) 
// on 9/10/2020

#include <stdio.h>

int main(void) {
    int input;
    //read integer from user
    printf("Enter square size: ");
    scanf("%d", &input);
    
    //create the square
    int row = 0;
    while (row <= (input / 2)) {
        int unit = 0;
        while (unit < (input / 2)) {
            printf("%2d", input - 1 - row - unit);
            unit++;
        }
        while (unit >= (input / 2) && unit < input) {
            printf("%2d", input - (input - unit) - row);
            unit++;
        }
        printf("\n");
        row++;
    }
    
    while (row > (input / 2) && row < input) {
        int unit = 0;
        while (unit < (input / 2)) {
            printf("%2d", input - (input - row) - unit);
            unit++;
        }
        while (unit >= (input / 2) && unit < input) {
            printf("%2d", input + 1 - (input - row) - (input - unit));
            unit++;
        }
        printf("\n");
        row++;
    }
    return 0;
}
