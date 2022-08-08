// COMP1511 Week $ Laboratory Exercise: TITLE
// This program  reads 2 integers and prints their absolute multiple.
//
// This program was written by Lisa (z5312476) 
// on 2/10/2020 for Weekly Test 03

#include <stdio.h>

int main(void) {
    int a;
    int b;
    int multiple;
    
    scanf("%d %d", &a, &b);
    
    multiple = a * b;
    
    if (multiple < 0) {
        multiple = multiple * -1;
    }
    if (multiple == 0) {
        printf("zero\n");
    }
    else {
        printf("%d\n", multiple);
    }
    
    return 0;
}
