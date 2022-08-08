#include <stdio.h>

#define NUM_ROWS 4
#define MAX_COLS 100

// Return the number of rows that add up to 0
int count_neutral_rows(int size, int array[NUM_ROWS][MAX_COLS]) {
    int neutrals = 0;
    int row = 0;
    while (row < NUM_ROWS) {
        int col = 0;
        int rowSum = 0;
        while (col < size) {
            rowSum += array[row][col];
            col++;
        }
        
        if (rowSum == 0) {
            neutrals++;
        }
        
        row++;
    }
    
    return neutrals;
}

// This is a simple main function which could be used
// to test your count_neutral_rows function.
// It will not be marked.
// Only your count_neutral_rows function will be marked.


int main(void) {
    int test_array[NUM_ROWS][MAX_COLS] = {
        {1, 2, 3, -3, 0},
        {1, 2, 3, -3, -3},
        {1, 4, 3, -3, -2},
        {1, -2, 3, -3, -3}
    };

    int result = count_neutral_rows(MAX_COLS, test_array);
    printf("%d\n", result);

    return 0;
}
