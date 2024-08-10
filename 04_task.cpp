//Create a program that solves Sudoku puzzles automatically. The program should take an input grid representing an unsolved Sudoku puzzle and use an algorithm to fill in the missing numbers.

//It should use backtracking or other suitable techniques to explore possible solutions and find the correct arrangement of numbers for the puzzle. Once solved, the program should display the completed Sudoku grid.

#include <iostream>
#include <vector>

#define N 9 // Size of the grid (9x9)

// Function to print the Sudoku grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            std::cout << grid[row][col] << " ";
        std::cout << std::endl;
    }
}

// Function to check if it's safe to place a number at grid[row][col]
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is not in the current row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check if 'num' is not in the current column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check if 'num' is not in the current 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(std::vector<std::vector<int>>& grid, int row, int col) {
    // If we have reached the 8th row and 9th column (end of the grid), return true
    if (row == N - 1 && col == N)
        return true;

    // Move to the next row if we have reached the last column
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip the already filled cells
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        // Check if it's safe to place the number
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively check for the next possibility
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        // Backtrack: remove the number if it doesn't lead to a solution
        grid[row][col] = 0;
    }

    return false;
}

int main() {
    // Example Sudoku puzzle (0 represents empty cells)
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        std::cout << "No solution exists" << std::endl;

    return 0;
}