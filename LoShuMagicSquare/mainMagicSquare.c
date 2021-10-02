#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Create a square, initialized to all 0s, to be filled with random numbers
    int randSqr[ROWS][COLS] = { 0 };

    int totalTries = 0;
    int traverse = 0;

    // Initialize the random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Create array and set values to be values of index 0 - 8
    int nums[9];
    for (int index = 0; index < 9; index++)
        nums[index] = index;

    check = 0;
    while (check != 1) {
        // Shuffle the array by randomly swapping the elements in the array
        for (int index = 0; index < 9; index++) {
            int tempValue = nums[index];
            int randIndex = rand() % 9;

            // Swap the random elements
            nums[index] = nums[randIndex];
            nums[randIndex] = tempValue;
        }

        // Fill the random square with the radomized elements
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                randSqr[row][col] = nums[traverse] + 1; // Add 1 to get 1 - 9
                traverse++;
            }
        }

        traverse = 0; // reset traverse for next traversal
        totalTries++; // count amount of tries
        check = checkMagicSquare(randSqr);
    }

    printf("Total number of tries for randSqr before success: %d\n", totalTries);
    for (int row = 0; row < ROWS; row++) {
        printf("[ ");
        for (int col = 0; col < COLS; col++) {
            printf("%d ", randSqr[row][col]);
        }
        printf("]\n");
    }

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