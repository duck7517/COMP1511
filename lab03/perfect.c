// COMP1511 Week 3 Laboratory Exercise: Are You Perfect
// This program will take positive integer input from user,
// print all the factors and the sum of the factors,
// then tell the user whether the integer is a 
// perfect number.
//
// This program was written by Lisa (z5312476) 
// on 30/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int input;
    
    //ask user for number
    printf("Enter number: ");
    scanf("%d", &input);
    
    //make sure input is positive
    //if not, terminate program
    if (input <= 0) {
        return 1;
    }
    
    //print factors of number
    printf("The factors of %d are: \n", input);
    
    //use loop to get factors
    int i = 1;
    int sum = 0;
    while (i <= input) {
        if (input % i == 0) {
            printf("%d\n", i);
            sum = sum + i;
        }
        i++;
    }
    
    //print sum of factors
    printf("Sum of factors = %d\n", sum);
    
    //tell user whether input is perfect number
    if (sum - input == input) {
        printf("%d is a perfect number\n", input);
    }
    else {
        printf("%d is not a perfect number\n", input);
    }



    return 0;
}
