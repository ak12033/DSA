#include <iostream>
#include <vector>
using namespace std;

//                              Best Time to Buy and Sell Stock IV

//                                            Recursive
/*
int solve(int index, int buy, vector<int>& prices, int limit) {

    // Base Case
    if(index == prices.size()) {
        return 0;
    }

    if(limit == 0) {
        return 0;
    }
    
    int profit = 0;
    if(buy) {
        int buyKaro = -prices[index] + solve(index+1, 0, prices, limit);
        int skipKaro = 0 + solve(index+1, 1, prices, limit);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int sellKaro = prices[index] + solve(index+1, 1, prices, limit-1);
        int skipKaro = 0 + solve(index+1, 0, prices, limit);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}
int maxProfit(int k, vector<int>& prices) {

    return solve(0, 1, prices, k);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(int index, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>>& dp) {

    // Base Case
    if(index == prices.size()) {
        return 0;
    }

    if(limit == 0) {
        return 0;
    }

    if(dp[index][buy][limit] != -1) {
        return dp[index][buy][limit];
    }
    
    int profit = 0;
    if(buy) {
        int buyKaro = -prices[index] + solve(index+1, 0, prices, limit, dp);
        int skipKaro = 0 + solve(index+1, 1, prices, limit, dp);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int sellKaro = prices[index] + solve(index+1, 1, prices, limit-1, dp);
        int skipKaro = 0 + solve(index+1, 0, prices, limit, dp);
        profit = max(sellKaro, skipKaro);
    }
    dp[index][buy][limit] = profit;
    return dp[index][buy][limit];
}
int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));
    return solve(0, 1, prices, k, dp);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                          Bottom-Up
/*
int solve(int k, vector<int>& prices) {

    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int limit = 1; limit <= k; limit++) {
                int profit = 0;
                if(buy) {
                    int buyKaro = -prices[index] + dp[index+1][0][limit];
                    int skipKaro = 0 + dp[index+1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[index] + dp[index+1][1][limit-1];
                    int skipKaro = 0 + dp[index+1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][k];
}
int maxProfit(int k, vector<int>& prices) {

    return solve(k, prices);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                        Space-Optimised
/*
int solve(int k, vector<int>& prices) {

    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(k+1, 0));
    vector<vector<int>> curr(2, vector<int>(k+1, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int limit = 1; limit <= k; limit++) {
                int profit = 0;
                if(buy) {
                    int buyKaro = -prices[index] + next[0][limit];
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[index] + next[1][limit-1];
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}
int maxProfit(int k, vector<int>& prices) {

    return solve(k, prices);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                         2D Approach

//                                          Recursive
/*
int solve(int index, int operationNo, int k, vector<int>& prices) {

    // Base Case
    if(index == prices.size()) {
        return 0;
    }

    if(operationNo == 2*k) {
        return 0;
    }
    
    int profit = 0;
    if(operationNo % 2 == 0) {
        int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices);
        int skipKaro = 0 + solve(index+1, operationNo, k, prices);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int sellKaro = prices[index] + solve(index+1, operationNo+1, k, prices);
        int skipKaro = 0 + solve(index+1, operationNo, k, prices);
        profit = max(sellKaro, skipKaro); 
    }
    return profit;
}
int maxProfit(int k, vector<int>& prices) {

    return solve(0, 0, k, prices);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>>& dp) {

    // Base Case
    if(index == prices.size()) {
        return 0;
    }

    if(operationNo == 2*k) {
        return 0;
    }

    if(dp[index][operationNo] != -1) {
        return dp[index][operationNo];
    }
    
    int profit = 0;
    if(operationNo % 2 == 0) {
        int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices, dp);
        int skipKaro = 0 + solve(index+1, operationNo, k, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int sellKaro = prices[index] + solve(index+1, operationNo+1, k, prices, dp);
        int skipKaro = 0 + solve(index+1, operationNo, k, prices, dp);
        profit = max(sellKaro, skipKaro); 
    }
    dp[index][operationNo] = profit;
    return dp[index][operationNo];
}
int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
    return solve(0, 0, k, prices, dp);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int solve(int k, vector<int>& prices) {

    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k + 1, 0));

    for(int index = n-1; index >= 0; index--) { 
        for(int operationNo = 2*k-1; operationNo >= 0; operationNo--){
            int profit = 0;
            if(operationNo % 2 == 0) {
                int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, skipKaro);
            }
            else {
                int sellKaro = prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(sellKaro, skipKaro); 
            }
            dp[index][operationNo] = profit;
        }
    }
    return dp[0][0];
}
int maxProfit(int k, vector<int>& prices) {

    return solve(k, prices);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/
//                                     Space-Optimised
/*
int solve(int k, vector<int>& prices) {

    int n = prices.size();

    vector<int> curr(2*k + 1, 0);
    vector<int> next(2*k + 1, 0);

    for(int index = n-1; index >= 0; index--) { 
        for(int operationNo = 2*k-1; operationNo >= 0; operationNo--){
            int profit = 0;
            if(operationNo % 2 == 0) {
                int buyKaro = -prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(buyKaro, skipKaro);
            }
            else {
                int sellKaro = prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(sellKaro, skipKaro); 
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}
int maxProfit(int k, vector<int>& prices) {

    return solve(k, prices);
}
int main() {

    vector<int> prices = {3, 2, 6, 5, 0, 3}; 
    int k = 2;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}
*/