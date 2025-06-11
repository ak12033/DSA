#include <iostream>
#include <vector>
using namespace std;

//                                Partition Equal Subset Sum

//                                        Recursive
/*
bool solve(int index, vector<int>& nums, int n, int target) {
    
    // Base Case
    if(index >= n) {
        return 0;
    }

    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }

    bool include = solve(index+1, nums, n, target - nums[index]);
    bool exclude = solve(index+1, nums, n, target);

    return include || exclude;
}
bool canPartition(vector<int>& nums) {

    int n = nums.size();

    int total = 0;
    for(int i : nums) {
        total += i;
    }

    if(total & 1) {
        return 0;
    }

    int target = total / 2;
    return solve(0, nums, n, target);
}
int main() {

    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (canPartition(nums) ? "Yes" : "No") << endl;

    return 0;
}
*/
//                                          Top-Down
/*
bool solve(int index, vector<int>& nums, int n, int target, vector<vector<int>> &dp) {
    
    // Base Case
    if(index >= n) {
        return 0;
    }

    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }

    if(dp[index][target] != -1) {
        return dp[index][target];
    }

    bool include = solve(index+1, nums, n, target - nums[index], dp);
    bool exclude = solve(index+1, nums, n, target, dp);

    dp[index][target] = include || exclude;
    return dp[index][target];
}
bool canPartition(vector<int>& nums) {

    int n = nums.size();

    int total = 0;
    for(int i : nums) {
        total += i;
    }

    if(total & 1) {
        return 0;
    }

    int target = total / 2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return solve(0, nums, n, target, dp);
}
int main() {

    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (canPartition(nums) ? "Yes" : "No") << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
bool solve(int n, vector<int>& arr, int target) {

    vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));

    for(int i=0; i<=n; i++) {
        dp[i][0] = true;
    }

    for(int index = n-1; index>=0; index--) {
        for(int t=0; t <= target; t++) {
            // Include
            bool incl = 0;
            if(t - arr[index] >= 0) {
                incl = dp[index+1][t-arr[index]];
            }
            // Exclude
            bool excl = dp[index+1][t];
            dp[index][t] = incl || excl;
        }
    }
    return dp[0][target];
}
bool canPartition(vector<int>& nums) {

    int n = nums.size();

    int total = 0;
    for(int i : nums) {
        total += i;
    }

    if(total & 1) {
        return 0;
    }

    int target = total / 2;
    return solve(n, nums, target);
}
int main() {

    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (canPartition(nums) ? "Yes" : "No") << endl;

    return 0;
}
*/
//                                        Space-Optimised
/*
bool solve(int n, vector<int>& arr, int target) {

    vector<int> curr(target + 1, 0);
    vector<int> next(target + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index = n-1; index>=0; index--) {
        for(int t=0; t <= target; t++) {
            // Include
            bool incl = 0;
            if(t - arr[index] >= 0) {
                incl = next[t-arr[index]];
            }
            // Exclude
            bool excl = next[t];
            curr[t] = incl || excl;
        }
        next = curr;
    }
    return next[target];
}
bool canPartition(vector<int>& nums) {

    int n = nums.size();

    int total = 0;
    for(int i : nums) {
        total += i;
    }

    if(total & 1) {
        return 0;
    }

    int target = total / 2;
    return solve(n, nums, target);
}
int main() {

    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (canPartition(nums) ? "Yes" : "No") << endl;

    return 0;
}
*/