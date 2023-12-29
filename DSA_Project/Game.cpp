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

void Game::generateSudoku(int lvl)
{
    srand(time(0));
    for (int i = 0; i < lvl; ++i) {
        int row = rand() % N;
        int col = rand() % N;
        int num = rand() % 9 + 1;

        if (board[row][col] == 0 && isValid( row, col, num)) {
            board[row][col] = num;
        }
        else {
            --i;  
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                list.Insert(i, j);
            }
        }
    }
}

void Game::printSudoku()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < N - 1) {
                cout << " ";
            }
        }

        cout << "\n";
        if ((i + 1) % 3 == 0 && i < N - 1) {
            cout << "\n";
        }
    }
    list.Display();
}

