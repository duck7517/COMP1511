// COMP1511 Week 5 Laboratory Exercise: Swap Pointers
// This program will take two pointers to integers as input and 
// swap the values stored in those two integers.
//
// This program was written by Lisa (z5312476) 
// on 13/10/2020 for tue17a


#include <stdio.h>

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}
