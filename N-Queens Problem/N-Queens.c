#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

// Function to check if position is safe
int isSafe(int row, int col) {
    int i, j;

    // Check left side of current row
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check lower-left diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

// Backtracking function
int solveNQ(int col) {

    // If all queens are placed
    if (col >= N)
        return 1;

    int i;

    // Try placing queen in all rows
    for (i = 0; i < N; i++) {

        // Check if safe
        if (isSafe(i, col)) {

            // Place queen
            board[i][col] = 1;

            // Recur for next column
            if (solveNQ(col + 1))
                return 1;

            // BACKTRACK
            board[i][col] = 0;
        }
    }

    return 0;
}

// Function to print solution
void printBoard() {
    int i, j;

    printf("\nSolution Exists:\n\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {

    printf("Enter value of N: ");
    scanf("%d", &N);

    if (solveNQ(0))
        printBoard();
    else
        printf("No Solution Exists");

    return 0;
}
