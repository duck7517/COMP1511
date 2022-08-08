// COMP1511 Week 3 Laboratory Exercise: Ordering Three Integers
// This program will take 3 integer inputs from the user
// and print them in numerically ascending order. 
//
// This program was written by Lisa (z5312476) 
// on 30/09/2020 for tue17a


#include <stdio.h>

int main(void) {
    int firstInput;
    int secondInput;
    int thirdInput;

    //Requesting integer inputs from user
    printf("Enter integer: ");
    scanf("%d", &firstInput);
    printf("Enter integer: ");
    scanf("%d", &secondInput);
    printf("Enter integer: ");
    scanf("%d", &thirdInput);
    
    
    //Print output line to user
    printf("The integers in order are: ");
    
    //Order the integers
    //Print the smallest integer first
    if (firstInput <= secondInput && firstInput <= thirdInput) {
        printf("%d ", firstInput);
    }    
    else if (secondInput <= thirdInput && secondInput <= firstInput) {
        printf("%d ", secondInput);
    }
    else {
        printf("%d ", thirdInput);
    }
    
    //print middle integer
    if (
    (firstInput <= secondInput || firstInput <= thirdInput) && 
    (firstInput >= secondInput || firstInput >=  thirdInput)
    ) {
        printf("%d ", firstInput); 
    }
    else if (
    (secondInput <= firstInput || secondInput <= thirdInput) &&
    (secondInput >= firstInput || secondInput >= thirdInput)
    ) {
        printf("%d ", secondInput);
    }
    else {
        printf("%d ", thirdInput);
    }
    
    //print last integer
    if (firstInput >= secondInput && firstInput >= thirdInput) {
        printf("%d\n", firstInput);
    }
    else if (secondInput >= firstInput && secondInput >= thirdInput) {
        printf("%d\n", secondInput);
    }
    else {
        printf("%d\n", thirdInput);
    }
    
    
    
    
    
    
    return 0;
}
