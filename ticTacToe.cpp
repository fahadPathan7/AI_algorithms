/*
Name: Fahad Pathan
Reg: 2019831065
*/

/*
This is a tik tak toe game implemented using minMax algoritm.
Player will play the game against AI.

the board is numbered as
1 2 3
4 5 6
7 8 9

player will choose an emptly cell and enter the value accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

char player = 'X';
char ai = 'O';

bool playGame = true; // if the game ended or not

// for printing the board after every step
void printBoard(char board[3][3]) {
    cout << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) cout << board[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}
// checking for win, loss or draw condition
int checkBoard(char board[3][3]) {
    // Checking rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == player) return 10;
            else if (board[row][0] == ai) return -10;
        }
    }

    // Checking columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == player) return 10;
            else if (board[0][col] == ai) return -10;
        }
    }

    // Checking diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player) return 10;
        else if (board[0][0] == ai) return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == player) return 10;
        else if (board[0][2] == ai) return -10;
    }

    return 0; // no one wins
}
// for checking tie
bool tieCheck(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == '_') return false;
        }
    }

    return true;
}
// min max algo
int minMax(char board[3][3], bool isMaximize) {
    int score = checkBoard(board);

    if (score == 10 || score == -10) return score; // player or ai has won

    if (tieCheck(board)) return 0; // tie situation

    if (isMaximize) {
        // to maximize player score
        int best = -INT_MAX;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == '_') {
                    board[row][col] = player; // temporary placement for further checking
                    best = max(best, minMax(board, !isMaximize)); // maximizing
                    board[row][col] = '_'; // resetting the temporary move
                }
            }
        }

        return best;
    }
    else {
        // to minimize player score (ai)
        int best = INT_MAX;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == '_') {
                    board[row][col] = ai; // temporary placement for further checking
                    best = min(best, minMax(board, !isMaximize)); // minimizing
                    board[row][col] = '_'; // resetting the temporary move
                }
            }
        }

        return best;
    }
}
// to find the best move for the ai
void aiBestMove(char board[3][3]) {
    int bestScore = INT_MAX;
    int rowVal = -1, colVal = -1; // row and column of the best move

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == '_') {
                board[row][col] = ai; // checking for every empty position

                int curScore = minMax(board, true);

                //cout << curScore << " "; //!

                board[row][col] = '_'; // as the move is not permanent yet so replacing it.

                // trying to get the minimum score for the player.
                if (curScore < bestScore) {
                    bestScore = curScore;
                    rowVal = row;
                    colVal = col;
                }
            }
        }
    }

    board[rowVal][colVal] = ai; // updating the best move for the ai. (final move)
}
// to check if the game will continue or not. win, loss or tie will be declared
bool gameContinue(char board[3][3]) {
    int score = checkBoard(board);
    if (score == 10) { // player has won
        cout << "Congratulations. You Win!" << endl;
        playGame = false;
    }
    else if (score == -10) { // player has lost
        cout << "You Lost! Try again." << endl;
        playGame = false;
    }
    else {
        bool check = tieCheck(board);
        if (check) { // draw match
            cout << "Draw!" << endl;
            playGame = false;
        }
    }

    return playGame; // will the game continue or not
}

int main() {
    // creating the board
    char board[3][3];
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) board[row][col] = '_';
    }

    printBoard(board); // printing the board initially

    while (playGame) {
        int choice;
        cout << "Enter your choice (1 - 9): ";
        cin >> choice; // entering the player choice
        choice--;
        board[choice / 3][choice % 3] = player; // updating player choice

        cout << "Players Move: " << endl;
        printBoard(board); // printing board after player's move

        if (!gameContinue(board)) break; // checking for win, loss or draw

        aiBestMove(board); // ai will give the best move
        cout << "AI move: " << endl;
        printBoard(board); // printing board after ai move

        if (!gameContinue(board)) break; // checking for win, loss or draw
    }
}
