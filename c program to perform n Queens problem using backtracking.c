#include <stdio.h>
#include <stdbool.h>

#define N 8

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check for queens in the same column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check for queens in the upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check for queens in the lower diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        printBoard(board);
        return true;
    }

    bool foundSolution = false;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            foundSolution = solveNQueensUtil(board, row + 1) || foundSolution;

            board[row][col] = 0;
        }
    }

    return foundSolution;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("No solution exists for the given board size.\n");
    }
}

int main() {
    solveNQueens();

    return 0;
}
