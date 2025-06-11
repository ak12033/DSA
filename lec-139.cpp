#include <iostream>
#include <vector>
#include <string>
using namespace std;

//                                   Wildcard Matching

//                                       Recursive
/*
bool solve(string& str, string& pattern, int i, int j) {

    // Base Case
    if(i < 0 && j < 0) {
        return true;
    }

    if(i >= 0 && j < 0) {
        return false;
    }
    if(i < 0 && j >= 0) {
        for(int k=0; k<=j; k++) {
            if(pattern[k] != '*') {
                return false;
            }
        }
        return true;
    }

    // Match
    if(str[i] == pattern[j] || pattern[j] == '?') {
        return solve(str, pattern, i-1, j-1);
    }
    // Replace with '* + any character' or Empty string 
    else if(pattern[j] == '*') {
        return (solve(str, pattern, i-1, j) || solve(str, pattern, i, j-1));
    }
    else {
        return false;
    }
}
bool isMatch(string s, string p) {

    return solve(s, p, s.length()-1, p.length()-1);
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/
//                                       1-Based Indexing
/*
bool solve(string& str, string& pattern, int i, int j) {

    // Base Case
    if(i == 0 && j == 0) {
        return true;
    }

    if(i > 0 && j == 0) {
        return false;
    }
    if(i == 0 && j > 0) {
        for(int k=1; k<=j; k++) {
            if(pattern[k-1] != '*') {
                return false;
            }
        }
        return true;
    }

    // Match
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
        return solve(str, pattern, i-1, j-1);
    }
    // Replace with '* + any character' or Empty string 
    else if(pattern[j-1] == '*') {
        return (solve(str, pattern, i-1, j) || solve(str, pattern, i, j-1));
    }
    else {
        return false;
    }
}
bool isMatch(string s, string p) {

    return solve(s, p, s.length(), p.length());
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/
//                                        Top-Down
/*
bool solve(string& str, string& pattern, int i, int j, vector<vector<int>>& dp) {

    // Base Case
    if(i < 0 && j < 0) {
        return true;
    }

    if(i >= 0 && j < 0) {
        return false;
    }

    if(i<0 && j>=0) {
        for(int k=0; k<=j; k++) {
            if(pattern[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // Match
    if(str[i] == pattern[j] || pattern[j] == '?') {
        dp[i][j] = solve(str, pattern, i-1, j-1, dp);
        return dp[i][j];
    }
    // Replace with '* + any character' or Empty string 
    else if(pattern[j] == '*') {
        dp[i][j] = (solve(str, pattern, i-1, j, dp) || solve(str, pattern, i, j-1, dp));
        return dp[i][j];
    }
    else {
        return false;
    }
}
bool isMatch(string s, string p) {

    vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
    return solve(s, p, s.length()-1, p.length()-1, dp);
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/
//                                   1-Based Indexing
/*
bool solve(string& str, string& pattern, int i, int j, vector<vector<int>>& dp) {
    
    // Base Case
    if(i==0 && j==0) {
        return true;
    }
    if(i>0 && j==0) {
        return false;
    }
    if(i==0 && j>0) {
        for(int k=1; k<=j; k++) {
            if(pattern[k-1] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // Match
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
        dp[i][j] = solve(str, pattern, i-1, j-1, dp);
        return dp[i][j];
    }
    else if(pattern[j-1] == '*') {
        dp[i][j] = (solve(str, pattern, i-1, j, dp) || solve(str, pattern, i, j-1, dp));
        return dp[i][j];
    }
    else {
        return false;
    }
}
bool isMatch(string s, string p) {

    vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
    return solve(s, p, s.length(), p.length(), dp);
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/
//                                        Bottom-Up
/*
bool solve(string& str, string& pattern) {

    vector<vector<int>> dp(str.length()+1, vector<int>(pattern.length()+1, 0));

    dp[0][0] = true;

    for(int j=1; j <= pattern.length(); j++) {
        bool flag = true;
        for(int k=1; k<=j; k++) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for(int i=1; i <= str.length(); i++) {
        for(int j=1; j <= pattern.length(); j++) {
            // Match
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*') {
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[str.length()][pattern.length()];
}
bool isMatch(string s, string p) {

    return solve(s, p);
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/
//                                      Space-Optimised
/*
bool solve(string& str, string& pattern) {

    vector<int> prev(pattern.length()+1, 0);
    vector<int> curr(pattern.length()+1, 0);

    prev[0] = true;

    for(int j=1; j <= pattern.length(); j++) {
        bool flag = true;
        for(int k=1; k<=j; k++) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for(int i=1; i <= str.length(); i++) {
        for(int j=1; j <= pattern.length(); j++) {
            // Match
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                curr[j] = prev[j-1];
            }
            else if(pattern[j-1] == '*') {
                curr[j] = (prev[j] || curr[j-1]);
            }
            else {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[pattern.length()];
}
bool isMatch(string s, string p) {

    return solve(s, p);
}
int main() {

    string s = "abcde";
    string p = "a*de";

    if(isMatch(s, p)) {
        cout << "Pattern matches the string!" << endl;
    } 
    else {
        cout << "Pattern does not match the string." << endl;
    }
    return 0;
}
*/