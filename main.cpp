// Author: Zain Budhwani
// Simple N x N Tic Tac Toe Game written in C++
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> buildBoard(int BOARD_SIZE) {

    vector<vector<char>> board;

    // Initializes our board to be of size BOARD_SIZE X BOARD_SIZE

    for(int i = 0; i < BOARD_SIZE; i++) {
        board.push_back(vector<char>());
    }

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i].push_back('#');
        }
    }

    return board;
} // Builds our board, and gives us a pointer to it

void printBoard(vector<vector<char>> *board, int BOARD_SIZE) {

    cout << "  ";
    for(int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
    }
    cout << endl;

    for(int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for(int j = 0; j < BOARD_SIZE; j++) {
            cout << (*board)[i][j] << " ";
        }
        cout << endl;
    }
} // Prints our updated board

int winConditionMet(int playerSwitch, vector<vector<char>> *board, int BOARD_SIZE) {

    // Check Horizontally
    if(playerSwitch == 1) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((*board)[i][j] == 'X') {
                    countToWin++;
                }
            }
            if(countToWin == BOARD_SIZE) {
                cout << "PLAYER 1 HAS WON!" << endl;
                printBoard(board,BOARD_SIZE);
                exit(0);
            }
        }
    } else {
        for(int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((*board)[i][j] == 'O') {
                    countToWin++;
                }
            }
            if(countToWin == BOARD_SIZE) {
                cout << "PLAYER 2 HAS WON!" << endl;
                printBoard(board,BOARD_SIZE);
                exit(0);
            }
        }
    }

    // Check Vertically
    if(playerSwitch == 1) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((*board)[j][i] == 'X') {
                    countToWin++;
                }
            }
            if(countToWin == BOARD_SIZE) {
                cout << "PLAYER 1 HAS WON!" << endl;
                printBoard(board, BOARD_SIZE);
                exit(0);
            }
        }
    } else {
        for(int i = 0; i < BOARD_SIZE; i++) {
            int countToWin = 0;
            for(int j = 0; j < BOARD_SIZE; j++) {
                if((*board)[j][i] == 'O') {
                    countToWin++;
                }
            }
            if(countToWin == BOARD_SIZE) {
                cout << "PlAYER 2 HAS WON!" << endl;
                printBoard(board, BOARD_SIZE);
                exit(0);
            }
        }
    }

    //Check Left Diagonal

    if(playerSwitch == 1) {
        int countToWin = 0;
        for(int i = 0,j = 0; i < BOARD_SIZE, j < BOARD_SIZE; i++, j++) {
                if((*board)[i][j] == 'X') {
                   countToWin++;
            }
        }
        if(countToWin == BOARD_SIZE) {
            cout << "PlAYER 1 HAS WON!" << endl;
            printBoard(board, BOARD_SIZE);
            exit(0);
        }
    } else {
        int countToWin = 0;
        for(int i = 0,j = 0; i < BOARD_SIZE, j < BOARD_SIZE; i++, j++) {
            if((*board)[i][j] == 'O') {
                countToWin++;
            }
        }
        if(countToWin == BOARD_SIZE) {
            cout << "PlAYER 2 HAS WON!" << endl;
            printBoard(board, BOARD_SIZE);
            exit(0);
        }
    }

    // Check Right Diagonal

    if(playerSwitch == 1) {
        int countToWin = 0;
        for(int i = BOARD_SIZE - 1, j = BOARD_SIZE - 1; i >= 0, j >= 0; i--, j--) {
            if((*board)[i][j] == 'X') {
                countToWin++;
            }
        }
        if(countToWin == BOARD_SIZE) {
            cout << "PlAYER 1 HAS WON!" << endl;
            printBoard(board, BOARD_SIZE);
            exit(0);
        }
    } else {
        int countToWin = 0;
        for(int i = BOARD_SIZE - 1, j = BOARD_SIZE - 1; i >= 0, j >= 0; i--, j--) {
            if((*board)[i][j] == 'O') {
                countToWin++;
            }
        }
        if(countToWin == BOARD_SIZE) {
            cout << "PlAYER 2 HAS WON!" << endl;
            printBoard(board, BOARD_SIZE);
            exit(0);
        }
    }

    // Check if there is no winner

    int countAllGone = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((*board)[i][j] != '#') {
                countAllGone++;
            }
        }
    }
    if(countAllGone == BOARD_SIZE * BOARD_SIZE) {
        cout << "NO WINNER!" << endl;
        exit(0);
    }

    return 0;
}

int turn(int playerSwitch, vector<vector<char>> *board, int BOARD_SIZE){

    string input;
    bool validInput = false;
    int xInput = 0;
    int yInput = 0;

    if(playerSwitch == 1) {
        cout << "PLAYER 1 TURN!" << endl;
        // Check to make sure player is not inserting in an already taken spot

        while(!validInput) {
            cout << "Type in Coordinates ex (1,2) to place an X on that spot!" << endl;
            cin >> input;

            xInput = (int)input[1] - 48;
            yInput = (int)input[3] - 48;

            if((*board)[xInput][yInput] == 'O' ||
                    (*board)[xInput][yInput] == 'X' ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
                cout << "Not Valid Input. Spot is already taken!" << endl;
            } else {
                validInput = true;
            }
        }

        (*board)[xInput][yInput] = 'X';
        winConditionMet(playerSwitch,board,BOARD_SIZE);

        playerSwitch = 0;
        return playerSwitch;
    } else {
        cout << "PLAYER 2 TURN!" << endl;

        while(!validInput) {
            cout << "Type in Coordinates ex (1,2) to place an X on that spot!" << endl;
            cin >> input;

            xInput = (int)input[1] - 48;
            yInput = (int)input[3] - 48;

            if((*board)[xInput][yInput] == 'O' ||
                    (*board)[xInput][yInput] == 'X' ||
                    xInput > BOARD_SIZE - 1 ||
                    yInput > BOARD_SIZE - 1 ||
                    xInput < 0 ||
                    yInput < 0) {
                cout << "Not Valid Input. Choose Again!" << endl;
            } else {
                validInput = true;
            }

        }

        (*board)[xInput][yInput] = 'O';
        winConditionMet(playerSwitch,board,BOARD_SIZE);

        playerSwitch = 1;
        return playerSwitch;
    }
}

int main() {

    int BOARD_SIZE = 0;
    vector<vector<char>> board;
    int shouldGameContinue = 0;
    int playerSwitch = 1;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "How big should the board be?" << endl;
    cin >> BOARD_SIZE;
    cout << "Creating a size of board " << BOARD_SIZE << " ..." << endl;

    board = buildBoard(BOARD_SIZE);
    while(shouldGameContinue == 0) {
        printBoard(&board,BOARD_SIZE);
        playerSwitch = turn(playerSwitch, &board, BOARD_SIZE);
        shouldGameContinue = winConditionMet(playerSwitch,&board, BOARD_SIZE);
    }
}