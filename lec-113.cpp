#include <iostream>
#include <vector>
using namespace std;

//                                          Recursive
/*
int solve(int n, vector<int>& days, vector<int>& costs, int index) {

    // Base Case
    if(index >= n) {
        return 0;
    }

    // 1 day pass
    int option1 = costs[0] + solve(n, days, costs, index+1);

    int i;
    // 7 days pass
    for(i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = costs[1] + solve(n, days, costs, i);

    // 30 days pass 
    for(i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = costs[2] + solve(n, days, costs, i);

    return min(option1, min(option2, option3));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {

    int n = days.size();
    return solve(n, days, costs, 0);
}
int main() {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};    

    int result = mincostTickets(days, costs);
    cout << "Minimum cost for tickets: " << result << endl;

    return 0;
}
*/
//                                         Top-Down
/*
int solve(int n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {

    // Base Case
    if(index >= n) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    // 1 day pass
    int option1 = costs[0] + solve(n, days, costs, index+1, dp);

    int i;
    // 7 days pass
    for(i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = costs[1] + solve(n, days, costs, i, dp);

    // 30 days pass 
    for(i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = costs[2] + solve(n, days, costs, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}
int mincostTickets(vector<int>& days, vector<int>& costs) {

    int n = days.size();
    vector<int> dp(n+1, -1);

    return solve(n, days, costs, 0, dp);
}
int main() {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};    

    int result = mincostTickets(days, costs);
    cout << "Minimum cost for tickets: " << result << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int  solve(int n, vector<int>& days, vector<int>& costs) {

    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k = n-1; k >= 0; k--) {
        //1 day pass
        int option1 = costs[0] + dp[k+1];

        int i;
        // 7 days pass
        for(i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = costs[1] + dp[i];

        // 30 days pass 
        for(i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
int mincostTickets(vector<int>& days, vector<int>& costs) {

    int n = days.size();
    return solve(n, days, costs);
}
int main() {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};    

    int result = mincostTickets(days, costs);
    cout << "Minimum cost for tickets: " << result << endl;

    return 0;
}
*/
