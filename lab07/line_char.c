// COMP1511 Week 7  Test: Line Character
// This program reads a line from its input then reads an integer n from its 
// input. It will then write the character in position n from the line.
//
// This program was written by Lisa (z5312476) 
// on 11/2020 for tue17a

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // create string and take input
    char input[256];
    fgets(input, 256, stdin);
    
    // take in the position requested by the user
    int position;
    scanf("%d", &position);

    char character = input[position];
    
    printf("The character in position %d is '%c'\n", position, character);
    
    return 0;
}
