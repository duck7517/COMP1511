// COMP1511 Week 2 Laboratory Exercise: Easter
// This program allows the user to enter a year,
// then calculates the date of Easter Sunday of that year.
//
// This program was written by Lisa (z5312476) 
// on 25/09/2020 for tue17a

#include <stdio.h>

int main(void) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int k;
    int l;
    int m;
    int p;
    int year;
    int easterMonth;
    int easterDate;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    /*
    if (year < 1583) {
        printf("This year is not a valid year in the Gregorian Calendar.\n"
        "The Gregorian Calendar beigns in 1583. Please enter a valid year.\n");
    }
    
    return 1;
    */
    
    
    //Easter Month calculation
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19*a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2*e + 2*i - h - k) % 7;
    m = (a + 11*h + 22*l) / 451;
    easterMonth = (h + l - 7*m + 114) / 31;  
    //[3=March, 4=April]
    
    //Date in Easter Month calculation
    p = (h + l - 7*m + 114) % 31;
    easterDate = p+1;     
    
    //Print outcome
    printf("Easter is ");
    
    if (easterMonth == 3) {
        printf("March");
    }
    if (easterMonth == 4) {
        printf("April");
    }
    
    printf(" %d in %d.\n", easterDate, year);
    
    
    return 0;
}
