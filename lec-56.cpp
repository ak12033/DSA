#include<iostream>
#include<stack>
#include <vector>
#include<limits.h>
using namespace std;

//                                    Next Smaller Element

//                                          Approach 1
/*
vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                          Approach 2
/*
vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        arr[i] = s.top();
        s.push(curr);
    }
    return arr;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                      Approach 3
/*
vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    
    for(int i = n-1; i >= 0; i--){
        int curr= arr[i];
        if(s.top() < curr){
            arr[i] = s.top();
            s.push(curr);  
        }
        else{
            s.pop();
            i++;
        }
    }
    return arr;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                 Previous Smaller Element
    
//                                         Approach 1
/*
vector<int> prevSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0; i<n ; i++) {
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();

    vector<int> result = prevSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = prevSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = prevSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                         Approach 2
/*
vector<int> prevSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0; i<n ; i++) {
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        // Ans is Stack ka Top
        arr[i] = s.top();
        s.push(curr);
    }
    return arr;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();

    vector<int> result = prevSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = prevSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = prevSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                    Approach 3
/*
vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    
    for(int i = 0; i < n; i++){
        int curr= arr[i];    
        if(s.top() < curr){
            arr[i]=s.top();
            s.push(curr);  
        }
        else{
            s.pop();
            i--;
        }
    }
    return arr;
}
int main(){

    vector<int> arr1 = {2, 1, 4, 3};
    int n = arr1.size();
    vector<int> result = nextSmallerElement(arr1, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = { 1, 2, 3, 4, 5};
    n = arr2.size();
    result = nextSmallerElement(arr2, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = { 4,3,2,1};
    n = arr3.size();
    result = nextSmallerElement(arr3, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                   Largest Rectangle in Histogram

//                                             Approach 1
/*
int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    int area = INT_MIN;
    for (int i=0; i<n; i++) {
        int left = i;
        int right = i;
        while(left > 0 && heights[left - 1] >= heights[i]) {
            left--;
        }
        while(right < n-1 && heights[right + 1] >= heights[i]) {
            right++;
        }
        int b = right - left + 1;
        int newArea = heights[i] * b;
        area = max(area, newArea);
    }
    return area;
}
int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;

    return 0;
}
*/
//                                             Approach 2
/*
vector<int> nextSmallerElement(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
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
vector<int> prevSmallerElement(vector<int> arr, int n) {

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
int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;

    return 0;
}
*/