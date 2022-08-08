// COMP1511 Week 7 Laboratory Exercise: Caesar Cipher
// This program encrypts input in a caesar cipher as requested by user.
//
// This program was written by Lisa (z5312476) 
// on 11/2020 for tue17a

#include <stdio.h>
#include <stdlib.h>


int encrypt(int character, int shift);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("There was no input!! Please enter a number on command line.\n");
        return 1;
    }
    int shift = (atoi(argv[1]) % 26);
    if (shift < 0) {
        shift = shift + 26;
    }
    int character = getchar();
    while (character != -1) {
        if ((character >= 'A' && character <= 'Z') ||
            (character >= 'a' && character <= 'z')) {
            character = encrypt(character, shift);
        }
        putchar(character);
        character = getchar();
    }
    
}


int encrypt(int character, int shift) {
    if (character >= 'A' && character <= 'Z') {
        if (character + shift <= 'Z') {
            character = character + shift;
        } else if (character + shift > 'Z') {
            character = (character + shift) - 26;
        } else if (character + shift < 'A') {
            character = (character + shift) + 26;
        }
    } else if (character >= 'a' && character <= 'z') {
        if (character + shift <= 'z') {
            character = character + shift;
        } else if (character + shift > 'z') {
            character = (character + shift) - 26;
        } else if (character + shift < 'a') {
            character = (character + shift) + 26;
        }
    }
    
    return character;
}
