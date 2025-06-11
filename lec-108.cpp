#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

//                                   Count derangements

//                                       Recursive
/*
int solve(int n) {
    
    // Base Case
    if(n == 1) {
      return 0;
    }

    if(n == 2) {
      return 1;
    }

    int ans = (((n-1) % MOD) * ((solve(n-1) % MOD) + (solve(n-2) % MOD)) % MOD);
    return ans;
}
long long int countDerangements(int n) {

    return solve(n);
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Result
    cout << "Number of derangements for " << n << " is " << countDerangements(n) << endl;

    return 0;
}
*/
//                                       Top-Down
/*
long long int solve(int n, vector<long long int>& dp) {
    
    // Base Case
    if(n == 1) {
      return 0;
    }
    if(n == 2) {
      return 1;
    }

    if(dp[n] != -1) {
      return dp[n];
    }

    dp[n] = (((n-1) % MOD) * ((solve(n-1, dp) % MOD) + (solve(n-2, dp) % MOD)) % MOD);
    return dp[n];
}
long long int countDerangements(int n) {

    vector<long long int> dp(n+1, -1);
    return solve(n, dp);
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Result
    cout << "Number of derangements for " << n << " is " << countDerangements(n) << endl;

    return 0;
}
*/
//                                   Bottom-Up
/*
long long int solve(int n) {

    vector<long long int> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++) {
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    
    return solve(n);
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Result
    cout << "Number of derangements for " << n << " is " << countDerangements(n) << endl;

    return 0;
}
*/
//                                     Space-Optimised
/*
long long int solve(int n) {

    if (n == 1) {
        return 0;
    }

    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<=n; i++) {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n) {

    return solve(n);
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Result
    cout << "Number of derangements for " << n << " is " << countDerangements(n) << endl;

    return 0;
}
/**/