#include <iostream>
#include <vector>
using namespace std;

//                                   House Robber II

//                                      Recursive
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
int rob(vector<int>& nums) {

    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    
    vector<int> first, second;
    for(int i=0; i<n; i++) {
        if(i != n-1) {
            first.push_back(nums[i]);
        }
        if(i != 0) {
            second.push_back(nums[i]);
        }
    }
    int ans = max(solve(first, first.size()-1), solve(second, second.size()-1));
    return ans;
}
int main() {

    vector<int> nums = {2, 3, 2};
    cout << "Maximum money that can be robbed: " << rob(nums) << endl;

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
int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);

    if (n == 1) {
        return nums[0];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++) {
        if(i != n-1) {
            first.push_back(nums[i]);
        }
        if(i != 0) {
            second.push_back(nums[i]);
        }
    }
    int ans = max(solve(first, first.size()-1, dp1), solve(second, second.size()-1, dp2));
    return ans;
}
int main() {

    vector<int> nums = {2, 3, 2};
    cout << "Maximum money that can be robbed: " << rob(nums) << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(vector<int>& nums) {

    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    
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
int rob(vector<int>& nums) {

    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }

    vector<int> first, second;

    for(int i=0; i<n; i++) {
        if(i != n-1) {
            first.push_back(nums[i]);
        }
        if(i != 0) {
            second.push_back(nums[i]);
        }
    }
    int ans = max(solve(first), solve(second));
    return ans;
}
int main() {

    vector<int> nums = {2, 3, 2};
    cout << "Maximum money that can be robbed: " << rob(nums) << endl;

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
int rob(vector<int>& nums) {

    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }

    vector<int> first, second;
    for(int i=0; i<n; i++) {
        if(i != n-1) {
            first.push_back(nums[i]);
        }
        if(i != 0) {
            second.push_back(nums[i]);
        }
    }
    return max(solve(first), solve(second));
}
int main() {

    vector<int> nums = {2, 3, 2};
    cout << "Maximum money that can be robbed: " << rob(nums) << endl;

    return 0;
}
*/