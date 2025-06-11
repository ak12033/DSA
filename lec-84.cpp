#include <iostream>
#include <vector>
using namespace std;

//                                    Sudoku Solver
/*
bool isSafe(int row, int col, vector<vector<char>>& board, int val) {

    for(int i=0; i<board.size(); i++) {
        // Row check
        if(board[row][i] == val) {
            return false;
        }
        // Column check
        if(board[i][col] == val) {
            return false;
        }
        // 3*3 matrix
        if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == val) {
            return false; 
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board ){

    int n = board[0].size();
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            // If cell empty
            if(board[row][col] == '.') {
                for(char val ='1'; val <='9'; val++) {
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;
                        // Recursion call
                        bool aageSolutionPossible = solve(board);
                        if(aageSolutionPossible) {
                            return true;
                        }
                        // Backtrack
                        else {
                            board[row][col] = '.';
                              
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    
    solve(board);
}
int main() {

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    // Output
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout << board[i][j] << " ";
            if(j == 2 || j == 5) {
                cout << " ";
            }
        }
        if(i == 2 || i == 5) {
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
*/