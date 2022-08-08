// COMP1511 Week $ Laboratory Exercise: TITLE
// This program reads 3 numbers and tells you whether
// they are strictly increasing, decreasing or neither.
//
// This program was written by Lisa (z5312476) 
// on 2/10/2020 for Weekly Test 03

#include <stdio.h>

int main(void) {
   double a;
   double b;
   double c;
   
    //ask user for 3 numbers
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf\n", &a, &b, &c);
    
    if (a < b && b < c) {
        printf("up\n");
    }
    else if (a > b && b > c) {
        printf("down\n");
    }
    else {
        printf("neither\n");
    }
    
    return 0;
}
