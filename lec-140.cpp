#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

//                                 N meetings in one room
/*
bool cmp(pair<int, int> a, pair<int, int> b) {

    return a.second < b.second;
}
int maxMeetings(vector<int>& start, vector<int>& end) {

    int n = start.size();

    vector<pair<int, int>> meets;    
    for(int i=0; i<n; i++) {
        pair<int, int> p = make_pair(start[i], end[i]);
        meets.push_back(p);
    }
        
    sort(meets.begin(), meets.end(), cmp);
        
    int cnt = 1;
    int ansEnd = meets[0].second;
    for(int i=1; i<n; i++) {
        if(meets[i].first > ansEnd) {
            cnt++;
            ansEnd = meets[i].second;
        }
    }
    return cnt;
}
int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of activities: " << maxMeetings(start, end) << endl;
    return 0;
}
*/

//                              Maximum Meetings in One Room
/*
bool cmp(vector<int> a, vector<int> b) {

    return a[1] < b[1];
}
vector<int> maxMeetings(int N, vector<int> &S,vector<int> &F) {

    vector<vector<int>> meets(N, vector<int> (3));
        
    for (int i=0; i<N; i++) {
        meets[i][0] = S[i];
        meets[i][1] = F[i];
        meets[i][2] = i+1;

    }    
    // Sort meetings by their end time
    sort(meets.begin(), meets.end(), cmp);
        
    vector<int> ans;

    ans.push_back(meets[0][2]);
    int ansEnd = meets[0][1];
    for(int i=1; i<N; i++) {
        if(meets[i][0] > ansEnd) {
            ans.push_back(meets[i][2]);
            ansEnd = meets[i][1];
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {

    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};
    int N = S.size();

    vector<int> result = maxMeetings(N, S, F);
    cout << "Meetings that can be attended: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                     Shop in Candy Store
/*
vector<int> candyStore(int candies[], int N, int K) {

    sort(candies, candies+N);
    
    int mini = 0;
    int buy = 0;
    int free = N-1; 
    while(buy <= free) {
    	mini = mini + candies[buy];
    	buy++;
    	free = free - K;
    }
    	 
    int maxi = 0;
    buy = N-1;
    free = 0;  
    while(free <= buy) {
    	maxi = maxi + candies[buy];
    	buy--;
    	free = free + K;
    }	 
    return{mini, maxi};
}
int main() {

    int candies[] = {3, 2, 1, 4};
    int N = sizeof(candies) / sizeof(candies[0]);
    int K = 2;

    vector<int> result = candyStore(candies, N, K);
    cout << "Minimum cost: " << result[0] << endl;
    cout << "Maximum cost: " << result[1] << endl;

    return 0;
}
*/

//                       Check if it is possible to survive on Island
/*
int minimumDays(int S, int N, int M) {

    if(M > N) {
        return -1;
    }

    if(S >= 7 && (N*6) < (M*7)) {
        return -1;
    }
    
    int totalFood = S*M;
    return (totalFood + N - 1) / N;
    // Or
    // if(totalFood % N == 0) {
    //     return (totalFood/N);
    // }
    // else {
    //     return ((totalFood/N) + 1);
    // }
}
int main() {

    int S = 10; 
    int N = 16; 
    int M = 2; 

    int result = minimumDays(S, N, M);
    if (result == -1) {
        cout << "Survival is not possible" << endl;
    } else {
        cout << "Minimum days needed to buy food: " << result << endl;
    }
    return 0;
}
*/

//                                      Reverse Words
/*
string reverseWords(string& s) {
        
    string ans = "";
    string temp = "";
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            reverse(temp.begin(), temp.end());
            if(!temp.empty()){
                ans = ans + temp + " ";
            }
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    if(!ans.empty() && ans.back() == ' ') {
        ans.pop_back();
    }
    return ans;
}
int main() {

    string s = "  hello   world  ";
    cout << "-" << reverseWords(s) << "-" << endl;
    
    return 0;
}
*/

//                                 Chocolate Distribution Problem
/*
int findMinDiff(vector<int>& a, int m) {
        
    sort(a.begin(), a.end());
        
    int i = 0;
    int j = m-1;

    int mini = INT_MAX;
    while(j < a.size()) {
        int diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}
int main() {

    vector<int> chocolates = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
    
    cout << "Minimum difference: " << findMinDiff(chocolates, m) << endl;

    return 0;
}
*/

//                                  Minimum Cost of ropes
/*
int minCost(vector<int>& arr) {
        
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<arr.size(); i++) {
        pq.push(arr[i]);
    }
        
    int cost = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
            
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main() {

    vector<int> arr = {4, 3, 2, 6};
    cout << "Minimum Cost: " << minCost(arr) << endl;

    return 0;
}
*/

//                                    Huffman Encoding
/*
class Node {

    public:
        int data;
        char ch;
        Node* left;
        Node* right;
        
        Node(int d, char c) {
            ch = c;
            data = d;
            left = NULL;
            right = NULL;
        }
};
class cmp {

    public:
        bool operator()(Node* a, Node* b) {

            return a->data > b->data;
        }
};
void traverse(Node* root, vector<string>& ans, string temp) {

	if(root->left == NULL && root->right == NULL) {
	    ans.push_back(string(1, root->ch) + " : " + temp);
        return;
	}
	        
    traverse(root->left, ans, temp + '0');
    traverse(root->right, ans, temp + '1');
}
vector<string> huffmanCodes(string S, vector<int> f, int N) {

	priority_queue <Node*, vector<Node*>, cmp> pq;
    
    // Create a node for each character and add to the priority queue
    for (int i=0; i<N; i++) {
        Node* temp = new Node(f[i], S[i]);
        pq.push(temp);
    }
            
    // Iterate until the heap contains only one node
    while(pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
                
        // Create a new internal node with the sum of frequencies
        Node* newNode = new Node(left->data + right->data, '\0');
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    Node* root = pq.top();
    vector<string> ans;
    string temp = "";
    traverse(root, ans, temp);

    return ans;
}
int main() {

    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    
    vector<string> codes = huffmanCodes(S, f, S.length());
    cout << "Huffman Codes:" << endl;
    for(int i=0; i < codes.size(); i++) {
        cout << codes[i] << endl;
    }
    return 0;
}
*/

//                                 Fractional Knapsack
/*
bool cmp(vector<double>& a, vector<double>& b) {

    return a[0] > b[0];
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

    vector<vector<double>> v(val.size(), vector<double>(3));
    
    for(int i=0; i<val.size(); i++) {
        v[i][0] = (1.0*val[i])/wt[i];
        v[i][1] = val[i];
        v[i][2] = wt[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    
    double totalvalue = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i][2] > capacity) {
            totalvalue += capacity * v[i][0];
            break;
        } 
        else {
            totalvalue += v[i][1];
            capacity -= v[i][2];
        }
    }
    return totalvalue;
}
int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    double maxProfit = fractionalKnapsack(val, wt, capacity);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
*/

//                                  Job Sequencing Problem
/*
bool cmp(vector<int>& a, vector<int>& b) {
        
    return a[2] > b[2];
}
vector<int> JobSequencing(vector<int>& id, vector<int>& deadline, vector<int>& profit) {
        
    int n = id.size();
        
    vector<vector<int>> job(n, vector<int>(3));    
    for(int i=0; i<n; i++) {
        job[i][0] = id[i];
        job[i][1] = deadline[i];
        job[i][2] = profit[i];
    }
        
    sort(job.begin(), job.end(), cmp);
        
    int maxiDeadline = INT_MIN;
    for(int i=0; i<n; i++) {
        maxiDeadline = max(maxiDeadline, deadline[i]);
    }
        
    vector<int> schedule(maxiDeadline+1, -1);

    int count = 0; 
    int maxProfit = 0;
    for (int i=0; i<n; i++) {
        int currProfit = job[i][2];
        int currJobID = job[i][0];
        int currDead = job[i][1];
        for(int k = currDead; k>0; k--) {
            if (schedule[k] == -1) {
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
    }
    return {count, maxProfit};
}
int main() {

    vector<int> id = {1, 2, 3, 4, 5};
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};

    vector<int> result = JobSequencing(id, deadline, profit);
    cout << "Total Jobs Done: " << result[0] << endl;
    cout << "Maximum Profit: " << result[1] << endl;

    return 0;
}
*/

//                                     Minimum number of Coins
/*
vector<int> minPartition(int N) {
        
    vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    vector<int> result;
    for(int coin : denominations) {
        while(N >= coin) {
            result.push_back(coin);
            N -= coin;
        }
    }
    return result;
}
int main() {

    int N = 43;

    vector<int> result = minPartition(N);
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                     Minimum Platforms
/*
int findPlatform(vector<int>& arr, vector<int>& dep) {
        
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
        
    int ans = 0, count = 0;
    int i = 0, j = 0;
    while(i < arr.size()) {
        if(arr[i] <= dep[j]) {
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        ans = max(ans, count); //updating the value with the current maximum
    }
    return ans;
}
int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum Platforms Required: " << findPlatform(arr, dep) << endl;

    return 0;
}
*/
