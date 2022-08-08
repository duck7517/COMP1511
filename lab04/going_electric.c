// COMP1511 Week 4 CHALLENGE Laboratory Exercise: Going Electric
// This program 
//
// This program was written by Lisa (z5312476) 
// on 8/10/2020 for tue17a


#include <stdio.h>



int main(void) {
    int fuelCount = 0;
    int stopCount = 0;
    int stopFuel;
    
    while (scanf("%d", &stopFuel) == 1) {
       
        //invalid input failsafe
        if (stopFuel < 0) {
            printf("A stop cannot have negative fuel!!");
            return 1;
        }
        
        fuelCount += stopFuel;
        stopCount++;
        fuelCount--;
        
        if (fuelCount < 0) {
            printf("0\n");
        }
    }
    
         
    
    return 0;
}

