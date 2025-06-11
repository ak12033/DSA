#include <iostream>
#include <vector>
using namespace std;

//                        Maximum sum of non-adjacent elements
//                                         OR
//                                    House Robber

//                                     Recursive
/*
int solve(vector<int>& nums, int n) {
    
    // Base Case
    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return nums[0];
    }
    
    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1) + 0;
    
    return max(incl, excl);
} 
int maximumNonAdjacentSum(vector<int>& nums) {

    int n = nums.size();
    int ans = solve(nums, n-1);
    return ans;
}
int main() {
    
    vector<int> nums = {9, 9, 8, 2};
    
    // Result
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/
//                                     Top-Down
/*
int solve(vector<int>& nums, int n, vector<int>& dp) {

    // Base Case
    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return nums[0];
    }

    if(dp[n] != -1) {
        return dp[n];
    }
    
    int incl = solve(nums, n-2, dp) + nums[n];
    int excl = solve(nums, n-1, dp) + 0;
    
    dp[n] = max(incl, excl);
    return dp[n];
} 
int maximumNonAdjacentSum(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n-1, dp);
}
int main() {
    
    vector<int> nums = {9, 9, 8, 2};
    
    // Result
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/
//                                     Bottom-Up
/*
int solve(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n, 0);
        
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
            
    for(int i=2; i<n; i++) {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){

    if(nums.size() == 1) {
        return nums[0];
    }
    return solve(nums);
}
int main() {
    
    vector<int> nums = {9, 9, 8, 2};
    
    // Result
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/
//                                  Space-Optimised
/*
int solve(vector<int>& nums) {

    int prev2 = 0;
    int prev1 = nums[0];
        
    for(int i=1; i<nums.size(); i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int>& nums) {

    return solve(nums); 
}
int main() {
    
    vector<int> nums = {9, 9, 8, 2};
    
    // Result
    int result = maximumNonAdjacentSum(nums);
    cout << "Maximum Non-Adjacent Sum: " << result << endl;
    
    return 0;
}
*/