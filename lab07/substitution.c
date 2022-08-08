// COMP1511 Week 7 Laboratory Exercise: Substitution Cipher
// This program encrypts input in a substitution cipher as requested by user.
//
// This program was written by Lisa (z5312476) 
// on 11/2020 for tue17a



#include <stdio.h>
#include <stdlib.h>

int encrypt(int character, char subs[], int charPos);

int main(int argc, char *argv[]) {
    
    int charPos;
    int character = getchar();
    while (character != -1) {
        if (character >= 'A' && character <= 'Z') {
            charPos = character - 'A';
            character = encrypt(character, argv[1], charPos);
        
        } else if (character >= 'a' && character <= 'z') {
            charPos = character - 'a';
            character = encrypt(character, argv[1], charPos);
        }
        putchar(character);
        character = getchar();
    }
    
    return 0;
}


int encrypt(int character, char subs[], int charPos) {
        
    if (character >= 'A' && character <= 'Z') {
        character = subs[charPos] - 'a' + 'A';
    } else if (character >= 'a' && character <= 'z') {
        character = subs[charPos];
    }
    return character;
}
