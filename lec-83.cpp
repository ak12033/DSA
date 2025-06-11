#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//                                      N-Queens

//                                     Approach 1
/*
bool isSafe(int row, int col, vector<vector<int>>& board, int n) {

    // Row checking
    int x = row;
    int y = col;
    while(y >= 0) {
        if(board[x][y--] == 1) {
            return false;
        }
    }
    // Diagonal 1 checking
    y = col;
    while(x >= 0 && y >= 0) {
        if(board[x--][y--] == 1) {
            return false;
        }
    }
    // Diagonal 2 checking
    x = row;
    y = col;
    while(x < n && y >= 0) {
        if(board[x++][y--] == 1) {
            return false;
        }
    }
    return true;
}
void addSolution(vector<vector<string>>& ans, vector<vector<int>>& board, int n) {

    vector<string> temp;
    for(int i=0; i<n; i++) {
        string s;
        for(int j=0; j<n; j++) {
            if(board[i][j] == 1) {
                s.push_back('Q');
            }
            else {
                s.push_back('.');
            }
        }
        temp.push_back(s);
    }
    ans.push_back(temp);
}
void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {

    if(col == n) {
        addSolution(ans, board, n);
        return;
    }

    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            // Backtrack
            board[row][col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {

    vector<vector<int>> board(n, vector<int> (n, 0));
    vector<vector<string>> ans;
    solve(0, ans, board, n);
    return ans;
}
int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    if (solutions.empty()) {
        cout << "No solution exists for n = " << n << endl;
    } 
    else {
        cout << "All possible solutions for n = " << n << " are:" << endl;
        for (auto solution : solutions) {
            for (auto row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
*/
//                                     Approach 2
/*
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagnolCheck;
unordered_map<int, bool> bottomLeftDiagnolCheck;
bool isSafe(vector<string>& board, int row, int col, int n) {

    if(rowCheck[row] == true ) {
        return false;
    }
    if(upperLeftDiagnolCheck[n - 1 + col - row] == true) {
        return false;
    }
    if(bottomLeftDiagnolCheck[row + col] == true) {
        return false;
    }
    return true;
}
void solve(vector<vector<string>>& ans, vector<string>& board, int n, int col) {

    // Base Case
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++) {
        if(isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            // Updation in map
            rowCheck[row] = true;
            upperLeftDiagnolCheck[n - 1 + col - row] = true;
            bottomLeftDiagnolCheck[row + col] = true;
            // Recursive 
            solve(ans, board, n, col+1);
            // Backtrack
            board[row][col] = '.';
            rowCheck[row] = false;
            upperLeftDiagnolCheck[n - 1 + col - row] = false;
            bottomLeftDiagnolCheck[row + col] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    
    // Board
    vector<string> board(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            board[i].push_back('.');
        }
    }
    vector<vector<string>> ans;
    int col = 0;
    solve(ans, board, n, col);
    return ans;
}
int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    if (solutions.empty()) {
        cout << "No solution exists for n = " << n << endl;
    } 
    else {
        cout << "All possible solutions for n = " << n << " are:" << endl;
        for (auto solution : solutions) {
            for (auto row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
*/