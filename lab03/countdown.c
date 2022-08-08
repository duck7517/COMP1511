// COMP1511 Week 3 Laboratory Exercise: Countdown
// This program uses a loop to print a countdown from 10 to 1.
//
// This program was written by Lisa (z5312476) 
// on 30/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    //initialise counter to 10
    int counter = 10; 
    // loop until not > 0
    while (counter >= 0) { // Have printed all numbers between 1 and counter
        // print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1; 
    } // counter == -1



    return 0;
}
