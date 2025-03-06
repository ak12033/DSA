#include <iostream>
#include <vector>
using namespace std;

//                                      Pizza With 3n Slices

//                                            Recursive
/*
int solve(int index, int endIndex, vector<int>& slices, int n) {

    // Base Case
    if(n == 0 || index > endIndex) {
        return 0;
    }

    int include = slices[index] + solve(index+2, endIndex, slices, n-1);
    int exclude = 0 + solve(index+1, endIndex, slices, n);

    return max(include, exclude);
}
int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();
    int case1 = solve(0, k-2, slices, k/3);
    int case2 = solve(1, k-1, slices, k/3);

    return max(case1, case2);
}
int main() {

    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Result
    int result = maxSizeSlices(slices);
    cout << "Maximum size slices sum: " << result << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {

    // Base Case
    if(n == 0 || index > endIndex) {
        return 0;
    }

    if(dp[index][n] != -1) {
        return dp[index][n];
    }

    int include = slices[index] + solve(index+2, endIndex, slices, n-1, dp);
    int exclude = 0 + solve(index+1, endIndex, slices, n, dp);

    dp[index][n] = max(include, exclude);
    return dp[index][n];
}
int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();

    vector<vector<int>> dp1(k, vector<int>(k/3 + 1, -1));
    vector<vector<int>> dp2(k, vector<int>(k/3 + 1, -1));

    int case1 = solve(0, k-2, slices, k/3, dp1);
    int case2 = solve(1, k-1, slices, k/3, dp2);

    return max(case1, case2);
}
int main() {

    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Result
    int result = maxSizeSlices(slices);
    cout << "Maximum size slices sum: " << result << endl;

    return 0;
}
*/
//                                         Bottom-Up
/*
int solve(vector<int>& nums) {

    int k = nums.size();

    vector<vector<int>> dp1(k+2, vector<int>(k/3 + 1, 0));
    for(int index = k-2; index >= 0; index--) {
        for(int n=1; n <= k/3; n++) {
            int include = nums[index] + dp1[index+2][n-1];
            int exclude = 0 + dp1[index+1][n];
            dp1[index][n] = max(include, exclude);
        }
    }
    int case1 = dp1[0][k/3];

    vector<vector<int>> dp2(k+2, vector<int>(k/3 + 1, 0));
    for(int index = k-1; index >= 1; index--) {
        for(int n=1; n <= k/3; n++) {
            int include = nums[index] + dp2[index+2][n-1];
            int exclude = 0 + dp2[index+1][n];
            dp2[index][n] = max(include, exclude);
        }
    }
    int case2 = dp2[1][k/3];

    return max(case1, case2);
}
int maxSizeSlices(vector<int>& slices) {

    return solve(slices);
}
int main() {

    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Result
    int result = maxSizeSlices(slices);
    cout << "Maximum size slices sum: " << result << endl;

    return 0;
}
*/
//                                    Space-Optimised
/*
int solve(vector<int>& nums) {

    int k = nums.size();

    vector<int> prev1(k/3 + 1, 0);
    vector<int> curr1(k/3 + 1, 0);
    vector<int> next1(k/3 + 1, 0);

    for(int index = k-2; index >= 0; index--) {
        for(int n=1; n <= k/3; n++) {
            int include = nums[index] + next1[n-1];
            int exclude = 0 + curr1[n];
            prev1[n] = max(include, exclude);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k/3];

    vector<int> prev2(k/3 + 1, 0);
    vector<int> curr2(k/3 + 1, 0);
    vector<int> next2(k/3 + 1, 0);

    for(int index = k-1; index >= 1; index--) {
        for(int n=1; n <= k/3; n++) {
            int include = nums[index] + next2[n-1];
            int exclude = 0 + curr2[n];
            prev2[n] = max(include, exclude);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[k/3];

    return max(case1, case2);
}
int maxSizeSlices(vector<int>& slices) {

    return solve(slices);
}
int main() {

    vector<int> slices = {1, 2, 3, 4, 5, 6};

    // Result
    int result = maxSizeSlices(slices);
    cout << "Maximum size slices sum: " << result << endl;

    return 0;
}
*/