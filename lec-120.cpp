#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                          Maximum Height by Stacking Cuboids 

//                                       Recursive
/*
bool check(vector<int> base, vector<int> newBox) {

    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]) {
        return true;
    }
    else {
        return false;
    }
}
int solve(int n, vector<vector<int>>& cuboids, int curr, int prev) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    // Include 
    int take = 0;
    if(prev == -1 || check(cuboids[curr], cuboids[prev])) {
        take = cuboids[curr][2] + solve(n, cuboids, curr+1, curr);
    }
    // Exclude
    int notTake = solve(n, cuboids, curr+1, prev);

    return max(take, notTake);
}
int maxHeight(vector<vector<int>>& cuboids) {

    // Step 1: Sort all dimensions of every cuboid
    for(auto &it : cuboids) {
        sort(it.begin(), it.end());
    }

    // Step 2: Sort all cuboids on the basis of w or l
    sort(cuboids.begin(),cuboids.end());

    return solve(cuboids.size(), cuboids, 0, -1);
}
int main() {

    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << "Maximum stackable height: " << maxHeight(cuboids) << endl;

    return 0;
}
*/
//                                       Top-Down
/*
bool check(vector<int> base, vector<int> newBox) {

    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]) {
        return true;
    }
    else {
        return false;
    }
}
int solve(int n, vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp) {
    
    // Base Case
    if(curr == n) {
        return 0;
    }

    if(dp[curr][prev+1] != -1) {
        return dp[curr][prev+1];
    }

    // Include 
    int take = 0;
    if(prev == -1 || check(cuboids[curr], cuboids[prev])) {
        take = cuboids[curr][2] + solve(n, cuboids, curr+1, curr, dp);
    }
    // Exclude
    int notTake = solve(n, cuboids, curr+1, prev, dp);

    dp[curr][prev+1] = max(take, notTake);
    return dp[curr][prev+1];
}
int maxHeight(vector<vector<int>>& cuboids) {

    // Step 1: Sort all dimensions of every cuboid
    for(auto &it : cuboids) {
        sort(it.begin(), it.end());
    }

    // Step 2: Sort all cuboids on the basis of w or l
    sort(cuboids.begin(),cuboids.end());

    int n = cuboids.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return solve(n, cuboids, 0, -1, dp);
}
int main() {

    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << "Maximum stackable height: " << maxHeight(cuboids) << endl;

    return 0;
}
*/
//                                       Bottom-Up
/*
bool check(vector<int> base, vector<int> newBox) {

    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]) {
        return true;
    }
    else {
        return false;
    }
}
int solve(int n, vector<vector<int>>& cuboids) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || check(cuboids[curr], cuboids[prev])) {
                take = cuboids[curr][2] + dp[curr+1][curr+1];
            }
            // Exclude
            int notTake = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
int maxHeight(vector<vector<int>>& cuboids) {

    // Step 1: Sort all dimensions of every cuboid
    for(auto &it : cuboids) {
        sort(it.begin(), it.end());
    }

    // Step 2: Sort all cuboids on the basis of w or l
    sort(cuboids.begin(),cuboids.end());

    return solve(cuboids.size(), cuboids);
}
int main() {

    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << "Maximum stackable height: " << maxHeight(cuboids) << endl;

    return 0;
}
*/
//                                     Space-Optimised
/*
bool check(vector<int> base, vector<int> newBox) {

    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]) {
        return true;
    }
    else {
        return false;
    }
}
int solve(int n, vector<vector<int>>& cuboids) {

    vector<int> currRow(n+1, 0) ;
    vector<int> nextRow(n+1, 0);

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr - 1; prev >= -1; prev--) {
            // Include
            int take = 0;
            if(prev == -1  || check(cuboids[curr], cuboids[prev])) {
                take = cuboids[curr][2] + nextRow[curr+1];
            }
            // Exclude
            int notTake = 0 + nextRow[prev+1];
            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
int maxHeight(vector<vector<int>>& cuboids) {

    // Step 1: Sort all dimensions of every cuboid
    for(auto &it : cuboids) {
        sort(it.begin(), it.end());
    }

    // Step 2: Sort all cuboids on the basis of w or l
    sort(cuboids.begin(),cuboids.end());

    return solve(cuboids.size(), cuboids);
}
int main() {

    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << "Maximum stackable height: " << maxHeight(cuboids) << endl;

    return 0;
}
*/