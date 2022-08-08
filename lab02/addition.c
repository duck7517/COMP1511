// COMP1511 Week 2 Laboratory Exercise: Addition
// This program will ask for two integers then display the sum of them.
//
// This program was written by Lisa (z5312476) 
// on 22/09/2020 for tue17a


#include <stdio.h>

int main(void) {
    int firstNumber;
    int secondNumber;
    int sum;
    //Asking for two integer inputs.
    printf("Please enter two integers: ");
    scanf("%d %d", &firstNumber, &secondNumber);
    
    //Addition calculation
    sum = firstNumber + secondNumber;
    
    //Present sum of integers.
    printf("%d + %d = %d\n", firstNumber, secondNumber, sum);


    return 0;
}
