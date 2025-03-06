#include <iostream>
#include <vector>
using namespace std;

//                                     Recursive
/*
int solve(vector<int>& nums, int target) {
    
    // Base Case
    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }
    
    int ans = 0;
    for(int i=0; i<nums.size(); i++) {
        ans += solve(nums, target-nums[i]);
    }
    return ans;
}
int combinationSum4(vector<int>& nums, int target) {

    return solve(nums, target);
}
int main() {

    vector<int> nums = {1, 2, 3};
    int target = 4;

    int result = combinationSum4(nums, target);
    cout << "Number of possible combinations: " << result << endl;

    return 0;
}
*/
//                                      Top-Down
/*
int solve(vector<int>& nums, int target, vector<int>& dp) {
    
    // Base Case
    if(target < 0) {
        return 0;
    }

    if(target == 0) {
        return 1;
    }
    if(dp[target] != -1) {
        return dp[target];
    }
    int ans =0;
    for(int i=0; i<nums.size(); i++) {
        ans += solve(nums, target - nums[i], dp);
    }
    dp[target] = ans;
    return dp[target];
}
int combinationSum4(vector<int>& nums, int target) {

    vector<int> dp(target+1, -1);
    return solve(nums, target, dp);
}
int main() {

    vector<int> nums = {1, 2, 3};
    int target = 4;

    int result = combinationSum4(nums, target);
    cout << "Number of possible combinations: " << result << endl;

    return 0;
}
*/
//                                     Bottom-Up
/*
int solve(vector<int>& nums, int target) {

    vector<unsigned int> dp(target+1, 0);

    dp[0] = 1;

    // Traversing the target from 1 to target..
    for(int i=1; i<=target; i++) {
        for(int j=0; j<nums.size(); j++) {
            if(i-nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}
int combinationSum4(vector<int>& nums, int target) {

    return solve(nums, target);
}
int main() {

    vector<int> nums = {1, 2, 3};
    int target = 4;

    int result = combinationSum4(nums, target);
    cout << "Number of possible combinations: " << result << endl;

    return 0;
}
*/