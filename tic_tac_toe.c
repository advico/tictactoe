#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Functions
void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int win = 0;

    initializeBoard(board);

    while (1) {
        system("clear || cls");
        displayBoard(board);

        makeMove(board, currentPlayer);

        if (checkWin(board)) {
            system("clear || cls");
            displayBoard(board);
            printf("\nCongratulations! Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board)) {
            system("clear || cls");
            displayBoard(board);
            printf("\nIt's a draw! The board is full.\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(char board[SIZE][SIZE], char player) {
    int row, col;

    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}
