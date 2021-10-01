#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int checkMagicSquare(int arr[ROWS][COLS]);

int main() {
    int sqr1[ROWS][COLS] = {{4, 9, 2},
                            {3, 5, 7},
                            {8, 1, 6}
                            };
    
    int sqr2[ROWS][COLS] = {{4, 9, 1},
                            {3, 5, 7},
                            {8, 2, 6}
                            };

    int check = checkMagicSquare(sqr1);
    if (check == 1)
        printf("sqr1 is a magic square.\n");
    else
        printf("sqr1 is not a magic square.\n");

    check = checkMagicSquare(sqr2);
    if (check == 1)
        printf("sqr2 is a magic square.\n");
    else
        printf("sqr2 is not a magic square.\n");

    return EXIT_SUCCESS;
}

int checkMagicSquare(int arr[ROWS][COLS])
{
    // Add all numbers from each row and check if they equal 15
    for (int row = 0; row < ROWS; row++) {
        if ((arr[row][0] + arr[row][1] + arr[row][2]) != 15)
            return 0;
    }

    // Add all numbers from each column and check if they equal 15
    for (int col = 0; col < COLS; col++) {
        if ((arr[0][col] + arr[1][col] + arr[2][col]) != 15)
            return 0;
    }

    // Check first diagonal
    if ((arr[0][0] + arr[1][1] + arr[2][2]) != 15)
        return 0;
    
    // Check second diagonal
    if ((arr[2][0] + arr[1][1] + arr[0][2]) != 15)
        return 0;
    
    // If we make it here, then we passed all tests and it is a magic square
    return 1;
}