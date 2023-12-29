#include "Game.h"

int main() {
    // Create an instance of the Game class
    Game sudokuGame;

    // Generate a Sudoku grid with 30 clues
    sudokuGame.generateSudoku(30);

    // Print the generated Sudoku grid
    sudokuGame.printSudoku();

    return 0;
}
