#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//                                      Fibonacci Number

//                                         Recursive
/*
int fib(int n) {

    if(n <= 1) {
        return n;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
*/
//                                         Top-Down
/*
int fibo(int n, vector<int>& dp) {

    // Base Case
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // Step 2
    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}
int fib(int n) {

    vector<int> dp(n+1);
    for(int i=0; i<=n; i++) {
        dp[i] = -1;
    }
    return fibo(n, dp);
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
*/
//                                          Bottom-Up
/*
int fib(int n) {

    if(n==0) {
        return 0;
    }
    // Step 1
    vector<int> dp(n+1);

    // Step 2
    dp[1] = 1;
    dp[0] = 0;

    // Step 3
    for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
*/
//                                     Space-Optimised
/*
int fib(int n) {

    if(n==0) {
        return n;
    }

    // Step 2
    int prev1 = 1;
    int prev2 = 0;
    for(int i=2; i<=n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
    }
    return prev1;
}
int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
*/






int solve(vector<int>& arr, int diff, int index, int lastval) {

    if(index >= arr.size()) {
        return 0;
    }

    // Skip
    int skip = 0;
    if(arr[index] == lastval) {
        skip = solve(arr, diff, index+1, lastval); 
    }
    // Include
    int include = 0;
    if(lastval + diff == arr[index]) {
        include = 1+solve(arr, diff, index+1, arr[index]);
    }
    return max(skip, include);
}
int longestSubsequence(vector<int>& arr, int difference) {

    return solve(arr, difference, 0, arr[0]);
}
int main() {

    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    vector<int> arr2 = {1,2,3,4,5};
    int difference = 1;
    cout << longestSubsequence(arr2, difference) << endl;  // Output: 4
    return 0;
}