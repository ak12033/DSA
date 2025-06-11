#include <iostream>
#include <vector>
using namespace std;

//                                  Unique Binary Search Trees

//                                          Recursive
/*
int solve(int n) {

    // Base Case
    if (n <= 1) {
        return 1;
    }

    int ans = 0;
    // Think i as root node
    for (int i=1; i<=n; i++) {
        ans += solve(i-1) * solve(n-i);
    }
    return ans;
}
int numTrees(int n) {

    return solve(n);
}
int main() {

    int n = 5;
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(int n, vector<int>& dp) {

    // Base Case
    if (n <= 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;
    // Think i as root node
    for (int i=1; i<=n; i++) {
        ans += solve(i-1, dp) * solve(n-i, dp);
    }
    dp[n] = ans;
    return dp[n];
}
int numTrees(int n) {

    vector<int> dp(n+1, -1);
    return solve(n, dp);
}
int main() {

    int n = 5;
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n) << endl;

    return 0;
}
*/
//                                         Bottom-Up
/*
int solve(int n) {

    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    // i -> Number of nodes
    for(int i=2; i<=n; i++) {
        // j -> Root node
        for(int j=1; j<=i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}
int numTrees(int n) {

    return solve(n);
}
int main() {

    int n = 5;
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n) << endl;

    return 0;
}
*/
//                               Catalan Number Approach
/*
int numTrees(int n) {

    // Base case
    if(n <= 1) {
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        res += numTrees(i) * numTrees(n-i-1);
    }
    return res;
}
int main() {

    int n = 5;
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n) << endl;

    return 0;
}
*/