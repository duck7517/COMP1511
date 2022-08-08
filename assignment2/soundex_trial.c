// A test program for origianl soundex encoder
// 
// Written by Lisa Guo (z5312476)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000

void soundex_encode(char plaintext[MAX_LEN], char code[MAX_LEN]);

int main(void) {
    char name[MAX_LEN];
    fgets(name, MAX_LEN, stdin);
    char code[5] = {'0'};
    soundex_encode(name, code);
    fputs(code, stdout);
    putchar('\n');
}


void soundex_encode(char plaintext[MAX_LEN], char code[5]) {
    int i = 0;
    
    // The first character remains the same. Convert all to uppercase so ASCII
    // values can be compared without case differences.
    while (plaintext[i] != '\n') {
        plaintext[i] = toupper(plaintext[i]);
        i++;
    }
    // Loop through to store the values of each letter. When finding the
    // value of the next letter, if it is the same as the previous, 
    // do not store number and skip to next char of plaintext.
    // If there was a 0, instead of inserting a 0, make a note of the 0
    // so that numbers wont be merged if they do not correspond to 
    // adjacent letters.
    i = 0;
    int j = 0;
    int zeroed = 0;
    while (plaintext[i] != '\n' && j < 4) {
        if (plaintext[i] == 'A' || plaintext[i] == 'E' ||
                   plaintext[i] == 'I' || plaintext[i] == 'O' ||
                   plaintext[i] == 'U' || plaintext[i] == 'Y' ||
                   plaintext[i] == 'H' || plaintext[i] == 'W' ) {
            char value = '0';
            if (j == 0) {
                code[j] = value;
                j++;
            }
            zeroed = 1;
        } else if (plaintext[i] == 'B' || plaintext[i] == 'F' ||
                   plaintext[i] == 'P' || plaintext[i] == 'V') {
            char value = '1';
            if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'C' || plaintext[i] == 'G' ||
                   plaintext[i] == 'J' || plaintext[i] == 'K' ||
                   plaintext[i] == 'Q' || plaintext[i] == 'S' ||
                   plaintext[i] == 'X' || plaintext[i] == 'Z') {
            char value = '2';
            if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'D' || plaintext[i] == 'T' ) {
            char value = '3';
            if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'L') {
            char value = '4';
            if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'M' || plaintext[i] == 'N' ) {
            char value = '5';
            if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'R') {
            char value = '6';
           if (j == 0 || zeroed == 1 || code[j-1] != value) {
                code[j] = value;
                j++;
                zeroed = 0;
            }
        }
        i++;
    }
    // Make sure the first letter of code is the same as plaintext.
    code[0] = plaintext[0];
    // If there are less than 4 characters in the code after encoding,
    // fill in the rest as 0s, keeping last as null terminator.
    while (j < 4) {
        code[j] = '0';
        j++;
    }
    code[4] = '\0';
    
}
