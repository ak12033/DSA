#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <limits.h>
using namespace std;

//                              Minimum Cost Tree From Leaf Values

//                                          Recursive
/*
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right) {

    // Base Case
    // Leaf node
    if(left == right) {
        return 0;
    }

    int ans = INT_MAX;
    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
    }
    return ans;
}
int mctFromLeafValues(vector<int>& arr) { 

    map<pair<int, int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi, 0, arr.size()-1);
}
int main() {

    vector<int> arr = {6, 2, 4};

    int result = mctFromLeafValues(arr);
    cout << "Minimum Cost to Merge Leaf Values: " << result << endl;

    return 0;
}
*/
//                                        Top-Down
/*
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {

    // Base Case
    // Leaf node
    if(left == right) {
        return 0;
    }

    if(dp[left][right] != -1) {
        return dp[left][right];
    }

    int ans = INT_MAX;
    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}
int mctFromLeafValues(vector<int>& arr) { 

    map<pair<int, int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return solve(arr, maxi, 0, arr.size()-1, dp);
}
int main() {

    vector<int> arr = {6, 2, 4};

    int result = mctFromLeafValues(arr);
    cout << "Minimum Cost to Merge Leaf Values: " << result << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {

    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int left = n-1; left >= 0; left--) {
        for(int right = left+1; right < n; right++) {
            int ans = INT_MAX;
            for(int i = left; i < right; i++) {
                ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
            }
            dp[left][right] = ans;
        }
    }
    return dp[0][n-1];
}
int mctFromLeafValues(vector<int>& arr) { 

    map<pair<int, int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi);
}
int main() {

    vector<int> arr = {6, 2, 4};

    int result = mctFromLeafValues(arr);
    cout << "Minimum Cost to Merge Leaf Values: " << result << endl;

    return 0;
}
*/
//                            Optimised Approach using Stack
/*
int mctFromLeafValues(vector<int>& arr) {

    stack<int> st;

    int sum = 0;
    int t;
    for(int a : arr) {
        while(!st.empty() && a > st.top()) {
            t = st.top();
            st.pop();
            if(st.empty()) {
                sum += t * a;
            }
            else {
                sum += t * min(st.top(), a);
            }
        }
        st.push(a);
    }
    while(!st.empty()) {
        t = st.top();
        st.pop();
        if (!st.empty()) {
            sum += st.top() * t;
        }
    }
    return sum;
}
int main() {

    vector<int> arr = {6, 2, 4};

    int result = mctFromLeafValues(arr);
    cout << "Minimum Cost to Merge Leaf Values: " << result << endl;

    return 0;
}
*/