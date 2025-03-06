#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//                               Longest Arithmetic Subsequence

//                                         Recursive
/*
int solve(int index, int diff, vector<int>& nums) {

    // Backward check
    if(index < 0) {
        return 0;
    }

    int ans = 0;
    for(int j = index-1; j >= 0; j--) {
        if(nums[index] - nums[j] == diff) {
            ans = max(ans, 1 + solve(j, diff, nums));
        }
    }
    return ans;
}
int longestArithSeqLength(vector<int>& nums) {

    int n = nums.size();

    if(n <= 2) {
        return n;
    }
        
    int ans = 0;  
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            ans = max(ans, 2 + solve(i, nums[j]-nums[i], nums));
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {3, 6, 9, 12}; 

    int result = longestArithSeqLength(nums);
    cout << "Longest Arithmetic Subsequence Length: " << result << endl;

    return 0;
}
*/
//                                         Top-Down
/*
int solve(int index, int diff, vector<int>& nums, vector<vector<int>>& dp) {

    // Backward check
    if(index < 0) {
        return 0;
    }

    // Adding 501 to avoid negative difference
    if(dp[index][diff+501] != -1) {
        return dp[index][diff+501];
    }

    int ans = 0;
    for(int j = index-1; j >= 0; j--) {
        if(nums[index] - nums[j] == diff) {
            ans = max(ans, 1 + solve(j, diff, nums, dp));
        }
    }
    return dp[index][diff+501] = ans;
}
int longestArithSeqLength(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(1002, -1));

    if(n <= 2) {
        return n;
    }

    int ans = 0;  
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            ans = max(ans, 2 + solve(i, nums[j]-nums[i], nums, dp));
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {3, 6, 9, 12}; 

    int result = longestArithSeqLength(nums);
    cout << "Longest Arithmetic Subsequence Length: " << result << endl;

    return 0;
}
*/
//                                  Top-Down (unordered_map)
/*
int solve(int index, int diff, vector<int>& nums, unordered_map <int, int> dp[]) {

    // Backward check
    if(index < 0) {
        return 0;
    }

    // Adding 501 to avoid negative difference
    if(dp[index].count(diff)) {
        return dp[index][diff];
    }

    int ans = 0;
    for(int j = index-1; j >= 0; j--) {
        if(nums[index] - nums[j] == diff) {
            ans = max(ans, 1 + solve(j, diff, nums, dp));
        }
    }
    dp[index][diff] = ans;
    return dp[index][diff];
}
int longestArithSeqLength(vector<int>& nums) {

    int n = nums.size();
    unordered_map <int,int> dp[n];

    if(n <= 2) {
        return n;
    }

    int ans = 0;  
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            ans = max(ans, 2 + solve(i, nums[j]-nums[i], nums, dp));
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {3, 6, 9, 12}; 

    int result = longestArithSeqLength(nums);
    cout << "Longest Arithmetic Subsequence Length: " << result << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int longestArithSeqLength(vector<int>& nums) {

    int n = nums.size();
    unordered_map<int,int> dp[n];

    if (n <= 2) {
        return n;
    }

    int ans = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            int diff = nums[i] - nums[j];
            int cnt = 1;
            if(dp[j].count(diff)) {
                cnt = dp[j][diff];
            }
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {3, 6, 9, 12}; 

    int result = longestArithSeqLength(nums);
    cout << "Longest Arithmetic Subsequence Length: " << result << endl;

    return 0;
}
*/