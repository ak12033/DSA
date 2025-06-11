#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

//                                  Bridges In A Graph
/*
void dfs(int node, int parent, vector<int>& discT, vector<int>& low, unordered_map <int, bool>& visited, vector<vector<int>>& result, unordered_map <int, list <int>>& adj, int timer) {

    visited[node] = true;
    discT[node] = low[node] = timer++;
    
    for(auto neighbour : adj[node]) {
        if(neighbour == parent) {
            continue;
        }
        if(!visited[neighbour]) {
            dfs(neighbour, node, discT, low, visited, result, adj, timer);
            low[node] = min(low[node], low[neighbour]);
            
            if(low[neighbour] > discT[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        // Back Edge
        else {
            low[node] = min(low[node], discT[neighbour]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {

    unordered_map <int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    
    }
    
    vector<int> discT(v, -1);
    vector<int> low(v, -1);
    unordered_map <int, bool> visited;
    int parent = -1;
 
    int timer = 0;

    // Call DFS
    vector<vector<int>> result;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            dfs(i, parent, discT, low, visited, result, adj, timer);
        }
    }
    return result;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;
    
    vector<vector<int>> edges(m, vector<int>(2));
    
    // Read the edges
    cout << "Enter the edges : " << endl;
    for (int i=0; i<m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    // Result
    vector<vector<int>> bridges = findBridges(edges, n, m);
    cout << "Bridges in the graph are:" << endl;
    if(bridges.empty()) {
        cout << 0 << endl;
    }
    else {
        for (auto bridge : bridges) {
            cout << bridge[0] << " - " << bridge[1] << endl;
        }
    }
    return 0;
}
*/