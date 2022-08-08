#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char *argv[]) {
    // you can always assume you will have exactly one command line argument.
    assert(argc == 2);
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];
    fgets(string1, MAX_LENGTH, stdin);
    fgets(string2, MAX_LENGTH, stdin);
    
    // convert everything to full uppercase to compare
    char compareArg[MAX_LENGTH];
    int i = 0;
    while (argv[1][i] != '\0') {
        if (islower(argv[1][i])) {
            compareArg[i] = argv[1][i] - 32;
        } else {
            compareArg[i] = argv[1][i];
        }
        i++;
    }
    compareArg[i] = '\0';
    
    char compare1[MAX_LENGTH];
    i = 0;
    while (string1[i] != '\n') {
        if (islower(string1[i])) {
            compare1[i] = string1[i] - 32;
        } else {
            compare1[i] = string1[i];
        }
        i++;
    }
    compare1[i] = '\0';
    
    char compare2[MAX_LENGTH];
    i = 0;
    while (string2[i] != '\n') {
        if (islower(string2[i])) {
            compare2[i] = string2[i] - 32;
        } else {
            compare2[i] = string2[i];
        }
        i++;
    }
    compare2[i] = '\0';
    
    // compare each string with argument string
    i = 0;
    int diff1 = 0;
    while (compareArg[i] != '\0') {
        if (compareArg[i] != compare1[i]) {
            diff1++;
        }
        i++;
    }
    
    i = 0;
    int diff2 = 0;
    while (compareArg[i] != '\0') {
        if (compareArg[i] != compare2[i]) {
            diff2++;
        }
        i++;
    }
    
    
    if (diff1 <= diff2) {
        printf("%d %s", diff1, string1);
    } else {
        printf("%d %s", diff2, string2);
    }
    
    return 0;
}
