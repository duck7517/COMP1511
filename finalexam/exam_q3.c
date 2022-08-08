#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

int main(void) {
    int array[MAX_LENGTH] = {-5};
    int items = 0;
    while (scanf("%d", &array[items]) == 1) {
        items++;
    }
    
    // checking j by looping though array with k
    int newArray[MAX_LENGTH] = {0};
    
    int copy = 0;
    while (copy < items) {
        newArray[copy] = array[copy];
        copy++;
    }
    
    int j = 1;
    while (j < items) {
        int k = 0;
        while (k < j) {
            if (array[j] % array[k] == 0) {
                newArray[j] = -1;
            }
            k++;
        }
        j++;
    }
    
    j = 0;
    while (j < items) {
        printf("%d\n", newArray[j]);
        j++;
    }
}
