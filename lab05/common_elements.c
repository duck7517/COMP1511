// COMP1511 Week $ Laboratory Exercise: TITLE
// This program will copy all of the values in source1 which are also 
// found in source2 into destination return the number of 
// elements copied into destination
//
// This program was written by Lisa (z5312476) 
// on /10/2020 for tue17a

#include <stdio.h>

int common_elements(
    int length, 
    int source1[length], 
    int source2[length], 
    int destination[length]
);

// test 7 
int main(void) {
    int source1[6] = {1, 4, 1, 5, 9, 2};
    int source2[6] = {1, 1, 2, 3, 5, 8};
    int destination[6];
    
    common_elements(6, source1, source2, destination);
    
    int i = 0;
    while (i < 6) {
        printf("%d", destination[i]);
        i++;
    }
    printf("\n");
    return 0;
}


int common_elements(
    int length, 
    int source1[length], 
    int source2[length], 
    int destination[length]
) {
    int i = 0;
    int counter = 0;
    
    while (i < length) {
        int nextI = 0;
        int j = 0;
        while (j < length && !nextI) {
            if ((source1[i] == source2[j]) && (counter <= i)) {
                destination[counter] = source1[i];
                counter++;
                nextI = 1;
            } 
            j++;
        }
        i++;
    }
    return counter;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
