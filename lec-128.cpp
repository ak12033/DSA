#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//                             Guess Number Higher or Lower II

//                                        Recursive
/*
int solve(int start, int end) {

    // Base Case
    if(start >= end) {
        return 0;
    }
    
    int mini = INT_MAX;
    for(int i = start; i <= end; i++) {
        mini = min(mini, i + max(solve(start, i-1), solve(i+1, end)));
    }
    return mini;
}
int getMoneyAmount(int n) {

    return solve(1, n);
}
int main() {

    int n = 10;
    cout << "Minimum cost to guarantee a win for n = " << n << " is: " << getMoneyAmount(n) << endl;

    return 0;
}
*/
//                                         Top-Down
/*
int solve(int start, int end, vector<vector<int>>& dp) {

    // Base Case
    if(start >= end) {
        return 0;
    }

    if(dp[start][end] != -1) {
        return dp[start][end];
    }
    
    int mini = INT_MAX;
    for(int i = start; i <= end; i++) {
        mini = min(mini, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
    }
    dp[start][end] = mini;
    return dp[start][end];
}
int getMoneyAmount(int n) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1, n, dp);
}
int main() {

    int n = 10;
    cout << "Minimum cost to guarantee a win for n = " << n << " is: " << getMoneyAmount(n) << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(int n) {

    vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

    for(int start = n; start >= 1; start--) {
        for(int end = start+1; end <= n; end++) {
            int mini = INT_MAX;
            for(int i = start; i <= end; i++) {
                mini = min(mini, i + max(dp[start][i-1], dp[i+1][end]));
            }
            dp[start][end] = mini;
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n) {

    return solve(n);
}
int main() {

    int n = 10;
    cout << "Minimum cost to guarantee a win for n = " << n << " is: " << getMoneyAmount(n) << endl;

    return 0;
}
*/