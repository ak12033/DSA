#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                           Longest Increasing Subsequence

//                                      Recursive
/*
int solve(int n, vector<int>& nums, int curr, int prev) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    // Include 
    int take = 0;
    if(prev == -1 || nums[curr] > nums[prev]) {
        take = 1 + solve(n, nums, curr+1, curr);
    }
    // Exclude
    int notTake = solve(n, nums, curr+1, prev);

    return max(take, notTake);
}
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();
    return solve(n, nums, 0, -1);
}
int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
*/
//                                      Top-Down
/*
int solve(int n, vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    if(dp[curr][prev+1] != -1) {
        return dp[curr][prev+1];
    }

    // Include 
    int take = 0;
    if(prev == -1 || nums[curr] > nums[prev]) {
        take = 1 + solve(n, nums, curr+1, curr, dp);
    }
    // Exclude
    int notTake = solve(n, nums, curr+1, prev, dp);

    dp[curr][prev+1] = max(take, notTake);
    return dp[curr][prev+1];
}
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solve(n, nums, 0, -1, dp);
}
int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
*/
//                                     Bottom-Up
/*
int solve(int n, vector<int>& nums) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || nums[curr] > nums[prev]) {
                take = 1 + dp[curr+1][curr+1];
            }
            // Exclude
            int notTake = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();
    return solve(n, nums);
}
int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
*/
//                                     Space-Optimised
/*
int solve(int n, vector<int>& nums) {

    vector<int> currRow(n+1, 0) ;
    vector<int> nextRow(n+1, 0);

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || nums[curr] > nums[prev]) {
                take = 1 + nextRow[curr+1];
            }
            // Exclude
            int notTake = 0 + nextRow[prev+1];
            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();
    return solve(n, nums);
}
int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
*/
//                                  Binary Search Approach
/*
int solve(vector<int>& nums) {

    vector<int> ans;

    ans.push_back(nums[0]);
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
        // Find index of just bigger element in ans
        int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
        ans[index] = nums[i];
        }
    }
    return ans.size();
}
int lengthOfLIS(vector<int>& nums) {

    return solve(nums);
}
int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
*/

//                              Russian Doll Envelopes

//                                     Recursive
/*
static bool comp(vector<int>& a, vector<int>& b) {

    // Sort in decreasing order of the second number.
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    // Sort in increasing order of the first number.
    return a[0] < b[0];  
}
int solve(int n, vector<vector<int>>& envelopes, int curr, int prev) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    // Include 
    int take = 0;
    if(prev == -1 || envelopes[curr][1] > envelopes[prev][1]) {
        take = 1 + solve(n, envelopes, curr+1, curr);
    }
    // Exclude
    int notTake = solve(n, envelopes, curr+1, prev);

    return max(take, notTake);
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);

    return solve(n, envelopes, 0, -1);
}
int main() {

    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of Russian Doll Envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
*/
//                                      Top-Down
/*
static bool comp(vector<int>& a, vector<int>& b) {

    // Sort in decreasing order of the second number.
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    // Sort in increasing order of the first number.
    return a[0] < b[0];  
}
int solve(int n, vector<vector<int>>& envelopes, int curr, int prev, vector<vector<int>>& dp) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    if(dp[curr][prev+1] != -1) {
        return dp[curr][prev+1];
    }

    // Include 
    int take = 0;
    if(prev == -1 || envelopes[curr][1] > envelopes[prev][1]) {
        take = 1 + solve(n, envelopes, curr+1, curr, dp);
    }
    // Exclude
    int notTake = solve(n, envelopes, curr+1, prev, dp);

    dp[curr][prev+1] = max(take, notTake);
    return dp[curr][prev+1];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);

    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(n, envelopes, 0, -1, dp);
}
int main() {

    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of Russian Doll Envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
static bool comp(vector<int>& a, vector<int>& b) {

    // Sort in decreasing order of the second number.
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    // Sort in increasing order of the first number.
    return a[0] < b[0];  
}
int solve(int n, vector<vector<int>>& envelopes) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || envelopes[curr][1] > envelopes[prev][1]) {
                take = 1 + dp[curr+1][curr+1];
            }
            // Exclude
            int notTake = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);

    return solve(n, envelopes);
}
int main() {

    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of Russian Doll Envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
*/
//                                    Space-Optimised
/*
static bool comp(vector<int>& a, vector<int>& b) {

    // Sort in decreasing order of the second number.
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    // Sort in increasing order of the first number.
    return a[0] < b[0];  
}
int solve(int n, vector<vector<int>>& envelopes) {

    vector<int> currRow(n+1, 0) ;
    vector<int> nextRow(n+1, 0);

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || envelopes[curr][1] > envelopes[prev][1]) {
                take = 1 + nextRow[curr+1];
            }
            // Exclude
            int notTake = 0 + nextRow[prev+1];
            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);

    return solve(n, envelopes);
}
int main() {

    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of Russian Doll Envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
*/
//                                  Binary Search Approach
/*
static bool comp(vector<int>& a, vector<int>& b) {

    // Sort in decreasing order of the second number.
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    // Sort in increasing order of the first number.
    return a[0] < b[0];  
}
int solve(vector<vector<int>>& envelopes) {

    vector<int> ans;

    ans.push_back(envelopes[0][1]);
    for(int i=1; i<envelopes.size(); i++) {
        if(envelopes[i][1] > ans.back()) {
            ans.push_back(envelopes[i][1]);
        }
        else {
        // Find index of just bigger element in ans
        int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
        ans[index] = envelopes[i][1];
        }
    }
    return ans.size();
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    sort(envelopes.begin(), envelopes.end(), comp);
    return solve(envelopes);
}
int main() {

    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of Russian Doll Envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}
*/