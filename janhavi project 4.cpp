#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

// Display Board
void displayBoard() {

    cout << "\n";

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << " " << board[i][j] << " ";

            if (j < 2)
                cout << "|";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }

    cout << "\n";
}

// Place Move
bool placeMove(int choice) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {

        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Check Winner
bool checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check Draw
bool checkDraw() {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Reset Board
void resetBoard() {

    char value = '1';

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            board[i][j] = value++;
        }
    }

    currentPlayer = 'X';
}

// Main Function
int main() {

    char replay;

    do {

        resetBoard();

        int choice;

        while (true) {

            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";

            cin >> choice;

            if (choice < 1 || choice > 9) {

                cout << "Invalid position!\n";
                continue;
            }

            if (!placeMove(choice)) {

                cout << "Position already taken!\n";
                continue;
            }

            if (checkWinner()) {

                displayBoard();

                cout << "🎉 Player "
                     << currentPlayer
                     << " wins!\n";

                break;
            }

            if (checkDraw()) {

                displayBoard();

                cout << "Game Draw!\n";

                break;
            }

            // Switch Player
            currentPlayer =
                (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}