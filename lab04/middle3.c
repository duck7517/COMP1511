// COMP1511 Week 4 Weekly Test: Middle 3
// This program 
//
// This program was written by Lisa (z5312476) 
// on /10/2020 for tue17a

#include <stdio.h>


int main(void) {
    int inOne;
    int inTwo;
    int inThree;
    
    // ask and scan 3 inputs from user
    printf("Enter integer: ");
    scanf("%d", &inOne);
    printf("Enter integer: ");
    scanf("%d", &inTwo);
    printf("Enter integer: ");
    scanf("%d", &inThree);
    
    printf("Middle: ");
    
    //determine middle
    //first one is middle
    if ((inOne <= inTwo && inOne >= inThree)
    || (inOne >= inTwo && inOne <= inThree)) {
        printf("%d", inOne) ;
    } else if ((inTwo <= inOne && inTwo >= inThree) 
    || (inTwo >= inOne && inTwo <= inThree)) {
        printf("%d", inTwo);
    } else if ((inThree <= inTwo && inThree >= inOne) 
    || (inThree >= inTwo && inThree <= inOne)) {
        printf("%d", inThree);
    }
    
    printf("\n");
    return 0;
}
