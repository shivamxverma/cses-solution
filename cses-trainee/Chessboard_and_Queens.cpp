#include <iostream>
using namespace std;

char grid[8][8];
int countSolutions = 0;

bool CanPlace(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (grid[i][col] == '*') return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == '*') return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (grid[i][j] == '*') return false;
    }

    return true;
}

void Solve(int row) {
    if (row == 8) {
        countSolutions++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (grid[row][col] == '.' && CanPlace(row, col)) {
            grid[row][col] = '*';
            Solve(row + 1);
            grid[row][col] = '.'; 
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j]; 
        }
    }

    Solve(0);
    cout << countSolutions << endl;

    return 0;
}
