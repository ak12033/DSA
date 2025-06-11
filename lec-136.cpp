#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//                              Longest Palindromic Subsequence

//                                         Recursive
/*
int solve(string& a, string& b, int i, int j) {

    // Base Case
    if(i == a.length()) {
        return 0;
    }

    if(j == b.length()) {
        return 0;
    }

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + solve(a, b, i+1, j+1);
    }
    else {
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }
    return ans;
}
int longestPalindromeSubseq(string s) {

    string revStr = s;
    reverse(revStr.begin(), revStr.end());

    return solve(s, revStr, 0, 0);
}
int main() {

    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << longestPalindromeSubseq(s) << endl;

    return 0;
}
*/
//                                         Top-Down
/*
int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {

    // Base Case
    if(i == a.length()) {
        return 0;
    }

    if(j == b.length()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + solve(a, b, i+1, j+1, dp);
    }
    else {
        ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int longestPalindromeSubseq(string s) {

    string revStr = s;
    reverse(revStr.begin(), revStr.end());

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    return solve(s, revStr, 0, 0, dp);
}
int main() {

    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << longestPalindromeSubseq(s) << endl;

    return 0;
}
*/
//                                       Bottom-Up
/*
int solve(string& a, string& b) {

    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i = a.length()-1; i >= 0; i--) {
        for(int j = b.length()-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + dp[i+1][j+1];
            }
            else {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int longestPalindromeSubseq(string s) {

    string revStr = s;
    reverse(revStr.begin(), revStr.end());

    return solve(s, revStr);
}
int main() {

    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << longestPalindromeSubseq(s) << endl;

    return 0;
}
*/
//                                      Space-Optimised
/*
int solve(string& a, string& b) {

    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int i = a.length()-1; i >= 0; i--) {
        for(int j = b.length()-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + next[j+1];
            }
            else {
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int longestPalindromeSubseq(string s) {

    string revStr = s;
    reverse(revStr.begin(), revStr.end());

    return solve(s, revStr);
}
int main() {

    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << longestPalindromeSubseq(s) << endl;

    return 0;
}
*/