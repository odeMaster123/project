// #include "Game_9.h"
// #include <limits>
//
// Game::Game() {
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             board[i][j] = 0;
//
//     for (int i = 0; i < 10; i++)
//         used[i] = false;
//
//     currentPlayer = 1;
// }
//
// void Game::clearInputIfBad() const {
//     if (cin.fail()) {
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
// }
//
// void Game::displayBoard() const {
//     cout << "\nCurrent Board:\n";
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (board[i][j] == 0) cout << " _ ";
//             else cout << " " << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
//
// void Game::displayAvailableNumbers() const {
//     cout << "Available numbers - Player 1 (odd): ";
//     for (int n = 1; n <= 9; n += 2)
//         if (!used[n]) cout << n << " ";
//     cout << "\nAvailable numbers - Player 2 (even): ";
//     for (int n = 2; n <= 8; n += 2)
//         if (!used[n]) cout << n << " ";
//     cout << endl;
// }
//
// bool Game::isValidMove(int number, int row, int col) const {
//     if (number < 1 || number > 9) {
//         return false;
//     }
//     if (row < 0 || row > 2 || col < 0 || col > 2) {
//         return false;
//     }
//
//     if (board[row][col] != 0) return false;
//     if (used[number]) return false;
//
//     if (currentPlayer == 1 && number % 2 == 0) return false;
//     if (currentPlayer == 2 && number % 2 != 0) return false;
//
//     return true;
// }
//
// void Game::makeMove(int number, int row, int col) {
//     board[row][col] = number;
//     used[number] = true;
// }
//
// bool Game::checkWin() const {
//     for (int i = 0; i < 3; i++) {
//         if (board[i][0] != 0 && board[i][1] != 0 && board[i][2] != 0) {
//             if (board[i][0] + board[i][1] + board[i][2] == 15) return true;
//         }
//
//         if (board[0][i] != 0 && board[1][i] != 0 && board[2][i] != 0) {
//             if (board[0][i] + board[1][i] + board[2][i] == 15) return true;
//         }
//     }
//
//     if (board[0][0] != 0 && board[1][1] != 0 && board[2][2] != 0)
//         if (board[0][0] + board[1][1] + board[2][2] == 15) return true;
//
//     if (board[0][2] != 0 && board[1][1] != 0 && board[2][0] != 0)
//         if (board[0][2] + board[1][1] + board[2][0] == 15) return true;
//
//     return false;
// }
//
// bool Game::isDraw() const {
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (board[i][j] == 0) return false;
//     return true;
// }
//
// void Game::switchPlayer() {
//     currentPlayer = (currentPlayer == 1 ? 2 : 1);
// }
//
// void Game::play() {
//     cout << "Welcome to Numerical Tic-Tac-Toe!\n";
//     displayBoard();
//
//     while (true) {
//         int number = -1, row = -1, col = -1;
//
//         cout << "\nPlayer " << currentPlayer << " turn:\n";
//         displayAvailableNumbers();
//
//         cout << "Enter number (1-9): ";
//         cin >> number;
//         if (cin.fail()) {
//             cout << "Input must be a number. Try again.\n";
//             clearInputIfBad();
//             continue;
//         }
//
//         cout << "Enter row and column (0-2) separated by space: ";
//         cin >> row >> col;
//         if (cin.fail()) {
//             cout << "Row/column must be numbers 0,1,2. Try again.\n";
//             clearInputIfBad();
//             continue;
//         }
//
//         if (!isValidMove(number, row, col)) {
//             if (number < 1 || number > 9) {
//                 cout << "Invalid number: must be between 1 and 9.\n";
//             } else if (row < 0 || row > 2 || col < 0 || col > 2) {
//                 cout << "Invalid position: row and column must be in 0..2.\n";
//             } else if (used[number]) {
//                 cout << "That number has already been used.\n";
//             } else if (board[row][col] != 0) {
//                 cout << "That cell is already occupied.\n";
//             } else if (currentPlayer == 1 && number % 2 == 0) {
//                 cout << "Player 1 must play an odd number.\n";
//             } else if (currentPlayer == 2 && number % 2 != 0) {
//                 cout << "Player 2 must play an even number.\n";
//             } else {
//                 cout << "Invalid move. Try again.\n";
//             }
//             continue;
//         }
//
//         makeMove(number, row, col);
//         displayBoard();
//
//         if (checkWin()) {
//             cout << "\n Player " << currentPlayer << " wins\n";
//             break;
//         }
//
//         if (isDraw()) {
//             cout << "\nIt's a draw!\n";
//             break;
//         }
//
//         switchPlayer();
//     }
// }
//
