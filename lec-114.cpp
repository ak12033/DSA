#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//                              Minimum Cost For Tickets
/*
int mincostTickets(vector<int>& days, vector<int>& costs) {
        
    queue <pair<int, int>> week;
    queue <pair<int, int>> month;

    int ans = 0;
    for(int day : days) {
        while(!month.empty() && month.front().first + 30 <= day) {
            month.pop();
        }
        while(!week.empty() && week.front().first + 7 <= day) {
            week.pop();
        }

        week.push({day, ans + costs[1]});
        month.push({day, ans + costs[2]});
        
        ans = min(ans + costs[0], min(week.front().second, month.front().second));
    }
    return ans;
}
int main() {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};    

    int result = mincostTickets(days, costs);
    cout << "Minimum cost for tickets: " << result << endl;

    return 0;
}
*/