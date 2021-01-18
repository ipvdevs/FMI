/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Ivan Penev
* @idnumber 62535
* @task 2
* @compiler GCC
*
*/

#include <iostream>

const unsigned MAX_SIZE = 200;
const unsigned MIN_SIZE = 4;

struct Coordinate {
    int row, col;
};

bool knightKMoves(Coordinate step, const Coordinate dest,
                  int **board, const int rows, const int cols,
                  int k, int stepsDone) {

    if ((step.row == dest.row) && (step.col == dest.col) && stepsDone <= k) {
        return true;
    }

    if (stepsDone >= k) {
        return false;
    }

    int knightMovesRows[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int knightMovesCols[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    for (int i = 0; i < 8; ++i) {
        Coordinate possibleMove = {knightMovesRows[i] + step.row,
                                   knightMovesCols[i] + step.col};

        bool isInsideBoard = (possibleMove.row >= 0 && possibleMove.row <= rows - 1) &&
                             (possibleMove.col >= 0 && possibleMove.col <= cols - 1);

        if (isInsideBoard) {
            int valueOnIndex = board[possibleMove.row][possibleMove.col];
            bool wasAlreadyThere = (valueOnIndex != 0 && valueOnIndex != -1);
            if (!wasAlreadyThere) {
                ++stepsDone;
                board[possibleMove.row][possibleMove.col] = stepsDone;
            } else {
                if ((valueOnIndex > 0 && valueOnIndex <= stepsDone)) {
                    continue;
                } else {
                    ++stepsDone;
                    board[possibleMove.row][possibleMove.col] = stepsDone;
                }
            }

            if (knightKMoves(possibleMove, dest, board, rows, cols, k, stepsDone)) {
                return true;
            }
            --stepsDone;
        }
    }
    return false;
}

int main() {
    int rows;
    std::cin >> rows;
    if (rows < MIN_SIZE || rows > MAX_SIZE) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    //Cols
    int cols;
    std::cin >> cols;
    if (cols < MIN_SIZE || cols > MAX_SIZE) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int p;
    std::cin >> p;
    if (p < 0 || p > rows - 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int q;
    std::cin >> q;
    if (q < 0 || q > cols - 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    Coordinate startPosition = {p, q};

    int p1;
    std::cin >> p1;
    if (p1 < 0 || p1 > rows - 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int q1;
    std::cin >> q1;
    if (q1 < 0 || q1 > cols - 1) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    Coordinate finalPosition = {p1, q1};

    int k;
    std::cin >> k;
    if (k <= 0 || k > 30) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    int **board = new int *[rows];

    for (int row = 0; row < rows; ++row) {
        board[row] = new int[cols];
        for (int col = 0; col < cols; ++col) {
            board[row][col] = 0;
        }
    }

    board[startPosition.row][startPosition.col] = -1;

    bool result = knightKMoves(startPosition, finalPosition, board, rows, cols, k, 0);

    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;

    std::cout << (result ? "True" : "False") << std::endl;
    return 0;
}