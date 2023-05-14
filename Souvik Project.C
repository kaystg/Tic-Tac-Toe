#include <stdio.h>

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char symbol) {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return 1;
    return 0;
}

// Function to play the game
void playGame() {
    char board[3][3];
    int row, col, player = 1, moves = 0;
    
    // Initialize the board with empty spaces
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
    
    // Game loop
    while (1) {
        // Draw the board
        drawBoard(board);
        
        // Get the current player's symbol (X or O)
        char symbol = (player == 1) ? 'X' : 'O';
        
        // Get the player's move
        printf("Player %d, enter your move (row [0-2] and column [0-2]): ", player);
        scanf("%d %d", &row, &col);
        
        // Validate the move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // Update the board with the player's move
        board[row][col] = symbol;
        
        // Check if the current player has won
        if (checkWin(board, symbol)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }
        
        // Check if it's a draw
        moves++;
        if (moves == 9) {
            drawBoard(board);
            printf("It's a draw!\n");
            break;
        }
        
        // Switch to the other player
        player
