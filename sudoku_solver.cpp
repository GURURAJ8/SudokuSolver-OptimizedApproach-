#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 9;
int masks[3][SIZE] = {0}; // Combines row, column, and box masks into a single array

struct Cell {
    int row, col, options;
};

// Get the 3×3 box index
inline int getBoxIndex(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

// Initialize masks & find blank cells
void initialize(vector<vector<int>>& grid, vector<Cell>& blanks) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            int num = grid[r][c];
            if (num != 0) {
                int mask = (1 << num);
                masks[0][r] |= mask; // Row mask
                masks[1][c] |= mask; // Column mask
                masks[2][getBoxIndex(r, c)] |= mask; // Box mask
            } else {
                int options = 0;
                for (int i = 1; i <= 9; i++) {
                    if (!(masks[0][r] & (1 << i)) &&
                        !(masks[1][c] & (1 << i)) &&
                        !(masks[2][getBoxIndex(r, c)] & (1 << i)))
                        options++;
                }
                blanks.push_back({r, c, options});
            }
        }
    }
    sort(blanks.begin(), blanks.end(), [](const Cell& a, const Cell& b) {
        return a.options < b.options; // Sort to prioritize easier cells
    });
}

// Solve Sudoku using constraint propagation and backtracking
bool solveSudoku(vector<vector<int>>& grid, vector<Cell>& blanks, int index = 0) {
    if (index == blanks.size()) return true;

    int r = blanks[index].row, c = blanks[index].col;
    int box = getBoxIndex(r, c);
    int available = ~(masks[0][r] | masks[1][c] | masks[2][box]) & 0x3FE; // Available numbers (mask)

    while (available) {
        int num = __builtin_ctz(available); // Get lowest bit set (fastest way to pick)
        available &= (available - 1); // Remove that number from available

        int mask = (1 << num);
        grid[r][c] = num;
        masks[0][r] |= mask;
        masks[1][c] |= mask;
        masks[2][box] |= mask;

        if (solveSudoku(grid, blanks, index + 1)) return true;

        // Backtrack
        grid[r][c] = 0;
        masks[0][r] &= ~mask;
        masks[1][c] &= ~mask;
        masks[2][box] &= ~mask;
    }
    return false;
}

// Print Sudoku Grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
}

// Main Function
int main() {
    vector<vector<int>> grid = {
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

    vector<Cell> blanks;
    initialize(grid, blanks);

    if (solveSudoku(grid, blanks)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
