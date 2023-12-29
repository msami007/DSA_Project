#include "Game.h"
LinkList list;

Game::Game()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
            arr[i][j] = 0;
        }
    }
}

bool Game::isValid( int row, int col, int num)
{
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[subgridRow + i][subgridCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Game::isUniqueSolution() {
    int originalBoard[N][N];
    bool emptyCellFound = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            originalBoard[i][j] = board[i][j];
        }
    }
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= N; ++num) {
                    if (arr[row][col] == num) continue;

                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku()) {
                            for (int i = 0; i < N; ++i)
                                for (int j = 0; j < N; ++j)
                                    board[i][j] = originalBoard[i][j];
                            return false;
                        }
                        board[row][col] = 0;
                    }
                }
                emptyCellFound = true;
                break;
            }
        }
        if (emptyCellFound) break;
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = originalBoard[i][j];
    return true;
}



void Game::generateSudoku(int lvl)
{
    srand(time(0));
    solveSudoku();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = board[i][j];
        }
    }
    int cellsToRemove = 81 - lvl;
    while (cellsToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (board[row][col] != 0) {
            int temp = board[row][col];
            board[row][col] = 0;

            // Check if the puzzle remains unique and solvable
            if (isUniqueSolution()) {
                cellsToRemove--;
            }
            else {
                // If not, restore the original value
                board[row][col] = temp;
            }
        }
    }
    list.Clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                list.Insert(i, j);
            }
        }
    }
}

bool Game::solveSudoku()
{
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= N; ++num) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku()) {
                            return true;
                        }

                        // If placing 'num' in the current position doesn't lead to a
                        // solution, backtrack
                        board[row][col] = 0;
                    }
                }
                // No valid number found, backtrack
                return false;
            }
        }
    }
}

void Game::printSudoku()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 0) {
                cout << "_ ";
            }
            else {
                cout << board[i][j] << " ";
            }
            if ((j + 1) % 3 == 0 && j < N - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        if ((i + 1) % 3 == 0 && i < N - 1) {
            cout << "\n";
        }
    }

}

bool Game::isSolved() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 0 || !isValid(i, j, board[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void Game::play() {
    int row, col, num;
    while (!isSolved()) {
        cout << "\nEnter row (1-" << N << "), column (1-" << N << "), and number (1-" << N << ") to insert (separated by spaces): ";
        cin >> row >> col >> num;

        // Adjust for 0-indexed array
        row--;
        col--;

        if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > N) {
            cout << "Invalid input. Please enter numbers within the grid range.\n";
            continue;
        }

        if (!list.listcheck(row, col)) {
            cout << "This cell is pre-filled and cannot be changed. Please choose another cell.\n";
            continue;
        }

        if (isValid(row, col, num)) {
            board[row][col] = num;
            cout << "Updated Sudoku Board:\n";
            printSudoku();
        }
        else {
            cout << "Invalid move. This number violates Sudoku rules.\n";
        }
    }

    cout << "Congratulations! You've solved the Sudoku!\n";
}


