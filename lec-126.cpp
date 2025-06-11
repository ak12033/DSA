#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//                     Longest Arithmetic Subsequence of Given Difference

//                                       Recursive
/*
int solve(vector<int>& arr, int diff, int index) {

    int result = 0;
    for(int j=index+1; j<arr.size(); j++) {
        if(arr[j] - arr[index] == diff) {
            result = max(result, 1 + solve(arr, diff, j));
        }
    }
    return result;
}
int longestSubsequence(vector<int>& arr, int difference) {
    
    int result = 0;
    for(int i=0; i<arr.size(); i++) {
        result = max(result, 1 + solve(arr, difference, i)); 
    }
    return result;
}
int main() {

    vector<int> arr = {1, 5, 7, 8, 5, 3}; 
    int difference = -2;

    // Result
    int result = longestSubsequence(arr, difference);
    cout << "Length of the longest subsequence with difference " << difference << " is: " << result << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(vector<int>& arr, int diff, int index, vector<int>& dp) {

    if(dp[index] != -1) {
        return dp[index];
    }
    int result = 0;
    for(int j=index+1; j<arr.size(); j++) {
        if(arr[j] - arr[index] == diff) {
            result = max(result, 1 + solve(arr, diff, j, dp));
        }
    }
    dp[index] = result;
    return dp[index];
}
int longestSubsequence(vector<int>& arr, int difference) {

    int n = arr.size();
    vector<int> dp(n, -1);
    
    int result = 0;
    for(int i=0; i<arr.size(); i++) {
        result = max(result, 1 + solve(arr, difference, i, dp)); 
    }
    return result;
}
int main() {

    vector<int> arr = {1, 5, 7, 8, 5, 3}; 
    int difference = -2;

    // Result
    int result = longestSubsequence(arr, difference);
    cout << "Length of the longest subsequence with difference " << difference << " is: " << result << endl;

    return 0;
}
*/
//                                         Bottom-Up
/*
int longestSubsequence(vector<int>& arr, int difference) {

    unordered_map<int,int> dp;

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        int temp = arr[i] - difference;
        int tempAns = 0;
        // Checking whether temp exists or not
        if(dp.count(temp)) {
            tempAns = dp[temp];
        }
        // Current ans update
        dp[arr[i]] = 1 + tempAns;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}
int main() {

    vector<int> arr = {1, 5, 7, 8, 5, 3}; 
    int difference = -2;

    // Result
    int result = longestSubsequence(arr, difference);
    cout << "Length of the longest subsequence with difference " << difference << " is: " << result << endl;

    return 0;
}
*/