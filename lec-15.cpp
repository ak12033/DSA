#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                               Book Allocation Problem
/*
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {

    int s = 0;
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else if(m>n){
            return -1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    // Define the array of books (number of pages)
    vector<int> arr = {10, 20, 30, 40}; 

    // Number of books
    int n = arr.size();

    // Number of students
    int m = 2;

    // Calling the findPages function to get the answer
    int result = findPages(arr, n, m);

    // Output the result
    cout << "The minimum number of pages a student can have is: " << result << endl;

    return 0;
}
*/

//                               Painter's Partition Problem
/*
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int paintersCount = 1;
    int boardSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(boardSum + arr[i] <= mid) {
            boardSum += arr[i];
        }
        else{
            paintersCount++;
            if(paintersCount > m || arr[i] > mid ) {
            return false;
            }
            boardSum = arr[i];
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k){

    int s = 0;
    int sum = 0;
    for(int i = 0; i<boards.size(); i++) {
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(boards,boards.size(),k,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    // Input: number of boards and number of painters.
    int n, m;
    cout << "Enter the number of boards: ";
    cin >> n;
    cout << "Enter the number of painters: ";
    cin >> m;

    // Input: the length of each board.
    vector<int> boards(n);
    cout << "Enter the lengths of the boards: ";
    for(int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    // Find and output the largest minimum distance that can be assigned to any painter.
    int result = findLargestMinDistance(boards, m);
    cout << "The largest minimum distance each painter can work is: " << result << endl;

    return 0;
}
*/

//                                      Aggressive cows
/*
bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i=1; i<n; i++ ){
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(), stalls.end());
   	int s = 0;
    int e=stalls[n-1];
    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
int main() {

    int n, k;
    cout << "Enter number of stalls and number of cows: ";
    cin >> n >> k; // Read number of stalls and cows
    vector<int> stalls(n);
    
    cout << "Enter the positions of the stalls: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i]; // Read the positions of stalls
    }
    
    int result = solve(n, k, stalls); // Get the result
    cout << "The largest minimum distance is: " << result << endl; // Output the result

    return 0;
}
*/