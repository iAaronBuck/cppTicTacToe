#include <iostream>
#include <string>

using namespace std;

class TicTacToeGame {
    public: 
        void playHumanGame();
        void playEasyAIGame();
    
    private:
        int spotsChosen[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
        void printBoard();
        int makeMove(int move, int player);
        bool checkWinner();
        bool isEmpty();
        bool isFull();
};

bool TicTacToeGame::isFull() {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            if (spotsChosen[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToeGame::isEmpty() {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            if (spotsChosen[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void TicTacToeGame::printBoard() {
    string topRow = "| ";
    string entry = "1";
    string horizontal = "|=============|\n";
    if (spotsChosen[0][0] == 1)
        entry = "X";
    if (spotsChosen[0][0] == 2)
        entry = "O";
    topRow += entry + " || ";
    entry = "2";
    if (spotsChosen[0][1] == 1)
        entry = "X";
    if (spotsChosen[0][1] == 2)
        entry = "O";
    topRow += entry + " || ";
    entry = "3";
    if (spotsChosen[0][2] == 1)
        entry = "X";
    if (spotsChosen[0][2] == 2)
        entry = "O";
    topRow += entry + " |\n" + horizontal;
    
    string middleRow = "| ";
    entry = "4";
    if (spotsChosen[1][0] == 1)
        entry = "X";
    if (spotsChosen[1][0] == 2)
        entry = "O";
    middleRow += entry + " || ";
    entry = "5";
    if (spotsChosen[1][1] == 1)
        entry = "X";
    if (spotsChosen[1][1] == 2)
        entry = "O";
    middleRow += entry + " || ";
    entry = "6";
    if (spotsChosen[1][2] == 1)
        entry = "X";
    if (spotsChosen[1][2] == 2)
        entry = "O";
    middleRow += entry + " |\n" + horizontal;
    
    string bottomRow = "| ";
    entry = "7";
    if (spotsChosen[2][0] == 1)
        entry = "X";
    if (spotsChosen[2][0] == 2)
        entry = "O";
    bottomRow += entry + " || ";
        entry = "8";
    if (spotsChosen[2][1] == 1)
        entry = "X";
    if (spotsChosen[2][1] == 2)
        entry = "O";
    bottomRow += entry + " || ";
    entry = "9";
    if (spotsChosen[2][2] == 1)
        entry = "X";
    if (spotsChosen[2][2] == 2)
        entry = "O";
    bottomRow += entry + " |\n";
    cout << (topRow + middleRow + bottomRow);
}

int TicTacToeGame::makeMove(int move, int player) {
    int row = move / 3;
    int col = move % 3;
    if (spotsChosen[row][col] == 0) {
        spotsChosen[row][col] = player;
        return 0;
    }
    else {
        string s1 = "Slot ";
        cout << s1 + to_string(move + 1) + " is already taken, please type another integer and press return." << endl;
        return -1;
    }
}

bool TicTacToeGame::checkWinner(){
    if (spotsChosen[0][0] != 0) {
        if (spotsChosen[0][0] == spotsChosen[0][1] && spotsChosen[0][1] == spotsChosen[0][2])
            return true;
        if (spotsChosen[0][0] == spotsChosen[1][1] && spotsChosen[1][1] == spotsChosen[2][2])
            return true;
        if (spotsChosen[0][0] == spotsChosen[1][0] && spotsChosen[1][0] == spotsChosen[2][0])
            return true;
    }
    if (spotsChosen[1][0] != 0) {
        if (spotsChosen[1][0] == spotsChosen[1][1] && spotsChosen[1][1] == spotsChosen[1][2])
            return true;
    }
    if (spotsChosen[2][0] != 0) {
        if (spotsChosen[2][0] == spotsChosen[2][1] && spotsChosen[2][1] == spotsChosen[2][2])
            return true;
        if (spotsChosen[2][0] == spotsChosen[1][1] && spotsChosen[1][1] == spotsChosen[0][2])
            return true;
    }
    if (spotsChosen[0][2] != 0) {
        if (spotsChosen[0][2] == spotsChosen[1][2] && spotsChosen[1][2] == spotsChosen[2][2])
            return true;
    }
    if (spotsChosen[0][1] != 0) {
        if (spotsChosen[0][1] == spotsChosen[1][1] && spotsChosen[1][1] == spotsChosen[2][1])
            return true;
    }
    return false;
}

void TicTacToeGame::playHumanGame() {
    int input;
    int player = 1;
    cout << "Hello! The board is arranged as\n";
    string greeting = "'s turn. Please enter an integer between 1 and 9, inclusive.\n";
    while(!(checkWinner() || isFull())) {
        printBoard();
        cout << (((player == 1) ? "X" : "O") + greeting);
        cin >> input;
        input--;
        int failedMove = makeMove(input, player);
        while (failedMove != 0) {
            cin >> input;
            input--;
            failedMove = makeMove(input, player);
        };
        if (player == 1) {
            player = 2;
        } 
        else {
            player = 1;
        }
    }
    printBoard();
    if (checkWinner()) {
        cout << ((player == 2) ? "X" : "O") << "'s Win!" << endl;
    }
    else {
        cout << "The board is full and this round is a draw!" << endl;
    }
}

void TicTacToeGame::playEasyAIGame() {
    int input;
    int player = 1;
    cout << "Hello! The board is arranged as\n";
    string greeting = "'s turn. Please enter an integer between 1 and 9, inclusive.\n";
    while(!(checkWinner() || isFull())) {
        printBoard();
        cout << (((player == 1) ? "X" : "O") + greeting);
        //TODO: make psuedo-random AI moves
        cin >> input;
        input--;
        int failedMove = makeMove(input, player);
        while (failedMove != 0) {
            cin >> input;
            input--;
            failedMove = makeMove(input, player);
        };
        if (player == 1) {
            player = 2;
        } 
        else {
            player = 1;
        }
    }
    printBoard();
    if (checkWinner()) {
        cout << ((player == 2) ? "X" : "O") << "'s Win!" << endl;
    }
    else {
        cout << "The board is full and this round is a draw!" << endl;
    }
}

int main() {
    TicTacToeGame ourGame;
    cout << "Time to play Tic-Tac Toe!\n" << endl;

    ourGame.playHumanGame();
}