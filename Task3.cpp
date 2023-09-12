/*  Build a simple console-based Tic-Tac-Toe game that
    allows two players to play against each other
    Game Board: Create a 3x3 grid as the game board.
    Players: Assign "X" and "O" to two players.
    Display Board: Show the current state of the board.
    Player Input: Prompt the current player to enter their move.
    Update Board: Update the game board with the player's move.
    Check for Win: Check if the current player has won.
    Check for Draw: Determine if the game is a draw.
    Switch Players: Alternate turns between "X" and "O" players.
    Display Result: Show the result of the game (win, draw, or ongoing).
    Play Again: Ask if the players want to play another game.   */

#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Check diagonal (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // There are still empty cells
            }
        }
    }
    return true;  // All cells are filled, it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));  // Initialize the empty 3x3 board
    char currentPlayer = 'X';  // Player 'X' starts

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        // Check if the chosen cell is valid and empty
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            // Update the board with the player's move
            board[row - 1][col - 1] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                break;
            }

            // Check if the game is a draw
            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players for the next turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
