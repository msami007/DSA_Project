#include "Game.h"

int main() {
    Game sudokuGame;

    cout << "Generated Sudoku Board:\n";
    sudokuGame.printSudoku();

    int difficultyLevel;
    cout << "\nEnter difficulty level (1-80): ";
    cin >> difficultyLevel;

    if (difficultyLevel < 1 || difficultyLevel > 80) {
        cout << "Invalid difficulty level. Exiting.\n";
        return 1;
    }

    sudokuGame.generateSudoku(difficultyLevel);

    cout << "\nInitial Sudoku Board:\n";
    sudokuGame.printSudoku();

    sudokuGame.play();

    return 0;
}


