#include <iostream>
#include <vector>
using namespace std;

//                          Number of Dice Rolls With Target Sum

//                                        Recursive
/*
int solve(int dice, int faces, int target) {
         
    // Base Case
    if(target < 0) {
        return 0;
    }

    if(target != 0 && dice == 0 ) {
        return 0;
    }

    if(target == 0 && dice != 0 ) {
        return 0;
    }

    if(target == 0 && dice == 0) {
        return 1;
    }

    int ans = 0;
    for(int i=1; i <= faces; i++) {
        ans = ans + solve(dice-1, faces, target-i);
    }
    return ans;
}
int numRollsToTarget(int n, int k, int target) {

    return solve(n, k, target);
}
int main() {

    int n = 2, k = 6, target = 7;
    cout << "Number of ways: " << numRollsToTarget(n, k, target) << endl;

    return 0;
}
*/
//                                         Top-Bottom
/*
int mod = 1e9 + 7;
int solve(int dice, int faces, int target, vector<vector<int>>& dp) {
         
    // Base Case
    if(target < 0) {
        return 0;
    }

    if(target != 0 && dice == 0) {
        return 0;
    }

    if(target == 0 && dice != 0) {
        return 0;
    }

    if(target == 0 && dice == 0) {
        return 1;
    }

    if(dp[dice][target] != -1) {
        return dp[dice][target] % mod;
    }

    int ans = 0;
    for(int i=1; i <= faces; i++) {
        ans = (ans + solve(dice-1, faces, target-i, dp)) % mod;
    }
    dp[dice][target] = ans % mod;
    return dp[dice][target];
}
int numRollsToTarget(int n, int k, int target) {

    vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));
    return solve(n, k, target, dp);
}
int main() {

    int n = 2, k = 6, target = 7;
    cout << "Number of ways: " << numRollsToTarget(n, k, target) << endl;

    return 0;
}
*/
//                                          Bottom-Up
/*
int mod = 1e9 + 7;
int solve(int d, int f, int t){

    vector<vector<int>> dp(d+1, vector<int>(t+1, 0));

    dp[0][0] = 1;

    for(int dice = 1; dice <= d; dice++) {
        for(int target = 1; target <= t; target++) {
        int ans = 0;
            for(int i=1; i <= f; i++) {
                if(target - i >= 0) {
                    ans = (ans + dp[dice-1][target-i]) % mod;
                }
            }
            dp[dice][target] = ans % mod;
        }
    }
    return dp[d][t];
}
int numRollsToTarget(int n, int k, int target) {

    return solve(n, k, target);
}
int main() {

    int n = 2, k = 6, target = 7;
    cout << "Number of ways: " << numRollsToTarget(n, k, target) << endl;

    return 0;
}
*/
//                                      Space-Optimised
/*
int mod = 1e9 + 7;
int solve(int d, int f, int t){

    vector<int> prev(t+1, 0);
    vector<int> curr(t+1, 0);

    prev[0] = 1;

    for(int dice = 1; dice <= d; dice++) {
        for(int target = 1; target <= t; target++) {
        int ans = 0;
            for(int i=1; i <= f; i++) {
                if(target - i >= 0) {
                    ans = (ans + prev[target-i]) % mod;
                }
            }
            curr[target] = ans % mod;
        }
        prev = curr;
    }
    return prev[t];
}
int numRollsToTarget(int n, int k, int target) {

    return solve(n, k, target);
}
int main() {

    int n = 2, k = 6, target = 7;
    cout << "Number of ways: " << numRollsToTarget(n, k, target) << endl;

    return 0;
}
*/