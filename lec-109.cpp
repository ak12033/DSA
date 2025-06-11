#include <iostream> 
#include <vector>
using namespace std;

//                                   Painting the Fence

//                                       Recursive
/*
int solve(int n, int k) {

    // Base Case
    if(n == 1) {
        return k;
    }

    if(n == 2) {
        return k + k*(k-1);
    }

    int ans = solve(n-2, k) * (k-1) + solve(n-1, k) * (k-1);
    return ans;
}
int countWays(int n, int k) {
        
    return solve(n, k);
}
int main() {

    int n, k;
    cin >> n >> k;

    cout << countWays(n, k) << endl;
    return 0;
}
*/
//                                         Top-Down
/*
int solve(int n, int k, vector<int>& dp) {

    // Base Case
    if(n == 1) {
        return k;
    }
    
    if(n == 2) {
        return k + k*(k-1);
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = solve(n-2, k, dp) * (k-1) + solve(n-1, k, dp) * (k-1);
    return dp[n];
}
int countWays(int n, int k) {
        
    vector<int> dp(n+1,-1);
    return solve(n, k, dp);
}
int main() {

    int n, k;
    cin >> n >> k;

    cout << countWays(n, k) << endl;
    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(int n, int k) {

    vector<int> dp(n+1, 0);

    dp[1] = k;
    dp[2] = k + k*(k-1);

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-2] * (k-1) + dp[i-1] * (k-1);
    }
    return dp[n];
}
int countWays(int n, int k) {
        
    return solve(n, k);
}
int main() {

    int n, k;
    cin >> n >> k;

    cout << countWays(n, k) << endl;
    return 0;
}
*/
//                                       Space-Optimised
/*
int solve(int n, int k) {

    if(n == 1) {
        return k;
    }

    int prev2 = k;
    int prev1 = k + k*(k-1);

    for(int i=3; i<=n; i++) {
        int ans = prev2 * (k-1) + prev1 * (k-1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int countWays(int n, int k) {
        
    return solve(n, k);
}
int main() {

    int n, k;
    cin >> n >> k;

    cout << countWays(n, k) << endl;
    return 0;
}
*/