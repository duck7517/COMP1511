// COMP1511 Week 2 Laboratory Exercise: Dice Range
// This program will ask the user for the number
// of sides on each dice and the number of dice.
// It will then output the range of possible rolls
// and the average of possible outcomes.
//
// This program was written by Lisa (z5312476) 
// on 23/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int sides;
    int dice;
    int lowerRange;
    int upperRange;
    double average;
    
    //Ask use for input
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &dice);
    
    //Remove invalid responses
    if (sides <= 0 || dice <= 0) {
        printf("These dice will not produce a range.\n");
    }
    else {
    
        //Calculation of range
        lowerRange = dice;
        upperRange = dice * sides;
    
        printf("Your dice range is %d to %d.\n", lowerRange, upperRange);
    
        //Calculation of average
        average = (sides + 1) * 0.5 * dice;
    
        printf("The average value is %lf\n", average);

    }
    return 0;
}
