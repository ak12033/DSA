#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

//                            Count Strongly Connected Components 
//                                   (Kosaraju’s Algorithm)
/*
void dfs(int node, unordered_map <int, bool>& vis, stack <int>& st, unordered_map <int, list <int>>& adj) {

    vis[node] = true;
    for (auto nbr : adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }
	// Topo logic
    st.push(node);
}
void revDfs(int node, unordered_map <int, bool>& vis, unordered_map <int, list <int>>& transpose) {

    vis[node] = true;
    for(auto nbr : transpose[node]) {
        if(!vis[nbr]) {
            revDfs(nbr, vis, transpose);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {

	// Adj list
	unordered_map <int, list <int>> adj;
	for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Topo sort
    unordered_map <int, bool> vis;
    stack <int> st;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Create a transpose graph
    unordered_map <int, list <int>> transpose;
    for(int i=0; i<v; i++) {
        vis[i] = 0;
        for (auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }

    // Dfs call using transposeAdjList graph
    int count = 0;
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        if(!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}
int main() {

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    // Input the edges
    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    // Result
    int sccCount = stronglyConnectedComponents(n, edges);
    cout << "Number of strongly connected components: " << sccCount << endl;
    
    return 0;
}
*/