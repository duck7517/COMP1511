// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by Lisa Guo (z5312476)
// on 06/10/2020
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    double areaValue;
    areaValue = M_PI * radius * radius;       
    return areaValue; 
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    double circumferenceValue;
    circumferenceValue = M_PI * 2 * radius;
    return circumferenceValue;
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    double diameterValue;
    diameterValue = 2 * radius;
    return diameterValue; 
}
