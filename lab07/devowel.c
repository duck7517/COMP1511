// COMP1511 Week 7 Laboratory Exercise: Devowelling Text
// This program reads character and returns it without lowercase vowels.
//
// This program was written by Lisa (z5312476) 
// on 10/2020 for tue17a

#include <stdio.h>
#include <stdlib.h>


int is_vowel(int character);

int main(void) {
    
    int character = getchar();
    while (character != -1) {
        if (!is_vowel(character)) {
            putchar(character);
        }
        character = getchar();
    }
    return 0;
}


int is_vowel(int character) {
    if (character == 'a' ||
        character == 'e' ||
        character == 'i' ||
        character == 'o' ||
        character == 'u'
    ) {    
        return 1;
    }
    return 0;
}

