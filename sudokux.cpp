#include <iostream>
using namespace std;

const int N = 9;
const int UNASSIGNED = 0;

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlaceNumber(int grid[N][N], int row, int col, int num) {

    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgridRow + i][subgridCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool foundEmptyCell = false;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                foundEmptyCell = true;
                break;
            }
        }
        if (foundEmptyCell) {
            break;
        }
    }


    if (!foundEmptyCell) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (canPlaceNumber(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

int main() {

    int grid[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solved!" << endl;
        printGrid(grid);
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}