#include <iostream>
#include <vector>
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