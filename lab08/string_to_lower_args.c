// COMP1511 Week $ Laboratory Exercise: TITLE
// This program 
//
// This program was written by Lisa (z5312476) 
// on 11/2020 for tue17a


#include <stdio.h>



int main(int argc, char *argv[]) {
    int i = 1;
    int ascii = 0;
    while (i < argc) {
        int j = 0;
        while (argv[i][j] != 0) {
            ascii = argv[i][j];
            if (ascii >= 'A' && ascii <= 'Z') {
                ascii = ascii - 'A' + 'a';
            }
            putchar(ascii);
            j++;
        }
        printf(" ");
        i++;
    }
    printf("\n");
    
    
    return 0;
}
