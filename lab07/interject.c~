// COMP1511 Week 7 Test: Interject
//
// This program was written by Lisa(z5312476)
// on November 2020
//
// This program adds interjections to strings.

#include <stdio.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    char butt[MAX_SIZE] = {0};

    int i = 0;
    int j = index;
    while (str[j] != '\0') {
        butt[i] = str[j];
        i++;
        j++;
    }
    
    i = 0;
    j = index;
    while (interject[i] != '\0') {
        str[j] = interject[i];
        i++;
        j++;
    }
    
    i = 0;
    while (butt[i] != '\0') {
        str[j] = butt[i];
        i++;
        j++;
    }
    str[j] = '\0';
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);
    
    char str5[MAX_SIZE] = "Water Street";
    printf("%s -> ", str5);
    interject(str5, "fall", 5);
    printf("%s\n", str5);
    
    char str6[MAX_SIZE] = "Sponge pants";
    printf("%s -> ", str6);
    interject(str6, "bob", 6);
    interject(str6, "Square", 10);
    printf("%s\n", str6);

    return 0;
}
