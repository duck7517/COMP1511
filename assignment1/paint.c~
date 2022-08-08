// Assignment 1 20T3 COMP1511: CS Paint
// This program takes in standard input from the user using a set of numerical
// values as instructions, and drawing on a canvas of 5 possible shades. 
// It is able to produce straight and diagonal lines, boxes of a darkness of 
// the user's choice using a system of number commands and by entering x and y 
// coordinates.
// 
//
// This program was written by 
// Lisa Guo (z5312476) on October 2020
//

#include <stdio.h>
#include <stdlib.h>

#define N_ROWS 20
#define N_COLS 36

#define BLACK 0
#define WHITE 4



void displayCanvas(int canvas[N_ROWS][N_COLS]);
void clearCanvas(int canvas[N_ROWS][N_COLS]);
void correctInputs(int *startRow, int *startCol, int *endRow, int *endCol);
int invalid(int *startRow, int *startCol, int *endRow, int *endCol);
void clamp(int *startRow, int *startCol, int *endRow, int *endCol);
void drawLine(int startRow, int startCol, int endRow, int endCol, 
              int canvas[N_ROWS][N_COLS], int shade);
void straight(int startRow, int startCol, int endRow, 
              int endCol, int canvas[N_ROWS][N_COLS], int shade);
void diagonal(int startRow, int startCol, int endRow, 
              int endCol, int canvas[N_ROWS][N_COLS], int shade);
void fillRec(int startRow, int startCol, int endRow, 
             int endCol, int canvas[N_ROWS][N_COLS], int shade);
void playMacro(int startRow, int startCol, int endRow, int endCol, 
               int canvas[N_ROWS][N_COLS], int macros[10][5], int shade, 
               int numCmd, int rowOffset, int colOffset);
void saveState(int save[N_ROWS][N_COLS], int canvas[N_ROWS][N_COLS]);


int main(void) {
    int canvas[N_ROWS][N_COLS];

    clearCanvas(canvas);

    int cmd;
    int startRow = -1;
    int startCol = -1;
    int endRow = -1;
    int endCol = -1;
    int macros[10][5] = {0};
    int runMacro = 0;
    int saves = 0;
    int shade = BLACK;
    int save1[N_ROWS][N_COLS] = {0};
    int save2[N_ROWS][N_COLS] = {0};
    int save3[N_ROWS][N_COLS] = {0};
    int save4[N_ROWS][N_COLS] = {0};
    int save5[N_ROWS][N_COLS] = {0};
    
    
    // Keeps scanning commands until EOF.
    while (scanf("%d", &cmd) == 1) {
        
        // Lets the user draw lines by entering 2 points.
        if (cmd == 1) {
            scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
            drawLine(startRow, startCol, endRow, endCol, canvas, shade);
        }
        
        // Lets the user scan in 2 points to draw a rectangle.
        if (cmd == 2) {
            scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
            if (invalid(&startRow, &startCol, &endRow, &endCol)) {
                fillRec(startRow, startCol, endRow, endCol, canvas, shade);
            }
        }
        
        // Lets the user set a new shade the draw in from here onwards.
        if (cmd == 3) {
            int shadeScan = -1;
            scanf("%d", &shadeScan);
            if (shadeScan >= 0 && shadeScan <= 4) {
                shade = shadeScan;
            }
        }
        
        // Lets the user copy parts of the canvas and paste at a new point.
        if (cmd == 4) {
            int tgtRow = -1;
            int tgtCol = -1;

            scanf("%d %d %d %d %d %d", &startRow, &startCol, 
                   &endRow, &endCol, &tgtRow, &tgtCol);
            
            // Fixes inputs so that command always starts at 
            // top and left.
            correctInputs(&startRow, &startCol, &endRow, &endCol);
            
            // Create a new array for storing copy section.
            // Since input was corrected, dimensions of required copy area
            // can be calculated without absolute value. This will later be
            // used for the loop to know when to stop pasting.
            int height = endRow - startRow;
            int length = endCol - startCol;
            int copy[N_ROWS][N_COLS] = {0};
            
            // Prevents copying from outside of the canvas.
            clamp(&startRow, &startCol, &endRow, &endCol);
            
            // Scans in desired area to store in the new array "copy".
            int rowCopy = 0;
            int colCopy = 0;
            int row = startRow;
            int col = startCol;
            while (row <= endRow) {
                while (col <= endCol) {
                    copy[rowCopy][colCopy] = canvas[row][col];
                    col++;
                    colCopy++;
                }
                col = startCol;
                colCopy = 0;
                row++;
                rowCopy++;
            }
            
            // Set up paste condition to ignore invalid input.
            // Prevents pasting if the entire paste will end up outside
            // the canvas.
            int paste = 1;
            if (tgtRow >= N_ROWS || (tgtRow + height) < 0) {
                paste = 0;
            } else if (tgtCol >= N_COLS || (tgtCol + length) < 0) {
                paste = 0;
            }
            
            // Pastes stored section of canvas into new canvas location.
            // If statements only let values be changed when the current
            // row and col are within the canvas to prevent crashing.           
            rowCopy = 0;
            colCopy = 0;
            if (paste) {
                row = tgtRow;
                col = tgtCol;
                while (row <= (tgtRow + height)) {
                    if (row >= 0 && row < N_ROWS) {
                        while (col <= (tgtCol + length)) { 
                            if (col >= 0 && col < N_COLS) {
                                canvas[row][col] = copy[rowCopy][colCopy];
                            }
                            col++;
                            colCopy++;
                        }
                    }
                    row++;
                    rowCopy++;
                    col = tgtCol;
                    colCopy = 0;
                }
            }
        }
        
        // Recording macros.
        // Pre-initiate as this need to be used in multiple different commands.
        int numCmd;
        if (cmd == 5) {
            scanf("%d", &numCmd);
            
            // Loop will scan in the requested number of commands.
            int cmdSer = 0;
            while (cmdSer < numCmd) {
                int i = 0;
                while (i < 5) {
                    scanf("%d", &macros[cmdSer][i]);
                    i++;
                }
                cmdSer++;
            }
            
            // This will ensure that using the print macros cmd will not 
            // run unless this record cmd has first been used.
            runMacro = 1;
        }
        
        //Playing back macros.
        if (cmd == 6) {
            int rowOffset = -1;
            int colOffset = -1;
            scanf("%d %d", &rowOffset, &colOffset);
            
            //Only run if runMacro is true ie. == 1.
            if (runMacro) {
                playMacro(startRow, startCol, endRow, endCol, canvas, 
                          macros, shade, numCmd, rowOffset, colOffset); 
            }
        }
        
        // Save the state of the canvas when this cmd is used.
        if (cmd == 7) {
            
            // Counter of how many saves have occurred also helps to
            // figure out which array to store the current canvas in.
            // Using the modulus will enable to continue overwriting the same 
            // five saves without limiting how many saves can be done in total.
            saves++;
            if (saves % 5 == 1) {
                saveState(save1, canvas);
            } else if (saves % 5 == 2) {
                saveState(save2, canvas);
            } else if (saves % 5 == 3) {
                saveState(save3, canvas);
            } else if (saves % 5 == 4) {
                saveState(save4, canvas);
            } else if (saves % 5 == 0) {
                saveState(save5, canvas);
            }
        }
        
    }
    
    // If there are saves, they will be printed in order from oldest to newest.
    if (saves > 0) {
        int i = 0;
        if (saves > 5) {
            i = saves - 5;
        }
        // This loop will go through and print the saves in the right order 
        // by using modulus and the number of total saves.
        while (i < saves) {
            i++;
            if (i % 5 == 1) {
                displayCanvas(save1);
            } else if (i % 5 == 2) {
                displayCanvas(save2);
            } else if (i % 5 == 3) {
                displayCanvas(save3);
            } else if (i % 5 == 4) {
                displayCanvas(save4);
            } else if (i % 5 == 0) {
                displayCanvas(save5);
            }
            printf("\n");
        }        
    }
    
    displayCanvas(canvas);

    return 0;
}


// Saves the curent state of the canvas to the required save array.
void saveState(int saveSer[N_ROWS][N_COLS], int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    int saveRow = 0;
    while (row < N_ROWS) {
        int col = 0;
        int saveCol = 0;
        while (col < N_COLS) {
            saveSer[saveRow][saveCol] = canvas[row][col];
            col++;
            saveCol++;
        }
        row++;
        saveRow++;
    }
}


// Takes stored macros and pastes them on the canvas with a row and column
// offset specified by the user.
void playMacro(int startRow, int startCol, int endRow, int endCol, 
               int canvas[N_ROWS][N_COLS], int macros[10][5], int shade, 
               int numCmd, int rowOffset, int colOffset) {
    
    //Scan through array to execute stored commands.
    int cmdSer = 0;
    while (cmdSer < numCmd) {
        startRow = macros[cmdSer][1] + rowOffset;
        startCol = macros[cmdSer][2] + colOffset;
        endRow = macros[cmdSer][3] + rowOffset;
        endCol = macros[cmdSer][4] + colOffset;
        
        if (macros[cmdSer][0] == 1) {
            drawLine(startRow, startCol, endRow, endCol, canvas, shade);
        } else if (macros[cmdSer][0] == 2) {
            if (invalid(&startRow, &startCol, &endRow, &endCol)) {
                fillRec(startRow, startCol, endRow, endCol, canvas, shade);
            }
        }
        cmdSer++;
    }
}


// Combines the functions for straight and diagonal lines and applies
// the conditions for each function to run.
void drawLine(int startRow, int startCol, int endRow, int endCol, 
              int canvas[N_ROWS][N_COLS], int shade) {
    
    // Only run function if at least part of the input lies within the canvas.
    if (invalid(&startRow, &startCol, &endRow, &endCol)) {
        // This sets the conditions for 45 degree diagonals.
        if (abs(startRow - endRow) == abs(startCol - endCol)) {
            clamp(&startRow, &startCol, &endRow, &endCol);
            diagonal(startRow, startCol, endRow, endCol, canvas, shade);
        }
        // If it us not a diagonal, a straight line will be drawn.
        // The input must also be corrected to always start from top and left.
        straight(startRow, startCol, endRow, endCol, canvas, shade);
    }
}


// Translates scan of draw line instructions into corresponding "pixels"
// in the array.
void straight(int startRow, int startCol, int endRow, 
              int endCol, int canvas[N_ROWS][N_COLS], int shade) {
    
    // Ensure orientation of rectangle is from top-left to bottom-right
    // and ensure only values within the canvas are affected.
    correctInputs(&startRow, &startCol, &endRow, &endCol);
    clamp(&startRow, &startCol, &endRow, &endCol);
     
    // If the line starts and ends on the same row it is a horizontal line.
    // While loop changes integers from affected part of array to current shade.
    if (startRow == endRow) { // Horizontal line.
        int col = startCol;
        while (col >= startCol && col <= endCol) {
            canvas[startRow][col] = shade;
            col++;
        }
    }
    if (startCol == endCol) { // Vertical line.
        int row = startRow;
        while (row >= startRow && row <= endRow) {
            canvas[row][startCol] = shade;
            row++;
        }
    }
}


// This allows for diagonal lines to be printed.
void diagonal(int startRow, int startCol, int endRow, 
              int endCol, int canvas[N_ROWS][N_COLS], int shade) {
    
    // Ensure only values within the canvas are affected.
    clamp(&startRow, &startCol, &endRow, &endCol);
    
    if (startRow <= endRow) { // Start top.
        int row = startRow;
        int col = startCol;
        if (startCol <= endCol) { // Start left.
            while (row <= endRow) {
                canvas[row][col] = shade;
                row++;
                col++;
            }
        } else if (startCol >= endCol) { // Start right.
            while (row <= endRow) {
                canvas[row][col] = shade;
                row++;
                col--;
            }
        }
    } else if (startRow >= endRow) { // Start bottom.
        int row = endRow;
        int col = endCol;
        if (startCol <= endCol) { // Start left.
            while (row <= startRow) {
                canvas[row][col] = shade;
                row++;
                col--;
            }
        } else if (endCol <= startCol) { // Start right.
            while (row <= startRow) {
                canvas[row][col] = shade;
                row++;
                col++;
            }
        }
    }
}


// Translates user input for fill rectangle into the corresponding pixels
// in the canvas.
void fillRec(int startRow, int startCol, int endRow, 
             int endCol, int canvas[N_ROWS][N_COLS], int shade) {
    
    // Ensure orientation of rectangle is from top-left to bottom-right
    // and ensure only values within the canvas are affected.
    correctInputs(&startRow, &startCol, &endRow, &endCol);
    clamp(&startRow, &startCol, &endRow, &endCol);
    
    // Alter the required values on the array to fill requested rectangle.
    int row = startRow;
    int col = startCol;
    while (row <= endRow) {
        while (col <= endCol) {
            canvas[row][col] = shade;
            col++;
        }
        row++;
        col = startCol;
    }
}


// If a part of the input is within the canvas, this will clamp values 
// outside the canvas so that only inputs within the array are printed.
void clamp(int *startRow, int *startCol, int *endRow, int *endCol) {
    if (*startRow < 0) {
        *startRow = 0;
    }
    if (*startRow >= N_ROWS) {
        *startRow = N_ROWS - 1;
    }
    if (*startCol < 0) {
        *startCol = 0;
    }
    if (*startCol >= N_COLS) {
        *startCol = N_COLS - 1;
    }
    if (*endRow < 0) {
        *endRow = 0;
    }
    if (*endRow >= N_ROWS) {
        *endRow = N_ROWS - 1;
    }
    if (*endCol < 0) {
        *endCol = 0;
    }
    if (*endCol >= N_COLS) {
        *endCol = N_COLS - 1;
    }
}


// Prevent the command from being carried out if input both starts and 
// finishes outside canvas.
int invalid(int *startRow, int *startCol, int *endRow, int *endCol) {
    if (
        ((*startRow < 0 || *startRow > N_ROWS) && 
        (*endRow < 0 || *endRow > N_ROWS)) ||
        ((*startCol < 0 || *startCol > N_COLS) &&
        (*endCol < 0 || *endCol > N_COLS))
    ) {
        return 0;
    } else {
        return 1;
    }
}
 
 
// Corrects the user imput so that startRow is always top and
// startCol is always left.
void correctInputs(int *startRow, int *startCol, int *endRow, int *endCol) {
    if (*startRow > *endRow) {
        int tmp = *startRow;
        *startRow = *endRow;
        *endRow = tmp;
    }
    if (*startCol > *endCol) {
        int tmp = *startCol;
        *startCol = *endCol;
        *endCol = tmp;
    }
}  

    
// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}
