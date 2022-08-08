// COMP1511 Week 4 Laboratory Exercise: Print Pi
// This program prints the first n digits of pi, 
// where n is specified by the user
//
// This program was written by Lisa (z5312476) 
// on 6/10/2020 for tue17a
// 

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int digits;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digits);
    
    //Protecc from invalid input
    if (digits > 10) {
        printf("Please enter a number less than or equal to 10.\n");
        return 1;
    }

    int i = 0;
    while (i < digits) {
        if (i == 1) {
            printf(".");
        }
        printf("%d", pi[i]);
        i++;
    }
    printf("\n");

    return 0;
}
