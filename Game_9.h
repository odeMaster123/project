#pragma once
#include <iostream>
using namespace std;

class Game {
private:
    int board[3][3];
    bool used[10];
    int currentPlayer;

public:
    Game();
    void clearInputIfBad() const;

    void displayBoard() const;

    void displayAvailableNumbers() const;

    bool isValidMove(int number, int row, int col) const;
    void makeMove(int number, int row, int col);
    bool checkWin() const;
    bool isDraw() const;
    void switchPlayer();
    void play();
};


