#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//                                        Coin Change

//                                         Recursive
/*
int solve(vector<int>& coins, int x) {

    if(x == 0) {
        return 0;
    }

    if(x < 0) {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = solve(coins, x-coins[i]);
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}
int coinChange(vector<int>& coins, int amount) {

    int ans = solve(coins, amount);
    if(ans == INT_MAX) {
        return -1;
    }
    return ans;
}
int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 1;

    // Result
    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}
*/
//                                         Top-Down
/*
int solve(vector<int>& coins, int x, vector<int>& dp) {

    if(x == 0) {
        return 0;
    }

    if(x < 0) {
        return INT_MAX;
    }

    if(dp[x] != -1) {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = solve(coins, x-coins[i], dp);
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    return dp[x];
}
int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount+1, -1);

    int ans = solve(coins, amount, dp);
    if(ans == INT_MAX) {
        return -1;
    }
    return ans;
}
int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 1;

    // Result
    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(vector<int>& coins, int x) {

    vector<int> dp(x+1, INT_MAX);

    dp[0] = 0;

    for(int i=1; i<=x; i++) {
        for(int j=0; j<coins.size(); j++) {
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }
    return dp[x];
}
int coinChange(vector<int>& coins, int amount) {

    int ans = solve(coins, amount);
    if(ans == INT_MAX) {
        return -1;
    }
    return ans;
}
int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // Result
    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}
*/





