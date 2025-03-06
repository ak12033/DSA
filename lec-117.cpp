#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//                                    Minimum Sideway Jumps

//                                          Recursive
/*
int solve(vector<int>& obstacles, int currlane, int currpos) {

    // Base Case
    int n = obstacles.size()-1;
    if(currpos == n) {
        return 0;
    }

    if(obstacles[currpos+1] != currlane) {
        return solve(obstacles, currlane, currpos+1);
    }
    else {
        int ans = INT_MAX;
        for(int i=1; i<=3; i++) {
            if(currlane != i && obstacles[currpos] != i) {
                ans = min(ans, 1 + solve(obstacles, i, currpos));
            }
        }
        return ans;
    }
}
int minSideJumps(vector<int>& obstacles) {

    return solve(obstacles, 2, 0);
}
int main() {

    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << "Minimum Side Jumps: " << minSideJumps(obstacles) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp) {

    // Base Case
    int n = obstacles.size()-1;
    if(currpos == n) {
        return 0;
    }

    if(dp[currlane][currpos] != -1) {
        return dp[currlane][currpos];
    }

    if(obstacles[currpos+1] != currlane) {
        return solve(obstacles, currlane, currpos+1, dp);
    }
    else {
        int ans = INT_MAX;
        for(int i=1; i<=3; i++) {
            if(currlane != i && obstacles[currpos] != i) {
                ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}
int minSideJumps(vector<int>& obstacles){

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
    return solve(obstacles, 2, 0, dp);
}
int main() {

    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << "Minimum Side Jumps: " << minSideJumps(obstacles) << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int solve(vector<int>& obstacles) {

    int n = obstacles.size()-1;
    vector<vector<int>> dp(4,vector<int>(obstacles.size(), 1e9));

    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;

    for(int currpos = n-1; currpos >= 0; currpos--) {
        for(int currlane = 1; currlane <= 3; currlane++) {
            if(obstacles[currpos+1] != currlane) {
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }
            // Sideways Jump
            else {
                int ans = 1e9;
                for(int i=1; i<=3; i++) {
                    if(currlane != i && obstacles[currpos] != i) {
                        ans = min(ans, 1 + dp[i][currpos+1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}
int minSideJumps(vector<int>& obstacles) {

    return solve(obstacles);
}
int main() {

    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << "Minimum Side Jumps: " << minSideJumps(obstacles) << endl;

    return 0;
}
*/
//                                  Space-Optimised
/*
int solve(vector<int>& obstacles) {

    int n = obstacles.size()-1;
          
    vector<int> next(4, INT_MAX);
    vector<int> curr(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currpos = n-1; currpos >= 0; currpos--) {
        for(int currlane = 1; currlane <= 3; currlane++) {
            if(obstacles[currpos+1] != currlane) {
                curr[currlane] = next[currlane];
            }
            // Sideways Jump
            else {   
                int ans = INT_MAX;
                for(int i=1; i<=3; i++) {
                    if(currlane != i && obstacles[currpos] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}    
int minSideJumps(vector<int>& obstacles) {

    return solve(obstacles);
}
int main() {

    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << "Minimum Side Jumps: " << minSideJumps(obstacles) << endl;

    return 0;
}
*/