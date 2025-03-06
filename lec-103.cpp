#include <iostream>
#include <vector>
using namespace std;

//                                    Climbing Stairs

//                                       Recursive
/*
int solve(int n, int i) {

    // Base Case
    if(i == n) {
        return 1;
    }
    if(i > n) {
        return 0;
    }
    return (solve(n, i+1) + solve(n, i+2));
} 
int climbStairs(int n) {
    
    int ans = solve(n, 0);
    return ans;
}
int main() {

    int n;
    cout << "Enter number of stairs" << endl;
    cin >> n;

    cout << climbStairs(n) << endl;

    return 0;
}
*/
//                                        Top-Down
/*
int solve(int n, int i, vector<int>& dp) {

    // Base Case
    if(i == n) {
        return 1;
    }
    if(i > n) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    dp[i] = solve(n, i+1, dp) + solve(n, i+2, dp);
    return dp[i];
}
int climbStairs(int n) {

    vector<int> dp(n+1, -1);
    return solve(n, 0, dp);
}
int main() {

    int n;
    cout << "Enter number of stairs" << endl;
    cin >> n;

    cout << climbStairs(n) << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(int n) {

    if(n==0) {
        return 1;
    }
    // Step 1
    vector<int> dp(n+1);

    // Step 2
    dp[1] = 1;
    dp[0] = 1;

    // Step 3
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int climbStairs(int n) {

    return solve(n);
}
int main() {

    int n;
    cout << "Enter number of stairs" << endl;
    cin >> n;

    cout << climbStairs(n) << endl;

    return 0;
}
*/
//                                  Space-Optimised
/*
int solve(int n) {

    if(n == 0) {
        return 1;
    }

    // Step 2
    int prev1 = 1;
    int prev2 = 1;
    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int climbStairs(int n) {
  
    return solve(n);
}
int main() {

  int n;
  cout << "Enter number of stairs" << endl;
  cin >> n;

  cout << climbStairs(n) << endl;

  return 0;
}
*/

//                                  Min Cost Climbing Stairs

//                                         Recursive
/*
int solve(vector<int> &cost, int n) {

    // Base Case
    if(n == 0) {
        return cost[0];
    }
    if(n == 1){ 
        return cost[1];
    }
    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}
int minCostClimbingStairs(vector<int>& cost) {
  
    int n = cost.size();
    int ans = min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}
int main() {

    vector<int> cost = {10, 15, 20}; 

    int result = minCostClimbingStairs(cost);  
    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
*/
//                                      Top-Down
/*
int solve(vector<int>& cost, int n, vector<int>& dp){

    if(n == 0) {
        return cost[0];
    }
    if(n == 1) {
        return cost[1];
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return dp[n];
}
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    vector<int> dp(n+1, -1);
    return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
}
int main() {

    vector<int> cost = {10, 15, 20}; 

    int result = minCostClimbingStairs(cost);  
    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
*/
//                                     Bottom-Up
/*
int solve1(vector<int>& cost, int n) {

    // Step 1: Creation of dp array
    vector<int> dp(n+1);
    
    // Step 2: Base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Step 3
    for(int i=2; i<n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    return solve1(cost, n);
}
int main() {

    vector<int> cost = {10, 15, 20}; 

    int result = minCostClimbingStairs(cost);  
    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
*/
//                                     Space-Optimised
/*
int solve(vector<int>& cost, int n) {

    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i=2; i<n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();
    return solve(cost, n);
}
int main() {

    vector<int> cost = {10, 15, 20}; 

    int result = minCostClimbingStairs(cost);  
    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
*/