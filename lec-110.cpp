#include <iostream> 
#include <vector>
using namespace std;

//                                    0/1 Knapsack

//                                      Recursive
/*
int solve(vector<int>& weight, vector<int>& value, int index, int capacity) {

    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if(index == 0) {
		if(weight[0] <= capacity) {
			return value[0];
		}
      	else {
        	return 0;
      	}
    }

    // Include - Check if the current item can be included without exceeding the knapsack's capacity
	int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity-weight[index]);
    }
    // Exclude
	int exclude = solve(weight, value, index-1, capacity);

    // Calculate the maximum value by either excluding the current item or including it
	int ans = max(exclude, include);
    return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    return solve(weight, value, n-1, maxWeight);
}
int main() {

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {20, 50, 60, 100};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value that can be obtained: " << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
*/
//                                      Top-Down
/*
int solve(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>>& dp) {

    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if(index == 0) {
		if(weight[0] <= capacity) {
			return value[0];
		}
      	else {
        	return 0;
      	}
    }

    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    // Include - Check if the current item can be included without exceeding the knapsack's capacity
	int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity-weight[index], dp);
    }
    // Exclude
	int exclude = solve(weight, value, index-1, capacity, dp);

    // Calculate the maximum value by either excluding the current item or including it
	dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n-1, maxWeight, dp);
}
int main() {

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {20, 50, 60, 100};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value that can be obtained: " << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
*/
//                                      Bottom-Up
/*
int solve(vector<int>& weight, vector<int>& value, int n, int capacity) {

	// Step1:
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));	

    // Step2: Analyze Base Case
    for (int w = 0; w <= capacity; w++) {
		if(weight[0] <= w) {
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
    }

    for(int index = 1; index < n; index++) {
        for (int w = 0; w <= capacity; w++) {
            // Include
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + dp[index-1][w-weight[index]];
            }
            // Exclude
			int exclude = dp[index-1][w];
            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    return solve(weight, value, n, maxWeight);
}
int main() {

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {20, 50, 60, 100};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value that can be obtained: " << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
*/
//                                    Space-Optimised
/*
int solve(vector<int>& weight, vector<int>& value, int n, int capacity) {

	// Step1:
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);	

    // Step2: Analyze Base Case
    for(int w = 0; w <= capacity; w++) {
		if(weight[0] <= w) {
			prev[w] = value[0];
		}
		else{
			prev[w] = 0;
		}
    }

    for(int index = 1; index < n; index++) {
        for (int w = 0; w <= capacity; w++) {
            // Include
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + prev[w-weight[index]];
            }
            // Exclude
			int exclude = prev[w];
            curr[w] = max(exclude, include);
        }
        prev = curr;
    }
    return prev[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    return solve(weight, value, n, maxWeight);
}
int main() {

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {20, 50, 60, 100};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value that can be obtained: " << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
*/
//                            More Optimised (using one array)
/*
int solve(vector<int>& weight, vector<int>& value, int n, int capacity) {

	// Step1:
	vector<int> curr(capacity+1, 0);	

    // Step2: Analyze Base Case
    for(int w = 0; w <= capacity; w++) {
		if(weight[0] <= w) {
			curr[w] = value[0];
		}
		else{
			curr[w] = 0;
		}
    }

    for(int index = 1; index < n; index++) {
        for (int w = capacity; w >= 0; w--) {
            // Include
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + curr[w-weight[index]];
            }
            // Exclude
			int exclude = curr[w];
            curr[w] = max(exclude, include);
        }
    }
    return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    return solve(weight, value, n, maxWeight);
}
int main() {

    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {20, 50, 60, 100};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value that can be obtained: " << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
*/