#include <iostream>
#include <vector>
#include <string>
using namespace std;

//                              Rat in a Maze Problem - I
/*
bool isSafe(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) {

    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}
void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) {
    
    // Base Case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;     

    // Down
    if (isSafe(x+1, y, visited, arr, n)) {
        solve(x+1, y, arr, n, ans, visited, path + 'D');
    }

    // Left
    if (isSafe(x, y-1, visited, arr, n)) {
        solve(x, y-1, arr, n, ans, visited, path + 'L');
    }

    // Right
    if (isSafe(x, y+1, visited, arr, n)) {
        solve(x, y+1, arr, n, ans, visited, path + 'R');
    }

    // Up
    // Right
    if (isSafe(x-1, y, visited, arr, n)) {
        solve(x-1, y, arr, n, ans, visited, path + 'U');
    }

    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>>& m) {
        
    int n = m.size();
    vector<string> ans;
    vector<vector<bool>> visited (n, vector<bool> (n, 0));

    if(m[0][0] == 0) {
        return ans;
    }
    
    string path = "";
    solve(0, 0, m, n, ans, visited, path);
    return ans;    
}
int main() {

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    
    vector<string> paths = findPath(maze);

    // Print the result paths
    if (paths.empty()) {
        cout << "No path found!" << endl;
    } 
    else {
        cout << "Paths: " << endl;
        for (auto path : paths) {
            cout << path << endl;
        }
    }
    return 0;
}
*/