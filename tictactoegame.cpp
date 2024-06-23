#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "Current board state:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--|---|--\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
    }

    void playGame() {
        int row, col;
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(row - 1, col - 1)) {
                gameWon = checkWin();
                gameDraw = checkDraw();

                if (!gameWon && !gameDraw) {
                    switchPlayer();
                }
            }
        }

        displayBoard();

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }
    }
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            game.resetBoard();
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
