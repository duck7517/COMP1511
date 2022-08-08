// COMP1511 Week 3 Laboratory Exercise: Three or Five
// This program takes a positive integer from user
// and prints all integers less than the input that are
// divisible by three or five in ascending order.
//
// This program was written by Lisa (z5312476) 
// on 30/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int number;
    
    //take integer input from user
    printf("Enter number: ");
    scanf("%d", &number);
    
    //make sure integer is positive
    //if not, program will terminate
    if (number <= 0) {
        return 1;
    }
    
    //otherwise run loop to print numbers
    else {
        int i = 1;
        //use integer i as the counter
        
        while (i < number) { //
            if (i % 3 == 0 || i % 5 == 0) {
                printf("%d\n", i);
            }
            i++;
        }
    }
    
    
    return 0;
}
