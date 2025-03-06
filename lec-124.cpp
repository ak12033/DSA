#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//                         Minimum Swaps To Make Sequences Increasing

//                                          Recursive
/*
int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
    
    // Base Case
    if(index == nums1.size()) {
        return 0;
    }

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];
    // If the previous elements are needed to swap, swap them for comparison
    if(swapped) {
        swap(prev1, prev2);
    }

    int ans = INT_MAX;
    // No swap
    if(nums1[index] > prev1 && nums2[index] > prev2) {
        ans = solve(nums1, nums2, index+1, 0);
    }
    // Swap       
    if (nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));
    }
    return ans;
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    return solve(nums1, nums2, 1, swapped);
}
int main() {

    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};

    // Result
    int result = minSwap(nums1, nums2);
    cout << "Minimum swaps needed: " << result << endl;

    return 0;
}
*/
//                                      Top-Down
/*
int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp) {
    
    // Base Case
    if(index == nums1.size()) {
        return 0;
    }

    if(dp[index][swapped] != -1){
        return dp[index][swapped];
    }

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];
    // If the previous elements are needed to swap, swap them for comparison
    if(swapped) {
        swap(prev1, prev2);
    }

    int ans = INT_MAX;
    // No swap
    if(nums1[index] > prev1 && nums2[index] > prev2) {
        ans = solve(nums1, nums2, index+1, 0, dp);
    }
    // Swap       
    if (nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans, 1 + solve(nums1, nums2, index+1, 1, dp));
    }
    dp[index][swapped] = ans;
    return dp[index][swapped];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));

    bool swapped = 0;
    return solve(nums1, nums2, 1, swapped, dp);
}
int main() {

    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};

    // Result
    int result = minSwap(nums1, nums2);
    cout << "Minimum swaps needed: " << result << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index = n-1; index >= 1; index--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            // Catch
            if(swapped) {
                swap(prev1, prev2);
            }
            // No swap
            if(nums1[index] > prev1 && nums2[index] > prev2) {
                ans = dp[index+1][0];
            }  
            // Swap
            if(nums1[index] > prev2 && nums2[index] > prev1) {
                ans = min(ans, 1 + dp[index+1][1]);
            } 
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}
int main() {

    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};

    // Result
    int result = minSwap(nums1, nums2);
    cout << "Minimum swaps needed: " << result << endl;

    return 0;
}
*/
//                                    Space-Optimised-1
/*
int solve(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int index = n-1; index >= 1; index--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            // Catch
            if(swapped) {
                swap(prev1, prev2);
            }
            // No swap
            if(nums1[index] > prev1 && nums2[index] > prev2) {
                ans = next[0];
            }  
            // Swap
            if(nums1[index] > prev2 && nums2[index] > prev1) {
                ans = min(ans, 1 + next[1]);
            } 
            curr[swapped] = ans;
        }
        next = curr;
    }
    return next[0];
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}
int main() {

    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};

    // Result
    int result = minSwap(nums1, nums2);
    cout << "Minimum swaps needed: " << result << endl;

    return 0;
}
*/
//                                     Space-Optimised-2
/*
int solve(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
    
    int currswap = 0;
    int currnoswap = 0;
    int nextswap = 0;
    int nextnoswap = 0;

    for(int index = n-1; index >= 1; index--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            // Catch
            if(swapped) {
                swap(prev1, prev2);
            }
            // No swap
            if(nums1[index] > prev1 && nums2[index] > prev2) {
                ans = nextnoswap;
            }  
            // Swap
            if(nums1[index] > prev2 && nums2[index] > prev1) {
                ans = min(ans, 1 + nextswap);
            } 
            if(swapped) {
                currswap = ans;
            }
            else {
                currnoswap = ans;
            }
        }
        nextswap = currswap;
        nextnoswap = currnoswap;
    }
    return nextnoswap;
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {

    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}
int main() {

    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};

    // Result
    int result = minSwap(nums1, nums2);
    cout << "Minimum swaps needed: " << result << endl;

    return 0;
}
*/