#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

//                                      Maximal Rectangle
/*
vector<int> nextSmallerElement(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        // Ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        // Ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();
    
    vector<int> next(n);
    next = nextSmallerElement(heights, n);
        
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        int l = heights[i];
        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}
int maximalRectangle(vector<vector<char>>& matrix) {

    vector<int> dp(matrix[0].size(), 0); 

    int maxi = INT_MIN;
    for(int i=0; i < matrix.size(); i++) {
        for(int j=0; j< dp.size(); j++) {
            if(matrix[i][j] == '1') {
                dp[j]++;
            }
            else {
                dp[j] = 0;
            }
        }
        maxi = max(maxi, largestRectangleArea(dp));
    }
    return maxi;
}
int main() {

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;

    return 0;
}
*/