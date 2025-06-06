#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
#define MAX 719

//                                 Celebrity Problem
/*
bool knows(vector<vector<int>>& M, int a, int b, int n) {

    if(M[a][b] == 1)
        return true;
    else
        return false;
}
int celebrity(vector<vector<int> >& M, int n) {

    stack<int> s;

    // Step 1 : Push All Elements in a Stack
    for(int i=0; i<n; i++) {
        s.push(i);
    }   
    // Step 2 : Get 2 Elements and Compare them
    while(s.size() > 1) {    
        int a = s.top();
        s.pop();
            
        int b = s.top();
        s.pop();
            
        if(knows(M,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ans = s.top();
    // Step 3 : Single Element in Stack is Potential Celebrity
    // So Verify it
        
    int zeroCount = 0;
    for(int i=0; i<n; i++) {
        if(M[ans][i] == 0)
            zeroCount++;
    }
    // All Zeroes
    if(zeroCount != n){
        return -1;
    }   
    // Column Check
    int oneCount = 0;
    for(int i=0; i<n; i++) {
        if(M[i][ans] == 1)
            oneCount++;
    }    
    if(oneCount != n-1){
        return -1;
    }
    return ans;    
}
int main() {

        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> M[i][j];
            }
        }
        cout << celebrity(M, n) << endl;

        return 0;
}
*/

//                                         Maximal Rectangle

//                                             Approach 1
/*
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    int area = INT_MIN;
    for(int i=0; i<n; i++){ 
        int left = i;
        int right = i;
        while(left > 0 && heights[left-1] >= heights[i]){
            left--;
        }
        while(right < n-1 && heights[right+1] >= heights[i]){
            right++;
        }
        int b = right - left + 1;
        int newArea = heights[i] * b;
        area = max(area, newArea);
    }
    return area;
}
int maximalRectangle(vector<vector<char>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m, 0);

    int area = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == '1'){
                heights[j]++;
            }
            else {
                heights[j] = 0;
            }
        }
        area = max(area, largestRectangleArea(heights));
    }
    return area;
}
int main() {
    
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = maximalRectangle(matrix);
    cout << "Maximal rectangle area: " << result << endl;
    
    return 0;
}
*/
//                                             Approach 2
/*
vector<int> nextSmallerElement(int *arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0 ; i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}    
vector<int> prevSmallerElement(int* arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}    
int largestRectangleArea(int* heights, int n) {
        
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
int maxArea(int M[MAX][MAX], int n, int m) {
        
    // Compute Area for First Row
    int area = largestRectangleArea(M[0], m);
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<m; j++) {
            // Row Udpate: By Adding Previous Row's Value
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
        }    
        // Entire Row is Updated Now
        area = max(area, largestRectangleArea(M[i], m));        
    }
    return area;
}
int main() {

    int M[MAX][MAX];
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter matrix elements (0 or 1):"<< endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }
    cout << "Maximum rectangular area of 1's: " << maxArea(M, n, m) << endl;

    return 0;
}
*/