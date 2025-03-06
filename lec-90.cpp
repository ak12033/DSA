#include <iostream>
#include <vector>
#include <unordered_map> 
#include <stack>
#include <list> 
using namespace std;

//                              Topological Sort using DFS
/*
void topoSort(int node, unordered_map <int, bool> &visited;, stack <int>& s, unordered_map <int, list<int>>& adj) {

    visited[node] = 1;
    for(auto neighbour: adj[node]) {
        if(!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {

    // Create adjacency list
    unordered_map <int, list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map <int, bool> visited;
    stack<int> s;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    vector<vector<int>> edges(m);
    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Result
    vector<int> result = topologicalSort(edges, n, m);
    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
*/